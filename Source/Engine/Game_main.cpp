#include "Game.h"
#include "attack_fields.h"

Piece Game::pieces[64];
Turn Game::curTurn;
bool Game::check;
BitBoard Game::WK, Game::WQ, Game::WR, Game::WB, Game::WN, Game::WP;
BitBoard Game::BK, Game::BQ, Game::BR, Game::BB, Game::BN, Game::BP;
BitBoard Game::WA, Game::BA;
BitBoard Game::ALL;
GameResult Game::result;
GameHash Game::hash = GameHash(GameConfiguration());
int Game::halfMoveCount;
int Game::moveCount;
std::vector<UndoData> Game::undoDatas;
std::vector<Move> Game::moves;
int Game::movePtr = 0;
int Game::numMovesAvail = -1;

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

	result = GameResult::NONE;
	hash = GameHash(GameConfiguration());

	undoDatas.clear();

	movePtr = 0;
	moves.clear();
	numMovesAvail = -1;

}