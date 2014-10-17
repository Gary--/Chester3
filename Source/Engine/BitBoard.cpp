#include "BitBoard.h"
#include <stdlib.h>
#include "chess_macros.h"
#include "ChessAssert.h"

BitBoard::BitBoard(){}
BitBoard::BitBoard(uint64_t value) : value(value){}

BitBoard::~BitBoard(){}

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


const BitBoard BitBoard::EMPTY = BitBoard(0);
const BitBoard BitBoard::FULL = BitBoard(~0ULL);


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
	return (position.ToSingletonBoard() & (*this)) != BitBoard::EMPTY;
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