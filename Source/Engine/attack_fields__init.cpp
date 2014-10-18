#include "attack_fields.h"
#include "Attack_Fields_init.h"

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

}