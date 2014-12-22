#include "BitBoard_Position_Iterator.h"


BitBoard_BitBoard_Iterator::BitBoard_BitBoard_Iterator(const BitBoard bb, const BitBoard left) : bb(bb), left(left) {}

BitBoard BitBoard_BitBoard_Iterator::operator*() const {
	return bb;
}

void BitBoard_BitBoard_Iterator::operator++() {
	left ^= bb;
	bb = left.LSB();
}

bool BitBoard_BitBoard_Iterator::operator!=(const BitBoard_BitBoard_Iterator& other) const {
	return left != other.left;
}




BitBoard_BitBoard_Iterator_Generator::BitBoard_BitBoard_Iterator_Generator(BitBoard bitBoard) : bb(bitBoard) {}
BitBoard_BitBoard_Iterator BitBoard_BitBoard_Iterator_Generator::begin() const {
	return BitBoard_BitBoard_Iterator(bb.LSB(), bb);
}
BitBoard_BitBoard_Iterator BitBoard_BitBoard_Iterator_Generator::end() const {
	return BitBoard_BitBoard_Iterator(BitBoard::EMPTY(), BitBoard::EMPTY());
}




BitBoard_Position_Iterator::BitBoard_Position_Iterator(BitBoard_BitBoard_Iterator it) : it(it) {}

Position BitBoard_Position_Iterator::operator*() const {
	return (*it).ToPosition();
}

void BitBoard_Position_Iterator::operator++() {
	++it;
}

bool BitBoard_Position_Iterator::operator!=(const BitBoard_Position_Iterator& other) const {
	return it != other.it;
}



BitBoard_Position_Iterator_Generator::BitBoard_Position_Iterator_Generator(BitBoard_BitBoard_Iterator_Generator gen) : gen(gen) {}
BitBoard_Position_Iterator BitBoard_Position_Iterator_Generator::begin() const {
	return BitBoard_Position_Iterator(gen.begin());
}
BitBoard_Position_Iterator BitBoard_Position_Iterator_Generator::end() const{
	return BitBoard_Position_Iterator(gen.end());
}