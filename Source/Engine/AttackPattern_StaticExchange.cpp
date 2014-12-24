#include "AttackPattern.h"
#include "StaticExchange.h"
#include <algorithm>



namespace {

	// Knights and Bishops share the same type.
	int ind(const Piece piece) {
		return piece.asIndex() - (piece >= Piece::BISHOP());
	}

	uint8_t pieceBit(const Piece piece) {
		_ASSERTE(Piece::PAWN() <= piece && piece <= Piece::KING());

		// 5 highest bits are for the piece types.
		return (uint8_t)4 << ind(piece);
	}

	int limit(const Piece piece) {
		switch (piece.asEnum()) {
		case PieceEnum::PAWN:
			return 2;
		case PieceEnum::KNIGHT:
			return 3;
		case PieceEnum::BISHOP:
			return 3;
		case PieceEnum::ROOK:
			return 2;
		case PieceEnum::QUEEN:
			return 1;
		case PieceEnum::KING:
			return 1;
		default:
			_ASSERTE(false);
			return 0;
		}
	}

	int likliness(const Piece piece) {
		switch (piece.asEnum()) {
		case PieceEnum::PAWN:
			return 2;
		case PieceEnum::KNIGHT:
			return 1;
		case PieceEnum::BISHOP:
			return 1;
		case PieceEnum::ROOK:
			return 3;
		case PieceEnum::QUEEN:
			return 4;
		case PieceEnum::KING:
			return 5;
		default:
			return 99;
		}
	}

	int pieceValue(const Piece piece) {
		switch (piece.asEnum()) {
		case PieceEnum::PAWN:
			return 1;
		case PieceEnum::KNIGHT:
			return 3;
		case PieceEnum::BISHOP:
			return 3;
		case PieceEnum::ROOK:
			return 5;
		case PieceEnum::QUEEN:
			return 9;
		case PieceEnum::KING:
			return 50;
		default:
			_ASSERTE(false);
			return 0;
		}
	}

	int8_t SEE_full[7][256][256] = { 0 };

	int8_t SEE_min[256][256] = { 0 };
	Piece smallest[256];
	bool inited = false;

	
}

#pragma region AttackPattern
AttackPattern::AttackPattern() : value(0) {}
AttackPattern::AttackPattern(uint8_t value) : value(value) {}
AttackPattern::AttackPattern(const std::string str) : AttackPattern() {
	const int n = str[0] - '0';
	int actuallyAdded = 0;

	Piece piece = Piece::INVALID();
	for (char c : str.substr(2)) {
		piece = Piece::fromChar(c);
		add(Piece::fromChar(c));
		actuallyAdded++;
	}
	add(piece, n - actuallyAdded);
}

void AttackPattern::add(const Piece piece) {
	_ASSERTE(Piece::PAWN() <= piece && piece <= Piece::KING());
	value++;
	value |= pieceBit(piece);
}
void AttackPattern::add(const Piece piece, const  int n) {
	_ASSERTE(n >= 0);
	if (n == 0) {
		return;
	}
	_ASSERTE(Piece::PAWN() <= piece && piece <= Piece::KING());

	value += n;
	value |= pieceBit(piece);
}

bool AttackPattern::contains(const Piece piece) const {
	_ASSERTE(Piece::PAWN() <= piece && piece <= Piece::KING());
	return (value & pieceBit(piece))!=0;
}


bool AttackPattern::isEmpty() const {
	return value == 0;
}

bool AttackPattern::isNotEmpty() const {
	return !(this->isEmpty());
}


int AttackPattern::getCount() const {
	return value & (uint8_t)0x7; // Count is stored in the least 3 bits.
}


bool AttackPattern::operator==(const AttackPattern other) const {
	return value == other.value;
}


bool AttackPattern::operator!=(const AttackPattern other) const {
	return !(*this == other);
}

AttackPattern AttackPattern::operator|(const AttackPattern other) const {
	return AttackPattern(value | other.value);
}


std::string AttackPattern::str() const {
	std::string res;
	res += '0' + getCount();
	res += ':';

	FOR_PIECE_ALL(piece) {
		if (piece != Piece::BISHOP() && this->contains(piece)) {
			res += piece.asChar(Turn::BLACK());
		}
	}

	return res;
}

int AttackPattern::getPieceCount(const Piece piece) const {
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
		
		Piece pieceToInc = Piece::INVALID();
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

		counts[ind(pieceToInc==Piece::INVALID() ? Piece::KNIGHT() : pieceToInc)]++;
	}
	

	return counts[ind(piece)];
}

bool AttackPattern::isValid() const {
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

#pragma region StaticExchange
void StaticExchange::init() {
	if (inited) {
		return;
	}
	inited = true;

	FOR_PIECE_ALL(attacker) {
		for (int i = 0; i < 256; ++i) {
			for (int j = 0; j < 256; j++) {
				AttackPattern attackers(i);
				AttackPattern defenders(j);
				SEE_full[attacker.asIndex()][attackers.value][defenders.value] = 
					attackCostImpl(attacker, attackers, defenders);
			}
		}
	}
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 256; j++) {
			const AttackPattern attackers(i);
			const AttackPattern defenders(j);
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

		smallest[i] = AttackPattern(i).smallestAttackerImpl();
	}
}

int StaticExchange::attackCostImpl( Piece attacker, const  AttackPattern attackers, const  AttackPattern defenders) {
	if (attacker == Piece::BISHOP()) {
		attacker = Piece::KNIGHT();
	}

	if (!attackers.isValid() || !defenders.isValid() ||
		defenders.getCount() == 0) {
		return 0;
	}

	if (!attackers.contains(attacker)) {
		return 100;
	}

	if (attackers.getCount() == 1 && defenders.getCount() == 1) {

	}

	int atkPtr = 0, defPtr = 0;
	Piece attackingPieces[8] = { Piece::EMPTY() };
	Piece defendingPieces[8] = { Piece::EMPTY() };

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

int StaticExchange::attackCost(Piece attacker, AttackPattern attackers, AttackPattern defenders) {
	return SEE_full[attacker.asIndex()][attackers.value][defenders.value];
}

int StaticExchange::attackCostMin(AttackPattern attackers, AttackPattern defenders) {
	return SEE_min[attackers.value][defenders.value];
}

int StaticExchange::materialChange(Move move) {
	int result = pieceValue(move.getTarg());
	
	if (move.getType() == MoveType::ENPEASENT) {
		result += pieceValue(Piece::PAWN());
	} else if (move.isPromotion()) {
		result += pieceValue(move.promotionPiece()) - pieceValue(Piece::PAWN());
	}
	return result;
}

int StaticExchange::PieceValue(Piece piece) {
	return pieceValue(piece);
}

Piece AttackPattern::smallestAttackerImpl() const {
	FOR_PIECE_NOT_BISHOP(piece) {
		if (contains(piece)) {
			return piece;
		}
	}
	return Piece::INVALID();
}

Piece AttackPattern::getSmallestPiece() const {
	return smallest[value];
}



#pragma endregion