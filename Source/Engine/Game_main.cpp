#include "Game.h"

namespace {
	bool inited = false;
}

void Game::init() {
	if (inited) {
		return;
	}
	inited = true;

	GameHash::init();
}