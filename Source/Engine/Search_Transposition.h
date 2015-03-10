#pragma once
#include <cstdint>
#include "Search_SearchResult.h"
#include "Search_Parameters.h"

enum class TT_Entry_Type : uint8_t {EXACT, LOWER_BOUND,UPPER_BOUND, INVALID};

struct TTItem {
public:
	TTItem();
	uint64_t hash;
	int score;

	void setMove(Move move);
	Move getMove() const;

	void setDepth(uint8_t depth);
	uint8_t getDepth() const;

	void setType(TT_Entry_Type ype);
	TT_Entry_Type getType() const;

private:
	uint32_t moveDepthType;

	
};

class Search_Transposition {
public:
	// Returns what was passed to it for easy coding
	static void addTransposition(Search_Parameters params, Search_SearchResult result);
	static TTItem getTransposition(Search_Parameters params);

private:
	const static int tableSizeMb = 128;
	const static int TTSize = tableSizeMb * 1000000 / sizeof(TTItem);
	static TTItem TT[TTSize];
};

