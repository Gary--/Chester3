#pragma once
#include "Move.h"
#include "GameConfiguration.h"
namespace MateFinder {

	// Moves by the turn player. Return NULLMOVE if none found.
	Move findMatingMove(GameConfiguration conf, int moves);

}