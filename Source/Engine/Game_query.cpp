#include "Game.h"
#include "Game_UndoData.h"

Turn Game::getTurn() {
	return curTurn;
}

BitBoard Game::getPieces(const Turn turn, const Piece piece) {
	return pieces[turn.asIndex()][piece.asIndex()];
}



BitBoard Game::getAllPieces() {
	return ALL;
}

BitBoard Game::getPlayerPieces(const Turn turn) {
	return playerPieces[turn.asIndex()];
}

Piece Game::getPieceAt(const Position pos) {
	return pieceTypes[pos.index()];
}

Turn Game::getOwnerAt(const Position pos) {
	return getPlayerPieces(Turn::WHITE()).contains(pos) ? Turn::WHITE() : Turn::BLACK();
}

bool Game::getCanCastle(const Turn turn, const Side side) {
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
	conf.setHalfMoveClock(getHalfMoveClock());
	conf.setMoveNumber(getMoveNumber());

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

// Get the move matching the given string. Example: e1e2, e7e8q (promotion)
Move Game::getMoveUciString(std::string uciString) {
	return getGameConfiguration().getMoveUciString(uciString);
}

// Get the move matching the given string.
Move Game::getMoveEpdString(std::string epdString) {
	return getGameConfiguration().getMoveEpdString(epdString);
}