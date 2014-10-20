#pragma once
#include <cstdint>
#include "BitBoard.h"
#include <string>

#define FOR_POSITION_64(p) for(Position p=Position(0);p.index()<64;p=Position(p.index()+1))

class BitBoard;
// Represents one of the 64 squares on the board.
class Position
{

private:
	
	uint8_t value;
public:
	Position();
	explicit Position(int value);
	explicit Position(const char* value);
	explicit Position(const std::string& value);
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

