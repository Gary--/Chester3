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

MoveType promoType(Piece piece);

struct Move
{

public:
	Move(MoveType type,Position from, Position to, Piece piece, Piece targ);

	static Move NULL_MOVE();
	bool isPromotion() const;
	Piece promotionPiece() const;
	bool isCapture() const;
	bool isTactical() const;

	Move();
	~Move();


	MoveType getType() const;
	Position getFrom() const;
	Position getTo() const;
	Piece getPiece() const;
	Piece getTarg() const;

	Move operator=(const Move& other);
	bool operator==(const Move other);
	bool operator!=(const Move other);
private:
	/*MoveType type;
	Position from, to;
	Piece piece, targ;*/
	uint32_t value;
};

