#pragma once
#include "AttackPattern.h"
#include "Move.h"

// Manages computing of AttackPattern
// By default will compute AttackPattern for squares on demand.
// setPrecompute will efficiently compute the AttackPattern for every square
class AttackMap {
	void synchronize();

	bool setPrecompute();
	void notifyMove(Move move, Turn turn);
	void notifyUndoMove(Move move, Turn turn);

	// Control turn has on the position.
	AttackPattern getAtkPat(Turn turn, Position position);
private:

};