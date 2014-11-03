#include "Game.h"
#include "attack_fields.h"

using namespace AttackFields;


int Game::numMovesAvailableImpl() {
	//const Turn curTurn = Turn::WHITE;
	const bool check = getCheck();
	const BitBoard M = getPlayerPieces(curTurn);
	const BitBoard MK = getPieces(curTurn, Piece::KING);
	const BitBoard MP = getPieces(curTurn, Piece::PAWN);
	const BitBoard MR = getPieces(curTurn, Piece::ROOK);
	const BitBoard MB = getPieces(curTurn, Piece::BISHOP);
	const BitBoard MN = getPieces(curTurn, Piece::KNIGHT);
	const BitBoard MQ = getPieces(curTurn, Piece::QUEEN);

	const Position kingPos = MK.ToPosition();
	const BitBoard T = getPlayerPieces(!curTurn);
	const BitBoard TR = getPieces(!curTurn, Piece::ROOK) | getPieces(!curTurn, Piece::QUEEN);
	const BitBoard TB = getPieces(!curTurn, Piece::BISHOP) | getPieces(!curTurn, Piece::QUEEN);
	const BitBoard TN = getPieces(!curTurn, Piece::KNIGHT);
	const BitBoard TP = getPieces(!curTurn, Piece::PAWN);
	const Position theirKingPos = getPieces(!curTurn, Piece::KING).ToPosition();

	const BitBoard kingRing = AttackFields::kingTargs(kingPos);

	BitBoard posTargs = ~M;
	BitBoard posPieces = M;



#pragma region Dangers: Squares attacked by opponent
	const BitBoard jumpDanger = attackedByJump(!curTurn);
	BitBoard rightLosDanger, diagLosDanger;
	FOR_BIT(bit, TR) {
		rightLosDanger |= rookTargs(bit.ToPosition(), (ALL&~MK));
	}
	FOR_BIT(bit, TB) {
		diagLosDanger |= bishopTargs(bit.ToPosition(), (ALL&~MK));
	}

	const BitBoard danger = jumpDanger | rightLosDanger | diagLosDanger;
#pragma endregion

#pragma region Threats: Opponents pieces which attack our king


	BitBoard jumpThreats, rightLosThreats, diagLosThreats;
	if (check) {
		jumpThreats = (TP & pawnTargs(kingPos, curTurn)) | (TN & knightTargs(kingPos));
		rightLosThreats = TR & rookTargs(kingPos, ALL);
		diagLosThreats = TB & bishopTargs(kingPos, ALL);

		_ASSERTE((rightLosThreats & diagLosThreats) == BitBoard::EMPTY());
		_ASSERTE(((rightLosThreats | diagLosThreats)&jumpThreats) == BitBoard::EMPTY());
	}
	const BitBoard threats = jumpThreats | rightLosThreats | diagLosThreats;
	_ASSERTE(threats.count() <= 2);

	int result = 0;
#pragma endregion
	// KING
	result += (kingRing &~(danger | M)).count();


	// We are in double check. We can only move our king.
	if (threats.count() > 1) {
		return result;
	}



#pragma region Pinning
	BitBoard rightPinned;
	FOR_BIT(bit, M &rightLosDanger & rookTargs(kingPos, ALL)) {
		if (rightLosThreats != ((rookTargs(kingPos, ALL^bit) & TR))) {
			rightPinned |= bit;
		}
	}

	BitBoard diagPinned;
	FOR_BIT(bit, M & diagLosDanger & bishopTargs(kingPos, ALL)) {
		if (diagLosThreats != ((bishopTargs(kingPos, ALL^bit) & TB))) {
			diagPinned |= bit;
		}
	}
	const BitBoard allPinned = rightPinned | diagPinned;
	_ASSERTE((rightPinned & diagPinned) == BitBoard::EMPTY());
	_ASSERTE(allPinned == (allPinned & M));//is a subset of my pieces

	// In your face LOS same as jump. Do this after pinning!
	jumpThreats |= (rightLosThreats&kingRing) | (diagLosThreats&kingRing);
	rightLosThreats &= ~kingRing;
	diagLosThreats &= ~kingRing;
#pragma endregion




	// Try to capture the threat.
	if (threats != BitBoard::EMPTY()) {
		posPieces ^= allPinned;

		const Position threatPos = threats.ToPosition();
		const Piece threatPiece = getPieceAt(threatPos);

		// Capture the threat with a pawn
		BitBoard capturingPawns = pawnTargs(threatPos, !curTurn) & MP & posPieces;
		result += (capturingPawns&~pawnPromoZone(curTurn)).count();
		result += 4*(capturingPawns&pawnPromoZone(curTurn)).count();

		if (threatPiece == Piece::PAWN && getEnpeasentColumn() != GameConfiguration::NO_ENPEASENT_COLUMN) {
			Position to = enpeasentTo(curTurn, getEnpeasentColumn());
			result += (pawnTargs(to, !curTurn) & MP & posPieces).count();
		}

		result += (knightTargs(threatPos) & MN & posPieces).count();


		const BitBoard posHeroBishopLocations = bishopTargs(threatPos, ALL) & posPieces;
		const BitBoard posHeroRookLocations = rookTargs(threatPos, ALL) & posPieces;


		result += (posHeroRookLocations & MR).count();
		result += (posHeroBishopLocations & MB).count();
		result += ((posHeroRookLocations | posHeroBishopLocations)&MQ).count();

		// The only way to respond to a jump threat was to capture.
		if (jumpThreats != BitBoard::EMPTY()) {
			return result;
		} else { // If it was an LOS threat, we can block also.
			posTargs = blockingTargs(kingPos, threatPos) &~ALL;

		}
	}




	// Knights cannot move while pinned
	FOR_BIT(knight, MN & posPieces &~allPinned) {
		Position from = knight.ToPosition();
		result += (knightTargs(from) & posTargs).count();
	}

	FOR_BIT(rook, MR & posPieces &~allPinned) {
		Position from = rook.ToPosition();
		result += (rookTargs(from, ALL) & posTargs).count();
	}

	FOR_BIT(rook, MR & posPieces & rightPinned) {
		Position from = rook.ToPosition();
		result += (rookTargs(from, ALL) & posTargs & pinnedTargs(kingPos, from)).count();
	}

	FOR_BIT(bishop, MB & posPieces & ~allPinned) {
		Position from = bishop.ToPosition();
		result += (bishopTargs(from, ALL) & posTargs).count();
	}

	FOR_BIT(bishop, MB & posPieces & diagPinned) {
		Position from = bishop.ToPosition();
		result += (bishopTargs(from, ALL) & posTargs & pinnedTargs(kingPos, from)).count();
	}

	FOR_BIT(queen, MQ & posPieces & ~allPinned) {
		Position from = queen.ToPosition();
		result += (queenTargs(from, ALL) & posTargs).count();
	}

	FOR_BIT(queen, MQ & posPieces & allPinned) {
		Position from = queen.ToPosition();
		result += (queenTargs(from, ALL) & posTargs & pinnedTargs(kingPos, from)).count();
	}


	BitBoard pawnsThatCanMoveForward = (~allPinned | (rightPinned & BitBoard::colBits(kingPos.col()))) &
		MP & posPieces;
	BitBoard inEmptyFrontOfPawns = pawnsThatCanMoveForward.shiftForward(curTurn) & ~ALL;

	result += ((inEmptyFrontOfPawns & posTargs)&~pawnPromoZone(curTurn)).count();
	result += 4 * ((inEmptyFrontOfPawns & posTargs)&pawnPromoZone(curTurn)).count();


	inEmptyFrontOfPawns &= pawnJumpZone(curTurn).shiftForward(curTurn);
	result += (inEmptyFrontOfPawns.shiftForward(curTurn) & ~ALL & posTargs).count();



	if (!check) {
		// TODO: dun need pos targs here
		BitBoard kingX = bishopTargs(kingPos, BitBoard::EMPTY());
		BitBoard pawnsThatCanCapture = ~allPinned | diagPinned;

		{
			BitBoard leftCapturingPawns = (MP & posPieces & pawnsThatCanCapture).shiftForward(curTurn).shiftLeft()  & T &
				(kingX | ~diagPinned.shiftForward(curTurn).shiftLeft());
			result += (leftCapturingPawns&~pawnPromoZone(curTurn)).count();
			result += 4 * (leftCapturingPawns&pawnPromoZone(curTurn)).count();
		}
		
		{
			BitBoard rightCapturingPawns = (MP & posPieces & pawnsThatCanCapture).shiftForward(curTurn).shiftRight()  & T  &
				(kingX | ~diagPinned.shiftForward(curTurn).shiftRight());
			result += (rightCapturingPawns&~pawnPromoZone(curTurn)).count();
			result += 4 * (rightCapturingPawns&pawnPromoZone(curTurn)).count();
		}
		

		if (getEnpeasentColumn() != GameConfiguration::NO_ENPEASENT_COLUMN) {
			Position to = enpeasentTo(curTurn, getEnpeasentColumn());
			BitBoard capturedBit = enpeasentCaptured(curTurn, getEnpeasentColumn()).ToSingletonBoard();
			FOR_BIT(pawn, pawnTargs(to, !curTurn) & MP & posPieces & ~rightPinned) {
				Position from = pawn.ToPosition();
				BitBoard newBlockers = ALL ^ to.ToSingletonBoard() ^ pawn ^ capturedBit;
				if ((rookTargs(kingPos, newBlockers) & TR) == BitBoard::EMPTY() &&
					(bishopTargs(kingPos, newBlockers) & TB) == BitBoard::EMPTY()) {
					result++;
				}
			}
		}

		FOR_SIDE(side) {
			if (getCanCastle(curTurn, side) &&
				(ALL & castleEmptySquares(curTurn, side)) == BitBoard::EMPTY() &&
				(danger & castleSafeSquares(curTurn, side)) == BitBoard::EMPTY()) {
				result++;
			}
		}
	}

	return result;
}

