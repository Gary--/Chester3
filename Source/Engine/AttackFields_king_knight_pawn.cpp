#include "AttackFields.h"
#include <cmath>
#include <algorithm>

namespace {
	BitBoard kingTargsArr[64];
	BitBoard knightTargsArr[64];
	BitBoard pawnTargsArr[2][64];
}

void AttackFields::initKingKnightPawn() {

	
	FOR_8(r1) {
		FOR_8(c1) {
			const Position from(r1, c1);
			FOR_TURN(turn) {
				const BitBoard forwarded = from.asSingletonBitboard().shiftForward(turn);
#pragma warning(disable : 4800)
				pawnTargsArr[turn.asIndex()][from.index()] = forwarded.shiftLeft() | forwarded.shiftRight();
#pragma warning(default : 4800)
			}

			FOR_8(r2) {
				FOR_8(c2) {
					const Position to(r2, c2);
					const int dr = abs(r1 - r2);
					const int dc = abs(c1 - c2);

					if (from == to || std::max(dr,dc)>2) {
						continue;
					}

					if (std::max(dr, dc) == 1) {
						kingTargsArr[from.index()] |= to.asSingletonBitboard();
					}

					if (dr + dc == 3) {
						knightTargsArr[from.index()] |= to.asSingletonBitboard();
					}

				}
			}
		}
	}

}

BitBoard AttackFields::kingTargs(const Position position) {
	return kingTargsArr[position.index()];
}

BitBoard AttackFields::knightTargs(const Position position) {
	return knightTargsArr[position.index()];
}

BitBoard AttackFields::pawnTargs(const Position position, const Turn turn) {
#pragma warning(disable : 4800)
	return pawnTargsArr[turn.asIndex()][position.index()];
#pragma warning(default : 4800)
}

BitBoard AttackFields::pawnTargs(const BitBoard pawns, const Turn turn) {
	BitBoard forward = pawns.shiftForward(turn);
	return forward.shiftLeft() | forward.shiftRight();
}

BitBoard AttackFields::knightTargs(const BitBoard knights) {
	BitBoard beside = knights.shiftLeft() | knights.shiftRight();
	BitBoard beside2 = knights.shiftLeft().shiftLeft() | knights.shiftRight().shiftRight();

	return beside.shiftUp().shiftUp() | beside.shiftDown().shiftDown() |
		beside2.shiftUp() | beside2.shiftDown();
}

// If a pawn moves from here, it will be promoted
BitBoard AttackFields::pawnPromoZone(const Turn turn) {
	return BitBoard::rowBits(turn.isWhite() ? 1 : 6);
}

// If a pawn is here, it can move forward 2 squares.
BitBoard AttackFields::pawnJumpZone(const Turn turn) {
	return pawnPromoZone(!turn);
}

BitBoard AttackFields::backRow(const Turn turn) {
	return turn.isWhite() ? BitBoard::rowBits(7) : BitBoard::rowBits(0);
}

Position AttackFields::enpeasentTo(const Turn turn, const  int enpeasentColumn) {
	return Position(turn.isWhite() ? 2 : 5, enpeasentColumn);
}
Position AttackFields::enpeasentCaptured(const Turn turn, const  int enpeasentColumn) {
	return Position(turn.isWhite() ? 3 : 4, enpeasentColumn);
}