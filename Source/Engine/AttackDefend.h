#pragma once
#include <cstdint>
#include "chess_consts.h"


//+------+------+------+------+------+------+------+------+
//| BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7 |
//+------+------+------+------+------+------+------+------+
//|      Number of     | PAWN |KNIGHT| ROOK | QUEEN| KING |
//|      ATTACKERS     |      |BISHOP|      |      |      |
//+------+------+------+------+------+------+------+------+

// === Resolving Ambiguity
// Piece   Limit    Likliness
//   P       2         2
//  N/B      3         1
//   R       2         3
//   Q       1         4
//   K       1         5

// 1. Set the count of every piece that appears to 1.

// 2. Increment count of the piece that comes first when sorted by
//    the following but is not at or past its limit.
//        (curCount, likliness)
//    If everything was at limit, increase count of valid piece
//    with lowest likliness.
//
// 3. If not everything accounted for, goto 2.

class AtkPat {
public:
	AtkPat();
	AtkPat add(Piece piece) const;
	bool contains(Piece piece) const;
	bool isEmpty() const;
	int getCount() const;

	// How much would you lose by moving a piece there?
	int enemyAttackCost(Piece piece);
	int friendlyAttackCost(Piece piece);
private:
	uint8_t value;
};

