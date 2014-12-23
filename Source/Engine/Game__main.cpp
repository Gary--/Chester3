#include "Game.h"
#include "AttackFields.h"
#include "Game_UndoData.h"

Piece Game::pieceTypes[64];
Turn Game::curTurn;
BitBoard Game::pieces[2][7];
BitBoard Game::playerPieces[2];
BitBoard Game::ALL;
int Game::fullMoveCount=0;

int Game::movePtr = 0;
Game_UndoData Game::cur;


Game::Game() {}
Game::~Game() {}


namespace {
	bool inited = false;
}


void Game::init() {
	if (inited) {
		return;
	}
	inited = true;

	Game_Hash::init();
	AttackFields::init();

	reset();
}


void Game::reset() {
	init();
	curTurn = Turn::WHITE();

	FOR_TURN(turn) {
		*sp(turn) = BitBoard::EMPTY();
		FOR_PIECE_ALL(piece) {
			*s(turn, piece) = BitBoard::EMPTY();
		}
	}
		
	Game::ALL = BitBoard::EMPTY();

	fullMoveCount = 1;
	FOR_POSITION_64(pos) {
		pieceTypes[pos.index()] = Piece::EMPTY();
	}


	resetMoveManager();

}