#pragma once
#include <cstdint>
#include "Search_SearchResult.h"
#include "Search_Parameters.h"

struct TTItem {
	uint64_t hash;
	int score;
	Move bestMove;
	char depth;
	NodeType type;

};

class Search_Transposition {
public:
	// Returns what was passed to it for easy coding
	static Search_SearchResult addTransposition(Search_Parameters params, Search_SearchResult result);
	static TTItem getTransposition(Search_Parameters params);

private:

	const static int TTSize = 1000000;
	static TTItem TT[TTSize];
};

