#include "AttackMap.h"
#include <vector>
#include "Game.h"
#include "AttackFields.h"

using namespace std;

namespace {
	struct AttackMapSaved {
		AttackPattern patterns[64];
		bool precomputed;

		AttackMapSaved() {
			precomputed = false;
		}
	};

	vector<AttackMapSaved> maps;
}

void AttackMap::synchronize() {
	maps.clear();
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
	pat.add(Piece::QUEEN(), queens.count);
}