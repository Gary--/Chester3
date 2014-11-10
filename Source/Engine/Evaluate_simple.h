#include "Move.h"

class SimpleEvaluation {
public:
	static int evaluateFull(Turn turn);
	static int evaluateMaterial(Turn turn);
	static int evaluatePosition(Turn turn);

	static void synchronize();

	//Turn is always who made the move.
	static void notifyMove(Move move, Turn turn);
	static void notifyUndoMove(Move move, Turn turn);
private:
};