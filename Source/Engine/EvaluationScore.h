#pragma once
#include "Chess.h"
#include <cstdint>
// Scores for a full evaluation of one position. Read only.
struct EvaluationScore {
	const static int INVALID_SCORE = INT_MIN+2;

	EvaluationScore(); // Returns in invalid state

	static EvaluationScore GetFromGameState(); // Evaluate the current Game state and generate an instance.
	static EvaluationScore GetInvalid();

	bool isValid() const;

	int getOverall(Turn perspective) const; // Sum of all the scores
	double getLateness() const;// Portion of material remaining

	// Methods marked relative means only 1 score is actually stored internally. Turn is just perspective
	int getSimple(Turn turn) const; // The simple evaluation
	int getRelativeMaterial(Turn perspective) const;
	int getKingDanger(Turn turn) const;// Positive if turn's king is in danger
	int getRelativeCenter(Turn perspective) const;
	int getRelativeMobility(Turn perspective) const;
	int getPawns(Turn turn) const;
	int getMisc(Turn turn) const;
	
private:
	EvaluationScore(bool _);

	const double lateness;

	const int whiteSimple, blackSimple;

	const int relativeMobility;
	const int relativeMaterial;
	const int whiteKingDanger, blackKingDanger;
	const int relativeCenter;
	const int whitePawns, blackPawns;
	const int whiteMisc, blackMisc;
	const bool _isValid;
};