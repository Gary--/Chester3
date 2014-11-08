#pragma once
#include <cstdint>
#include "AttackDefend.h"
class SEE {
public:
	static void init();

	// How much do we lose if we attack the square.
	static int attackCost(Piece attacker, AtkPat attackers, AtkPat defenders);

	// How much do we lose if we attack the square with the smallest
	// that can attack it.
	static int attackCostMin(AtkPat attackers, AtkPat defenders);

private:
	static void initSEE(Piece attacker, AtkPat attackers, AtkPat defenders);
};