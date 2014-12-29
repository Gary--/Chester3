#include "Search.h"
#include "Game.h"
#include "EvaluationManager.h"

void Search::synchronize() {
	EvaluationManager::synchronize();
}



void Search::searchMakeMove(const Move move) {
	nNullsMade += move == Move::NULL_MOVE();
	nChecks += Game::getCheck();

	EvaluationManager::notifyMove(move, Game::getTurn());
	Game::makeMove(move);
}

Move Search::searchUndoMove() {
	const Move move = Game::undoMove();
	EvaluationManager::notifyUndoMove(move, Game::getTurn());


	nChecks -= Game::getCheck();
	nNullsMade -= move == Move::NULL_MOVE();

	return move;
}