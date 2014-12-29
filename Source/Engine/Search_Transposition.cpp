#include "Search_Transposition.h"
#include "Game.h"

TTItem Search_Transposition::TT[TTSize];

Search_SearchResult Search_Transposition::addTransposition(Search_Parameters params, Search_SearchResult result) {
	uint64_t hash = Game::getHash();

	TTItem item;
	item.depth = params.depth;
	item.hash = hash;
	item.score = result.score;
	item.bestMove = result.pv.move;
	
	if (item.score >= params.beta) {
		item.type = TT_Entry_Type::LOWER_BOUND;
	} else if (item.score <= params.alpha) {
		item.type = TT_Entry_Type::UPPER_BOUND;
	} else {
		item.type = TT_Entry_Type::EXACT;
	}

	TT[hash%TTSize] = item;

	return result;
}

TTItem Search_Transposition::getTransposition(Search_Parameters params) {
	TTItem result = TT[Game::getHash()%TTSize];
	if (result.hash != Game::getHash()) {
		result.type = TT_Entry_Type::INVALID;
	}

	return result;
}


