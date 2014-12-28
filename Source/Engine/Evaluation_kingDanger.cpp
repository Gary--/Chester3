#include "Evaluation.h"
#include "Game.h"
#include "AttackFields.h"
#include "AttackPattern.h"
#include "AttackMap.h"
#include <algorithm>

using namespace std;

namespace {
	int patternScore(const AttackPattern pat) {
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

	struct Danger {
		int count; // how many squares around king are threatened (appoximately this)
		AttackPattern pattern; //what pieces are attacking around our king

		Danger() {
			count = 0;
			pattern = AttackPattern();
		}
	};

	BitBoard getLightPieces(const Turn turn) {
		return Game::getPieces(turn, Piece::KNIGHT()) |
			Game::getPieces(turn, Piece::ROOK()) | Game::getPieces(turn, Piece::BISHOP());
	}

	Danger calcDanger(const Turn turn) {
		const Turn other = !turn;
		const Position kingPos = Game::getKingPosition(turn);
		const BitBoard kingSquare = AttackFields::kingTargs(kingPos) | Game::getPieces(turn, Piece::KING());

		const BitBoard patternZone = kingSquare.shiftForward(turn) &~kingSquare;
		const BitBoard blockerZone = kingSquare & BitBoard::rowBits(kingPos.row()).shiftForward(turn);
		const BitBoard backZone = kingSquare &~blockerZone;
		_ASSERTE((kingSquare | kingSquare.shiftForward(turn)) == (patternZone | blockerZone | backZone));
		_ASSERTE(kingPos.col() == 0 || kingPos.col() == 7 || kingPos.row() == 0 || kingPos.row() == 7 || backZone.count() == 6);
		_ASSERTE((patternZone&blockerZone).isEmpty());
		_ASSERTE((patternZone&backZone).isEmpty());
		_ASSERTE((blockerZone&backZone).isEmpty());

		Danger danger;
		if (getLightPieces(other).count() >= 2) {
			const char kingPositionValue[64] = {
				4, 4, 4, 4, 4, 4, 4, 4,
				4, 4, 4, 4, 4, 4, 4, 4,
				4, 4, 4, 4, 4, 4, 4, 4,
				4, 4, 4, 4, 4, 4, 4, 4,
				4, 4, 4, 4, 4, 4, 4, 4,
				4, 3, 3, 3, 3, 3, 3, 4,
				2, 1, 1, 1, 1, 1, 1, 2,
				2, 0, 0, 0, 0, 0, 0, 2,
			};
			danger.count += kingPositionValue[kingPos.perspective(turn).index()];
		}

		FOR_BIT(bit, patternZone | blockerZone | backZone) { // Each position around the king..
			const Position pos = bit.ToPosition();
			const AttackPattern threat = AttackMap::getAttackPattern(!turn, pos);
			danger.pattern = danger.pattern | threat;

			if ((bit & patternZone).isNotEmpty()) { // pattern only
				continue;
			}
			if (threat.isEmpty()) { // there's no threat here
				continue;
			}
			danger.count++;

			const AttackPattern defend = AttackMap::getAttackPattern(turn, pos);
			if (defend.getCount() <= 1) { // the square around our king is threatened, but not defended
				danger.count++;
			}
			if ((bit & blockerZone).isNotEmpty()) { // one of the 3 squares right in front of our king
				if ((Game::getPlayerPieces(turn)&bit).isEmpty()) { // we do not have a piece here
					danger.count++;
				}
			}
		}

		return danger;
	}


}

int Evaluation::kingDanger(const Turn turn) {
	const Turn other = !turn;

	// skip safety if they have no queen or they have only a queen
	if (Game::getPieces(other, Piece::QUEEN()).isEmpty() || getLightPieces(other).isEmpty()) {
		return 0;
	}
	

	Danger danger = calcDanger(turn);


	const int scaling[] = { 0, 2, 3, 6, 12, 18, 25, 37, 50, 75,100, 125, 
		150, 175, 200, 225, 250, 275, 300, 325,350, 375, 400, 
		425, 450, 475, 500, 525, 550, 575,600  };

	danger.count += patternScore(danger.pattern);
	danger.count = min(danger.count,(int)_countof(scaling)-1);
	return scaling[danger.count];
}

AttackPattern  Evaluation::DEBUG_kingDangerPattern(const Turn turn) {
	return calcDanger(turn).pattern;
}

int Evaluation::DEBUG_kingDangerCount(const Turn turn) {
	return calcDanger(turn).count;
}