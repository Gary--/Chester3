#include "Game_Hash.h"


#pragma warning (disable: 4800)

Game_Hash::Game_Hash() {}

namespace {
	uint64_t zorbist[2][7][64] = { 0 };
	uint64_t enpeasentZorbist[9] = { 0 };
	uint64_t castleZorbist[2][2] = { 0 };

	uint64_t random() {
		return BitBoard::random().asInt64();
	}

	bool inited = false;
}



void Game_Hash::init() {
	if (inited) {
		return;
	}
	inited = true;

	for (int i = 0; i < 8; ++i) {
		enpeasentZorbist[i] = random();
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			castleZorbist[i][j] = random();
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j < 7; ++j) {//empty is left as 0
			for (int k = 0; k < 64; ++k) {
				zorbist[i][j][k] = random();
			}
		}
	}
}

Game_Hash::Game_Hash(const GameConfiguration& conf) {
	hash = 0;
	enpeasent = GameConfiguration::NO_ENPEASENT_COLUMN;

	// turn
	if (conf.getTurn() == Turn::BLACK()) {
		toggleTurn();
	}

	// Castling rights
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			canCastle[i][j] = true;
			hash ^= castleZorbist[i][j];
		}
	}
	FOR_TURN(turn) {
		FOR_SIDE(side) {
			if (!conf.getCanCastle(turn, side)) {
				voidCastle(turn, side);
			}
		}
	}

	// Pieces
	FOR_POSITION_64(pos) {
		togglePiece(pos,conf.getOwnerAt(pos), conf.getPieceAt(pos));
	}

	//enpeasent
	setEnpeasent(conf.getEnpeasentColumn());

}

bool Game_Hash::getCanCastle(const Turn player, const  Side side) const {
	return canCastle[player.asIndex()][bool(side)];
}

int Game_Hash::getEnpeasent() const {
	return enpeasent;
}

void Game_Hash::togglePiece(const Position position, const  Turn player, const  Piece piece) {
	hash ^= zorbist[player.asIndex()][piece.asIndex()][position.index()];
}

void Game_Hash::setEnpeasent(const int value) {
	hash ^= enpeasentZorbist[enpeasent];
	enpeasent = value;
	hash ^= enpeasentZorbist[enpeasent];
}

void Game_Hash::voidCastle(const Turn player, const  Side side) {
	if (canCastle[player.asIndex()][bool(side)]) {
		canCastle[player.asIndex()][bool(side)] = false;
		hash ^= castleZorbist[player.asIndex()][bool(side)];
	}
}

void Game_Hash::toggleTurn() {
	hash = ~hash;
}

uint64_t Game_Hash::toInt64() const {
	return hash;
}

bool Game_Hash::operator==(const Game_Hash& other) const {
	return hash == other.hash;
}

#pragma warning (default: 4800)