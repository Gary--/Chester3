#include "Move.h"

class SimpleEvaluation {
public:
	int evaluateFull(Turn turn);
	int evaluateMaterial(Turn turn);
	int evaluatePosition(Turn turn);

	static void synchronize();
	void notifyMove(Move move);
	void notifyUndoMove(Move move);
private:
};