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
	UNKNOWN,
};
#define FOR_PIECE(x,low,high) for(Piece x=low;x<=high;x=(Piece)((uint8_t)x+1))
//#define FOR_PIECE(x) FOR_PIECE(x,Piece::PAWN,PIECE::KING)


//Used only for castling
#define FOR_SIDE(x) for(Side x=Side::LEFT,temp__##__LINE__;x==Side::LEFT || temp__##__LINE__ == Side::LEFT;temp__##__LINE__ = x, x=Side::RIGHT )

enum class Side : bool {LEFT, RIGHT,};// queen and king side respecively

// Iterates (BLACK, WHITE)
#define FOR_TURN(x) for(Turn x=Turn::BLACK,temp__##__LINE__;x==Turn::BLACK || temp__##__LINE__ == Turn::BLACK;temp__##__LINE__ = x, x=Turn::WHITE )
enum class Turn : bool {
	BLACK,
	WHITE
};
Turn operator!(Turn turn);

namespace ChessUtils {
	Piece pieceFromChar(char c);// . used for empty
	Turn turnFromChar(char c);// Uppercase = WHITE, else BLACK
	char charFromPieceTurn(Turn turn, Piece piece);
}