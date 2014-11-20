#include "stdafx.h"
#include "Evaluation_test_helpers.h"
#include "Game.h"
#include "Evaluation.h"

void confSync(GameConfiguration conf){
	Game::configure(conf);
	Evaluation::synchronize();
}

void confSync(const char* FEN) {
	confSync(GameConfiguration(FEN));
}