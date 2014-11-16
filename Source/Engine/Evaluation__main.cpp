#include "Evaluation.h"

namespace {
	bool inited = false;
}
void Evaluation::init() {
	if (inited) {
		return;
	}
	inited = true;

	initPawns();
}

void Evaluation::synchronize() {
	init();
	synchronizeMaterial();
}

void Evaluation::notifyMove(Move move, Turn turn) {
	notifyMoveMaterial(move, turn);
}

void Evaluation::notifyUndoMove(Move move, Turn turn) {
	notifyUndoMoveMaterial(move, turn);
}