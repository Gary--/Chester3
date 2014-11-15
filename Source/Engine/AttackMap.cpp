#include "AttackMap.h"
#include <vector>
#include "Game.h"
#include "AttackFields.h"

using namespace std;

namespace {
	struct AttackMapSaved {
		AttackPattern patterns[2][64];
		bool precomputed;

		AttackMapSaved() {
			precomputed = false;
		}

		void clearPatterns() {
			memset(patterns, 0, 128 * sizeof(AttackPattern));
		}
	};

	vector<AttackMapSaved> maps;
}

void AttackMap::synchronize() {
	maps.clear();
	maps.push_back(AttackMapSaved());
}

void AttackMap::notifyMove(Move move, Turn turn) {
	maps.push_back(AttackMapSaved());
}

void AttackMap::notifyUndoMove(Move move, Turn turn) {
	maps.pop_back();
}

AttackPattern AttackMap::getAttackPattern(Turn turn, Position position) {
	return getAttackPatternImpl(turn, position);
}

AttackPattern AttackMap::getAttackPatternImpl(Turn turn, Position position) {
	AttackPattern pat;
	
	BitBoard pawns = Game::getPieces(turn, Piece::PAWN()) & AttackFields::pawnTargs(position, !turn);
	pat.add(Piece::PAWN(), pawns.count());

	BitBoard knights = Game::getPieces(turn, Piece::KNIGHT()) & AttackFields::knightTargs(position);
	pat.add(Piece::KNIGHT(), knights.count());

	bool king = (Game::getPieces(turn, Piece::KING()) & AttackFields::kingTargs(position))!=BitBoard::EMPTY();
	pat.add(Piece::KING(), king);

	BitBoard potentialRooks = AttackFields::rookTargs(position, Game::getAllPieces());
	BitBoard potentialBishops = AttackFields::bishopTargs(position, Game::getAllPieces());

	BitBoard rooks = Game::getPieces(turn, Piece::ROOK()) & potentialRooks;
	pat.add(Piece::ROOK(), rooks.count());

	BitBoard bishops = Game::getPieces(turn, Piece::BISHOP()) & potentialBishops;
	pat.add(Piece::BISHOP(), bishops.count());

	BitBoard queens = Game::getPieces(turn, Piece::QUEEN()) & (potentialBishops | potentialRooks);
	pat.add(Piece::QUEEN(), queens.count());

	return pat;
}

void AttackMap::precompute() {
	if (maps.back().precomputed) {
		return;
	}
	maps.back().precomputed = true;

	auto& pats = maps.back();
	//maps.back().clearPatterns();
	
	FOR_TURN(turn) {
		FOR_BIT(king, AttackFields::kingTargs(Game::getPieces(turn, Piece::KING()).ToPosition())) {
			pats.patterns[turn.asIndex()][king.ToPosition().index()].add(Piece::KING());
		}

		FOR_BIT(knight, Game::getPieces(turn, Piece::KNIGHT())) {
			FOR_BIT(targ, AttackFields::knightTargs(knight.ToPosition())) {
				pats.patterns[turn.asIndex()][targ.ToPosition().index()].add(Piece::KNIGHT());
			}
		}

		const BitBoard blockers = Game::getAllPieces();

		FOR_BIT(bishop, Game::getPieces(turn, Piece::BISHOP())) {
			FOR_BIT(targ, AttackFields::bishopTargs(bishop.ToPosition(), blockers)) {
				pats.patterns[turn.asIndex()][targ.ToPosition().index()].add(Piece::BISHOP());
			}
		}

		FOR_BIT(rook, Game::getPieces(turn, Piece::ROOK())) {
			FOR_BIT(targ, AttackFields::rookTargs(rook.ToPosition(), blockers)) {
				pats.patterns[turn.asIndex()][targ.ToPosition().index()].add(Piece::ROOK());
			}
		}

		FOR_BIT(queen, Game::getPieces(turn, Piece::QUEEN())) {
			FOR_BIT(targ, AttackFields::queenTargs(queen.ToPosition(), blockers)) {
				pats.patterns[turn.asIndex()][targ.ToPosition().index()].add(Piece::QUEEN());
			}
		}

		const BitBoard MP_forward = Game::getPieces(turn, Piece::PAWN()).shiftForward(turn);
		const BitBoard left = MP_forward.shiftLeft();
		const BitBoard right = MP_forward.shiftLeft();
		const BitBoard both = left&right;

		FOR_BIT(targ, (left | right) &~both) {
			pats.patterns[turn.asIndex()][targ.ToPosition().index()].add(Piece::PAWN());
		}

		FOR_BIT(targ, both) {
			pats.patterns[turn.asIndex()][targ.ToPosition().index()].add(Piece::PAWN(),2);
		}
	}
}