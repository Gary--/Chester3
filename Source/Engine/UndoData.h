#include "Move.h"
#include "GameHash.h"

struct UndoData {
	UndoData(Move move, GameHash hash, int numMovesAvail,bool check);

	Move move;
	int numMovesAvailable;
	GameHash hash;
	bool check;
};