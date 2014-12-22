#include "BitBoard_Position_Iterator.h"


BitBoard_Position_Iterator::BitBoard_Position_Iterator(const BitBoard bb, const BitBoard left) : bb(bb), left(left) {}

Position BitBoard_Position_Iterator::operator*() const {
	return bb.ToPosition();
}

void BitBoard_Position_Iterator::operator++() {
	left ^= bb;
	bb = left.LSB();
}

bool BitBoard_Position_Iterator::operator!=(const BitBoard_Position_Iterator& other) const {
	return left != other.left;
}

