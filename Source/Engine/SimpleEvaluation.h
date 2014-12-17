#include "Move.h"

class SimpleEvaluation {
public:
	static int all(Turn turn);
	static int material(Turn turn);
	static int position(Turn turn);

	static void synchronize();

	//Turn is always who made the move.
	static void notifyMove(Move move, Turn turn);
	static void notifyUndoMove(Move move, Turn turn);
private:
};