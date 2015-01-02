#include "Evaluation.h"
#include "Game.h"
#include "AttackMap.h"
#include <algorithm>
using namespace std;

namespace {

	// If we've at least 7 in total mating power, we can mate.
	int matingPower(const Piece piece) {
		switch (piece.asEnum()) {
		case PieceEnum::PAWN:
			return 0;
		case PieceEnum::KNIGHT:
			return 3;
		case PieceEnum::BISHOP:
			return 4;
		case PieceEnum::ROOK:
			return 7;
		case PieceEnum::QUEEN:
			return 7;
		default:
			return 0;
		}
	}

	bool hasSufficientMatingPower(const Turn turn) {
		const Turn other = !turn;
		int power = 0;
		FOR_POS(pos, Game::getPlayerPieces(turn)) {

			// Filter out enprise pieces
			if (AttackMap::getAttackPattern(other, pos).isNotEmpty() &&
				(AttackMap::getAttackPattern(turn, pos).isEmpty())) {
				continue;
			}

			power += matingPower(Game::getPieceAt(pos));
		}
		return power >= 7;
	}

	int mateScore(Turn turn) {
		// If they have more than just their king, this is not a basic checkmate
		if (Game::getPlayerPieces(!turn).count() > 1) {
			return 0;
		}
		if (!hasSufficientMatingPower(turn)) {
			return 0;
		}


		int score = 5000;
		const Position ourKingPos = Game::getKingPosition(turn);
		const Position theirKingPos = Game::getKingPosition(!turn);

		// Encourage engine to bring all pieces closer to enemy king
		FOR_POS(pos, Game::getPlayerPieces(turn)) {
			score += (14 - pos.taxiDistance(theirKingPos)) * 5;
		}

		const BitBoard MB = Game::getPieces(turn, Piece::BISHOP());
		const bool whiteBishop = (MB & BitBoard::WHITE_SQUARES()).isNotEmpty();
		const bool blackBishop = (MB & BitBoard::BLACK_SQUARES()).isNotEmpty();
		const bool noBishops = !whiteBishop && !blackBishop;
		
		const int corneringFactor = 15;
		int minCornerDist = 10;
		if (noBishops || whiteBishop) {
			minCornerDist = min(minCornerDist, Position("a8").taxiDistance(theirKingPos));
			minCornerDist = min(minCornerDist, Position("h1").taxiDistance(theirKingPos));
		}
		if (noBishops || blackBishop) {
			minCornerDist = min(minCornerDist, Position("a1").taxiDistance(theirKingPos));
			minCornerDist = min(minCornerDist, Position("h8").taxiDistance(theirKingPos));
		}

		score += corneringFactor*(14-minCornerDist);

		return score;

	}
}

int Evaluation::mating(Turn perspective) {
	return mateScore(perspective) - mateScore(!perspective);
}