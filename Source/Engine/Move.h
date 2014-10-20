#pragma once
#include "chess_consts.h"
#include "Position.h"

enum class MoveType : uint8_t{
	REGULAR			= 0, 
	CAPTURE			= 1, 
	CASTLE_LEFT		= 2,
	CASTLE_RIGHT	= 3,
	PAWN_JUMP		= 4,
	ENPEASENT		= 5,
	PROMO_KNIGHT	= 6, //PROMO_X - 4 gives the piece
	PROMO_BISHOP	= 7,
	PROMO_ROOK		= 8,
	PROMO_QUEEN		= 9,
	INVALID			= 10,
	RESIGN			= 11,
	NULL_MOVE		= 12,
};

struct Move
{

public:
	Move(MoveType type,Position from, Position to);
	static Move RESIGN();
	static Move NULL_MOVE();
	Move();
	~Move();

private:
	const MoveType type;
	const Position from, to;
};

