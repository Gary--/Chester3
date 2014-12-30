#include "MoveOrdering.h"
#include <algorithm>
#include "Game.h"
#include "AttackMap.h"
#include <iostream>
#include "Search_Killers.h"
#include "StaticExchange.h"
#include "Search_History.h"
#include "Search_Transposition.h"
using namespace std;

OrderedMove::OrderedMove(Move move, int rating, OrderedMoveType type) :move(move), rating(rating), type(type) {}

bool operator<(const OrderedMove& a, const OrderedMove& b) {
	return a.rating > b.rating;
}



// ============= MOVE ORDERING

std::vector<OrderedMove> MoveOrdering::moves;


MoveOrdering::MoveOrdering() {
	n = 0;
}

MoveOrdering::MoveOrdering(const Search_Parameters params, GameMoveIteratorGenerator gen) {
	n = 0;

	Move TTbestMove = Move::INVALID();
	{
		TTItem ttItem = Search_Transposition::getTransposition(params);
		if (ttItem.type != TT_Entry_Type::INVALID) {
			TTbestMove = ttItem.bestMove;
		}
	}

	for (Move move : gen) {
		n++;
		OrderedMove orderedMove = order(params, TTbestMove, move);
		moves.push_back(orderedMove);
	}
	sort(moves.end() - n, moves.end());
}


MoveOrdering::~MoveOrdering() {}

void MoveOrdering::dispose() {
	moves._Pop_back_n(n);
}


OrderedMove MoveOrdering::order(Search_Parameters params, Move TTbestMove,Move move) {
	int rating = 0;
	OrderedMoveType type = OrderedMoveType::NONE;
	
	if (type == OrderedMoveType::NONE && params.pv.move==move) {
		type = OrderedMoveType::PV_MOVE;
		rating = 60000;
		//cout << "PV" << endl;
	}

	if (type == OrderedMoveType::NONE && TTbestMove==move) {
		type = OrderedMoveType::BEST_MOVE;
		rating = 59999;
	}

	if (type == OrderedMoveType::NONE && move.isTactical()) {
		int see = AttackMap::SEE(move);
		if (see > 0) {
			rating = 50000 + see * 100 - StaticExchange::PieceValue(move.getPiece());
			type = OrderedMoveType::WINNING_CAPTURE;
		} else if (see == 0) {
			type = OrderedMoveType::EVEN_CAPTURE;
			rating = 30000 + see;
		} else {
			type = OrderedMoveType::LOSING_CAPTURE;
			rating = 20000 + see;
		}

	}

	if (type == OrderedMoveType::NONE &&Search_Killers::isKiller(params, move)) {
		type = OrderedMoveType::KILLER;
		rating = 25000;

	}

	if (type == OrderedMoveType::NONE) {
		rating += Search_History::getHistory(move);


	}

	return OrderedMove(move, rating, OrderedMoveType::NONE);
}

OrderedMoveIterator MoveOrdering::begin() const {
	return OrderedMoveIterator((int)moves.size() - n);
}

OrderedMoveIterator MoveOrdering::end() const {
	return OrderedMoveIterator((int)moves.size());
}



// ==== Iterator

OrderedMoveIterator::OrderedMoveIterator(int i) : i(i) {}


OrderedMove OrderedMoveIterator::operator*() const {
	return MoveOrdering::moves[i];
}

void OrderedMoveIterator::operator++() {
	i++;
}

bool OrderedMoveIterator::operator!=(const OrderedMoveIterator& other) const {
	return i != other.i;
}


