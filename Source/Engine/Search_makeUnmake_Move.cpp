#include "Search.h"
#include "Game.h"
#include "EvaluationManager.h"
void Search::configureGame(const GameConfiguration conf) {
	Game::configure(conf);
	EvaluationManager::synchronize();
}

void Search::searchMakeMove(const Move move) {
	EvaluationManager::notifyMove(move, Game::getTurn());
	Game::makeMove(move);
}

Move Search::searchUndoMove() {
	const Move move = Game::undoMove();
	EvaluationManager::notifyUndoMove(move, Game::getTurn());
	return move;
}