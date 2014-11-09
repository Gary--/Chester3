#include "Move.h"

class SimpleEvaluation {
public:
	int evaluateFull(Turn turn);
	int evaluateMaterial(Turn turn);
	int evaluatePosition(Turn turn);

	static void synchronize();

	//Turn is always who made the move.           Order won't matter later
	void notifyMove(Move move, Turn turn);     //Call before Game::makeMove
	void notifyUndoMove(Move move, Turn turn); //Call after Game::undoMove
private:
};