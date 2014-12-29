#pragma once
#include <cstdint>
#include "Chess.h"
#include <string>

// Things are unspecified if more than 7 pieces are added.
//+------+------+------+------+------+------+------+------+
//| BIT7 | BIT6 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0 |
//+------+------+------+------+------+------+------+------+
//| KING | QUEEN| ROOK |KNIGHT| PAWN |      Number of     |
//|      |      |      |BISHOP|      |      ATTACKERS     |
//+------+------+------+------+------+------+------+------+


// Piece | Limit  | Likliness | Value
//   P       2         2          1
//  N/B      3         1          3
//   R       2         3          5
//   Q       1         4          9
//   K       1         5         50

// === Resolving Ambiguity
// 1. Set the count of every piece that appears to 1.
// 2. Increment count of the piece that comes first when sorted by
//    the following but is not at or past its limit.
//        (curCount, likliness)
//    If everything was at limit, increase count of N.
//
// 3. If not everything accounted for, goto 2.

#define FOR_PIECE_NOT_BISHOP(x) for (Piece x = Piece::PAWN(); x <= Piece::KING(); x = Piece(x.asIndex()  + (x == Piece::KNIGHT() ? 2 : 1)))

__declspec(align(1)) class AttackPattern {
public:
	AttackPattern();
	// Example: "3:NQ"
	explicit AttackPattern(std::string str);

	// Add the given piece to the pattern.
	void add(Piece piece);

	// Add n of piece to the pattern.
	void add(Piece piece, int n);

	// Does the pattern contain at least 1 of piece?
	bool contains(Piece piece) const;

	// Does the pattern contain no pieces?
	bool isEmpty() const;

	// Does the pattern contain at least 1 piece?
	bool isNotEmpty() const;

	// How many pieces (not necessarily distinct) does the pattern contain?
	int getCount() const;

	// Least valued piece. Piece::INVALID() if isEmpty();
	Piece getSmallestPiece() const;

	bool operator==(const AttackPattern other) const;
	bool operator!=(const AttackPattern other) const;

	// (a|b).contains(p) == (a.contains(p) || b.contains(p))
	AttackPattern operator|(const AttackPattern other) const;

	// Example: "3:NQ"
	std::string str() const;

	// ONLY CALLED BY INIT and DEBUG
	int getPieceCount(Piece piece) const;

	// 1 << pieceBitLocation(piece) is the bitmask for the piece
	static int pieceBitLocation(Piece piece);



private:
	bool isValid() const;
	AttackPattern(uint8_t value);
	Piece smallestAttackerImpl() const;
	uint8_t value;
	friend class StaticExchange;
};

