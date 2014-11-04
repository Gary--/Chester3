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
	movePtr = 0;
	cur = UndoData();
}

void Game::addMove(Move move) {
	moves.push_back(move);
	cur.numMovesStored++;
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
	if (cur.numMovesStored == -1) {
		cur.numMovesStored = 0;
		generateMovesImpl();
		cur.numMovesAvailable = cur.numMovesStored;

	}
}

int Game::getNumValidMoves() {
	generateMoves();
	return cur.numMovesAvailable;
}

AllMoveIteratorGenerator Game::getAllMoves() {
	generateMoves();

	return AllMoveIteratorGenerator(&moves, movePtr, movePtr+ cur.numMovesAvailable, false);
}


void Game::pushMove(Move move) {
	cur.move = move;

	if (cur.numMovesStored > 0) {
		movePtr += cur.numMovesStored;
	}

	undoDatas.push_back(cur);
	
	cur.numMovesStored = -1;
	cur.numMovesAvailable = -1;
	
}

void Game::popMove() {
	moves.erase(moves.begin() + movePtr, moves.end());
	

	cur = undoDatas.back();
	undoDatas.pop_back();


	movePtr -= cur.numMovesStored;

}