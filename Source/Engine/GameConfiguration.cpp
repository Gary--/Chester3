#include "GameConfiguration.h"


GameConfiguration::GameConfiguration() 
{
	FOR_POSITION_64(pos) {
		clearPieceAt(pos);
	}

	turn = Turn::WHITE;

	setCanCastle(Turn::WHITE, Side::LEFT, false);
	setCanCastle(Turn::WHITE, Side::RIGHT, false);
	setCanCastle(Turn::BLACK, Side::LEFT, false);
	setCanCastle(Turn::BLACK, Side::RIGHT, false);

	setHalfMoveClock(0);
	setMoveNumber(1);
	setEnpeasentColumn(NO_ENPEASENT_COLUMN);
}

const int GameConfiguration::NO_ENPEASENT_COLUMN = 8;

GameConfiguration::~GameConfiguration() {}


Turn GameConfiguration::getTurn() const {
	return turn;
}
void GameConfiguration::setTurn(Turn turn) {
	this->turn = turn;
}

Piece GameConfiguration::getPieceAt(Position position) const {
	return pieces[position.index()];
}
void GameConfiguration::setPieceAt(Position position, Turn turn, Piece piece) {
	pieces[position.index()] = piece;
	owners[position.index()] = turn;
}

void GameConfiguration::clearPieceAt(Position position) {
	setPieceAt(position, Turn::BLACK, Piece::EMPTY);
}


Turn GameConfiguration::getOwnerAt(Position position) const {
	return owners[position.index()];
}

#pragma warning(disable:4800)//force to bool
bool GameConfiguration::getCanCastle(Turn turn, Side side) const {
	return canCastle[(bool)turn][(bool)side];
}
void GameConfiguration::setCanCastle(Turn turn, Side side, bool value) {
	canCastle[(bool)turn][(bool)side] = value;
}
#pragma warning(default:4800)

int GameConfiguration::getHalfMoveClock() const {
	return halfMoveClock;
}
void GameConfiguration::setHalfMoveClock(int value) {
	halfMoveClock = value;
}

int GameConfiguration::getMoveNumber() const {
	return moveNumber;
}
void GameConfiguration::setMoveNumber(int value) {
	moveNumber = value;
}

int GameConfiguration::getEnpeasentColumn() const {
	return enpeasentColumn;
}
void GameConfiguration::setEnpeasentColumn(int value) {
	enpeasentColumn = value;
}

std::string GameConfiguration::str() const {
	return "to be implemented as FEN";
}