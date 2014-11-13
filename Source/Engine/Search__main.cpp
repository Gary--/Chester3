#include "Search.h"
#include "Evaluate_simple.h"
#include "Game.h"

void Search::configureGame(GameConfiguration conf) {
	Game::configure(conf);
	SimpleEvaluation::synchronize();
}