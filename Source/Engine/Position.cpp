#include "Position.h"
#include "ChessAssert.h"
#include <crtdbg.h>
#include <sstream>
Position::Position() : value(0)
{
}


Position::~Position() 
{
}

bool const operator==(const Position pos1, Position pos2){
	return pos1.value == pos2.value;
}

bool const operator!=(const Position pos1, Position pos2){
	return !(pos1 == pos2);
}

Position::Position(int value): value(value){
	ChessAssert::Assert_64(value);
}
Position::Position(int row, int column) :value(8*row + column){
	ChessAssert::Assert_8(row);
	ChessAssert::Assert_8(column);
}

int Position::row() const
{
	return value / 8;
}


int Position::col() const
{
	return value % 8;
}


int Position::index() const
{
	return value;
}

BitBoard Position::ToSingletonBoard() const
{
	return BitBoard(((uint64_t) 1)<< value);
}

Position Position::verticalFlip() const{
	return Position(value ^ 56);
}

std::string Position::str() const
{
	std::stringstream iss;
	iss << "Position(" << value << ")";
	std::string res;
	iss >> res;
	return res;
}
