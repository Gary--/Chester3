#pragma once
#include "Game.h"
#include <vector>

class AllMoveIterator {
public:
	Move operator*() const;
	void operator++();
	bool operator!=(const AllMoveIterator& other) const;

private:
	AllMoveIterator(const std::vector<Move>* const moves, uint16_t cur, uint8_t left, bool tacticalOnly);
	const std::vector<Move>* const moves;
	uint16_t cur;//current index into the vector
	uint8_t left;//how many moves left. Only useful for tactical only
	const bool tacticalOnly;

	

	friend class AllMoveIteratorGenerator;
};


class AllMoveIteratorGenerator {
public:
	AllMoveIterator begin();
	AllMoveIterator end();
	

private:
	friend class Game;
	AllMoveIteratorGenerator(const std::vector<Move>* const moves, uint16_t start, uint16_t finish, bool tacticalOnly);
	
	const std::vector<Move>* const moves;
	const uint16_t start;
	const uint16_t finish;
	bool tacticalOnly;

	
};