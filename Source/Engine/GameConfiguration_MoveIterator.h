#pragma once
#include <vector>
#include "Move.h"

struct GameConfiguration;
class GameConfiguration_MoveIterator {
public:
	Move operator*() const;
	void operator++();
	bool operator!=(const GameConfiguration_MoveIterator& other) const;
private:
	friend class GameConfiguration_MoveIterator_Generator;

	explicit GameConfiguration_MoveIterator(std::vector<Move>::const_iterator it);
	std::vector<Move>::const_iterator it;
};

class GameConfiguration_MoveIterator_Generator {
public:
	GameConfiguration_MoveIterator begin() const;
	GameConfiguration_MoveIterator end() const;
private:
	friend struct GameConfiguration;
	explicit GameConfiguration_MoveIterator_Generator(GameConfiguration conf);

	void addMove(const GameConfiguration& conf, Move move);
	void addPawnMove(const GameConfiguration& conf, Move move);
	void generateMoves(const GameConfiguration& conf);

	std::vector<Move> moves;
};