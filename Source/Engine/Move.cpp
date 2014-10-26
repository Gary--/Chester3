#include "Move.h"


Move::Move() : 
Move(MoveType::INVALID, Position(), Position(), Piece::EMPTY, Piece::EMPTY)
{
}


Move::~Move()
{
}

Move::Move(MoveType type, Position from, Position to,Piece piece, Piece targ) :
type(type), from(from), to(to), piece(piece),targ(targ){}

Move Move::RESIGN(){
	return Move(MoveType::RESIGN, Position(), Position(),Piece::EMPTY,Piece::EMPTY);
}

Move Move::NULL_MOVE(){
	return Move(MoveType::NULL_MOVE, Position(), Position(), Piece::EMPTY, Piece::EMPTY);
}


MoveType Move::getType() const {
	return type;
}
Position Move::getFrom() const {
	return from;
}
Position Move::getTo() const {
	return to;
}
Piece Move::getPiece() const {
	return piece;
}
Piece Move::getTarg() const {
	return targ;
}

bool Move::isCapture() const {
	return targ != Piece::EMPTY || type == MoveType::ENPEASENT;
}

bool Move::isPromotion() const {
	return type >= MoveType:: PROMO_KNIGHT;
}

Piece Move::promotionPiece() const {
	return (Piece)((uint8_t)Piece::KNIGHT + (uint8_t)type - (uint8_t)MoveType::PROMO_KNIGHT);
}

MoveType promoType(Piece piece) {
	_ASSERTE(Piece::KNIGHT <= piece && piece <= Piece::QUEEN);
	return MoveType((uint8_t)MoveType::PROMO_KNIGHT
					+ (uint8_t)piece - (uint8_t)Piece::KNIGHT);

}