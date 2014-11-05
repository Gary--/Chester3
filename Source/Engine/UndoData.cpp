#include "UndoData.h"

UndoData::UndoData() {
	check = false;
	numMovesStored = 0;
	movesStored = MovesStored::NONE;
	deadPositionState = DeadPositionState::UNKNOWN;
}