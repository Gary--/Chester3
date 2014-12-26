#include "Search_Transposition.h"
#include "Game.h"

TTItem Search_Transposition::TT[TTSize];

Search_SearchResult Search_Transposition::addTransposition(Search_Parameters params, Search_SearchResult result) {
	uint64_t hash = Game::getHash();

	TTItem item;
	item.depth = params.depth;
	item.hash = hash;
	item.score = result.score;

	TT[hash%TTSize] = item;

	return result;
}

TTItem Search_Transposition::getTransposition(Search_Parameters params) {
	TTItem result = TT[Game::getHash()%TTSize];
	if (result.hash != Game::getHash()) {
		result.type = NodeType::UNKNOWN;
	}

	return result;
}


