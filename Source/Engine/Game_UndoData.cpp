#include "Game_UndoData.h"

Game_UndoData::Game_UndoData() {
	check = false;
	numMovesStored = 0;
	movesStored = MovesStored::NONE;
	deadPositionState = DeadPositionState::UNKNOWN;
	repeatedness = 1;
	halfMoveClock = 0;
}