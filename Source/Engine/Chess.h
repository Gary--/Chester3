#pragma once
#include <cstdint>
#include <string>

#define FOR_8(x) for (int x = 0; x < 8;++x)
#define FOR_64(x) for (int x = 0; x < 64;++x)

//Used only for castling
#define FOR_SIDE(x) for(Side x=Side::LEFT,temp__##__LINE__;x==Side::LEFT || temp__##__LINE__ == Side::LEFT;temp__##__LINE__ = x, x=Side::RIGHT )

enum class Side : bool { LEFT, RIGHT, };// queen and king side respecively
Side operator!(Side side);


// Iterates (BLACK, WHITE)
#define FOR_TURN(x) for(Turn x=Turn::BLACK(),temp__##__LINE__;x==Turn::BLACK() || temp__##__LINE__ == Turn::BLACK();temp__##__LINE__ = x, x=Turn::WHITE() )
struct Turn {
public:
	Turn();

	Turn operator!() const;

	// White gives true, Black gives false.
	bool asIndex() const;

	bool operator==(const Turn other) const;
	bool operator!=(const Turn other) const;

	std::string str() const;

	bool isWhite() const;
	bool isBlack() const;

	static Turn WHITE();
	static Turn BLACK();

	// Uppercase = WHITE, else BLACK
	static Turn fromChar(char c);
private:
	explicit Turn(bool value);
	bool value;
};



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
	INVALID,//7
};


struct Piece {
public:
	explicit Piece(uint8_t value);
	Piece();
	static Piece fromChar(char c);//PNBRQKpnbrqk
	char asChar(Turn turn) const;

	static Piece EMPTY();
	static Piece PAWN();
	static Piece KNIGHT();
	static Piece BISHOP();
	static Piece ROOK();
	static Piece QUEEN();
	static Piece KING();
	static Piece INVALID();

	static Piece random();//  [PAWN,KING]

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
