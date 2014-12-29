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

	// Lazy evaluation using only static material and piece-square
	int getRelativeSimple(Turn perspective) const; // The simple evaluation

	// Material score adjusted for lateness
	int getRelativeMaterial(Turn perspective) const;

	// Positive if turn's king is in danger
	int getKingDanger(Turn turn) const;

	// Control of the center squares
	int getRelativeCenter(Turn perspective) const;

	// Mobility of knights, bishops, rooks
	int getRelativeMobility(Turn perspective) const;

	// Pawn formation/structure, passed pawns
	int getPawns(Turn turn) const;

	// Misc
	int getMisc(Turn turn) const;

	// Is the turn playing in check?
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