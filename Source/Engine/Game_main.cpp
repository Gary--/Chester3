#include "Game.h"
#include "attack_fields.h"

Piece Game::pieces[64];
Turn Game::curTurn;
BitBoard Game::WK, Game::WQ, Game::WR, Game::WB, Game::WN, Game::WP;
BitBoard Game::BK, Game::BQ, Game::BR, Game::BB, Game::BN, Game::BP;
BitBoard Game::WA, Game::BA;
BitBoard Game::ALL;

int Game::movePtr = 0;
UndoData Game::cur;

namespace {
	bool inited = false;
}

void Game::init() {
	if (inited) {
		return;
	}
	inited = true;

	GameHash::init();
	AttackFields::init();

	reset();
}


void Game::reset() {
	init();
	curTurn = Turn::WHITE;

	Game::WK = Game::WQ = Game::WR = Game::WB = Game::WN = Game::WP =
		Game::BK = Game::BQ = Game::BR = Game::BB = Game::BN = Game::BP =
		Game::WA = Game::BA =
		Game::ALL = BitBoard::EMPTY();

	FOR_POSITION_64(pos) {
		pieces[pos.index()] = Piece::EMPTY;
	}


	resetMoveManager();

}