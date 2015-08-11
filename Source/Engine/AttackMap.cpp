#include "AttackMap.h"
#include <vector>
#include "Game.h"
#include "AttackFields.h"
#include "StaticExchange.h"
#include "AttackPattern.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace {

	// bit n of i is on <==> bit 8*n of rows[i] is on.
	AttackPattern patterns[2][64];
	uint64_t savedHash=0;

	uint64_t rows[256] = { 0 };
	bool inited = false;


	void addPat(const Turn turn, const Piece piece, const BitBoard cover) {
		FOR_8(r) {
			uint64_t coverRowBits = (cover.asInt64() >> (8 * r)) & 0xFFULL;

			if (coverRowBits) {
				const uint64_t rowMask = rows[coverRowBits];

				uint64_t* rowPtr = reinterpret_cast <uint64_t*>(&patterns[turn.asIndex()][8 * r]);
				*rowPtr |= rowMask << AttackPattern::pieceBitLocation(piece);
				*rowPtr += rowMask;
			}
		}
	}

	void resetPats() {
		memset(patterns, 0, sizeof(patterns));
	}


	static void init() {
		if (inited) {
			return;
		}
		inited = true;

		for (uint8_t x = 0;; x++) {
			for (int col = 0; col < 8; ++col) {
				if (x & (1 << col)) {
					rows[x] |= ((uint64_t)1 << (col * 8));
				}
			}

			if (x == 255) {
				break;
			}
		}
	}


}

void AttackMap::synchronize() {
	init();
	return;
}

void AttackMap::notifyMove(const Move move, const  Turn turn) {
	return;
}

void AttackMap::notifyUndoMove(const Move move, const  Turn turn) {
	return;
}

AttackPattern AttackMap::getAttackPattern(const Turn turn, const  Position position) {
	if (savedHash == Game::getHash()) {
		return patterns[turn.asIndex()][position.index()];;
	}


	return getAttackPatternImpl(turn, position);
}

AttackPattern AttackMap::getAttackPatternImpl(const Turn turn, const  Position position) {
	AttackPattern pat;

	{
		const BitBoard pawns = Game::getPieces(turn, Piece::PAWN()) & AttackFields::pawnTargs(position, !turn);
		pat.add(Piece::PAWN(), pawns.count());
	}

	{
		const BitBoard knights = Game::getPieces(turn, Piece::KNIGHT()) & AttackFields::knightTargs(position);
		pat.add(Piece::KNIGHT(), knights.count());
	}

	{
		bool king = (Game::getPieces(turn, Piece::KING()) & AttackFields::kingTargs(position)) != BitBoard::EMPTY();
		pat.add(Piece::KING(), king);
	}

	{
		const BitBoard potentialRooks = AttackFields::rookTargs(position, Game::getAllPieces());
		const BitBoard potentialBishops = AttackFields::bishopTargs(position, Game::getAllPieces());

		const BitBoard rooks = Game::getPieces(turn, Piece::ROOK()) & potentialRooks;
		pat.add(Piece::ROOK(), rooks.count());

		const BitBoard bishops = Game::getPieces(turn, Piece::BISHOP()) & potentialBishops;
		pat.add(Piece::BISHOP(), bishops.count());

		const BitBoard queens = Game::getPieces(turn, Piece::QUEEN()) & (potentialBishops | potentialRooks);
		pat.add(Piece::QUEEN(), queens.count());
	}

	return pat;
}

void AttackMap::precompute() {
	if (savedHash == Game::getHash() || savedHash == ~Game::getHash()) {
		return;
	}
	savedHash = Game::getHash();


	resetPats();
	FOR_TURN(turn) {
		//FOR_POS(kingPos, AttackFields::kingTargs(Game::getKingPosition(turn))) {
		//	pats.patterns[turn.asIndex()][kingPos.index()].add(Piece::KING());
		//}
		addPat(turn, Piece::KING(), AttackFields::kingTargs(Game::getKingPosition(turn)));

		FOR_POS(knightPos, Game::getPieces(turn, Piece::KNIGHT())) {
			addPat(turn, Piece::KNIGHT(), AttackFields::knightTargs(knightPos));
			//FOR_POS(targ, AttackFields::knightTargs(knightPos)) {
			//	pats.patterns[turn.asIndex()][targ.index()].add(Piece::KNIGHT());
			//}
		}

		const BitBoard blockers = Game::getAllPieces();

		FOR_POS(bishopPos, Game::getPieces(turn, Piece::BISHOP())) {
			addPat(turn, Piece::BISHOP(), AttackFields::bishopTargs(bishopPos, blockers));
			//FOR_POS(targ, AttackFields::bishopTargs(bishopPos, blockers)) {
			//	pats.patterns[turn.asIndex()][targ.index()].add(Piece::BISHOP());
			//}
		}

		FOR_POS(rookPos, Game::getPieces(turn, Piece::ROOK())) {
			addPat(turn, Piece::ROOK(), AttackFields::rookTargs(rookPos, blockers));
			//FOR_POS(targ, AttackFields::rookTargs(rookPos, blockers)) {
			//	pats.patterns[turn.asIndex()][targ.index()].add(Piece::ROOK());
			//}
		}

		FOR_POS(queenPos, Game::getPieces(turn, Piece::QUEEN())) {
			addPat(turn, Piece::QUEEN(), AttackFields::queenTargs(queenPos, blockers));
			//FOR_POS(targ, AttackFields::queenTargs(queenPos, blockers)) {
			//	pats.patterns[turn.asIndex()][targ.index()].add(Piece::QUEEN());
			//}
		}

		// 1 sqr in front of our pawns
		const BitBoard MP_forward = Game::getPieces(turn, Piece::PAWN()).shiftForward(turn);

		addPat(turn, Piece::PAWN(), MP_forward.shiftLeft());
		addPat(turn, Piece::PAWN(), MP_forward.shiftRight());


		//const BitBoard both = left&right;

		//FOR_POS(targ, (left | right) &~both) {
		//	pats.patterns[turn.asIndex()][targ.index()].add(Piece::PAWN());
		//}

		//FOR_POS(targ, both) {
		//	pats.patterns[turn.asIndex()][targ.index()].add(Piece::PAWN(), 2);
		//}
	}
}

int AttackMap::SEE(Move move) {
	const AttackPattern attackers = getAttackPattern(Game::getTurn(), move.getTo());
	const AttackPattern defenders = getAttackPattern(!Game::getTurn(), move.getTo());

	return StaticExchange::materialChange(move) - StaticExchange::attackCost(move.getPiece(), attackers, defenders);
}
