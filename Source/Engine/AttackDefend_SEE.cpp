#include "AttackDefend.h"
#include "static_exchange.h"
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

	int pieceValue(Piece piece) {
		switch (piece) {
		case Piece::PAWN:
			return 1;
		case Piece::KNIGHT:
			return 3;
		case Piece::BISHOP:
			return 3;
		case Piece::ROOK:
			return 5;
		case Piece::QUEEN:
			return 9;
		case Piece::KING:
			return 50;
		default:
			_ASSERTE(false);
			return 0;
		}
	}

	int8_t SEE_full[7][256][256] = { 0 };

	int8_t SEE_min[256][256] = { 0 };

	bool inited = false;

	
}

#pragma region AtkPat
AtkPat::AtkPat() : value(0) {}
AtkPat::AtkPat(uint8_t value) : value(value) {}

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

	for (int i = tot; tot < getCount(); ++tot){
		bool updated = false;
		

		int minCount = 8;
		FOR_PIECE_NOT_BISHOP(p) {
			if (contains(p)) {
				minCount = std::min(minCount, counts[ind(p)]);
			}
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
	}
	

	return counts[ind(piece)];
}

bool AtkPat::isValid() const {
	int tot = 0;
	bool hasPiece = false;
	FOR_PIECE_NOT_BISHOP(p) {
		tot += contains(p);
		if (contains(p)) {
			hasPiece = true;
		}
	}
	if (tot > getCount()) {
		return false;
	}

	if (!hasPiece && getCount() > 0) {
		return false;
	}
	return true;
}

#pragma endregion

#pragma region SEE
void SEE::init() {
	if (inited) {
		return;
	}
	inited = true;

	FOR_PIECE_ALL(attacker) {
		for (int i = 0; i < 256; ++i) {
			for (int j = 0; j < 256; j++) {
				AtkPat attackers(i);
				AtkPat defenders(j);
				SEE_full[(uint8_t)attacker][attackers.value][defenders.value] = 
					attackCostImpl(attacker, attackers, defenders);
			}
		}
	}
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 256; j++) {
			AtkPat attackers(i);
			AtkPat defenders(j);
			if (!attackers.isValid() || !defenders.isValid() ||
				attackers.getCount() == 0) {
				continue;
			}
			FOR_PIECE_NOT_BISHOP(minPiece) {
				if (attackers.contains(minPiece)) {
					SEE_min[attackers.value][defenders.value] =
						attackCost(minPiece, attackers, defenders);
					break;
				}
			}
		}
	}
}

int SEE::attackCostImpl(Piece attacker, AtkPat attackers, AtkPat defenders) {
	if (attacker == Piece::BISHOP) {
		attacker = Piece::KNIGHT;
	}

	if (!attackers.isValid() || !defenders.isValid() ||
		defenders.getCount() == 0 || !attackers.contains(attacker)) {
		return 0;
	}

	if (attackers.getCount() == 1 && defenders.getCount() == 1) {

	}

	int atkPtr = 0, defPtr = 0;
	Piece attackingPieces[8] = { Piece::EMPTY };
	Piece defendingPieces[8] = { Piece::EMPTY };

	FOR_PIECE_NOT_BISHOP(p) {
		for (int i = 0; i < attackers.getPieceCount(p) - (p == attacker); i++) {
			attackingPieces[atkPtr++] = p;
		}
		for (int i = 0; i < defenders.getPieceCount(p); i++) {
			defendingPieces[defPtr++] = p;
		}
	}

	int nAtk = atkPtr, nDef = defPtr;
	int values[17] = { 0 };
	int valuePtr = 0;

	atkPtr = defPtr = 0;
	while (true) {
		if (defPtr == nDef) {
			break;
		}
		values[valuePtr++] = pieceValue(defendingPieces[defPtr++]);

		if (atkPtr == nAtk) {
			break;
		}
		values[valuePtr++] = pieceValue(attackingPieces[atkPtr++]);
	}

	// cost for the piece here to make a capture
	int costs[17] = { 0 };
	costs[valuePtr] = 100;//can't take when we have nothing there
	for (int i = valuePtr - 1; i >= 0; --i) {
		costs[i] = std::max(0, values[i] - costs[i + 1]);
	}
	return std::max(0, pieceValue(attacker) - costs[0]);
	
}

int SEE::attackCost(Piece attacker, AtkPat attackers, AtkPat defenders) {
	return SEE_full[(uint8_t)attacker][attackers.value][defenders.value];
}

int SEE::attackCostMin(AtkPat attackers, AtkPat defenders) {
	return SEE_min[attackers.value][defenders.value];
}

#pragma endregion