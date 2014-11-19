#include "Evaluation.h"
#include "Game.h"
#include "AttackFields.h"
#include "AttackPattern.h"
#include "AttackMap.h"

namespace {
	int patternScore(AttackPattern pat) {
		const uint8_t patternValueTable[32] = {
       //      . P N N R R R R Q Q Q Q Q Q Q Q K K K K K K K K K K K K K K K K
       //            P   P N N   P N N R R R R   P N N R R R R Q Q Q Q Q Q Q Q
       //                    P       P   N N N       P   P N N   P N N R R R R
               0,0,0,0,0,0,1,1,0,1,2,2,2,3,3,3,0,0,0,0,1,1,2,2,2,3,3,3,3,3,3,3 };
		uint8_t res = 0;
		if (pat.contains(Piece::PAWN())) {
			res |= 1;
		}
		if (pat.contains(Piece::KNIGHT())) {
			res |= 2;
		}
		if (pat.contains(Piece::ROOK())) {
			res |= 4;
		}
		if (pat.contains(Piece::QUEEN())) {
			res |= 8;
		}
		if (pat.contains(Piece::KING())) {
			res |= 16;
		}
		return patternValueTable[res];
	}
}

int Evaluation::kingDanger(Turn turn) {
	const Position kingPos = Game::getPieces(turn, Piece::KING()).ToPosition();
	const BitBoard kingSquare = AttackFields::kingTargs(kingPos) | Game::getPieces(turn, Piece::KING());
	
	const BitBoard patternZone = kingSquare.shiftForward(turn) &~kingSquare;
	const BitBoard blockerZone = kingSquare & BitBoard::rowBits(kingPos.row()).shiftForward(turn);
	const BitBoard backZone = kingSquare &~blockerZone;
	_ASSERTE((kingSquare | kingSquare.shiftForward(turn)) == (patternZone | blockerZone | backZone));
	_ASSERTE(kingPos.col() == 0 || kingPos.col() == 0 || kingPos.row() == 0 || kingPos.row() == 7 || backZone.count() == 6);
	_ASSERTE(kingPos.row() == 0 || kingPos.row() == 7 || (blockerZone.count() == backZone.count() + 2));
	_ASSERTE((patternZone&blockerZone).isEmpty());
	_ASSERTE((patternZone&backZone).isEmpty());
	_ASSERTE((blockerZone&backZone).isEmpty());

	AttackPattern pattern;
	int count = 0;
	FOR_BIT(bit, patternZone | blockerZone | backZone) { // Each position around the king..
		const Position pos = bit.ToPosition();
		const AttackPattern threat = AttackMap::getAttackPattern(!turn, pos);
		pattern = pattern | threat;

		if ((bit & patternZone).isNotEmpty()) { // pattern only
			continue;
		}
		if (threat.isEmpty()) { // there's no threat here
			continue;
		}
		count++;

		const AttackPattern defend = AttackMap::getAttackPattern(turn, pos);
		if (defend.getCount() <= 1) { // the square around our king is threatened, but not defended
			count++;
		}
		if ((bit & blockerZone).isNotEmpty()) { // one of the 3 squares right in front of our king
			if ((Game::getPlayerPieces(turn)&bit).isEmpty()) { // we do not have a piece here
				count++;
			}
		}
	}



	return 0;
}