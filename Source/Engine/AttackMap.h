#pragma once
#include "AttackPattern.h"
#include "Move.h"

// Manages computing of AttackPattern
// By default will compute AttackPattern for squares on demand.
// setPrecompute will efficiently compute the AttackPattern for every square
class AttackMap {
public:
	// Initialize internal data structures.
	static void synchronize();

	// Precompute for the current Game hash. Only 1 will be stored.
	static void precompute();

	
	static void notifyMove(Move move, Turn turn);
	static void notifyUndoMove(Move move, Turn turn);

	// Control turn has on the position.
	static AttackPattern getAttackPattern(Turn turn, Position position);

	static int SEE(Move move);
private:
	static AttackPattern getAttackPatternImpl(Turn turn, Position position);
};