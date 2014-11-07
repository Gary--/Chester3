#include "Move.h"


Move::Move() : 
Move(MoveType::INVALID, Position(), Position(), Piece::EMPTY, Piece::EMPTY)
{
}


Move::~Move()
{
}

//  Least to most significant
//  4 bits for type
//  7 bits for from
//  7 bits for to
//  3 bits for piece
//  3 bits for targ
Move::Move(MoveType type, Position from, Position to, Piece piece, Piece targ) :
value(
(uint32_t)type |
(uint32_t)from.index() << 4 |
(uint32_t)to.index() << 11 |
(uint32_t)piece << 18 |
(uint32_t)targ << 21
)

{}


Move Move::NULL_MOVE(){
	return Move(MoveType::NULL_MOVE, Position(), Position(), Piece::EMPTY, Piece::EMPTY);
}


MoveType Move::getType() const {
	return (MoveType)(0xF & value);
}
Position Move::getFrom() const {
	return Position((value >> 4) & 0x3F);
}
Position Move::getTo() const {
	return Position((value >> 11) & 0x3F);
}
Piece Move::getPiece() const {
	return (Piece)((value >> 18) & 0x7);
}
Piece Move::getTarg() const {
	return (Piece)((value >> 21) & 0x7);
}

bool Move::isCapture() const {
	return getTarg() != Piece::EMPTY || getType() == MoveType::ENPEASENT;
}

bool Move::isPromotion() const {
	return getType() >= MoveType::PROMO_KNIGHT;
}

bool Move::isTactical() const {
	return isCapture() || isPromotion();
}

Piece Move::promotionPiece() const {
	return (Piece)((uint8_t)Piece::KNIGHT + (uint8_t)getType() - (uint8_t)MoveType::PROMO_KNIGHT);
}

MoveType promoType(Piece piece) {
	_ASSERTE(Piece::KNIGHT <= piece && piece <= Piece::QUEEN);
	return MoveType((uint8_t)MoveType::PROMO_KNIGHT
					+ (uint8_t)piece - (uint8_t)Piece::KNIGHT);

}

Move Move::operator=(const Move& other) {
	value = other.value;
	return *this;
}

bool Move::operator==(const Move other) {
	return value == other.value;
}
bool Move::operator!=(const Move other) {
	return !(*this == other);
}