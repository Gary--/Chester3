#pragma once

namespace Perft {
	int perftFull(const char* FEN, int depth);
	int perftLazy(const char* FEN, int depth);
	int perftUniquePositions(const char* FEN, int depth);
}