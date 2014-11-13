#include "Search.h"
#include "Game.h"
#include "Evaluate_simple.h"
void Search::searchMakeMove(Move move) {
	SimpleEvaluation::notifyMove(move, Game::getTurn());
	Game::makeMove(move);
	
}

Move Search::searchUndoMove() {
	Move move = Game::undoMove();
	SimpleEvaluation::notifyUndoMove(move,Game::getTurn());
	return move;
}