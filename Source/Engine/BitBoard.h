#pragma once
#include <cstdint>
#include <string>
#include "Position.h"
#include "chess_consts.h"

class Position;
// Represents a set of up to Positions
class BitBoard
{


private:
	uint64_t value;
	

public:
	explicit BitBoard(uint64_t value);
	~BitBoard();
	BitBoard();

	BitBoard operator|(const BitBoard other) const;
	BitBoard operator&(const BitBoard other) const;
	BitBoard operator^(const BitBoard other) const;
	BitBoard operator~() const;
	
	BitBoard operator|=(const BitBoard other);
	BitBoard operator&=(const BitBoard other);
	BitBoard operator^=(const BitBoard other);

	BitBoard shiftUp() const;
	BitBoard shiftDown() const;
	BitBoard shiftRight() const;
	BitBoard shiftLeft() const;

	BitBoard shiftForward(Turn turn) const;
	BitBoard shiftBackward(Turn turn) const;

	// Least significant bit
	BitBoard const LSB();
	bool  contains(Position position) const;

	const static BitBoard EMPTY;
	const static BitBoard FULL;

	

	friend bool operator==(const BitBoard bb1, const BitBoard bb2);
	friend bool operator!=(const BitBoard bb1, const BitBoard bb2);


	std::string  str() const;
	

	BitBoard verticalFlip() const;
	Position ToPosition() const;// Only use on a singleton board
	int count() const;


	static BitBoard rowBits(int row);
	static BitBoard colBits(int col);

	static BitBoard random();
};

