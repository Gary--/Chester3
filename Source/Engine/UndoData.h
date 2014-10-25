#include "Move.h"
#include "GameHash.h"

struct UndoData {
	UndoData(Move move, GameHash hash);

	Move move;
	int numMovesAvailable;
	GameHash hash;
};