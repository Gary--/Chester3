#pragma once
#include <cstdint>
#include <string>
#include "Position.h"
#include "chess_consts.h"

#define FOR_BIT(VAR,BITS) for(BitBoard BITS_COPY=(BITS),VAR=BitBoard::EMPTY(); (VAR=BITS_COPY.LSB())!=BitBoard::EMPTY(); BITS_COPY^=VAR)


class Position;
// Represents a set of up to Positions
class BitBoard
{


private:
	uint64_t value;
	

public:
	explicit BitBoard(uint64_t value);
	BitBoard(int r, int c);
	BitBoard();

	uint64_t AsInt64() const;

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

	static BitBoard EMPTY();
	static BitBoard FULL();
	static BitBoard BLACK_SQUARES();
	static BitBoard WHITE_SQUARES();



	

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

