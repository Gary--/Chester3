#include "Game.h"
#include "attack_fields.h"
#include <vector>

namespace {
	std::vector<UndoData> undoDatas;
	std::vector<Move> moves;
}

void Game::resetMoveManager() {
	undoDatas.clear();
	moves.clear();
}

void Game::addMove(Move move) {
	moves.push_back(move);
	cur.numMovesAvailable++;
}

void Game::addPawnMove(Move move) {
	if (AttackFields::pawnPromoZone(curTurn).contains(move.getFrom())) {
		FOR_PIECE(promo, Piece::KNIGHT, Piece::QUEEN) {
			addMove(Move(promoType(promo), move.getFrom(), move.getTo(), Piece::PAWN, move.getTarg()));
		}
	} else {
		addMove(move);
	}
}


void Game::generateMoves() {
	if (cur.numMovesAvailable == -1) {
		cur.numMovesAvailable = 0;
		generateMovesImpl();
	}
}

int Game::getNumValidMoves() {
	Game::generateMoves();
	return cur.numMovesAvailable;
}
Move Game::getMove(int n) {
	_ASSERTE(0 <= n && n < getNumValidMoves());
	return moves[movePtr + n];
}

void Game::pushMove(Move move) {
	cur.move = move;
	movePtr += cur.numMovesAvailable;

	undoDatas.push_back(cur);
	
	cur.numMovesAvailable = -1;
	
}

void Game::popMove() {
	if (cur.numMovesAvailable > 0) {
		moves.erase(moves.begin() + movePtr, moves.end());
	}

	cur = undoDatas.back();
	undoDatas.pop_back();

	if (cur.numMovesAvailable > 0) {
		movePtr -= cur.numMovesAvailable;
	}
}