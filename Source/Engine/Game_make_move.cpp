#include "Game.h"
#include "AttackFields.h"
#include "Game_UndoData.h"

void Game::makeMove(const Move move) {
	_ASSERTE(move != Move::INVALID());

	const bool wasInCheck = getCheck();
	pushMove(move);
	if (move == Move::NULL_MOVE()) {
		_ASSERTE(!wasInCheck);
		cur.hash.setEnpeasent(GameConfiguration::NO_ENPEASENT_COLUMN);

	} else {

#pragma region Unpack move
		const MoveType type = move.getType();
		const Position fromPos = move.getFrom();
		const BitBoard fromBit = fromPos.asSingletonBitboard();
		const Position toPos = move.getTo();
		const BitBoard toBit = toPos.asSingletonBitboard();
		const Piece piece = move.getPiece();
		const Piece targ = move.getTarg();
#pragma endregion



		_ASSERTE(!sp(curTurn)->contains(toPos));

#pragma region Normal Move
		ALL ^= fromBit;
		ALL |= toBit;
		setPieceAt(fromPos, Piece::EMPTY());
		setPieceAt(toPos, piece);

		*sp(curTurn) ^= fromBit | toBit;
		*sp(!curTurn) &= ~toBit;

		*s(curTurn, piece) ^= fromBit | toBit;
		cur.hash.togglePiece(fromPos, curTurn, piece);
		cur.hash.togglePiece(toPos, curTurn, piece);

		*s(!curTurn, targ) ^= toBit;
		cur.hash.togglePiece(toPos, !curTurn, targ);

		cur.hash.setEnpeasent(GameConfiguration::NO_ENPEASENT_COLUMN);
#pragma endregion



		if (type == MoveType::PAWN_JUMP) { // Make sure the move enpeasent is actually legal
			if (canEnpeasent(!getTurn(),toPos.col())) {
				cur.hash.setEnpeasent(toPos.col());
			}

		} else if (type == MoveType::ENPEASENT) {
			BitBoard capturedBit = toBit.shiftBackward(curTurn);
			Position capturedPos = capturedBit.ToPosition();

			toggleBit(!curTurn, capturedPos, Piece::PAWN());
			setPieceAt(capturedPos, Piece::EMPTY());
			cur.hash.togglePiece(capturedPos, !curTurn, Piece::PAWN());

		} else if (move.isPromotion()) {
			Piece promo = move.promotionPiece();

			*s(curTurn, Piece::PAWN()) ^= toBit;
			cur.hash.togglePiece(toPos, curTurn, Piece::PAWN());

			*s(curTurn, promo) ^= toBit;
			cur.hash.togglePiece(toPos, curTurn, promo);
			setPieceAt(toPos, promo);
		} else if (piece == Piece::KING()) {
			cur.hash.voidCastle(curTurn, Side::LEFT);
			cur.hash.voidCastle(curTurn, Side::RIGHT);

			if (type == MoveType::CASTLE_LEFT || type == MoveType::CASTLE_RIGHT) {
				int baseRow = curTurn.isWhite() ? 7 : 0;
				Position rookFrom(baseRow, type == MoveType::CASTLE_LEFT ? 0 : 7);
				Position rookTo(baseRow, type == MoveType::CASTLE_LEFT ? 3 : 5);
				BitBoard rookChange = rookFrom.asSingletonBitboard() | rookTo.asSingletonBitboard();

				ALL ^= rookChange;
				*sp(curTurn) ^= rookChange;
				*s(curTurn, Piece::ROOK()) ^= rookChange;
				setPieceAt(rookFrom, Piece::EMPTY());
				setPieceAt(rookTo, Piece::ROOK());

				cur.hash.togglePiece(rookFrom, curTurn, Piece::ROOK());
				cur.hash.togglePiece(rookTo, curTurn, Piece::ROOK());
			}
		}

		if (toPos == Position("a1") || fromPos == Position("a1")) {
			cur.hash.voidCastle(Turn::WHITE(), Side::LEFT);
		}
		if (toPos == Position("h1") || fromPos == Position("h1")) {
			cur.hash.voidCastle(Turn::WHITE(), Side::RIGHT);
		}
		if (toPos == Position("a8") || fromPos == Position("a8")) {
			cur.hash.voidCastle(Turn::BLACK(), Side::LEFT);
		}
		if (toPos == Position("h8") || fromPos == Position("h8")) {
			cur.hash.voidCastle(Turn::BLACK(), Side::RIGHT);
		}


		_ASSERTE(!posAttackedBy(getKingPosition(curTurn), !curTurn));

		{ // Check detection
			const BitBoard theirKingBit = getPieces(!curTurn, Piece::KING());

			cur.check = false;
			if ((piece == Piece::PAWN() && (AttackFields::pawnTargs(toPos, curTurn)&theirKingBit).isNotEmpty()) ||
				((piece == Piece::KNIGHT() || (move.isPromotion() && move.promotionPiece() == Piece::KNIGHT())) &&
				(AttackFields::knightTargs(toPos)&theirKingBit).isNotEmpty())) {
				cur.check = true;
			}
			if (cur.check == false && posAttackedByLOS(theirKingBit.ToPosition(), curTurn)) {
				cur.check = true;
			}
		}

	}
	
	fullMoveCount += curTurn.isBlack();


	curTurn = !curTurn;
	cur.hash.toggleTurn();
	postMoveUpdates();

	integrityCheck();
	
}

Move Game::undoMove() {
	curTurn = !curTurn;

	
	fullMoveCount -= curTurn.isBlack();
	//====
#pragma region Unpack Undo Data
	popMove();
	const Move move = cur.move;
	if (move == Move::NULL_MOVE()) {
		return move;
	}

	const MoveType type = move.getType();
	const Position fromPos = move.getFrom();
	const BitBoard fromBit = fromPos.asSingletonBitboard();
	const Position toPos = move.getTo();
	const BitBoard toBit = toPos.asSingletonBitboard();
	const Piece piece = move.getPiece();
	const Piece targ = move.getTarg();
#pragma endregion





#pragma region Pawn Special
	if (type == MoveType::ENPEASENT) {
		const BitBoard capturedBit = toBit.shiftBackward(curTurn);
		const Position capturedPos = capturedBit.ToPosition();

		setPieceAt(capturedPos, Piece::PAWN());
		toggleBit(!curTurn, capturedPos, Piece::PAWN());
	} else if (move.isPromotion()) {
		const Piece promo = move.promotionPiece();

		*s(curTurn, Piece::PAWN()) ^= toBit;
		*s(curTurn, promo) ^= toBit;
	} else if (type == MoveType::CASTLE_LEFT || type == MoveType::CASTLE_RIGHT) {
		int baseRow = curTurn.isWhite() ? 7 : 0;
		const Position rookFrom(baseRow, type == MoveType::CASTLE_LEFT ? 0 : 7);
		const Position rookTo(baseRow, type == MoveType::CASTLE_LEFT ? 3 : 5);
		const BitBoard rookChange = rookFrom.asSingletonBitboard() | rookTo.asSingletonBitboard();

		ALL ^= rookChange;
		*sp(curTurn) ^= rookChange;
		*s(curTurn, Piece::ROOK()) ^= rookChange;
		setPieceAt(rookFrom, Piece::ROOK());
		setPieceAt(rookTo, Piece::EMPTY());
	}

#pragma endregion


#pragma region Regular Move

	ALL ^= fromBit;
	*sp(curTurn) ^= fromBit | toBit;
	*s(curTurn, piece) ^= fromBit | toBit;

	setPieceAt(fromPos, piece);
	setPieceAt(toPos, targ);

	if (targ != Piece::EMPTY()) {
		*sp(!curTurn) ^= toBit;
		*s(!curTurn, targ) ^= toBit;
	} else {
		ALL ^= toBit;
	}
#pragma endregion

	

	integrityCheck();

	return move;
}