#pragma once
#include <cstdint>

enum class GameResult :uint8_t {
	NONE,
	IN_PROGRESS,
	STALEMATE,
	WHITE_WIN,
	BLACK_WIN,
};