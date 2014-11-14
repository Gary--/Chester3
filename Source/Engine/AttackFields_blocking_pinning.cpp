#include "AttackFieldsInit.h"









namespace {
	BitBoard pinnedMoves[64][64];
	BitBoard blockingMoves[64][64];
}

BitBoard AttackFields::pinnedTargs(Position kingPos, Position pinnedPos) {
	return pinnedMoves[kingPos.index()][pinnedPos.index()];
}

BitBoard AttackFields::blockingTargs(Position kingPos, Position attacker) {
	return blockingMoves[kingPos.index()][attacker.index()];
}

void AttackFieldInit::BlockingPinning() {
	for (int i = 0; i < 64; i++) {//king
		BitBoard king = Position(i).asSingletonBitboard();


		for (int j = 0; j < 64; j++) {//pinnedpiece
			BitBoard pinned = Position(j).asSingletonBitboard();
			BitBoard attacker = Position(j).asSingletonBitboard();

			blockingMoves[i][j] |= attacker | king;

			if ((pinned& AttackFields::queenTargs(Position(i),BitBoard::EMPTY())) == BitBoard::EMPTY()) {//no pin here
				pinnedMoves[i][j] = BitBoard::FULL();
			}

			pinnedMoves[i][j] |= pinned | king;
			for (int k = 0; k < 64; k++) {//new place to move to
				BitBoard targ = Position(k).asSingletonBitboard();

				if (((AttackFields::queenTargs(Position(j), targ) & king) == BitBoard::EMPTY())) {
					blockingMoves[i][j] |= targ;
				}
				
				// Have to stay within any LOS of king
				if ((targ& AttackFields::queenTargs(Position(i), BitBoard::EMPTY())) == BitBoard::EMPTY()) {//moving out of LOS of king completely
					continue;
				}


				if ((AttackFields::queenTargs(Position(i), targ | pinned)&(targ | pinned)).count() == 1) {
					pinnedMoves[i][j] |= targ;
				}

			}

		}



	}

}
