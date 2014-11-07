#include "AttackDefend.h"
#include <algorithm>



namespace {

	// Knights and Bishops share the same type.
	int ind(Piece piece) {
		return (uint8_t)piece - (piece >= Piece::BISHOP);
	}

	uint8_t pieceBit(Piece piece) {
		_ASSERTE(Piece::PAWN <= piece && piece <= Piece::KING);

		// 5 highest bits are for the piece types.
		return (uint8_t)4 << ind(piece);
	}

	int limit(Piece piece) {
		switch (piece) {
		case Piece::PAWN:
			return 2;
		case Piece::KNIGHT:
			return 3;
		case Piece::BISHOP:
			return 3;
		case Piece::ROOK:
			return 2;
		case Piece::QUEEN:
			return 1;
		case Piece::KING:
			return 1;
		default:
			_ASSERTE(false);
			return 0;
		}
	}

	int likliness(Piece piece) {
		switch (piece) {
		case Piece::PAWN:
			return 2;
		case Piece::KNIGHT:
			return 1;
		case Piece::BISHOP:
			return 1;
		case Piece::ROOK:
			return 3;
		case Piece::QUEEN:
			return 4;
		case Piece::KING:
			return 5;
		default:
			return 99;
		}
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

int AtkPat::getPieceCount(Piece piece) const {
	int counts[6] = { 0 };
	int tot = 0;

	FOR_PIECE_NOT_BISHOP(p) {
		if (contains(p)) {
			counts[ind(p)] = 1;
			tot++;
		}
	}
	_ASSERTE(tot <= getCount());

	while (tot < getCount()) {
		bool updated = false;
		

		int minCount = 0;
		FOR_PIECE_NOT_BISHOP(p) {
			minCount = std::max(minCount, counts[ind(p)]);
		}
		
		Piece pieceToInc = Piece::UNKNOWN;
		int bestLike = 9999;
		FOR_PIECE_NOT_BISHOP(p) {
			if (counts[ind(p)] >= limit(p) || counts[ind(p)]!=minCount) {
				continue;
			}
			if (likliness(p) < bestLike) {
				bestLike = likliness(p);
				pieceToInc = p;
			}
		}

		counts[ind(pieceToInc==Piece::UNKNOWN ? Piece::KNIGHT : pieceToInc)]++;
		
		tot++;
	}
	

	return counts[ind(piece)];
}