#include "Search_Transposition.h"
#include "Game.h"

TTItem Search_Transposition::TT[TTSize];

void Search_Transposition::addTransposition(Search_Parameters params, Search_SearchResult result) {
	uint64_t hash = Game::getHash();


	TTItem item;
	item.setDepth( params.depth);
	item.hash = hash;
	item.score = result.score;
	item.setMove(result.pv.move);
	
	if (item.score >= params.beta) {
		item.setType( TT_Entry_Type::LOWER_BOUND);
	} else if (item.score <= params.alpha) {
		item.setType(TT_Entry_Type::UPPER_BOUND);
	} else {
		item.setType(TT_Entry_Type::EXACT);
	}

	// Avoid replacing entries that are strictly more useful
	const TTItem cur = TT[Game::getHash() % TTSize];
	if (cur.hash == hash &&
		cur.getDepth() >= item.getDepth() &&
		(item.getType() == cur.getType() || cur.getType() == TT_Entry_Type::EXACT)
		) {
		return;
	}
		
	


	TT[hash%TTSize] = item;
}

TTItem Search_Transposition::getTransposition(Search_Parameters params) {
	TTItem result = TT[Game::getHash()%TTSize];
	if (result.hash != Game::getHash()) {
		result.setType(TT_Entry_Type::INVALID);
	}

	return result;
}



TTItem::TTItem() {
	hash = 0;
	score = 0;
	setDepth(0);
	setType(TT_Entry_Type::INVALID);
	setMove(Move::INVALID());
}


namespace {
	const int moveShift = 0;
	const uint32_t moveMask = 0x3FFFFF << moveShift;

	const int depthShift = 22;
	const uint32_t depthMask = (uint32_t)0xFF << depthShift;

	const int typeShift = 30;
	const uint32_t typeMask = (uint32_t)0x3 << typeShift;
}

Move TTItem::getMove() const {
	return Move((moveDepthType & moveMask) >> moveShift);
}

void TTItem::setMove(Move move) {
	moveDepthType &= ~moveMask;
	moveDepthType |= move.asInt32() << moveShift;
}

void TTItem::setDepth(uint8_t depth) {
	moveDepthType &= ~depthMask;
	moveDepthType |= depth << depthShift;
}

uint8_t TTItem::getDepth() const {
	return (moveDepthType&depthMask) >> depthShift;
}

void TTItem::setType(TT_Entry_Type type) {
	moveDepthType &= ~typeMask;
	moveDepthType |= (uint8_t)type << typeShift;
}

TT_Entry_Type TTItem::getType() const {
	return TT_Entry_Type((moveDepthType&typeMask) >> typeShift);
}
