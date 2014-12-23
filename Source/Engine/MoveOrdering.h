#pragma once
#include "Game_MoveIterator.h"
#include <vector>
#include "Search_Parameters.h"

enum class OrderedMoveType : char { BEST_MOVE, WINNING_CAPTURE, EVEN_CAPTURE, KILLER, LOSING_CAPTURE, NONE};

struct OrderedMove {
public:
	Move move;
	int rating;
	OrderedMoveType type;

	OrderedMove(Move move, int rating, OrderedMoveType type);

	
private:
};

bool operator<(const OrderedMove& a, const OrderedMove& b);

class MoveOrdering {
public:
	// Construct only when Game state is matching the generator.
	MoveOrdering(Search_Parameters params, GameMoveIteratorGenerator gen);
	explicit MoveOrdering(Search_Parameters params);

	std::vector<OrderedMove>::const_iterator begin() const;
	std::vector<OrderedMove>::const_iterator end() const;
	


	MoveOrdering();
	~MoveOrdering();

private:
	std::vector<OrderedMove> moves;

	static OrderedMove order(Move move);
};

