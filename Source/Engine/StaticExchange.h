#pragma once
#include <cstdint>
#include "AttackPattern.h"
#include "Move.h"
class StaticExchange {
public:
	static void init();

	// How much do we lose if we attack the square.
	static int attackCost(Piece attacker, AttackPattern attackers, AttackPattern defenders);

	// How much do we lose if we attack the square with the smallest
	// that can attack it.
	static int attackCostMin(AttackPattern attackers, AttackPattern defenders);

	
	static int materialChange(Move move);
private:
	

	static int attackCostImpl(Piece attacker, AttackPattern attackers, AttackPattern defenders);
};

