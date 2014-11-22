#include "Evaluation.h"
#include "Game.h"
#include "AttackFields.h"
#include "AttackMap.h"
#include <algorithm>

using namespace std;
#pragma warning (disable : 4244) //loss of precison
namespace {
	const char formation_1[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		16, 16, 16, 16, 16, 16, 16, 16,
		13, 14, 16, 16, 16, 16, 14, 13,
		8, 10, 13, 13, 13, 13, 10, 8,
		5, 7, 10, 10, 10, 10, 7, 5,
		2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	const char formation_2[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		10, 13, 16, 16, 16, 16, 13, 10,
		7, 10, 13, 13, 13, 13, 10, 7,
		5, 7, 8, 8, 8, 8, 7, 5,
		3, 5, 7, 7, 7, 7, 5, 3,
		2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	const char weakpawn_1[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		5, 5, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 3,
		3, 5, 5, 3, 3, 5, 5, 3,
		2, 5, 5, 3, 3, 5, 5, 2,
		0, 3, 5, 7, 7, 5, 3, 0,
		0, 2, 3, 7, 7, 3, 2, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	const char weakpawn_2[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		3, 5, 5, 5, 5, 5, 5, 3,
		3, 7, 13, 16, 16, 13, 7, 3,
		3, 5, 10, 10, 10, 10, 5, 3,
		3, 5, 10, 10, 10, 10, 5, 3,
		3, 5, 10, 13, 13, 10, 5, 3,
		3, 3, 7, 13, 13, 7, 3, 3,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	// for pressure calculation
	const char importance[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 2, 2, 0, 0, 0,
		0, 0, 0, 2, 2, 0, 0, 0,
		0, 1, 2, 2, 2, 2, 1, 0,
		0, 1, 2, 2, 2, 2, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};
}
int Evaluation::pawnStructureScore(Turn turn) {
	int res = 0;
	const Turn other = !turn;
	const BitBoard MP = Game::getPieces(turn, Piece::PAWN());
	const BitBoard TP = Game::getPieces(other, Piece::PAWN());
	const BitBoard myPawnCoverage = AttackFields::pawnTargs(MP, turn);
	const BitBoard theirPawnCoverage = AttackFields::pawnTargs(TP, other);


	int goodPawnCount = 0; // how many pawns we have, counting stacked isolated as 1
	// Stacked pawns
	FOR_8(col) {
		const BitBoard colBits = BitBoard::colBits(col);
		const int nPawns = (colBits&MP).count();//number 

		if (nPawns == 0) {//no pawns on this file
			continue;
		}

		if (nPawns == 1) {//no stackage here
			goodPawnCount++;
			continue;
		}

		res -= nPawns*(nPawns-1)* 20;

		// No friendly pawns on adjacent files
		if ((MP&(colBits.shiftLeft() | colBits.shiftRight())).isEmpty()) {
			res -= nPawns*(nPawns - 1) * 20;
			goodPawnCount += 1; //count this stack as just 1 pawn
		} else {
			goodPawnCount += nPawns; //count as the actual nmber
		}

		if ((colBits&TP).isEmpty()) { // On half open file
			res -= nPawns*(nPawns - 1) * 10;
		}
	}

	// Pawns become much more valuable as the game goes on
	res += (int)(lateness() * max(0, goodPawnCount - 1) * 100);

	BitBoard weakPawns = MP; // not defended or easily defendable

	const BitBoard sideBySide = (weakPawns.shiftForward(turn)&myPawnCoverage).shiftBackward(turn);
	weakPawns ^= sideBySide;
	FOR_BIT(pawn, sideBySide) {
		res += formation_1[pawn.ToPosition().perspective(turn).index()];
	}
	_ASSERTE(sideBySide == ((MP.shiftLeft()&MP) | (MP.shiftRight()&MP)));

	const BitBoard directlyProtected = weakPawns&myPawnCoverage;
	weakPawns ^= directlyProtected;

	const BitBoard aBitAhead = (weakPawns.shiftBackward(turn)&myPawnCoverage).shiftForward(turn);
	weakPawns ^= aBitAhead;
	FOR_BIT(pawn, aBitAhead | directlyProtected) {
		res += formation_2[pawn.ToPosition().perspective(turn).index()];
	}

	FOR_BIT(pawn, weakPawns) {
		const Position pos = pawn.ToPosition().perspective(turn);
		res -= weakpawn_1[pos.index()];
		if ((BitBoard::colBits(pos.col()) & TP).isEmpty()) { // half open file
			res -= weakpawn_2[pos.index()];
		}
	}



	_ASSERTE(MP == (weakPawns ^ sideBySide ^ directlyProtected ^ aBitAhead));

	// Pressure on unprotected pawns. Exclude pawns that attack their pawn
	FOR_BIT(pawn, MP &~(myPawnCoverage | theirPawnCoverage)) {
		const Position pos = pawn.ToPosition();
		const AttackPattern defenders = AttackMap::getAttackPattern(turn, pos);
		const AttackPattern attackers = AttackMap::getAttackPattern(other, pos);

		if (attackers.isEmpty() ||
			defenders.getSmallestPiece() < attackers.getSmallestPiece()) {
			continue;
		}
		int penalty = importance[pos.perspective(turn).index()];
		penalty <<= attackers.getCount();


		penalty += Evaluation::lateness() * penalty;
		penalty *= 0.4; // scale for binary


		res -= penalty;
	}

	return res;
}

Evaluation::PassedPawnResult::PassedPawnResult() {
	passedPawns = BitBoard::EMPTY();
	score = 0;
}

namespace {
	const char passedPawnValue[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
	   20,20,20,20,20,20,20,20,
	   16,16,16,16,16,16,16,16,
	   11,11,11,11,11,11,11,11,
		5, 5, 5, 5, 5, 5, 5, 5,
		3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	const char passedPawnLateValue[64] = {//more value to outside passed pawns
        0, 0, 0, 0, 0, 0, 0, 0,
       50,45,40,40,40,40,45,50,
       39,32,31,31,31,31,32,39,
       28,24,22,22,22,22,24,28,
       17,14,11,11,11,11,14,17,
       17, 8, 6, 6, 6, 6, 8,17,
       10, 8, 6, 6, 6, 6, 8,10,
        0, 0, 0, 0, 0, 0, 0, 0,
	};

	const char kingSupportValue[64] {
		0, 0, 0, 0, 0, 0, 0, 0,
	   32,32,32,32,32,32,32,32,
	   26,26,26,26,26,26,26,26,
	   20,20,20,20,20,20,20,20,
	   13,13,13,13,13,13,13,13,
	   10,10,10,10,10,10,10,10,
		6, 6, 6, 6, 6, 6, 6, 6,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	const char enemyKingDistValue[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		8, 8, 8, 8, 8, 8, 8, 8,
		6, 6, 6, 6, 6, 6, 6, 6,
		4, 4, 4, 4, 4, 4, 4, 4,
		2, 2, 2, 2, 2, 2, 2, 2,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	//int taxiDist(Position a, Position b) {

	//	return max(abs(a.col() - b.col()), abs(a.row() - b.row());
	//}
}

Evaluation::PassedPawnResult Evaluation::passedPawnEvaluation(Turn turn) {
	PassedPawnResult res;
	const Turn other = !turn;
	const BitBoard MP = Game::getPieces(turn, Piece::PAWN());
	const BitBoard TP = Game::getPieces(other, Piece::PAWN());
	const BitBoard myPawnCoverage = AttackFields::pawnTargs(MP, turn);
	const Position theirKingPos = Game::getPieces(other, Piece::KING()).ToPosition();

	// Identify passed pawns.
	FOR_BIT(pawn, MP) {
		const Position pos = pawn.ToPosition();
		if ((Evaluation::opposingPawns(pos, turn)&TP).isEmpty()) {
			res.passedPawns |= pawn;
		}
	}
	
	const BitBoard MR = Game::getPieces(turn, Piece::ROOK());
	const BitBoard MK = Game::getPieces(turn, Piece::KING());
	FOR_BIT(pawn, res.passedPawns) {
		const Position pos = pawn.ToPosition();
		const BitBoard colBits = BitBoard::colBits(pos.col());

		// Our rook is in the way of this passed pawn. HUGE penalty.
		// No bonuses are given at all.
		if ((colBits & pos.squaresForward(turn) & MR).isNotEmpty()) {
			res.score -= 70;

			// If the pawn is threatened, more penalty
			if (AttackMap::getAttackPattern(other, pos).isNotEmpty()) {
				res.score -= 70;
			}
			continue;//no other bonuses are given
		}
		
		// Our king is supporting the pawn. Bonus depending on how far along pawn is.
		if ((AttackFields::kingTargs(pos)&MK).isNotEmpty()) {
			res.score += (int)(lateness() * kingSupportValue[pos.perspective(turn).index()]);
		}

		// Enemy king distance
		const int distanceToTheirKing = theirKingPos.taxiDistance(pos);
		res.score += (int)(lateness()* distanceToTheirKing *enemyKingDistValue[pos.perspective(turn).index()]);
		


		const int baseScore = (int)((1.0 - lateness())* passedPawnValue[pos.perspective(turn).index()] +
			                  lateness() * passedPawnLateValue[pos.perspective(turn).index()]);


		res.score += baseScore;

		// connected with friendly pawn side by side or directly
		if ((pawn&myPawnCoverage).isNotEmpty() || (pawn.shiftForward(turn)&myPawnCoverage).isNotEmpty()) {
			res.score += baseScore;
		}

		
		const Position pos_1 = pos.shiftForward(turn); // 1 square forward
		// Check how far can this pawn get
		if (Game::getPieceAt(pos_1) == Piece::EMPTY()) {// in front is empty

			// === 1 square ahead check
			const AttackPattern next_1_defenders = AttackMap::getAttackPattern(turn, pos_1);
			const AttackPattern next_1_attackers = AttackMap::getAttackPattern(other, pos_1);

			// Next square is attacked, but not defended
			if (!next_1_attackers.isEmpty() && next_1_defenders.isEmpty()) {
				continue;
			}
			res.score += baseScore;

			// reached end of board
			if (pos_1.row() == 0 || pos_1.row() == 7) {
				res.score += 2 * baseScore;
				continue;
			}

			// === 2 squares ahead check
			const Position pos_2 = pos_1.shiftForward(turn);
			if (Game::getPieceAt(pos_2) != Piece::EMPTY()) {
				continue;
			}

			const AttackPattern next_2_defenders = AttackMap::getAttackPattern(turn, pos_2);
			const AttackPattern next_2_attackers = AttackMap::getAttackPattern(other, pos_2);
			// Next square is attacked, but not defended
			if (next_2_attackers.isNotEmpty() && next_2_defenders.isEmpty()) {
				continue;
			}
			res.score += baseScore;

			// reached end of board
			if (pos_2.row() == 0 || pos_2.row() == 7) {
				res.score += baseScore;
				continue;
			}

			const Position pos_3 = pos_2.shiftForward(turn);
			if (Game::getPieceAt(pos_3) != Piece::EMPTY()) {
				continue;
			}

			const AttackPattern next_3_defenders = AttackMap::getAttackPattern(turn, pos_3);
			const AttackPattern next_3_attackers = AttackMap::getAttackPattern(other, pos_3);
			if (next_3_attackers.isNotEmpty() && next_3_defenders.isEmpty()) {
				continue;
			}

			res.score += baseScore;

		} else { // Square in front is occupied
			if (Game::getOwnerAt(pos_1) == turn) {// We occupy the square in front
				res.score += baseScore;
			} else {
				const Piece enemyBlocker = Game::getPieceAt(pos_1);
				// Opponent is blocking our pawn with Rook or Queen. They are immobilized.
				if (enemyBlocker == Piece::ROOK() || enemyBlocker == Piece::QUEEN()) {
					// give 150 points if furthest pushed, otherwise, 100, otherwise 50.
					int factor = 3-min(3,pos.perspective(turn).row()-1);
					res.score += factor * 50;
				}
			}

			if (AttackMap::getAttackPattern(turn, pos).getCount() >= 2) { //square in front is covered by 2 of our pieces
				res.score += baseScore;
			}

			// square in front is defended
			const AttackPattern next_1_defenders = AttackMap::getAttackPattern(turn, pos_1);
			if (next_1_defenders.isNotEmpty()) {
				res.score += baseScore;
			}

		}
	}

	return res;
}

int Evaluation::pawns(Turn turn) {
	return pawnStructureScore(turn) + passedPawnEvaluation(turn).score;
}

int Evaluation::DEBUG_pawnFormation(Turn turn) {
	return pawnStructureScore(turn);
}

BitBoard Evaluation::DEBUG_passedPawns(Turn turn) {
	return passedPawnEvaluation(turn).passedPawns;
}

int Evaluation::DEBUG_passedPawnScore(Turn turn) {
	return passedPawnEvaluation(turn).score;
}

#pragma warning (default: 4244)