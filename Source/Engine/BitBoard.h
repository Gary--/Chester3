#pragma once
#include <cstdint>
#include <string>
#include "Position.h"
#include "Chess.h"

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

	uint64_t asInt64() const;

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
	static BitBoard EDGE_SQUARES();



	bool isEmpty() const;

	friend bool operator==(const BitBoard bb1, const BitBoard bb2);
	friend bool operator!=(const BitBoard bb1, const BitBoard bb2);


	std::string  str() const;
	
	BitBoard mirror() const;
	BitBoard perspective(Turn turn) const;//If black, returns mirror, else self.

	Position ToPosition() const;// Only use on a singleton board
	
	int count() const;


	static BitBoard rowBits(int row);
	static BitBoard colBits(int col);

	//rank + file
	//	\f  0  1  2  3  4  5  6  7
	//	r_________________________
	//	7 | 0  1  2  3  4  5  6  7   h8
	//	6 | 1  2  3  4  5  6  7  8
	//	5 | 2  3  4  5  6  7  8  9
	//	4 | 3  4  5  6  7  8  9 10
	//	3 | 4  5  6  7  8  9 10 11
	//	2 | 5  6  7  8  9 10 11 12
	//	1 | 6  7  8  9 10 11 12 13
	//	0 | 7  8  9 10 11 12 13 14
	static BitBoard diagonalBits(int i);

	//rank + file
	//	\f  0  1  2  3  4  5  6  7
	//	r_________________________
	//	7 | 7  8  9 10 11 12 13 14   h8
	//	6 | 6  7  8  9 10 11 12 13
	//	5 | 5  6  7  8  9 10 11 12
	//	4 | 4  5  6  7  8  9 10 11
	//	3 | 3  4  5  6  7  8  9 10
	//	2 | 2  3  4  5  6  7  8  9
	//	1 | 1  2  3  4  5  6  7  8
	//	0 | 0  1  2  3  4  5  6  7
	static BitBoard antiDiagonalBits(int i);

	// rowBits(0) | rowBits(1) | ... | rowBits(r-1)
	static BitBoard rowsLessThan(int r);
	
	// rowBits(r+1) | ... | rowBits(7)
	static BitBoard rowsGreaterThan(int r);

	static BitBoard random();
};

