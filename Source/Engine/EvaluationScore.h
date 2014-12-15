#pragma once
#include "Chess.h"

// Scores for a full evaluation of one position. Read only.
struct EvaluationScore {

	EvaluationScore(); // Returns in invalid state

	static EvaluationScore GetFromGameState(); // Evaluate the current Game state and generate an instance.
	static EvaluationScore GetInvalid();

	bool isValid() const;

	int getOverall(Turn turn) const; // Sum of all the scores
	double getLateness() const;// Portion of material remaining

	// Methods marked relative means only 1 score is actually stored internally. Turn is just perspective
	int getRelativeSimple(Turn perspective) const; // The simple evaluation
	int getRelativeMaterial(Turn perspective) const;
	int getKingDanger(Turn turn) const;// Positive if turn's king is in danger
	int getRelativeCenter(Turn perspective) const;
	int getRelativeMobility(Turn perspective) const;
	int getPawns(Turn turn);
private:
	const double lateness;

	const int simple;

	const int relativeMobility;
	const int relativeMaterial;
	const int whiteKingDanger, blackKingDanger;
	const int relativeCenter;
	const int relativeMobility;
	const int whitePawns, blackPawns;

	const bool _isValid;
};