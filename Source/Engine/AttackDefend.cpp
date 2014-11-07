#include "AttackDefend.h"

namespace {
	uint8_t pieceBit(Piece piece) {
		_ASSERTE(Piece::PAWN <= piece && piece <= Piece::KING);

		// 5 highest bits are for the piece types.
		// Knights and Bishops share the same type.
		return (uint8_t)4 << ((uint8_t)piece - (piece >= Piece::BISHOP));
	}
}


AtkPat::AtkPat() : value(0) {}


void AtkPat::add(Piece piece) {
	_ASSERTE(Piece::PAWN <= piece && piece <= Piece::KING);
	value++;
	value |= pieceBit(piece);
}


bool AtkPat::contains(Piece piece) const{
	_ASSERTE(Piece::PAWN <= piece && piece <= Piece::KING);
	return (value & pieceBit(piece))!=0;
}


bool AtkPat::isEmpty() const {
	return value == 0;
}


int AtkPat::getCount() const {
	return value & (uint8_t)0x7; // Count is stored in the least 3 bits.
}


bool AtkPat::operator==(const AtkPat other) const {
	return value == other.value;
}


bool AtkPat::operator!=(const AtkPat other) const {
	return !(*this == other);
}


std::string AtkPat::str() const {
	std::string res;
	res += '0' + getCount();
	res += ':';

	FOR_PIECE_ALL(piece) {
		if (piece != Piece::BISHOP && this->contains(piece)) {
			res += ChessUtils::charFromPieceTurn(Turn::WHITE, piece);
		}
	}

	return res;
}