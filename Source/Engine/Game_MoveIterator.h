#pragma once
#include "Game.h"
#include <vector>

class GameMoveIterator {
public:
	Move operator*() const;
	void operator++();
	bool operator!=(const GameMoveIterator& other) const;

private:
	GameMoveIterator(const std::vector<Move>* const moves, uint16_t cur, uint8_t left, bool tacticalOnly);
	const std::vector<Move>* const moves;
	uint16_t cur;//current index into the vector
	uint8_t left;//how many moves left. Only useful for tactical only
	const bool tacticalOnly;

	

	friend class GameMoveIteratorGenerator;
};


class GameMoveIteratorGenerator {
public:
	GameMoveIterator begin();
	GameMoveIterator end();
	

private:
	friend class Game;
	GameMoveIteratorGenerator(const std::vector<Move>* const moves, uint16_t start, uint16_t finish, bool tacticalOnly);
	
	const std::vector<Move>* const moves;
	const uint16_t start;
	const uint16_t finish;
	bool tacticalOnly;

	
};