#include "Game.h"
#include "attack_fields.h"

void Game::makeMove(Move move) {

#pragma region Pack Undo data
	UndoData undoData(move, hash,numMovesAvail,check);
	movePtr += numMovesAvail;
	numMovesAvail = -1;

	undoDatas.push_back(undoData);
#pragma endregion

#pragma region Unpack move
	const MoveType type = move.getType();
	const Position fromPos = move.getFrom();
	const BitBoard fromBit = fromPos.ToSingletonBoard();
	const Position toPos = move.getTo();
	const BitBoard toBit = toPos.ToSingletonBoard();
	const Piece piece = move.getPiece();
	const Piece targ = move.getTarg();
#pragma endregion
	
	

	_ASSERTE(!sp(curTurn)->contains(toPos));

#pragma region Normal Move
	ALL ^= fromBit;
	ALL |= toBit;
	setPieceAt(fromPos, Piece::EMPTY);
	setPieceAt(toPos, piece);
	
	*sp(curTurn) ^= fromBit | toBit;
	*sp(!curTurn) &= ~toBit;

	*s(curTurn, piece) ^= fromBit | toBit;
	hash.togglePiece(fromPos,curTurn,piece);
	hash.togglePiece(toPos, curTurn, piece);

	*s(!curTurn, targ) ^= toBit;
	hash.togglePiece(toPos, !curTurn, targ);

	hash.setEnpeasent(GameConfiguration::NO_ENPEASENT_COLUMN);
#pragma endregion



	if (type == MoveType::PAWN_JUMP) { // Make sure the move enpeasent is actually legal
		BitBoard enpeasentFrom = toBit.shiftLeft() | toBit.shiftRight();
		FOR_BIT(pawn, getPieces(!curTurn, Piece::PAWN) & enpeasentFrom) {
			Position theirKingPos = getPieces(!curTurn, Piece::KING).ToPosition();
			BitBoard newBlockers = getAllPieces() ^ pawn^toBit^
				AttackFields::enpeasentTo(!curTurn, toPos.col()).ToSingletonBoard();
			BitBoard diagProblems = (getPieces(curTurn, Piece::QUEEN) | getPieces(curTurn, Piece::BISHOP))&
				AttackFields::bishopTargs(theirKingPos, newBlockers);
			BitBoard rightProblems = (getPieces(curTurn, Piece::QUEEN) | getPieces(curTurn, Piece::ROOK))&
				AttackFields::rookTargs(theirKingPos, newBlockers);
			
			if ((diagProblems | rightProblems) == BitBoard::EMPTY()) {
				hash.setEnpeasent(toPos.col());
				break;
			}
		}
	} else if (type == MoveType::ENPEASENT) {
		BitBoard capturedBit = toBit.shiftBackward(curTurn);
		Position capturedPos = capturedBit.ToPosition();

		toggleBit(!curTurn, capturedPos, Piece::PAWN);
		setPieceAt(capturedPos, Piece::EMPTY);
		hash.togglePiece(capturedPos, !curTurn, Piece::PAWN);

	} else if (move.isPromotion()) {
		Piece promo = move.promotionPiece();

		*s(curTurn, Piece::PAWN) ^= toBit;
		hash.togglePiece(toPos, curTurn, Piece::PAWN);

		*s(curTurn, promo) ^= toBit;
		hash.togglePiece(toPos, curTurn, promo);
		setPieceAt(toPos, promo);
	} else if (piece == Piece::KING) {
		hash.voidCastle(curTurn, Side::LEFT);
		hash.voidCastle(curTurn, Side::RIGHT);

		if (type == MoveType::CASTLE_LEFT || type== MoveType::CASTLE_RIGHT) {
			int baseRow = curTurn == Turn::WHITE ? 7 : 0;
			Position rookFrom(baseRow, type == MoveType::CASTLE_LEFT ? 0 : 7);
			Position rookTo(baseRow, type == MoveType::CASTLE_LEFT ? 3 : 5);
			BitBoard rookChange = rookFrom.ToSingletonBoard() | rookTo.ToSingletonBoard();

			ALL ^= rookChange;
			*sp(curTurn) ^= rookChange;
			*s(curTurn, Piece::ROOK) ^= rookChange;
			setPieceAt(rookFrom, Piece::EMPTY);
			setPieceAt(rookTo, Piece::ROOK);

			hash.togglePiece(rookFrom, curTurn, Piece::ROOK);
			hash.togglePiece(rookTo, curTurn, Piece::ROOK);
		}
	}

	if (toPos == Position("a1") || fromPos == Position("a1")) {
		hash.voidCastle(Turn::WHITE, Side::LEFT);
	}
	if (toPos == Position("h1") || fromPos == Position("h1")) {
		hash.voidCastle(Turn::WHITE, Side::RIGHT);
	}
	if (toPos == Position("a8") || fromPos == Position("a8")) {
		hash.voidCastle(Turn::BLACK, Side::LEFT);
	}
	if (toPos == Position("h8") || fromPos == Position("h8")) {
		hash.voidCastle(Turn::BLACK, Side::RIGHT);
	}

	// =====
	if (curTurn == Turn::BLACK) {
		moveCount++;
	}

	
	_ASSERTE(!posAttackedBy(getPieces(curTurn, Piece::KING).ToPosition(), !curTurn));

	curTurn = !curTurn;
	check = posAttackedBy(getPieces(curTurn, Piece::KING).ToPosition(), !curTurn);
	hash.toggleTurn();

	integrityCheck();
	
}

void Game::undoMove() {
	curTurn = !curTurn;
	if (curTurn == Turn::BLACK) {
		moveCount--;
	}

	

	//====
#pragma region Unpack Undo Data
	UndoData undoData = undoDatas.back();
	undoDatas.pop_back();
	if (numMovesAvail > 0) {
		moves.erase(moves.begin() + movePtr, moves.end());
	}
	numMovesAvail = undoData.numMovesAvailable;
	if (numMovesAvail > 0) {
		movePtr -= numMovesAvail;
	}

	check  = undoData.check;
	hash = undoData.hash;

	Move move = undoData.move;
	const MoveType type = move.getType();
	const Position fromPos = move.getFrom();
	const BitBoard fromBit = fromPos.ToSingletonBoard();
	const Position toPos = move.getTo();
	const BitBoard toBit = toPos.ToSingletonBoard();
	const Piece piece = move.getPiece();
	const Piece targ = move.getTarg();
#pragma endregion





#pragma region Pawn Special
	if (type == MoveType::ENPEASENT) {
		BitBoard capturedBit = toBit.shiftBackward(curTurn);
		Position capturedPos = capturedBit.ToPosition();

		setPieceAt(capturedPos, Piece::PAWN);
		toggleBit(!curTurn, capturedPos, Piece::PAWN);
	} else if (move.isPromotion()) {
		Piece promo = move.promotionPiece();

		*s(curTurn, Piece::PAWN) ^= toBit;
		*s(curTurn, promo) ^= toBit;
	} else if (type == MoveType::CASTLE_LEFT || type == MoveType::CASTLE_RIGHT) {
		int baseRow = curTurn == Turn::WHITE ? 7 : 0;
		Position rookFrom(baseRow, type == MoveType::CASTLE_LEFT ? 0 : 7);
		Position rookTo(baseRow, type == MoveType::CASTLE_LEFT ? 3 : 5);
		BitBoard rookChange = rookFrom.ToSingletonBoard() | rookTo.ToSingletonBoard();

		ALL ^= rookChange;
		*sp(curTurn) ^= rookChange;
		*s(curTurn, Piece::ROOK) ^= rookChange;
		setPieceAt(rookFrom, Piece::ROOK);
		setPieceAt(rookTo, Piece::EMPTY);
	}

#pragma endregion


#pragma region Regular Move

	ALL ^= fromBit;
	*sp(curTurn) ^= fromBit | toBit;
	*s(curTurn, piece) ^= fromBit | toBit;

	setPieceAt(fromPos, piece);
	setPieceAt(toPos, targ);

	if (targ != Piece::EMPTY) {
		*sp(!curTurn) ^= toBit;
		*s(!curTurn, targ) ^= toBit;
	} else {
		ALL ^= toBit;
	}
#pragma endregion

	integrityCheck();
}