#pragma once
#include "Game_MoveIterator.h"
#include <vector>



struct OrderedMove {
public:
	Move move;
private:
};

class MoveOrdering {
public:
	// Construct only when Game state is matching the generator. Depth = 0 for quiesce
	explicit MoveOrdering(GameConfiguration_MoveIterator_Generator gen,int depth);

	std::vector<OrderedMove>::const_iterator begin() const;
	std::vector<OrderedMove>::const_iterator end() const;

	MoveOrdering();
	~MoveOrdering();

private:
	std::vector<OrderedMove> moves;
};

