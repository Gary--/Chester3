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
	
	Position verticalFlip() const;

	int index() const;
	int row() const;
	int col() const;
	BitBoard ToSingletonBoard() const;
	std::string str() const;
};

