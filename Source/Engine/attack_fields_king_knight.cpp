#include "attack_fields.h"
#include "Attack_Fields_init.h"
#include "chess_macros.h"
#include <cmath>
#include <algorithm>

namespace {
	BitBoard kingTargsArr[64];
	BitBoard knightTargsArr[64];
	BitBoard pawnTargsArr[2][64];
}

void AttackFieldInit::KingKnightPawn() {

	
	FOR_8(r1) {
		FOR_8(c1) {
			Position from(r1, c1);
			FOR_TURN(turn) {
				BitBoard forwarded = from.ToSingletonBoard().shiftForward(turn);
#pragma warning(disable : 4800)
				pawnTargsArr[(bool)turn][from.index()] = forwarded.shiftLeft() | forwarded.shiftRight();
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
						kingTargsArr[from.index()] |= to.ToSingletonBoard();
					}

					if (dr + dc == 3) {
						knightTargsArr[from.index()] |= to.ToSingletonBoard();
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

BitBoard AttackFields::pawnTargs(Turn turn,Position position) {
#pragma warning(disable : 4800)
	return pawnTargsArr[(bool)turn][position.index()];
#pragma warning(default : 4800)
}
