#include "Evaluation.h"
#include "StaticExchange.h"
#include "AttackMap.h"

namespace {
	bool inited = false;
}
void Evaluation::init() {
	if (inited) {
		return;
	}
	inited = true;
	StaticExchange::init();

	initPawns();
}

void Evaluation::synchronize() {
	init();
	synchronizeMaterial();
	AttackMap::synchronize();
}

void Evaluation::notifyMove(Move move, Turn turn) {
	notifyMoveMaterial(move, turn);
}

void Evaluation::notifyUndoMove(Move move, Turn turn) {
	notifyUndoMoveMaterial(move, turn);
}