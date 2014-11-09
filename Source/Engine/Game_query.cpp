#include "Game.h"

Turn Game::getTurn() {
	return curTurn;
}

BitBoard Game::getPieces(Turn turn, Piece piece) {
	if (turn == Turn::WHITE()) {
		switch (piece.asEnum()) {
		case PieceEnum::PAWN:
			return WP;
		case PieceEnum::KNIGHT:
			return WN;
		case PieceEnum::BISHOP:
			return WB;
		case PieceEnum::ROOK:
			return WR;
		case PieceEnum::QUEEN:
			return WQ;
		case PieceEnum::KING:
			return WK;
		}
	} else {
		switch (piece.asEnum()) {
		case PieceEnum::PAWN:
			return BP;
		case PieceEnum::KNIGHT:
			return BN;
		case PieceEnum::BISHOP:
			return BB;
		case PieceEnum::ROOK:
			return BR;
		case PieceEnum::QUEEN:
			return BQ;
		case PieceEnum::KING:
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
	if (turn == Turn::WHITE()) {
		return WA;
	} else {
		return BA;
	}
}

Piece Game::getPieceAt(Position pos) {
	return pieces[pos.index()];
}

Turn Game::getOwnerAt(Position pos) {
	return (pos.asSingletonBitboard() & WA) == BitBoard::EMPTY() ? Turn::BLACK() : Turn::WHITE();
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