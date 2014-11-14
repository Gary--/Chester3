#include "AttackFields.h"

namespace {
	bool inited = false;
}
void AttackFields::init() {
	if (inited) {
		return;
	}
	inited = true;

	initKingKnightPawn();
	initBishopRook();
	initBlockingPinning();
}