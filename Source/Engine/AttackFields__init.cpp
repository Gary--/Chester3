#include "AttackFields.h"
#include "AttackFieldsInit.h"

namespace {
	bool inited = false;
}
void AttackFields::init() {
	if (inited) {
		return;
	}
	inited = true;

	AttackFieldInit::KingKnightPawn();
	AttackFieldInit::BishopRook();
	AttackFieldInit::BlockingPinning();

}