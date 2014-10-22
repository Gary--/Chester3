#include "Game.h"

namespace {
	BitBoard scratch;
}

BitBoard* Game::s(Turn turn, Piece piece) {
	
	if (turn == Turn::WHITE) {
		switch (piece) {
		case Piece::EMPTY:
			return &scratch;
		case Piece::PAWN:
			return &WP;
		case Piece::KNIGHT:
			return &WN;
		case Piece::BISHOP:
			return &WB;
		case Piece::ROOK:
			return &WR;
		case Piece::QUEEN:
			return &WQ;
		case Piece::KING:
			return &WK;
		}
	} else {
		switch (piece) {
		case Piece::EMPTY:
			return &scratch;
		case Piece::PAWN:
			return &BP;
		case Piece::KNIGHT:
			return &BN;
		case Piece::BISHOP:
			return &BB;
		case Piece::ROOK:
			return &BR;
		case Piece::QUEEN:
			return &BQ;
		case Piece::KING:
			return &BK;
		}
	}
	_ASSERT(false);
	return nullptr;
}

BitBoard* Game::sp(Turn turn) {
	return turn == Turn::WHITE ? &WA : &BA;
}

void Game::toggleBit(Turn turn, Position position, Piece piece) {
	*s(turn, piece) ^= position.ToSingletonBoard();
	*sp(turn) ^= position.ToSingletonBoard();
	ALL ^= position.ToSingletonBoard();
}

void Game::setPieceAt(Position position, Piece piece) {
	pieces[position.index()] = piece;
}