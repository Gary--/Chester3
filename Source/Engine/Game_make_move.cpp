#include "Game.h"

void Game::resign() {
	result = getTurn() == Turn::WHITE ? GameResult::BLACK_WIN : GameResult::WHITE_WIN;
}

void Game::makeMove(Move move) {

	if (move.getType() == MoveType::RESIGN) {
		return resign();
	}

#pragma region Pack Undo data
	UndoData undoData(move, hash);
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
	
	
	//bbAllPieces ^= fromBB;
	//bbAllPieces |= toBB;
	//pieceTypeAt[fromInd] = EMPTY;
	//pieceTypeAt[toInd] = piece;

	//bbPlayerAllPieces[(bool)turn] ^= fromBB | toBB;
	//bbPlayerAllPieces[(bool)other] &= ~toBB;

	//bbPlayerPieces[(bool)turn][(int)piece] ^= fromBB | toBB;
	//cur.hash.update(turn, piece, fromInd);
	//cur.hash.update(turn, piece, toInd);

	//bbPlayerPieces[(bool)other][(int)targ] ^= toBB;
	//cur.hash.update(other, targ, toInd);

	//cur.hash.setEnpeasent(8);

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


#pragma region Pawn Special
	if (type == MoveType::PAWN_JUMP) {
		BitBoard enpeasentFrom = toBit.shiftLeft() | toBit.shiftRight();
		if ((*s(!curTurn, Piece::PAWN) & enpeasentFrom) != BitBoard::EMPTY()) {
			hash.setEnpeasent(toPos.col());
		}
	}

	if (type == MoveType::ENPEASENT) {
		BitBoard capturedBit = toBit.shiftBackward(curTurn);
		Position capturedPos = capturedBit.ToPosition();

		toggleBit(!curTurn, capturedPos, Piece::PAWN);
		setPieceAt(capturedPos, Piece::EMPTY);
		hash.togglePiece(capturedPos, !curTurn, Piece::PAWN);

	}

#pragma endregion

	// =====
	if (curTurn == Turn::BLACK) {
		moveCount++;
	}

	curTurn = !curTurn;
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

#pragma region Pawn Special
	if (type == MoveType::ENPEASENT) {
		BitBoard capturedBit = toBit.shiftBackward(curTurn);
		Position capturedPos = capturedBit.ToPosition();

		setPieceAt(capturedPos, Piece::PAWN);
		toggleBit(!curTurn, capturedPos, Piece::PAWN);
	}

#pragma endregion

	integrityCheck();
}