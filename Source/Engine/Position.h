#pragma once
#include <cstdint>
#include "BitBoard.h"

class BitBoard;
// Represents one of the 64 squares on the board.
class Position
{

private:
	Position();
	uint8_t value;
public:

	explicit Position(int value);
	Position(int row, int column);


	~Position();

	friend bool const operator==(const Position pos1,Position pos2);
	friend bool const operator!=(const Position pos1, Position pos2);
	
	int row();
	int col();
	BitBoard ToSingletonBoard();
	std::string str() const;
};

