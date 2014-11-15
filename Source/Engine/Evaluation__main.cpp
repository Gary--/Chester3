#include "Evaluation.h"

void Evaluation::synchronize() {
	synchronizeMaterial();
}

void Evaluation::notifyMove(Move move, Turn turn) {
	notifyMoveMaterial(move, turn);
}

void Evaluation::notifyUndoMove(Move move, Turn turn) {
	notifyUndoMoveMaterial(move, turn);
}