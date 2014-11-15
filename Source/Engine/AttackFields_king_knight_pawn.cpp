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
			Position from(r1, c1);
			FOR_TURN(turn) {
				BitBoard forwarded = from.asSingletonBitboard().shiftForward(turn);
#pragma warning(disable : 4800)
				pawnTargsArr[turn.asIndex()][from.index()] = forwarded.shiftLeft() | forwarded.shiftRight();
#pragma warning(default : 4800)
			}

			FOR_8(r2) {
				FOR_8(c2) {
					Position to(r2, c2);
					int dr = abs(r1 - r2);
					int dc = abs(c1 - c2);

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

BitBoard AttackFields::kingTargs(Position position) {
	return kingTargsArr[position.index()];
}

BitBoard AttackFields::knightTargs(Position position) {
	return knightTargsArr[position.index()];
}

BitBoard AttackFields::pawnTargs(Position position,Turn turn ) {
#pragma warning(disable : 4800)
	return pawnTargsArr[turn.asIndex()][position.index()];
#pragma warning(default : 4800)
}

BitBoard AttackFields::pawnTargs(BitBoard pawns, Turn turn) {
	BitBoard forward = pawns.shiftForward(turn);
	return forward.shiftLeft() | forward.shiftRight();
}

BitBoard AttackFields::knightTargs(BitBoard knights) {
	BitBoard beside = knights.shiftLeft() | knights.shiftRight();
	BitBoard beside2 = knights.shiftLeft().shiftLeft() | knights.shiftRight().shiftRight();

	return beside.shiftUp().shiftUp() | beside.shiftDown().shiftDown() |
		beside2.shiftUp() | beside2.shiftDown();
}

// If a pawn moves from here, it will be promoted
BitBoard AttackFields::pawnPromoZone(Turn turn) {
	return BitBoard::rowBits(turn == Turn::WHITE() ? 1 : 6);
}

// If a pawn is here, it can move forward 2 squares.
BitBoard AttackFields::pawnJumpZone(Turn turn) {
	return pawnPromoZone(!turn);
}

Position AttackFields::enpeasentTo(Turn turn, int enpeasentColumn) {
	return Position(turn == Turn::WHITE() ? 2 : 5, enpeasentColumn);
}
Position AttackFields::enpeasentCaptured(Turn turn, int enpeasentColumn) {
	return Position(turn == Turn::WHITE() ? 3 : 4, enpeasentColumn);
}