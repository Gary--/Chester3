#include "Game.h"
#include "attack_fields.h"

using namespace AttackFields;

//If I can capture a threatening pawn via EP
//HINT: put promo logic into add move
void Game::generateMovesImpl() {
	const BitBoard M = getPlayerPieces(curTurn);
	const BitBoard MK = getPieces(curTurn, Piece::KING);
	const BitBoard MP = getPieces(curTurn, Piece::PAWN);
	const BitBoard MR = getPieces(curTurn, Piece::ROOK);
	const BitBoard MB = getPieces(curTurn, Piece::BISHOP);
	const BitBoard MN = getPieces(curTurn, Piece::KNIGHT);
	const BitBoard MQ = getPieces(curTurn, Piece::QUEEN);

	const Position kingPos = MK.ToPosition();
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
	if (getCheck()) {
		jumpThreats = (TP & pawnTargs(kingPos, curTurn)) | (TN & knightTargs(kingPos));
		rightLosThreats = TR & rookTargs(kingPos, ALL);
		diagLosThreats = TB & bishopTargs(kingPos, ALL);

		_ASSERTE((rightLosThreats & diagLosThreats) == BitBoard::EMPTY());
		_ASSERTE(((rightLosThreats | diagLosThreats)&jumpThreats) == BitBoard::EMPTY());
	}
	const BitBoard threats = jumpThreats | rightLosThreats | diagLosThreats;
	_ASSERTE(threats.count() <= 2);

#pragma endregion
	// KING
	FOR_BIT(bit, kingRing &~(danger | M)) {
		Position to=bit.ToPosition();
		addMove(Move(MoveType::REGULAR, kingPos, to, Piece::KING, getPieceAt(to)));
	}

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


	

	// Try to capture the threat.
	if (threats!=BitBoard::EMPTY()) {
		posPieces ^= allPinned;

		const Position threatPos = threats.ToPosition();
		const Piece threatPiece = getPieceAt(threatPos);
		//// Capture the threat with a pawn
		//FOR_BIT(pawn, pawnTargs(threatPos, !curTurn) & MP &~allPinned) {
		//	addMove(Move(MoveType::REGULAR, pawn.ToPosition(), threatPos, Piece::PAWN, threatPiece));
		//}

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
			posTargs = blockingTargs(kingPos, threatPos) &~ALL;
			
		}
	}




	// Knights cannot move while pinned
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
		BitBoard tos = bishopTargs(from, ALL) & posTargs;
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

	/*
	
	BitBoard diagPinned, horiPinned
	BitBoard pinned;

	Classify in your face LOS as jump

	DO: king moves
	if in doubleCheck:
	    return


	if in check:
	    posPieces &= ~ pinned

	    DO: kill checker
		   enpeasent kill it
		   the piece killed will never reveal, except the hori double disappear reveal
		
		if LOS check:
		    posTargs &= blocking moves
	else:
	    DO: castle
	    DO: enpeasent


	*/

	assertMovesAreUnique();
}