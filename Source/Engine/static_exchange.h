#pragma once
#include <cstdint>
#include "AttackDefend.h"
namespace SEE {
	void init();

	// How much do we lose if we attack the square.
	int8_t attackCost(Piece attacker, AtkPat attackers, AtkPat defenders);

	// How much do we lose if we attack the square with the smallest
	// that can attack it.
	int8_t attackCostMin(AtkPat attackers, AtkPat defenders);
}