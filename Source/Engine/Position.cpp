#include "Position.h"
#include "ChessAssert.h"
#include <crtdbg.h>
#include <sstream>
using namespace std;


Position::Position() : value(0)
{
}


Position::Position(int value) : value(value) {
	ChessAssert::Assert_64(value);
}
Position::Position(int row, int column) : value(8 * row + column) {
	ChessAssert::Assert_8(row);
	ChessAssert::Assert_8(column);
}

Position::Position(const char* value) :
Position(7-(value[1] - '1'), value[0] - 'a')
{
	_ASSERTE('a' <= value[0] && value[0] <= 'h');
	_ASSERTE('1' <= value[1] && value[1] <= '8');
}

Position::Position(const std::string& value) :
Position(value.c_str()){}

Position::~Position() 
{
}

bool const operator==(const Position pos1, Position pos2){
	return pos1.value == pos2.value;
}

bool const operator!=(const Position pos1, Position pos2){
	return !(pos1 == pos2);
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
	std::string res;
	res += 'a' + col();
	res += '1' + (7 - row());

	return res;
}
