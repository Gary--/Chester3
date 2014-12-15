#pragma once
#include "Move.h"
#include <cstdint>

class EvaluationManager {
public:
	static void sync();
	static void notifyMove(Move move, Turn turn);
	static void notifyUndoMove(Move move, Turn turn);

	static const int UNKNOWN_EVAL_SCORE = INT_MIN;

	// Get the score from n turns ago. n=0 is the current turn
	static int getScore(Turn turn,int n);


private:
};