#pragma once
#include "Move.h"
#include <cstdint>
#include "EvaluationScore.h"
class EvaluationManager {
public:
	static void synchronize();
	static void notifyMove(Move move, Turn turn);
	static void notifyUndoMove(Move move, Turn turn);

	static int getSimpleScore(Turn turn);

	// Save the score of the current state
	static void calcScoreCurrent();

	// Get the score from n turns ago. n=0 is the current state.
	static EvaluationScore getScore(int n);

	// Get the score for the current state.
	static EvaluationScore getScore();

private:
	
};
