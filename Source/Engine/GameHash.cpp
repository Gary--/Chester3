#include "GameHash.h"
#include "chess_macros.h"

#pragma warning (disable: 4800)

namespace {
	uint64_t zorbist[2][7][64] = { 0 };
	uint64_t enpeasentZorbist[9] = { 0 };
	uint64_t castleZorbist[2][2] = { 0 };

	uint64_t random() {
		return BitBoard::random().AsInt64();
	}

	bool inited = false;
}

void GameHash::init() {
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

GameHash::GameHash(const GameConfiguration& conf) {
	hash = 0;
	enpeasent = GameConfiguration::NO_ENPEASENT_COLUMN;

	// turn
	if (conf.getTurn() == Turn::BLACK) {
		toggleTurn();
	}

	// Castling rights
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			canCastle[i][j] = true;
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


void GameHash::togglePiece(Position position,Turn player, Piece piece ) {
	hash ^= zorbist[(bool)player][(uint8_t)piece][position.index()];
}

void GameHash::setEnpeasent(int value) {
	hash ^= enpeasentZorbist[enpeasent];
	enpeasent = value;
	hash ^= enpeasentZorbist[enpeasent];
}

void GameHash::voidCastle(Turn player, Side side) {
	if (canCastle[(bool)player][bool(side)]) {
		canCastle[(bool)player][bool(side)] = false;
		hash ^= castleZorbist[(bool)player][bool(side)];
	}
}

void GameHash::toggleTurn() {
	hash = ~hash;
}

uint64_t GameHash::toInt64() const {
	return hash;
}

#pragma warning (default: 4800)