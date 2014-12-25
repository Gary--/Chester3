#pragma once
#include "Move.h"
#include "Game_Hash.h"



struct Game_UndoData {
private:
	friend class Game;

	Game_UndoData();

	enum class MovesStored : uint8_t { NONE, ALL, TACTICAL };
	enum class DeadPositionState : uint8_t { UNKNOWN, IS_MOVE, NO_MOVE };

	Game_Hash hash;
	Move move;
	int numMovesStored;
	int repeatedness;
	int halfMoveClock;
	MovesStored movesStored;
	DeadPositionState deadPositionState;
	bool check;
};