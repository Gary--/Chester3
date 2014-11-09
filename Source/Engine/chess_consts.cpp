#include "chess_consts.h"
#include <crtdbg.h>
#include <iostream>


#include "BitBoard.h"
using namespace std;


Piece randPiece() {
	return (Piece)(1 + rand() % 6);
}

Side operator!(Side side) {
#pragma warning(disable : 4800) //Forcing to bool
	return (Side)(!(bool)side);
#pragma warning(default : 4800)
}


#pragma region Piece

Piece::Piece(uint8_t value) : value(value) {}
Piece::Piece() : Piece(0) {}

Piece Piece::fromChar(char c) {
	if ('a' <= c && c < 'z') {
		c -= 'a' - 'A';
	}

	switch (c) {
	case 'K': return Piece::KING();
	case 'Q': return Piece::QUEEN();
	case 'R': return Piece::ROOK();
	case 'B': return Piece::BISHOP();
	case 'N': return Piece::KNIGHT();
	case 'P': return Piece::PAWN();
	case '.': return Piece::EMPTY();


	default:
		_ASSERT(false);
		return Piece::UNKNOWN();
		break;

	}
}

char Piece::asChar(Turn turn) const {
	char res = '?';

	switch (asEnum()) {
	case PieceEnum::KING: res = 'K'; break;
	case PieceEnum::QUEEN: res = 'Q'; break;
	case PieceEnum::ROOK: res = 'R'; break;
	case PieceEnum::BISHOP: res = 'B'; break;
	case PieceEnum::KNIGHT: res = 'N'; break;
	case PieceEnum::PAWN: res = 'P'; break;
	case PieceEnum::EMPTY: return '.'; break;

	default:
		_ASSERT(false);
		break;
	}

	if (turn == Turn::BLACK()) {
		res += 'a' - 'A';
	}

	return res;

}

Piece Piece::EMPTY() {
	return Piece(0);
}
Piece Piece::PAWN() {
	return Piece(1);
}
Piece Piece::KNIGHT() {
	return Piece(2);
}
Piece Piece::BISHOP() {
	return Piece(3);
}
Piece Piece::ROOK() {
	return Piece(4);
}
Piece Piece::QUEEN() {
	return Piece(5);
}
Piece Piece::KING() {
	return Piece(6);
}
Piece Piece::UNKNOWN() {
	return Piece(7);
}

Piece Piece::random() {
	return Piece(1 + rand() % 6);
}

uint8_t Piece::asIndex() const {
	return value;
}

PieceEnum Piece::asEnum() const {
	return (PieceEnum)value;
}

bool Piece::operator!=(const Piece other) const {
	return value != other.value;
}
bool Piece::operator==(const Piece other) const {
	return value == other.value;
}
bool Piece::operator<=(const Piece other) const {
	return value <= other.value;
}
bool Piece::operator<(const Piece other) const {
	return value < other.value;
}
bool Piece::operator>=(const Piece other) const {
	return value >= other.value;
}
bool Piece::operator>(const Piece other) const {
	return value > other.value;
}

Piece Piece::operator=(const Piece other) {
	value = other.value;
	return *this;
}

std::string Piece::str() const {
	switch (asEnum()) {
	case PieceEnum::EMPTY:
		return "EMPTY";
	case PieceEnum::PAWN:
		return "PAWN";
	case PieceEnum::KNIGHT:
		return "KNIGHT";
	case PieceEnum::BISHOP:
		return "BISHOP";
	case PieceEnum::ROOK:
		return "ROOK";
	case PieceEnum::QUEEN:
		return "QUEEN";
	case PieceEnum::KING:
		return "KING";
	case PieceEnum::UNKNOWN:
		return "UNKNOWN";
	default:
		_ASSERTE(false);
		return "ERROR";
	}
}

#pragma endregion

#pragma region Turn
Turn::Turn() : value(false) {}
Turn::Turn(bool value) : value(value) {}

std::string Turn::str() const {
	return *this == WHITE() ? "WHITE" : "BLACK";
}

Turn Turn::operator!() const {
	return Turn(!value);
}

bool Turn::asIndex() const {
	return value;
}

Turn Turn::fromChar(char c) {
	return ('a' <= c && c < 'z') ? Turn::BLACK() : Turn::WHITE();
}

Turn Turn::BLACK() {
	return Turn(false);
}

Turn Turn::WHITE() {
	return Turn(true);
}

bool Turn::operator==(const Turn other) const {
	return value == other.value;
}
bool Turn::operator!=(const Turn other) const {
	return !(*this == other);
}

#pragma endregion



