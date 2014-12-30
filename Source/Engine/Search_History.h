#pragma once
#include "Move.h"
#include "Search_Parameters.h"
class Search_History {
public:
	static void reset();

	// Call only on full search
	static void addHistory(Search_Parameters params, Move move);
	static int getHistory(Move move);

private:
	static void halve(Turn turn);

	const static int MAX_HISTORY = 2000;
	static int history[2][7][64];
};

