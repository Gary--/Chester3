#pragma once
#include <cstdint>
#include "chess_consts.h"
#include <string>


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

#define FOR_PIECE_NOT_BISHOP(x) for (Piece x = Piece::PAWN; x <= Piece::KING; x = (Piece)((uint8_t)x + (x == Piece::KNIGHT ? 2 : 1)))

class AtkPat {
public:
	AtkPat();
	void add(Piece piece);
	bool contains(Piece piece) const;
	bool isEmpty() const;
	int getCount() const;

	bool operator==(const AtkPat other) const;
	bool operator!=(const AtkPat other) const;
	std::string str() const;// Example: "3:NQ"

	// ONLY CALLED BY INIT
	int getPieceCount(Piece piece) const;

private:
	bool isValid() const;
	AtkPat(uint8_t value);
	uint8_t value;
	friend class SEE;
};
