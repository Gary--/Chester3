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
	bool getCheck() const;
private:
	EvaluationScore(bool _);

	double lateness;

	int whiteSimple, blackSimple;

	bool check;
	int relativeMobility;
	int relativeMaterial;
	int whiteKingDanger, blackKingDanger;
	int relativeCenter;
	int whitePawns, blackPawns;
	int whiteMisc, blackMisc;
	bool _isValid;
};