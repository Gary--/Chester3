#pragma once
#include <cstdint>
#include "BitBoard.h"
#include <string>
#include "Chess.h"
#define FOR_POSITION_64(p) for(Position p=Position(0);p.index()<64;p=Position(p.index()+1))

class BitBoard;
// Represents one of the 64 squares on the board.
class Position
{

private:

	uint8_t value;
	void AssertValid() const;

public:
	Position();//generates an invalid default Position
	explicit Position(int index);
	explicit Position(const char* value);
	explicit Position(const std::string& value);
	Position(int row, int column);


	~Position();

	friend bool const operator==(const Position pos1,Position pos2);
	friend bool const operator!=(const Position pos1, Position pos2);
	
	Position mirror() const;
	Position perspective(Turn turn) const;//return turn==Turn::WHITE() ? *this : mirror()

	int index() const;
	int row() const;
	int col() const;
	int diag() const;
	int antiDiag() const;

	int taxiDistance(Position other) const;//how many moves a king would take to move from here to there

	Position shiftUp() const;
	Position shiftDown() const;
	Position shiftLeft() const;
	Position shiftRight() const;
	Position shiftForward(Turn turn) const;
	Position shiftBackward(Turn turn) const;

	// Not including the current row
	BitBoard squaresAbove() const;
	BitBoard squaresBelow() const;
	BitBoard squaresForward(Turn turn) const;
	BitBoard squaresBackward(Turn turn) const;


	BitBoard asSingletonBitboard() const;
	std::string str() const;
};

