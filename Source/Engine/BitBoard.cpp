#include "BitBoard.h"
#include <stdlib.h>
#include "Chess.h"
#include "ChessAssert.h"
#include "Position.h"
#include "BitBoard_Position_Iterator.h"
BitBoard::BitBoard():value(0){}
BitBoard::BitBoard(uint64_t value) : value(value){}
BitBoard::BitBoard(int r, int c)  {
	*this = Position(r, c).asSingletonBitboard();
}
//BitBoard::~BitBoard(){}

uint64_t BitBoard::asInt64() const {
	return value;
}

bool  operator==(const BitBoard bb1, const BitBoard bb2){
	return bb1.value == bb2.value;
}

bool  operator!=(const BitBoard bb1, const BitBoard bb2){
	return !(bb1 == bb2);
}

#pragma region Bitwise Operators
BitBoard  BitBoard::operator|(const BitBoard other) const{
	return BitBoard(value | other.value);
}

BitBoard  BitBoard::operator&(const BitBoard other) const{
	return BitBoard(value & other.value);
}

BitBoard  BitBoard::operator^(const BitBoard other) const{
	return BitBoard(value ^ other.value);
}

BitBoard BitBoard::operator~() const {
	return BitBoard(~value);
}

BitBoard BitBoard::operator|=(const BitBoard other){
	value |= other.value;
	return BitBoard(value);
}

BitBoard BitBoard::operator&=(const BitBoard other){
	value &= other.value;
	return BitBoard(value);
}

BitBoard BitBoard::operator^=(const BitBoard other){
	value ^= other.value;
	return BitBoard(value);
}

bool BitBoard::isEmpty() const {
	return *this == EMPTY();
}

bool BitBoard::isNotEmpty() const {
	return *this != EMPTY();
}

BitBoard  BitBoard::LSB() const{
#pragma warning( disable : 4146)
	return BitBoard(value &-value);
#pragma warning(default : 4146)
}

#pragma endregion



BitBoard BitBoard::EMPTY() {
	return BitBoard(0);
}
BitBoard BitBoard::FULL() {
	return BitBoard(~0ULL);
}
BitBoard BitBoard::BLACK_SQUARES() {
	return  BitBoard(0x55AA55AA55AA55AAULL);
}
BitBoard BitBoard::WHITE_SQUARES() {
	return BitBoard(0xAA55AA55AA55AA55ULL);
}
BitBoard BitBoard::EDGE_SQUARES() {
	return rowBits(0) | rowBits(7) | colBits(0) | colBits(7);
}



std::string BitBoard::str() const
{
	std::string res;
	
	FOR_8(r){
		FOR_8(c){
			res += this->contains(Position(r, c)) ? '1' : '0';
		}
		res += '\n';
	}
	return res;
}

bool  BitBoard::contains(const Position position) const {
	return (position.asSingletonBitboard() & (*this)).isNotEmpty();
}


// Only use on a singleton board
Position  BitBoard::ToPosition() const
{
#pragma warning( disable : 4146)
	_ASSERTE(value != 0);
	_ASSERTE(value == (value&-value));
#pragma warning(default : 4146)

	return Position(__lzcnt64(value));
	//unsigned long index;
	//
	//_BitScanReverse64(&index, value);
	//return Position(index);
}

BitBoard BitBoard::mirror() const{
	return BitBoard(_byteswap_uint64(value));
}

BitBoard BitBoard::perspective(const Turn turn) const {
	return turn.isWhite() ? *this : mirror();
}


BitBoard BitBoard::shiftUp() const{
	return BitBoard(value >> 8);
}

BitBoard BitBoard::shiftDown() const{
	return BitBoard(value << 8);
}

BitBoard BitBoard::shiftRight() const{
	return BitBoard( (*this &~colBits(7)).value << 1 );
}

BitBoard BitBoard::shiftLeft() const{
	return BitBoard((*this &~colBits(0)).value >> 1);
}

BitBoard BitBoard::shiftForward(const Turn turn) const {
	if (turn.isWhite()) {
		return this->shiftUp();
	} else {
		return this->shiftDown();
	}
}

BitBoard BitBoard::shiftBackward(const Turn turn) const {
	return shiftForward(!turn);
}


int BitBoard::count() const
{
	return (int)__popcnt64(value);
}


BitBoard BitBoard::rowBits(const int row)
{
	ChessAssert::Assert_8(row);
	return BitBoard(0xFFULL << (8*row));
}


BitBoard BitBoard::colBits(const int col)
{
	ChessAssert::Assert_8(col);
	return BitBoard(0x0101010101010101ULL << col);
}

namespace {
	BitBoard antiDiag7() {
		return BitBoard(0x8040201008040201ULL);
	}
	BitBoard antiDiag8to14() {
		return BitBoard(0X80C0E0F0F8FCFEULL);
	}
	BitBoard antiDiag0to7() {
		return ~(antiDiag7() | antiDiag8to14());
	}

	BitBoard diag7() {
		return BitBoard(0x102040810204080);
	}
	BitBoard diag8to14() {
		return BitBoard(0xfefcf8f0e0c08000);
	}
	BitBoard diag0to7() {
		return BitBoard(~(diag7() | diag8to14()));
	}

}

BitBoard BitBoard::diagonalBits(const int i) {
	_ASSERTE(0 <= i && i < 15);
	return i==7 ? diag7() :
		( i < 7 ?
		BitBoard(diag7().value >> (7 - i)) &~(diag8to14()|diag7()) :
		BitBoard(diag7().value << (i - 7)) &~(diag0to7() | diag7()) );
}

BitBoard BitBoard::antiDiagonalBits(const int i) {
	_ASSERTE(0 <= i && i < 15);
	return i < 7 ?
		BitBoard(antiDiag7().value >> (7-i)) &~antiDiag8to14() :
		BitBoard(antiDiag7().value << (i-7)) &~antiDiag0to7();
}


BitBoard BitBoard::rowsLessThan(const int r) {
	ChessAssert::Assert_8(r);
	return BitBoard((1ULL << (8 * r)) - 1ULL);
}

BitBoard BitBoard::rowsGreaterThan(const int r) {
	ChessAssert::Assert_8(r);
#pragma warning (disable: 4146) //negating unsigned
	return BitBoard(-(2ULL << (8 * r + 7)));
#pragma warning (default: 4146)
}

BitBoard BitBoard::random(){
	const int size = BitBoard(RAND_MAX).count();
	int n = 0;
	uint64_t res = 0;
	while (n<64){
		res <<= size;
		res |= rand();
		n += size;
	}
	return BitBoard(res);
}

