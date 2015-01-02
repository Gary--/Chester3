#include "Evaluation.h"
#include "Game.h"
#include "AttackMap.h"
#include <algorithm>
#include "Search_SearchResult.h"
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

	int kingScoreTable[64] = {
		150, 150, 140, 120, 100, 70, 40, 00,
		150, 160, 190, 210, 130, 100, 70, 40,
		140, 190, 210, 230, 160, 130, 100, 70,
		120, 210, 230, 250, 200, 170, 130, 100,
		100, 130, 170, 200, 250, 230, 210, 120,
		70, 100, 130, 160, 230, 210, 190, 140,
		40, 70, 100, 130, 210, 190, 160, 150,
		00, 40, 70, 100, 120, 140, 150, 150 };


	int mateScore(Turn turn) {
		// If they have more than just their king, this is not a basic checkmate
		if (Game::getPlayerPieces(!turn).count() > 1) {
			return 0;
		}
		if (!hasSufficientMatingPower(turn)) {
			return 0;
		}


		int score = Search_SearchResult::PSEUDO_MATE_SCORE;
		const Position ourKingPos = Game::getKingPosition(turn);
		const Position theirKingPos = Game::getKingPosition(!turn);

		// Being king to enemy king
		score += (7 - ourKingPos.absoluteDistance(theirKingPos)) * 8;

		// Bring our pieces close to our king.
		FOR_POS(pos, Game::getPlayerPieces(turn)) {
			const Piece piece = Game::getPieceAt(pos);
			score += (7 - pos.absoluteDistance(ourKingPos)) * 2;
		}
		
		{ // Drive enemy king to corners colored like our bishops
			const BitBoard MB = Game::getPieces(turn, Piece::BISHOP());
			const bool whiteBishop = (MB & BitBoard::WHITE_SQUARES()).isNotEmpty();
			const bool blackBishop = (MB & BitBoard::BLACK_SQUARES()).isNotEmpty();
			const bool noBishops = !whiteBishop && !blackBishop;

			const int blackCornerScore = 250 - kingScoreTable[theirKingPos. index()];
			const int whiteCornerScore = 250 - kingScoreTable[theirKingPos.mirror().index()];
			if (noBishops) {
				score += max(blackCornerScore, whiteCornerScore);
			} else if (blackBishop) {
				score += blackCornerScore;
			} else{
				score += whiteCornerScore;
			}
		}

		


		return score;

	}
}

int Evaluation::mating(Turn perspective) {
	return mateScore(perspective) - mateScore(!perspective);
}