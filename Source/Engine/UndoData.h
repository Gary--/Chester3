#include "Move.h"
#include "GameHash.h"



struct UndoData {
	UndoData();

	GameHash hash;
	Move move;
	int numMovesAvailable;
	int numMovesStored;
	bool check;
};