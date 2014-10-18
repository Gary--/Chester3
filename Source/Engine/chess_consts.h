#pragma once
#include <cstdint>

//Properties to note:
// - Increasing in terms of value
// - empty is at 0
// - pieces without special rules [2,5]
enum class Piece : uint8_t {
	EMPTY,  //0
	PAWN,	//1
	KNIGHT,	//2
	BISHOP,	//3
	ROOK,	//4
	QUEEN,	//5
	KING,	//6
};

enum class Turn : bool {
	BLACK,
	WHITE
};
Turn operator!(Turn turn);