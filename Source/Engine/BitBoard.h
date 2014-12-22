#pragma once
#include <cstdint>
#include <string>
#include "Position.h"
#include "Chess.h"

#define FOR_BIT(BIT_VAR,BITBOARD_VAR) for(const BitBoard BIT_VAR : (BITBOARD_VAR).getBitBoardBitBoardIteratorGenerator())
#define FOR_POS(POS_VAR,BITBOARD_VAR) for(const Position POS_VAR : (BITBOARD_VAR).getBitBoardPositionIteratorGenerator())

class BitBoard_Position_Iterator_Generator;
class BitBoard_BitBoard_Iterator_Generator;
class Position;
// Represents a set of up to 64 Positions
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

	// Least significant bit. Returns a bit on the upper most row. If tied, left most.
	BitBoard LSB() const;

	// Iterator to singleton sub sets of this bitboard.
	BitBoard_BitBoard_Iterator_Generator getBitBoardBitBoardIteratorGenerator() const;

	// Iterator to Positions in the BitBoard;
	BitBoard_Position_Iterator_Generator getBitBoardPositionIteratorGenerator() const;

	// Is the Position in the set represented by this BitBoard?
	bool contains(Position position) const;

	static BitBoard EMPTY();
	static BitBoard FULL();
	static BitBoard BLACK_SQUARES();
	static BitBoard WHITE_SQUARES();
	static BitBoard EDGE_SQUARES();


	bool isNotEmpty() const;
	bool isEmpty() const;

	friend bool operator==(const BitBoard bb1, const BitBoard bb2);
	friend bool operator!=(const BitBoard bb1, const BitBoard bb2);


	std::string  str() const;
	
	// Flip. Maps e1 <-> e8.
	BitBoard mirror() const;

	//If Turn is black, returns mirror(), else self.
	BitBoard perspective(Turn turn) const;

	// If count()==1, returns the Position such that contains(Position)
	Position ToPosition() const;
	
	// How many on bits.
	int count() const;

	// All the bits in the given row.
	static BitBoard rowBits(int row);

	// All the bits in the given column.
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

	// Returns a randomly populated BitBoard
	static BitBoard random();
};

#include "BitBoard_Position_Iterator.h"