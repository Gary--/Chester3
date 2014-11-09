#include "Game.h"

Turn Game::getTurn() {
	return curTurn;
}

BitBoard Game::getPieces(Turn turn, Piece piece) {
	if (turn == Turn::WHITE) {
		switch (piece) {
		case Piece::PAWN:
			return WP;
		case Piece::KNIGHT:
			return WN;
		case Piece::BISHOP:
			return WB;
		case Piece::ROOK:
			return WR;
		case Piece::QUEEN:
			return WQ;
		case Piece::KING:
			return WK;
		}
	} else {
		switch (piece) {
		case Piece::PAWN:
			return BP;
		case Piece::KNIGHT:
			return BN;
		case Piece::BISHOP:
			return BB;
		case Piece::ROOK:
			return BR;
		case Piece::QUEEN:
			return BQ;
		case Piece::KING:
			return BK;
		}
	}
	_ASSERT(false);
	return BitBoard::EMPTY();
}



BitBoard Game::getAllPieces() {
	return ALL;
}

BitBoard Game::getPlayerPieces(Turn turn) {
	if (turn == Turn::WHITE) {
		return WA;
	} else {
		return BA;
	}
}

Piece Game::getPieceAt(Position pos) {
	return pieces[pos.index()];
}

Turn Game::getOwnerAt(Position pos) {
	return (pos.ToSingletonBoard() & WA) == BitBoard::EMPTY() ? Turn::BLACK : Turn::WHITE;
}

bool Game::getCanCastle(Turn turn, Side side) {
	return cur.hash.getCanCastle(turn, side);
}


int Game::getEnpeasentColumn() {
	return cur.hash.getEnpeasent();
}


bool Game::getCheck() {
	return cur.check;
}

uint64_t Game::getHash() {
	return cur.hash.toInt64();
}

GameConfiguration Game::getGameConfiguration() {
	GameConfiguration conf;
	conf.setTurn(Game::getTurn());
	conf.setEnpeasentColumn(Game::getEnpeasentColumn());


	FOR_TURN(turn) {
		FOR_SIDE(side) {
			conf.setCanCastle(turn, side, Game::getCanCastle(turn, side));
		}
	}

	FOR_POSITION_64(pos) {
		conf.setPieceAt(pos, Game::getOwnerAt(pos), Game::getPieceAt(pos));
	}

	return conf;
}