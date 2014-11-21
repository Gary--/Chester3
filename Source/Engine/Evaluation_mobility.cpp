#include "Evaluation.h"
#include "Game.h"
#include "AttackFields.h"
#include <algorithm>

using namespace std;

namespace {
	const int mobilityValue[137] = {
		0, 0, 1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 10, 11, 13, 14, 17, 19, 21, 24, 27, 30, 33,
		36, 39, 42, 46, 49, 53, 56, 59, 62, 65, 68, 71, 75, 78, 81, 84, 87, 90, 93, 96,
		100, 103, 106, 109, 112, 115, 118, 121, 125, 128, 131, 134, 137, 140, 143, 146,
		150, 153, 156, 159, 162, 165, 168, 171, 175, 178, 181, 184, 187, 190, 193, 196,
		200, 203, 206, 209, 212, 215, 218, 221, 225, 228, 231, 234, 237, 240, 243, 246,
		250, 253, 256, 259, 262, 265, 268, 271, 275, 278, 281, 284, 287, 290, 293, 296,
		300, 303, 306, 309, 312, 315, 318, 321, 325, 328, 331, 334, 337, 340, 343, 346,
		350, 353, 356, 359, 362, 365, 368, 371, 375, 378, 381, 384, 384, 390 };



	struct MobilityScore {
		int relative;
		int exact;
		MobilityScore() {
			relative = 0;
			exact = 0;
		}

		MobilityScore operator+(const MobilityScore& other) {
			MobilityScore res;
			res.exact = this->exact + other.exact;
			res.relative = this->relative + other.relative;
			return res;
		}
	};



	MobilityScore knightMobilityScore(Turn turn) {
		const int knightOutpostValue[64] = {
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0,10,15,20,20,15,10, 0,
			0, 8,12,15,15,12, 8, 0,
			0, 5, 8,10,10, 8, 5, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
		};
		const int knightMinMobilePenalty[9] = { 26, 10, 5, 0, 0, 0, 0, 0, 0 };
		const BitBoard twoPointKnightSqrs = BitBoard(0x007E424242427E00ULL);
		const BitBoard fourPointKnightSqrs = BitBoard(0x00003C3C3C3C0000ULL);

		const Turn other = !turn;

		const BitBoard M = Game::getPlayerPieces(turn);
		const BitBoard T = Game::getPlayerPieces(other);
		const BitBoard TP = Game::getPieces(other, Piece::PAWN());
		const BitBoard theirPawnControl = AttackFields::pawnTargs(TP, other);

		MobilityScore res;

		FOR_BIT(knight, Game::getPieces(turn, Piece::KNIGHT())) {
			Position pos = knight.ToPosition();
			BitBoard targs = AttackFields::knightTargs(pos); // Squares the knight controls...
			targs &= ~(M | theirPawnControl); // ... which aren't controlled by enemy pawn and are not occupied by us
			res.relative += 2 * (targs & twoPointKnightSqrs).count();
			res.relative += 4 * (targs & fourPointKnightSqrs).count();

			res.exact -= knightMinMobilePenalty[targs.count()];

			if (TP.count() >= 5) {

				// Can't be driven away by enemy pawns.
				if (((knight | knight.shiftForward(turn))&theirPawnControl).isEmpty()) {
					res.exact += knightOutpostValue[pos.perspective(turn).index()];
				}
			}
		}
		return res;
	}

	MobilityScore bishopMobilityScore(Turn turn) {
		const int bishopMinMobilePenalty[] = { 24, 24, 16, 12, 9, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		
		const Turn other = !turn;

		const BitBoard M = Game::getPlayerPieces(turn);
		const BitBoard MP = Game::getPieces(turn, Piece::PAWN());
		const BitBoard T = Game::getPlayerPieces(other);
		const BitBoard TP = Game::getPieces(other, Piece::PAWN());
		const BitBoard theirPawnControl = AttackFields::pawnTargs(TP, other);

		MobilityScore res;

		FOR_BIT(bishop, Game::getPieces(turn, Piece::BISHOP())) {
			const Position pos = bishop.ToPosition();

			// We are only stopped by their pieces and our pawns.
			BitBoard targs = AttackFields::bishopTargs(pos, T | MP);
			const BitBoard blockingPawns = targs & pos.squaresForward(turn) & MP;
			targs &= ~M ; // ... which are not occupied by us
			res.relative += targs.count();

			targs &= ~theirPawnControl;
			res.exact -= bishopMinMobilePenalty[targs.count()];

			// bad bishop
			FOR_BIT(pawn, blockingPawns) {
				//                                            .  P  N  B  R  Q  K  p  n  b  r  q  k
				const uint8_t badBishopBlockerPenalty[13] = { 1, 4, 1, 1, 1, 1, 1, 4, 2, 2, 1, 1, 1 };//penalty based on piece in front of blocking pawn
				const uint8_t badBishopPositionPenalty[64] = {
					0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 0, 0, 0, 0, 0,
					0, 0, 0, 1, 1, 0, 0, 0,
					0, 0, 1, 2, 2, 1, 0, 0,
					0, 1, 2, 2, 2, 2, 1, 0,
					0, 2, 2, 2, 2, 2, 2, 0,
					0, 0, 0, 0, 0, 0, 0, 0,
				};

				const Position frontPos = pawn.ToPosition().shiftForward(turn);
				const Piece frontPiece = Game::getPieceAt(frontPos);
				int frontPieceIndex = frontPiece.asIndex();
				if (frontPiece != Piece::EMPTY() && Game::getOwnerAt(frontPos) != turn) {
					frontPieceIndex += 6;
				}
				_ASSERTE(frontPieceIndex < 13);
				res.exact -= badBishopBlockerPenalty[frontPieceIndex] << badBishopPositionPenalty[pos.perspective(turn).index()];
			}
		}
		return res;
	}

	MobilityScore rookMobilityScore(Turn turn) {
		const int rookConnectedValue[64] = {
			15, 15, 15, 15, 15, 15, 15, 15,
			25, 25, 25, 25, 25, 25, 25, 25,
			4, 4, 6, 10, 10, 6, 4, 4,
			0, 0, 2, 3, 3, 2, 0, 0,
			0, 0, 2, 3, 3, 2, 0, 0,
			0, 0, 2, 3, 3, 2, 0, 0,
			0, 0, 2, 3, 3, 2, 0, 0,
			0, 0, 2, 3, 3, 2, 0, 0, };

		const Turn other = !turn;

		const BitBoard M = Game::getPlayerPieces(turn);
		const BitBoard MP = Game::getPieces(turn, Piece::PAWN());
		const BitBoard T = Game::getPlayerPieces(other);
		const BitBoard TP = Game::getPieces(other, Piece::PAWN());

		MobilityScore res;


		const BitBoard MR = Game::getPieces(turn, Piece::ROOK());
		FOR_BIT(rook, MR) {
			const Position pos = rook.ToPosition();
			const int row = pos.row();
			const int col = pos.col();
			const BitBoard colBits = BitBoard::colBits(col);
			const BitBoard rowBits = BitBoard::rowBits(row);

			BitBoard targsXRay = AttackFields::rookTargs(pos, T | MP);
			BitBoard targsNorm = AttackFields::rookTargs(pos, Game::getAllPieces());
			const bool openFile = (targsNorm & colBits & MP).isEmpty();
			const bool fullOpenFile = (targsNorm & colBits & (MP | TP)).isEmpty();
			const bool connectedRook = (targsNorm & MR).isNotEmpty();
			const bool horizontalConnectedRook = (targsNorm & MR & rowBits).isNotEmpty();

			targsXRay &= ~M;
			targsNorm &= ~M;
			res.relative += (targsNorm & rowBits).count(); // 1 point for horizontal

			// vertical mobility
			targsXRay &= colBits;
			targsNorm &= colBits;
			res.relative += 2 * targsNorm.count();
			res.relative += 1 * (targsXRay &~targsNorm).count();// 1 point for vertical XRAY

			// Scale value of open files based on number of my pawns
			if (fullOpenFile) {
				res.relative += MP.count() + 1;

				if (horizontalConnectedRook) {
					const int file_value[] = { -6, -5, -2, 0, 0, -2, -5, -6 };
					const int pawn_tab[] = { 0, 0, 0, 0, 0, 4, 8, 16, 16, 0, 0 };
					int bonus = file_value[col] + pawn_tab[TP.count()];
					res.exact += max(0, bonus);
				}
			} else if (openFile) {
				res.relative += MP.count() / 2 + 1;
			}

			// Rook connectedness
			if (connectedRook) {
				res.exact += rookConnectedValue[pos.perspective(turn).index()];
			}
		}
		return res;
	}


	MobilityScore turnMobilityScore(Turn turn) {
		return knightMobilityScore(turn) + bishopMobilityScore(turn) + rookMobilityScore(turn);
	}
}

int Evaluation::mobility() {
	MobilityScore white = turnMobilityScore(Turn::WHITE());
	MobilityScore black = turnMobilityScore(Turn::BLACK());

	int res = white.exact - black.exact;
	int diff = abs(white.relative - black.relative);
	diff = min(diff, 136);

	res += white.relative > black.relative ? mobilityValue[diff] : -mobilityValue[diff];

	return res;
}

int Evaluation::DEBUG_knightExactMobility(Turn turn) {
	return knightMobilityScore(turn).exact;
}

int Evaluation::DEBUG_knightRelativeMobility(Turn turn) {
	return  knightMobilityScore(turn).relative;
}
int Evaluation::DEBUG_bishopExactMobility(Turn turn) {
	return bishopMobilityScore(turn).exact;
}
int Evaluation::DEBUG_bishopRelativeMobility(Turn turn) {
	return bishopMobilityScore(turn).relative;
}
int Evaluation::DEBUG_rookExactMobility(Turn turn) {
	return rookMobilityScore(turn).exact;
}
int Evaluation::DEBUG_rookRelativeMobility(Turn turn) {
	return rookMobilityScore(turn).relative;
}