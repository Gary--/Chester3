#pragma once
#include <cstdint>
#include <string>


#define FOR_PIECE(x,low,high) for(Piece x=low;x<=high;x=Piece(x.asIndex()+1))
#define FOR_PIECE_ALL(x) FOR_PIECE(x,Piece::PAWN(),Piece::KING())

////Properties to note:
//// - Increasing in terms of value
//// - empty is at 0
//// - pieces without special rules [2,5]

enum class PieceEnum : uint8_t { // used for switches
	EMPTY,  //0
	PAWN,	//1
	KNIGHT,	//2
	BISHOP,	//3
	ROOK,	//4
	QUEEN,	//5
	KING,	//6
	UNKNOWN,//7
};


struct Piece {
public:
	explicit Piece(uint8_t value);
	Piece();

	static Piece EMPTY();
	static Piece PAWN();
	static Piece KNIGHT();
	static Piece BISHOP();
	static Piece ROOK();
	static Piece QUEEN();
	static Piece KING();
	static Piece UNKNOWN();
	
	//static Piece random();//  [PAWN,KING]

	uint8_t asIndex() const;
	PieceEnum asEnum() const;

	bool operator!=(const Piece other) const;
	bool operator==(const Piece other) const;
	bool operator<=(const Piece other) const;
	bool operator<(const Piece other) const;
	bool operator>=(const Piece other) const;
	bool operator>(const Piece other) const;

	Piece operator=(const Piece other);

	std::string str() const;
private:
	uint8_t value;
};

Piece randPiece();

//Used only for castling
#define FOR_SIDE(x) for(Side x=Side::LEFT,temp__##__LINE__;x==Side::LEFT || temp__##__LINE__ == Side::LEFT;temp__##__LINE__ = x, x=Side::RIGHT )

enum class Side : bool {LEFT, RIGHT,};// queen and king side respecively
Side operator!(Side side);


// Iterates (BLACK, WHITE)
#define FOR_TURN(x) for(Turn x=Turn::BLACK(),temp__##__LINE__;x==Turn::BLACK() || temp__##__LINE__ == Turn::BLACK();temp__##__LINE__ = x, x=Turn::WHITE() )
struct Turn {
public:
	Turn();

	Turn operator!() const;
	bool asIndex() const;

	bool operator==(const Turn other) const;
	bool operator!=(const Turn other) const;

	static Turn WHITE();
	static Turn BLACK();
	static Turn fromChar(char c);// Uppercase = WHITE, else BLACK
private:
	explicit Turn(bool value);
	bool value;
};


namespace ChessUtils {
	Piece pieceFromChar(char c);// . used for empty
	char charFromPieceTurn(Turn turn, Piece piece);
}