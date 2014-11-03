#include "Move.h"
#include "GameHash.h"

struct UndoData {
	UndoData();

	Move move;
	int numMovesAvailable;
	GameHash hash;
	bool check;
};