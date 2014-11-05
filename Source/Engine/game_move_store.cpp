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

bool Game::areMovesAvailable() {
	if (cur.numMovesStored >0) {
		return true;
	}

	if (isDefinitelyAMoveAvailable()) {
		return true;
	}

	generateAllMoves();

	return cur.numMovesStored > 0;

}

void Game::generateAllMoves() {
	if (cur.movesStored == UndoData::MovesStored::ALL) {
		return;
	}

	if (cur.movesStored == UndoData::MovesStored::TACTICAL) {
		moves.erase(moves.begin() + movePtr, moves.end());
		cur.numMovesStored = 0;
	} else {
		_ASSERTE(cur.numMovesStored == 0);
	}

	generateMovesImpl(false);
	
	cur.movesStored = UndoData::MovesStored::ALL;
}

void Game::generateTacticalMoves() {
	if (cur.movesStored == UndoData::MovesStored::ALL ||
		cur.movesStored == UndoData::MovesStored::TACTICAL) {
		return;
	}

	_ASSERTE(cur.numMovesStored == 0);

	generateMovesImpl(true);
}

int Game::getNumValidMoves() {
	generateAllMoves();
	return cur.numMovesStored;
}

AllMoveIteratorGenerator Game::getAllMoves() {
	generateAllMoves();
	return AllMoveIteratorGenerator(&moves, movePtr, movePtr+ cur.numMovesStored, false);
}

AllMoveIteratorGenerator Game::getTacticalMoves() {
	generateTacticalMoves();
	return AllMoveIteratorGenerator(&moves, movePtr, movePtr + cur.numMovesStored, true);
}


void Game::pushMove(Move move) {
	cur.move = move;

	movePtr += cur.numMovesStored;

	undoDatas.push_back(cur);
	cur.numMovesStored = 0;
	cur.deadPositionState = UndoData::DeadPositionState::UNKNOWN;
	cur.movesStored = UndoData::MovesStored::NONE;

}

void Game::popMove() {

	moves.erase(moves.begin() + movePtr, moves.end());
	
	cur = undoDatas.back();
	undoDatas.pop_back();

	movePtr -= cur.numMovesStored;
}