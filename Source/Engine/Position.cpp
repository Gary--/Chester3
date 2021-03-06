#include "Position.h"
#include "ChessAssert.h"
#include <sstream>
#include <algorithm>
using namespace std;


Position::Position() : Position(64)
{
}


Position::Position(const int value) : value(value) {
	_ASSERTE(0 <= value && value <= 64);//allow one more for invalid position
}
Position::Position(const int row, const  int column) : value(8 * row + column) {
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


void Position::AssertValid() const{
	_ASSERTE(0 <= value && value < 64);
}

int Position::row() const
{
	AssertValid();
	return value / 8;
}


int Position::col() const
{
	AssertValid();
	return value % 8;
}

int Position::antiDiag() const {
	return (7 - row()) + col();
}

int Position::diag() const {
	return col() + row();
}

int Position::absoluteDistance(const Position other) const {
	return max(abs(col() - other.col()), abs(row() - other.row()));
}

int Position::index() const
{
	return value;
}

Position Position::shiftUp() const {
	return Position(row() - 1, col());
}
Position Position::shiftDown() const {
	return Position(row() + 1, col());
}
Position Position::shiftLeft() const {
	return Position(row(), col()-1);
}
Position Position::shiftRight() const {
	return Position(row(), col() + 1);
}
Position Position::shiftForward(const Turn turn) const {
	return turn.isWhite() ? shiftUp() : shiftDown();
}
Position Position::shiftBackward(const Turn turn) const {
	return shiftForward(!turn);
}

BitBoard Position::squaresAbove() const{
	return BitBoard::rowsLessThan(row());
}

BitBoard Position::squaresBelow() const {
	return BitBoard::rowsGreaterThan(row());
}

BitBoard Position::squaresForward(const Turn turn) const {
	return turn.isWhite() ? squaresAbove() : squaresBelow();
}

BitBoard Position::squaresBackward(const Turn turn) const {
	return squaresForward(!turn);
}

BitBoard Position::asSingletonBitboard() const
{
	AssertValid();
	return BitBoard(((uint64_t) 1)<< value);
}

Position Position::mirror() const{
	AssertValid();
	return Position(value ^ 56);
}

Position Position::perspective(const Turn turn) const {
	return turn.isWhite() ? *this : mirror();
}

std::string Position::str() const
{
	std::string res;
	res += 'a' + col();
	res += '1' + (7 - row());

	return res;
}
