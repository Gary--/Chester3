#include "Evaluation.h"
#include "StaticExchange.h"
#include "AttackMap.h"
#include "AttackFields.h"

namespace {
	bool inited = false;
}
void Evaluation::init() {
	if (inited) {
		return;
	}
	inited = true;
	AttackFields::init();
	StaticExchange::init();
	
	initPawns();
}

void Evaluation::synchronize() {
	init();
	synchronizeMaterial();
	AttackMap::synchronize();
}

void Evaluation::notifyMove(const Move move, const  Turn turn) {
	notifyMoveMaterial(move, turn);
}

void Evaluation::notifyUndoMove(const Move move, const  Turn turn) {
	notifyUndoMoveMaterial(move, turn);
}