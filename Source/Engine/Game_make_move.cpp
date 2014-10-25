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

	// =====
	if (curTurn == Turn::BLACK) {
		moveCount++;
	}
	curTurn = !curTurn;
	
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




	//bbAllPieces ^= fromBB;
	//bbPlayerAllPieces[(bool)turn] ^= fromBB | toBB;
	//bbPlayerPieces[(bool)turn][(int)piece] ^= fromBB | toBB;

	//pieceTypeAt[fromInd] = piece;
	//pieceTypeAt[toInd] = targ;

	//if (targ != EMPTY) {//was a capture
	//	bbPlayerAllPieces[(bool)other] ^= toBB;
	//	bbPlayerPieces[(bool)other][(int)targ] ^= toBB;
	//	playerPieceCounts[(bool)other][(int)targ] ++;
	//} else {
	//	bbAllPieces ^= toBB;
	//}

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



	integrityCheck();
}