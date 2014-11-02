#include "BitBoard.h"
#include <stdlib.h>
#include "chess_macros.h"
#include "ChessAssert.h"
#include "Position.h"

BitBoard::BitBoard():value(0){}
BitBoard::BitBoard(uint64_t value) : value(value){}
BitBoard::BitBoard(int r, int c)  {
	*this = Position(r, c).ToSingletonBoard();
}
//BitBoard::~BitBoard(){}

uint64_t BitBoard::AsInt64() const {
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


BitBoard const BitBoard::LSB(){
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

bool  BitBoard::contains(Position position) const{
	return (position.ToSingletonBoard() & (*this)) != BitBoard::EMPTY();
}


// Only use on a singleton board
Position  BitBoard::ToPosition() const
{
#pragma warning( disable : 4146)
	_ASSERTE(value != 0);
	_ASSERTE(value == (value&-value));
#pragma warning(default : 4146)

	unsigned long index;
	_BitScanReverse64(&index, value);
	return Position(index);
}

BitBoard BitBoard::verticalFlip() const{
	return BitBoard(_byteswap_uint64(value));
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

BitBoard BitBoard::shiftForward(Turn turn) const {
	if (turn == Turn::WHITE) {
		return this->shiftUp();
	} else {
		return this->shiftDown();
	}
}

BitBoard BitBoard::shiftBackward(Turn turn) const {
	return shiftForward(!turn);
}


int BitBoard::count() const
{
	return (int)__popcnt64(value);
}


BitBoard BitBoard::rowBits(int row)
{
	ChessAssert::Assert_8(row);
	return BitBoard(0xFFULL << (8*row));
}


BitBoard BitBoard::colBits(int col)
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

BitBoard BitBoard::diagonalBits(int i) {
	_ASSERTE(0 <= i && i < 15);
	return i==7 ? diag7() :
		( i < 7 ?
		BitBoard(diag7().value >> (7 - i)) &~(diag8to14()|diag7()) :
		BitBoard(diag7().value << (i - 7)) &~(diag0to7() | diag7()) );
}

BitBoard BitBoard::antiDiagonalBits(int i) {
	_ASSERTE(0 <= i && i < 15);
	return i < 7 ?
		BitBoard(antiDiag7().value >> (7-i)) &~antiDiag8to14() :
		BitBoard(antiDiag7().value << (i-7)) &~antiDiag0to7();
}



BitBoard BitBoard::random(){
	int size = BitBoard(RAND_MAX).count(), n = 0;
	uint64_t res = 0;
	while (n<64){
		res <<= size;
		res |= rand();
		n += size;
	}
	return BitBoard(res);
}