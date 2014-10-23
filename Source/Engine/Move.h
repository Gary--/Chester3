#pragma once
#include "chess_consts.h"
#include "Position.h"

enum class MoveType : uint8_t{
	REGULAR,                   //0
	CASTLE_LEFT,               //1
	CASTLE_RIGHT,              //2
	PAWN_JUMP,                 //3
	RESIGN,                    //4
	NULL_MOVE,                 //5
	INVALID,                   //6
	ENPEASENT,                //12
	PROMO_KNIGHT,              //7
	PROMO_BISHOP,              //8
	PROMO_ROOK,                //9
	PROMO_QUEEN,              //10
	
};

struct Move
{

public:
	Move(MoveType type,Position from, Position to, Piece piece, Piece targ);
	static Move RESIGN();
	static Move NULL_MOVE();
	bool isPromotion() const;
	Piece promotionPiece() const;
	Move();
	~Move();


	const MoveType type;
	const Position from, to;
	const Piece piece, targ;
private:

};

