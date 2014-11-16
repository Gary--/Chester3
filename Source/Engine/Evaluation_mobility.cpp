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

	const BitBoard twoPointKnightSqrs = BitBoard(0x007E424242427E00ULL);
	const BitBoard fourPointKnightSqrs = BitBoard(0x00003C3C3C3C0000ULL);
	const int knightMinMobilePenalty[9] = { 26, 10, 5 , 0, 0, 0, 0, 0, 0 };
	const int bishopMinMobilePenalty[] = { 24, 24, 16, 12, 9, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    int knightOutpostValue[64] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0,10,15,20,20,15,10, 0,
        0, 8,12,15,15,12, 8, 0,
        0, 5, 8,10,10, 8, 5, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    };

	struct MobilityScore {
		int relative;
		int exact;
		MobilityScore() {
			relative = 0;
			exact = 0;
		}
	};

	MobilityScore turnMobilityScore(Turn turn) {
		const Turn other = !turn;

		const BitBoard M = Game::getPlayerPieces(turn);
		const BitBoard TP = Game::getPieces(other, Piece::PAWN());
		const BitBoard theirPawnControl = AttackFields::pawnTargs(TP, other);

		MobilityScore res;

#pragma region Knight
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
#pragma endregion



		return res;
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

int Evaluation::exactMobility(Turn turn) {
	return turnMobilityScore(turn).exact;
}
int Evaluation::relativeMobility(Turn turn) {
	return turnMobilityScore(turn).relative;
}