#pragma once
#include "AttackDefend.h"
#include "Move.h"

// Manages computing of AtkPat
// By default will compute AtkPat for squares on demand.
// setPrecompute will efficiently compute the AtkPat for every square
class AttackMap {
	void synchronize();

	bool setPrecompute();
	void notifyMove(Move move, Turn turn);
	void notifyUndoMove(Move move, Turn turn);

	// Control turn has on the position.
	AtkPat getAtkPat(Turn turn, Position position);
private:

};