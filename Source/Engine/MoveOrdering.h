#pragma once
#include "Game_MoveIterator.h"
#include <vector>
#include "Search_Parameters.h"

enum class OrderedMoveType : char { PV_MOVE, BEST_MOVE, WINNING_CAPTURE, EVEN_CAPTURE, KILLER, LOSING_CAPTURE, NONE };

struct OrderedMove {
public:
	Move move;
	int rating;
	OrderedMoveType type;

	OrderedMove(Move move, int rating, OrderedMoveType type);
private:
};

class OrderedMoveIterator {
public:
	OrderedMove operator*() const;
	void operator++();
	bool operator!=(const OrderedMoveIterator& other) const;

private:
	int i;
	explicit OrderedMoveIterator(int i);
	friend class MoveOrdering;
};

bool operator<(const OrderedMove& a, const OrderedMove& b);

class MoveOrdering {
public:
	// Construct only when Game state is matching the generator.
	MoveOrdering(Search_Parameters params, GameMoveIteratorGenerator gen);

	OrderedMoveIterator begin() const;
	OrderedMoveIterator end() const;
	
	void dispose();

	MoveOrdering();
	~MoveOrdering();

private:
	friend class OrderedMoveIterator;

	// How many moves this is.
	int n;
	static std::vector<OrderedMove> moves;
	static OrderedMove order(Search_Parameters params, Move move);
};

