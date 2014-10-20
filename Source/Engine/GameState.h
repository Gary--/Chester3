#pragma once
#include <cstdint>

enum class GameState :uint8_t {
	NONE,
	IN_PROGRESS,
	STALEMATE,
	WHITE_WIN,
	BLACK_WIN,
};