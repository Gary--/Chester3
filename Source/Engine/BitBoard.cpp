#include "BitBoard.h"


BitBoard::BitBoard(){}
BitBoard::BitBoard(uint64_t value) : value(value){}

BitBoard::~BitBoard(){}

#pragma region Bitwise Operators
BitBoard const BitBoard::operator|(const BitBoard other){
	return BitBoard(value | other.value);
}

bool const operator==(const BitBoard bb1, const BitBoard bb2){
	return bb1.value == bb2.value;
}

#pragma endregion



const std::string BitBoard::str()
{
	return "NOTHING YET";
}
