#pragma once
#include <cstdint>
#include "BitBoard.h"
#include <string>
#include "chess_consts.h"
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

	int index() const;
	int row() const;
	int col() const;
	int diag() const;
	int antiDiag() const;

	Position shiftUp() const;
	Position shiftDown() const;
	Position shiftLeft() const;
	Position shiftRight() const;
	Position shiftForward(Turn turn) const;
	Position shiftBackward(Turn turn) const;

	BitBoard asSingletonBitboard() const;
	std::string str() const;
};

