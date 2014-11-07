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
	void add(Piece piece);
	bool contains(Piece piece) const;
	bool isEmpty() const;
	int getCount() const;

	// How much would you lose by moving a piece there?
	int enemyAttackCost(Piece piece) const;
	int friendlyAttackCost(Piece piece) const;

	bool operator==(const AtkPat other) const;
	bool operator!=(const AtkPat other) const;
	std::string str() const;// Example: "3:NQ"
private:
	uint8_t value;
};

