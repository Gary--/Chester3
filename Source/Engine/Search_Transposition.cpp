#include "Search_Transposition.h"
#include "Game.h"

TTItem Search_Transposition::TT[TTSize];

void Search_Transposition::addTransposition(Search_Parameters params, Search_SearchResult result) {
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

	// Avoid replacing entries that are strictly more useful
	const TTItem cur = TT[Game::getHash() % TTSize];
	if (cur.hash == hash &&
		cur.depth >= item.depth &&
		(item.type == cur.type || cur.type == TT_Entry_Type::EXACT)
		) {
		return;
	}
		
	


	TT[hash%TTSize] = item;
}

TTItem Search_Transposition::getTransposition(Search_Parameters params) {
	TTItem result = TT[Game::getHash()%TTSize];
	if (result.hash != Game::getHash()) {
		result.type = TT_Entry_Type::INVALID;
	}

	return result;
}



TTItem::TTItem() {
	hash = 0;
	score = 0;
	bestMove = Move::INVALID();
	depth = -100;
	type = TT_Entry_Type::INVALID;
}
