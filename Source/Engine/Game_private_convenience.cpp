#include "Game.h"

namespace {
	BitBoard scratch;
}

BitBoard* Game::s(Turn turn, Piece piece) {
	
	if (turn == Turn::WHITE()) {
		switch (piece.asEnum()) {
		case PieceEnum::EMPTY:
			return &scratch;
		case PieceEnum::PAWN:
			return &WP;
		case PieceEnum::KNIGHT:
			return &WN;
		case PieceEnum::BISHOP:
			return &WB;
		case PieceEnum::ROOK:
			return &WR;
		case PieceEnum::QUEEN:
			return &WQ;
		case PieceEnum::KING:
			return &WK;
		}
	} else {
		switch (piece.asEnum()) {
		case PieceEnum::EMPTY:
			return &scratch;
		case PieceEnum::PAWN:
			return &BP;
		case PieceEnum::KNIGHT:
			return &BN;
		case PieceEnum::BISHOP:
			return &BB;
		case PieceEnum::ROOK:
			return &BR;
		case PieceEnum::QUEEN:
			return &BQ;
		case PieceEnum::KING:
			return &BK;
		}
	}
	_ASSERT(false);
	return nullptr;
}

BitBoard* Game::sp(Turn turn) {
	return turn == Turn::WHITE()? &WA : &BA;
}

void Game::toggleBit(Turn turn, Position position, Piece piece) {
	*s(turn, piece) ^= position.ToSingletonBoard();
	*sp(turn) ^= position.ToSingletonBoard();
	ALL ^= position.ToSingletonBoard();

	//hash.togglePiece(position, turn, piece);
}


void Game::clearPieceAt(Position position) {
	Piece piece = getPieceAt(position);
	if (piece == Piece::EMPTY()) {
		return;
	}

	Turn turn = getOwnerAt(position);
	
	*s(turn, piece) &= ~position.ToSingletonBoard();
	*sp(turn) &= ~position.ToSingletonBoard();
	ALL &= ~position.ToSingletonBoard();

	setPieceAt(position, Piece::EMPTY());

	cur.hash.togglePiece(position, turn, piece);
}
void Game::addPieceAt(Turn turn, Position position, Piece piece) {
	*s(turn, piece) |= position.ToSingletonBoard();
	*sp(turn) |= position.ToSingletonBoard();
	ALL |= position.ToSingletonBoard();
	setPieceAt(position, piece);
	cur.hash.togglePiece(position, turn, piece);
}


void Game::setPieceAt(Position position, Piece piece) {
	pieces[position.index()] = piece;
}