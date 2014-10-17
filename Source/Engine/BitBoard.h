#pragma once
#include <cstdint>
#include <string>
#include "Position.h"

class Position;
// Represents a set of up to Positions
class BitBoard
{


private:
	uint64_t value;
	BitBoard();

public:
	explicit BitBoard(uint64_t value);
	~BitBoard();

	BitBoard operator|(const BitBoard other) const;
	BitBoard operator&(const BitBoard other) const;
	BitBoard operator^(const BitBoard other) const;
	BitBoard operator~() const;
	
	BitBoard operator|=(const BitBoard other);
	BitBoard operator&=(const BitBoard other);
	BitBoard operator^=(const BitBoard other);

	// Least significant bit
	BitBoard const LSB();
	bool  contains(Position position) const;

	const static BitBoard EMPTY;
	const static BitBoard FULL;

	friend bool operator==(const BitBoard bb1, const BitBoard bb2);
	friend bool operator!=(const BitBoard bb1, const BitBoard bb2);
	std::string  str() const;
	// Only use on a singleton board
	Position ToPosition();
};

