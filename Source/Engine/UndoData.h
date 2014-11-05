#include "Move.h"
#include "GameHash.h"



struct UndoData {
private:
	friend class Game;

	UndoData();

	enum class MovesStored : uint8_t { NONE, ALL, TACTICAL };
	enum class DeadPositionState : uint8_t { UNKNOWN, IS_MOVE, NO_MOVE };

	GameHash hash;
	Move move;
	int numMovesStored;
	MovesStored movesStored;
	DeadPositionState deadPositionState;
	bool check;
};