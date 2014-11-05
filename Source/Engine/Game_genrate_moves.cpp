#include "Game.h"
#include "attack_fields.h"

using namespace AttackFields;

//If I can capture a threatening pawn via EP
//HINT: put promo logic into add move
void Game::generateMovesImpl(bool tacticalOnly) {
	//const Turn curTurn = Turn::WHITE;

#pragma region Unpack variables
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
#pragma endregion

#pragma region Declare from to restrictions
	BitBoard posTargs = ~M;
	if (check) {
		tacticalOnly = false;
	}
	if (tacticalOnly) {
		posTargs &= T;
	}
	BitBoard posPieces = M;
#pragma endregion


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

#pragma endregion
	
#pragma region KingMoves
	FOR_BIT(bit, kingRing &~danger & posTargs) {
		Position to=bit.ToPosition();
		addMove(Move(MoveType::REGULAR, kingPos, to, Piece::KING, getPieceAt(to)));
	}
#pragma endregion

	// We are in double check. We can only move our king.
	if (threats.count() > 1) {
		return;
	}



#pragma region Pinning
	BitBoard rightPinned;
	FOR_BIT(bit, M &rightLosDanger & rookTargs(kingPos, ALL)) {
		if (rightLosThreats != ((rookTargs(kingPos,ALL^bit) & TR))) {
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


	
#pragma region Check Response
	// Try to capture the threat.
	if (check) {
		posPieces ^= allPinned;

		const Position threatPos = threats.ToPosition();
		const Piece threatPiece = getPieceAt(threatPos);

		// Capture the threat with a pawn
		FOR_BIT(pawn, pawnTargs(threatPos, !curTurn) & MP & posPieces) {
			addPawnMove(Move(MoveType::REGULAR, pawn.ToPosition(), threatPos, Piece::PAWN, threatPiece));
		}
		if (threatPiece == Piece::PAWN && getEnpeasentColumn() != GameConfiguration::NO_ENPEASENT_COLUMN) {
			Position to = enpeasentTo(curTurn, getEnpeasentColumn());
			FOR_BIT(pawn, pawnTargs(to, !curTurn) & MP & posPieces) {
				addMove(Move(MoveType::ENPEASENT, pawn.ToPosition(), to, Piece::PAWN, Piece::EMPTY));
			}
		}
		

		FOR_BIT(knight, knightTargs(threatPos) & MN & posPieces) {
			addMove(Move(MoveType::REGULAR, knight.ToPosition(), threatPos, Piece::KNIGHT, threatPiece));
		}

		const BitBoard posHeroBishopLocations = bishopTargs(threatPos, ALL) & posPieces;
		const BitBoard posHeroRookLocations = rookTargs(threatPos, ALL) & posPieces;

		FOR_BIT(rook, posHeroRookLocations & MR) {
			addMove(Move(MoveType::REGULAR, rook.ToPosition(), threatPos, Piece::ROOK, threatPiece));
		}

		FOR_BIT(bishop, posHeroBishopLocations & MB) {
			addMove(Move(MoveType::REGULAR, bishop.ToPosition(), threatPos, Piece::BISHOP, threatPiece));
		}

		FOR_BIT(queen, (posHeroRookLocations | posHeroBishopLocations)&MQ) {
			addMove(Move(MoveType::REGULAR, queen.ToPosition(), threatPos, Piece::QUEEN, threatPiece));
		}

		// The only way to respond to a jump threat was to capture.
		if (jumpThreats != BitBoard::EMPTY()) {
			return;
		} else { // If it was an LOS threat, we can block also.
			BitBoard blocking = blockingTargs(kingPos, threatPos) &~ALL;;
			posTargs &= blocking;
		}
	}
#pragma endregion


#pragma region Regular Piece moves
	FOR_BIT(knight, MN & posPieces &~allPinned) {
		Position from = knight.ToPosition();
		FOR_BIT(toBit, knightTargs(from) & posTargs) {
			Position to = toBit.ToPosition();
			addMove(Move(MoveType::REGULAR, from, to, Piece::KNIGHT, getPieceAt(to)));
		}
	}

	FOR_BIT(rook, MR & posPieces &~allPinned) {
		Position from = rook.ToPosition();
		FOR_BIT(toBit, rookTargs(from,ALL) & posTargs) {
			Position to = toBit.ToPosition();
			addMove(Move(MoveType::REGULAR, from, to, Piece::ROOK, getPieceAt(to)));
		}
	}

	FOR_BIT(rook, MR & posPieces & rightPinned) {
		Position from = rook.ToPosition();
		FOR_BIT(toBit, rookTargs(from, ALL) & posTargs & pinnedTargs(kingPos,from)) {
			Position to = toBit.ToPosition();
			addMove(Move(MoveType::REGULAR, from, to, Piece::ROOK, getPieceAt(to)));
		}
	}

	FOR_BIT(bishop, MB & posPieces & ~allPinned) {
		Position from = bishop.ToPosition();
		FOR_BIT(toBit, bishopTargs(from, ALL) & posTargs) {
			Position to = toBit.ToPosition();
			addMove(Move(MoveType::REGULAR, from, to, Piece::BISHOP, getPieceAt(to)));
		}
	}

	FOR_BIT(bishop, MB & posPieces & diagPinned) {
		Position from = bishop.ToPosition();
		FOR_BIT(toBit, bishopTargs(from, ALL) & posTargs & pinnedTargs(kingPos, from)) {
			Position to = toBit.ToPosition();
			addMove(Move(MoveType::REGULAR, from, to, Piece::BISHOP, getPieceAt(to)));
		}
	}

	FOR_BIT(queen, MQ & posPieces & ~allPinned) {
		Position from = queen.ToPosition();
		FOR_BIT(toBit, queenTargs(from, ALL) & posTargs) {
			Position to = toBit.ToPosition();
			addMove(Move(MoveType::REGULAR, from, to, Piece::QUEEN, getPieceAt(to)));
		}
	}

	FOR_BIT(queen, MQ & posPieces & allPinned) {
		Position from = queen.ToPosition();
		FOR_BIT(toBit, queenTargs(from, ALL) & posTargs & pinnedTargs(kingPos, from)) {
			Position to = toBit.ToPosition();
			addMove(Move(MoveType::REGULAR, from, to, Piece::QUEEN, getPieceAt(to)));
		}
	}
#pragma endregion
	
#pragma region Pawn Forward Move
	BitBoard pawnsThatCanMoveForward = (~allPinned | (rightPinned & BitBoard::colBits(kingPos.col()))) &
		 MP & posPieces;
	BitBoard inEmptyFrontOfPawns = pawnsThatCanMoveForward.shiftForward(curTurn) & ~ALL;
	if (tacticalOnly) {
		inEmptyFrontOfPawns &= pawnPromoZone(curTurn).shiftForward(curTurn);
	}
	FOR_BIT(toBit, inEmptyFrontOfPawns & posTargs) {
		Position to = toBit.ToPosition();
		Position from = to.shiftBackward(curTurn);
		addPawnMove(Move(MoveType::REGULAR, from, to, Piece::PAWN, Piece::EMPTY));
	}

	inEmptyFrontOfPawns &= pawnJumpZone(curTurn).shiftForward(curTurn);
	FOR_BIT(toBit, inEmptyFrontOfPawns.shiftForward(curTurn) & ~ALL & posTargs) {
		Position to = toBit.ToPosition();
		Position from = to.shiftBackward(curTurn).shiftBackward(curTurn);
		addPawnMove(Move(MoveType::PAWN_JUMP, from, to, Piece::PAWN, Piece::EMPTY));
	}
#pragma endregion

	if (!check) {
		
#pragma region Pawn Captures
		BitBoard kingX = bishopTargs(kingPos, BitBoard::EMPTY());
		BitBoard pawnsThatCanCapture = ~allPinned | diagPinned;
		FOR_BIT(toBit, (MP & pawnsThatCanCapture).shiftForward(curTurn).shiftLeft()  & T &
				(kingX | ~diagPinned.shiftForward(curTurn).shiftLeft())) {
			Position to = toBit.ToPosition();
			Position from = to.shiftBackward(curTurn).shiftRight();
			addPawnMove(Move(MoveType::REGULAR, from, to, Piece::PAWN, getPieceAt(to)));
		}
		FOR_BIT(toBit, (MP & pawnsThatCanCapture).shiftForward(curTurn).shiftRight()  & T  &
				(kingX | ~diagPinned.shiftForward(curTurn).shiftRight())) {
			Position to = toBit.ToPosition();
			Position from = to.shiftBackward(curTurn).shiftLeft();
			addPawnMove(Move(MoveType::REGULAR, from, to, Piece::PAWN, getPieceAt(to)));
		}
#pragma endregion

#pragma region Enpeasent
		if (getEnpeasentColumn() != GameConfiguration::NO_ENPEASENT_COLUMN) {
			Position to = enpeasentTo(curTurn, getEnpeasentColumn());
			BitBoard capturedBit = enpeasentCaptured(curTurn, getEnpeasentColumn()).ToSingletonBoard();
			FOR_BIT(pawn, pawnTargs(to, !curTurn) & MP  & ~rightPinned) {
				Position from = pawn.ToPosition();
				BitBoard newBlockers = ALL ^ to.ToSingletonBoard() ^ pawn ^ capturedBit;
				if ((rookTargs(kingPos, newBlockers) & TR) == BitBoard::EMPTY() &&
					(bishopTargs(kingPos, newBlockers) & TB) == BitBoard::EMPTY()) {
					addMove(Move(MoveType::ENPEASENT, from, to, Piece::PAWN, Piece::EMPTY));
				}
			}
		}
#pragma endregion

#pragma region Castling
		if (!tacticalOnly) {
			FOR_SIDE(side) {
				if (getCanCastle(curTurn, side) &&
					(ALL & castleEmptySquares(curTurn, side)) == BitBoard::EMPTY() &&
					(danger & castleSafeSquares(curTurn, side)) == BitBoard::EMPTY()) {
					MoveType type = side == Side::LEFT ? MoveType::CASTLE_LEFT : MoveType::CASTLE_RIGHT;
					Position to(curTurn == Turn::WHITE ? 7 : 0, 4 + (side == Side::LEFT ? (-2) : 2));

					addMove(Move(type, kingPos, to, Piece::KING, Piece::EMPTY));
				}
			}
		}
#pragma endregion
	}



	assertMovesAreUnique();
}

