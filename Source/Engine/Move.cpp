#include "Move.h"


Move::Move() 
{
	*this = INVALID();
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
Move::Move(const MoveType type, const Position from, const Position to, const Piece piece, const  Piece targ) :
value(
(uint32_t)type |
(uint32_t)from.index() << 4 |
(uint32_t)to.index() << 11 |
(uint32_t)(piece.asIndex()) << 18 |
(uint32_t)(targ.asIndex()) << 21
)

{}

Move Move::INVALID() {
	return Move(MoveType::INVALID, Position(), Position(), Piece::EMPTY(), Piece::EMPTY());
}

Move Move::NULL_MOVE(){
	return Move(MoveType::NULL_MOVE, Position(), Position(), Piece::EMPTY(), Piece::EMPTY());
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
	return getTarg() != Piece::EMPTY() || getType() == MoveType::ENPEASENT;
}

bool Move::isPromotion() const {
	return getType() >= MoveType::PROMO_KNIGHT;
}

bool Move::isTactical() const {
	return isCapture() || isPromotion();
}

Piece Move::promotionPiece() const {
	return (Piece)((uint8_t)PieceEnum::KNIGHT + (uint8_t)getType() - (uint8_t)MoveType::PROMO_KNIGHT);
}

MoveType promoType(const Piece piece) {
	_ASSERTE(Piece::KNIGHT() <= piece && piece <= Piece::QUEEN());
	return MoveType((uint8_t)MoveType::PROMO_KNIGHT
					+ piece.asIndex() - (uint8_t)PieceEnum::KNIGHT);

}

Move Move::operator=(const Move& other){
	value = other.value;
	return *this;
}

bool Move::operator==(const Move other) const{
	return value == other.value;
}
bool Move::operator!=(const Move other) const{
	return !(*this == other);
}

std::string Move::str() const {
	if (*this == NULL_MOVE()) {
		return "0000";
	}

	std::string result = getFrom().str() + getTo().str();
	if (isPromotion()) {
		result += promotionPiece().asChar(Turn::BLACK());
	}
	return result;
}