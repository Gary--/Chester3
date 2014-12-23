#include "MoveOrdering.h"
#include <algorithm>
#include "Game.h"

namespace {

}

MoveOrdering::MoveOrdering() {}



MoveOrdering::MoveOrdering(GameConfiguration_MoveIterator_Generator gen, int depth) {
	for (Move move : gen) {
		//moves.push_back(move);
	}


}


MoveOrdering::~MoveOrdering() {}
