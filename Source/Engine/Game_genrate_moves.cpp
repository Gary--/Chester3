#include "Game.h"
#include "AttackFields.h"

//If I can capture a threatening pawn via EP
//HINT: put promo logic into add move
void Game::generateMovesImpl(bool tacticalOnly) {
	//const Turn curTurn = Turn::WHITE()

#pragma region Unpack variables
	const bool check = getCheck();
	const BitBoard M = getPlayerPieces(curTurn);
	const BitBoard MK = getPieces(curTurn, Piece::KING());
	const BitBoard MP = getPieces(curTurn, Piece::PAWN());
	const BitBoard MR = getPieces(curTurn, Piece::ROOK());
	const BitBoard MB = getPieces(curTurn, Piece::BISHOP());
	const BitBoard MN = getPieces(curTurn, Piece::KNIGHT());
	const BitBoard MQ = getPieces(curTurn, Piece::QUEEN());

	const Position kingPos = MK.ToPosition();
	const BitBoard T = getPlayerPieces(!curTurn);
	const BitBoard TR = getPieces(!curTurn, Piece::ROOK()) | getPieces(!curTurn, Piece::QUEEN());
	const BitBoard TB = getPieces(!curTurn, Piece::BISHOP()) | getPieces(!curTurn, Piece::QUEEN());
	const BitBoard TN = getPieces(!curTurn, Piece::KNIGHT());
	const BitBoard TP = getPieces(!curTurn, Piece::PAWN());

	const BitBoard kingRing = AttackFields::kingTargs(kingPos);
#pragma endregion

#pragma region Declare from to restrictions
	BitBoard posTargs = ~M;
	BitBoard posPawnTargs = posTargs;
	if (check) {
		tacticalOnly = false;
	}
	if (tacticalOnly) {
		posTargs &= T;
		posPawnTargs &= T | AttackFields::pawnPromoZone(curTurn).shiftForward(curTurn);
	}
	BitBoard posPieces = M;
#pragma endregion

	
#pragma region Dangers: Squares attacked by opponent
	const BitBoard jumpDanger = attackedByJump(!curTurn);
	BitBoard rightLosDanger, diagLosDanger;

	FOR_POS(pos,TR){
		rightLosDanger |= AttackFields::rookTargs(pos, (ALL&~MK));
	}
	FOR_POS(pos, TB) {
		diagLosDanger |= AttackFields::bishopTargs(pos, (ALL&~MK));
	}
	
	const BitBoard danger = jumpDanger | rightLosDanger | diagLosDanger;
#pragma endregion

#pragma region Threats: Opponents pieces which attack our king
	
	
	BitBoard jumpThreats, rightLosThreats, diagLosThreats;
	if (check) {
		jumpThreats = (TP & AttackFields::pawnTargs(kingPos, curTurn)) | (TN & AttackFields::knightTargs(kingPos));
		rightLosThreats = TR & AttackFields::rookTargs(kingPos, ALL);
		diagLosThreats = TB & AttackFields::bishopTargs(kingPos, ALL);

		_ASSERTE((rightLosThreats & diagLosThreats).isEmpty());
		_ASSERTE(((rightLosThreats | diagLosThreats)&jumpThreats).isEmpty());
	}
	const BitBoard threats = jumpThreats | rightLosThreats | diagLosThreats;
	_ASSERTE(threats.count() <= 2);

#pragma endregion
	
#pragma region KingMoves
	FOR_POS(to, kingRing &~danger & posTargs) {
		addMove(Move(MoveType::REGULAR, kingPos, to, Piece::KING(), getPieceAt(to)));
	}
#pragma endregion

	// We are in double check. We can only move our king.
	if (threats.count() > 1) {
		return;
	}



#pragma region Pinning
	BitBoard rightPinned;
	FOR_BIT(bit, M &rightLosDanger & AttackFields::rookTargs(kingPos, ALL)) {
		if (rightLosThreats != ((AttackFields::rookTargs(kingPos, ALL^bit) & TR))) {
			rightPinned |= bit;
		}
	}

	BitBoard diagPinned;
	FOR_BIT(bit, M & diagLosDanger & AttackFields::bishopTargs(kingPos, ALL)) {
		if (diagLosThreats != ((AttackFields::bishopTargs(kingPos, ALL^bit) & TB))) {
			diagPinned |= bit;
		}
	}
	const BitBoard allPinned = rightPinned | diagPinned;
	_ASSERTE((rightPinned & diagPinned).isEmpty());
	_ASSERTE(allPinned == (allPinned & M));//is a subset of my pieces

	// In your face LOS same as jump. Do this after pinning!
	jumpThreats |= (rightLosThreats&kingRing) | (diagLosThreats&kingRing);
	rightLosThreats &= ~kingRing;
	diagLosThreats &= ~kingRing;
#pragma endregion


	
#pragma region Check Response
	// Try to capture the threat.
	if (check) {
		posPieces ^= allPinned;

		const Position threatPos = threats.ToPosition();
		const Piece threatPiece = getPieceAt(threatPos);

		// Capture the threat with a pawn
		FOR_POS(to, AttackFields::pawnTargs(threatPos, !curTurn) & MP & posPieces) {
			addPawnMove(Move(MoveType::REGULAR, to, threatPos, Piece::PAWN(), threatPiece));
		}
		if (threatPiece == Piece::PAWN() && getEnpeasentColumn() != GameConfiguration::NO_ENPEASENT_COLUMN) {
			const Position to = AttackFields::enpeasentTo(curTurn, getEnpeasentColumn());
			FOR_POS(from, AttackFields::pawnTargs(to, !curTurn) & MP & posPieces) {
				addMove(Move(MoveType::ENPEASENT, from, to, Piece::PAWN(), Piece::EMPTY()));
			}
		}
		

		FOR_POS(from, AttackFields::knightTargs(threatPos) & MN & posPieces) {
			addMove(Move(MoveType::REGULAR, from, threatPos, Piece::KNIGHT(), threatPiece));
		}

		const BitBoard posHeroBishopLocations = AttackFields::bishopTargs(threatPos, ALL) & posPieces;
		const BitBoard posHeroRookLocations = AttackFields::rookTargs(threatPos, ALL) & posPieces;

		FOR_POS(from, posHeroRookLocations & MR) {
			addMove(Move(MoveType::REGULAR, from, threatPos, Piece::ROOK(), threatPiece));
		}

		FOR_POS(from, posHeroBishopLocations & MB) {
			addMove(Move(MoveType::REGULAR, from, threatPos, Piece::BISHOP(), threatPiece));
		}

		FOR_POS(from, (posHeroRookLocations | posHeroBishopLocations)&MQ) {
			addMove(Move(MoveType::REGULAR, from, threatPos, Piece::QUEEN(), threatPiece));
		}

		// The only way to respond to a jump threat was to capture.
		if (jumpThreats.isNotEmpty()) {
			return;
		} else { // If it was an LOS threat, we can block also.
			const BitBoard blocking = AttackFields::blockingTargs(kingPos, threatPos) &~ALL;;
			posTargs &= blocking;
			posPawnTargs &= blocking;
		}
	}
#pragma endregion


#pragma region Regular Piece moves
	FOR_POS(from, MN & posPieces &~allPinned) {
		FOR_POS(to, AttackFields::knightTargs(from) & posTargs) {
			addMove(Move(MoveType::REGULAR, from, to, Piece::KNIGHT(), getPieceAt(to)));
		}
	}

	FOR_POS(from, MR & posPieces &~allPinned) {
		FOR_POS(to, AttackFields::rookTargs(from, ALL) & posTargs) {
			addMove(Move(MoveType::REGULAR, from, to, Piece::ROOK(), getPieceAt(to)));
		}
	}

	FOR_POS(from, MR & posPieces & rightPinned) {
		FOR_POS(to, AttackFields::rookTargs(from, ALL) & posTargs & AttackFields::pinnedTargs(kingPos, from)) {
			addMove(Move(MoveType::REGULAR, from, to, Piece::ROOK(), getPieceAt(to)));
		}
	}

	FOR_POS(from, MB & posPieces & ~allPinned) {
		FOR_POS(to, AttackFields::bishopTargs(from, ALL) & posTargs) {
			addMove(Move(MoveType::REGULAR, from, to, Piece::BISHOP(), getPieceAt(to)));
		}
	}

	FOR_POS(from, MB & posPieces & diagPinned) {
		FOR_POS(to, AttackFields::bishopTargs(from, ALL) & posTargs & AttackFields::pinnedTargs(kingPos, from)) {
			addMove(Move(MoveType::REGULAR, from, to, Piece::BISHOP(), getPieceAt(to)));
		}
	}

	FOR_POS(from, MQ & posPieces & ~allPinned) {
		FOR_POS(to, AttackFields::queenTargs(from, ALL) & posTargs) {
			addMove(Move(MoveType::REGULAR, from, to, Piece::QUEEN(), getPieceAt(to)));
		}
	}

	FOR_POS(from, MQ & posPieces & allPinned) {
		FOR_POS(to, AttackFields::queenTargs(from, ALL) & posTargs & AttackFields::pinnedTargs(kingPos, from)) {
			addMove(Move(MoveType::REGULAR, from, to, Piece::QUEEN(), getPieceAt(to)));
		}
	}
#pragma endregion
	
	{// Pawn Forward Move
		const BitBoard pawnsThatCanMoveForward = (~allPinned | (rightPinned & BitBoard::colBits(kingPos.col()))) &
		MP & posPieces;
		BitBoard inEmptyFrontOfPawns = pawnsThatCanMoveForward.shiftForward(curTurn) & ~ALL;

		FOR_POS(to, inEmptyFrontOfPawns & posPawnTargs) {
			const Position from = to.shiftBackward(curTurn);
			addPawnMove(Move(MoveType::REGULAR, from, to, Piece::PAWN(), Piece::EMPTY()));
		}

		inEmptyFrontOfPawns &= AttackFields::pawnJumpZone(curTurn).shiftForward(curTurn);
		FOR_POS(to, inEmptyFrontOfPawns.shiftForward(curTurn) & ~ALL & posTargs) {
			Position from = to.shiftBackward(curTurn).shiftBackward(curTurn);
			addPawnMove(Move(MoveType::PAWN_JUMP, from, to, Piece::PAWN(), Piece::EMPTY()));
		}
	}

	if (!check) {
		
#pragma region Pawn Captures
		const BitBoard kingX = AttackFields::bishopTargs(kingPos, BitBoard::EMPTY());
		const BitBoard pawnsThatCanCapture = ~allPinned | diagPinned;
		FOR_POS(to, (MP & pawnsThatCanCapture).shiftForward(curTurn).shiftLeft()  & T &
				(kingX | ~diagPinned.shiftForward(curTurn).shiftLeft())) {
			const Position from = to.shiftBackward(curTurn).shiftRight();
			addPawnMove(Move(MoveType::REGULAR, from, to, Piece::PAWN(), getPieceAt(to)));
		}
		FOR_POS(to, (MP & pawnsThatCanCapture).shiftForward(curTurn).shiftRight()  & T  &
				(kingX | ~diagPinned.shiftForward(curTurn).shiftRight())) {
			const Position from = to.shiftBackward(curTurn).shiftLeft();
			addPawnMove(Move(MoveType::REGULAR, from, to, Piece::PAWN(), getPieceAt(to)));
		}
#pragma endregion

#pragma region Enpeasent
		if (getEnpeasentColumn() != GameConfiguration::NO_ENPEASENT_COLUMN) {
			const Position to = AttackFields::enpeasentTo(curTurn, getEnpeasentColumn());
			const BitBoard capturedBit = AttackFields::enpeasentCaptured(curTurn, getEnpeasentColumn()).asSingletonBitboard();
			FOR_BIT(pawn, AttackFields::pawnTargs(to, !curTurn) & MP  & ~rightPinned) {
				const Position from = pawn.ToPosition();
				const BitBoard newBlockers = ALL ^ to.asSingletonBitboard() ^ pawn ^ capturedBit;
				if ((AttackFields::rookTargs(kingPos, newBlockers) & TR).isEmpty() &&
					(AttackFields::bishopTargs(kingPos, newBlockers) & TB).isEmpty()) {
					addMove(Move(MoveType::ENPEASENT, from, to, Piece::PAWN(), Piece::EMPTY()));
				}
			}
		}
#pragma endregion

#pragma region Castling
		if (!tacticalOnly) {
			FOR_SIDE(side) {
				if (getCanCastle(curTurn, side) &&
					(ALL & AttackFields::castleEmptySquares(curTurn, side)).isEmpty() &&
					(danger & AttackFields::castleSafeSquares(curTurn, side)).isEmpty()) {
					const MoveType type = side == Side::LEFT ? MoveType::CASTLE_LEFT : MoveType::CASTLE_RIGHT;
					const Position to(curTurn.isWhite() ? 7 : 0, 4 + (side == Side::LEFT ? (-2) : 2));

					addMove(Move(type, kingPos, to, Piece::KING(), Piece::EMPTY()));
				}
			}
		}
#pragma endregion
	}



	assertMovesAreUnique();
}

