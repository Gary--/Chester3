#include "AttackFields.h"






namespace {
	BitBoard pinnedMoves[64][64];
	BitBoard blockingMoves[64][64];
}

BitBoard AttackFields::pinnedTargs(const Position kingPos, const  Position pinnedPos) {
	return pinnedMoves[kingPos.index()][pinnedPos.index()];
}

BitBoard AttackFields::blockingTargs(const Position kingPos, const  Position attacker) {
	return blockingMoves[kingPos.index()][attacker.index()];
}

void AttackFields::initBlockingPinning() {
	for (int i = 0; i < 64; i++) {//king
		const BitBoard king = Position(i).asSingletonBitboard();


		for (int j = 0; j < 64; j++) {//pinnedpiece
			const BitBoard pinned = Position(j).asSingletonBitboard();
			const BitBoard attacker = Position(j).asSingletonBitboard();

			if ((pinned& AttackFields::queenTargs(Position(i),BitBoard::EMPTY())).isEmpty()) {//no pin here
				pinnedMoves[i][j] = BitBoard::FULL();
			}

			pinnedMoves[i][j] |= pinned | king;
			for (int k = 0; k < 64; k++) {//new place to move to
				const BitBoard targ = Position(k).asSingletonBitboard();

				if (((AttackFields::queenTargs(Position(j), targ) & king).isEmpty())) {
					blockingMoves[i][j] |= targ;
				}
				
				// Have to stay within any LOS of king
				if ((targ& AttackFields::queenTargs(Position(i), BitBoard::EMPTY())).isEmpty()) {//moving out of LOS of king completely
					continue;
				}


				if ((AttackFields::queenTargs(Position(i), targ | pinned)&(targ | pinned)).count() == 1) {
					pinnedMoves[i][j] |= targ;
				}
			}
		}
	}
}
