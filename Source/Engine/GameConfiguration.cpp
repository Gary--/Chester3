#include "GameConfiguration.h"
#include "chess_macros.h"
#include <sstream>
#include "Game.h"

using namespace std;
using namespace ChessUtils;

GameConfiguration::GameConfiguration() 
{
	FOR_POSITION_64(pos) {
		clearPieceAt(pos);
	}

	turn = Turn::WHITE();

	setCanCastle(Turn::WHITE(), Side::LEFT, false);
	setCanCastle(Turn::WHITE(), Side::RIGHT, false);
	setCanCastle(Turn::BLACK(), Side::LEFT, false);
	setCanCastle(Turn::BLACK(), Side::RIGHT, false);

	setHalfMoveClock(0);
	setMoveNumber(1);
	setEnpeasentColumn(NO_ENPEASENT_COLUMN);
}

GameConfiguration GameConfiguration::mirror() const {
	GameConfiguration result;

	result.setTurn(!getTurn());
	result.setEnpeasentColumn(getEnpeasentColumn());
	result.setHalfMoveClock(getHalfMoveClock());
	result.setMoveNumber(getMoveNumber());

	FOR_POSITION_64(pos) {
		result.setPieceAt(pos.verticalFlip(), !getOwnerAt(pos), getPieceAt(pos));
	}

	FOR_TURN(turn) {
		FOR_SIDE(side) {
			result.setCanCastle(!turn, !side, getCanCastle(turn,side));
		}
	}

	return result;
}



GameConfiguration::GameConfiguration(std::string ForsythEdwardsNotation)
:GameConfiguration() {
	istringstream ss(ForsythEdwardsNotation);

	// Pieces
	string pieces;
	ss >> pieces;
	int r = 0;
	int c = 0;
	for (char ch : pieces) {
		if (ch == '/') {
			r++;
			_ASSERTE(c == 8);
			c = 0;
			continue;
		}
		if ('1' <= ch && ch <= '8') {
			c += ch - '0';
			continue;
		}

		setPieceAt(Position(r, c), Turn::fromChar(ch), Piece::fromChar(ch));
		c++;
	}
	
	//turn
	string turn;
	ss >> turn;
	setTurn(turn == "w" ? Turn::WHITE(): Turn::BLACK());
	

	//castling
	string castling;
	ss >> castling;
	if (castling != "-") {
		for (char ch : castling) {
			if (ch == 'K') {
				setCanCastle(Turn::WHITE(), Side::RIGHT, true);
			} else if (ch == 'Q') {
				setCanCastle(Turn::WHITE(), Side::LEFT, true);
			} else 	if (ch == 'k') {
				setCanCastle(Turn::BLACK(), Side::RIGHT, true);
			} else if (ch == 'q') {
				setCanCastle(Turn::BLACK(), Side::LEFT, true);
			}
		}
	}
	
	//enpeasnet
	string enpeasent;
	ss >> enpeasent;
	if (enpeasent != "-") {
		setEnpeasentColumn(enpeasent[0]-'a');
	}

	//Turn counts
	int halfTurns;
	if (ss >> halfTurns) { //OPTIONAL turn counts
		_ASSERTE(halfTurns >= 0);
		setHalfMoveClock(halfTurns);

		int fullTurns;
		ss >> fullTurns;
		_ASSERTE(fullTurns >= 0);
		if (fullTurns) {
			setMoveNumber(fullTurns);
		}
	}
}



GameConfiguration::~GameConfiguration() {}

const int GameConfiguration::NO_ENPEASENT_COLUMN = 8;

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
	setPieceAt(position, Turn::BLACK(), Piece::EMPTY());
}


Turn GameConfiguration::getOwnerAt(Position position) const {
	return owners[position.index()];
}

#pragma warning(disable:4800)//force to bool
bool GameConfiguration::getCanCastle(Turn turn, Side side) const {
	return canCastle[turn.asIndex()][(bool)side];
}
void GameConfiguration::setCanCastle(Turn turn, Side side, bool value) {
	canCastle[turn.asIndex()][(bool)side] = value;
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

string GameConfiguration::str_min() const {
	string res;

	//PIECES
	FOR_8(r) {
		int empties = 0;
		for (int c = 0; c < 8; ++c) {
			Position pos(r, c);
			if (getPieceAt(pos) != Piece::EMPTY()) {
				if (empties > 0) {
					res += '0' + empties;
					empties = 0;
				}
				res += ChessUtils::charFromPieceTurn(getOwnerAt(pos), getPieceAt(pos));
			} else {
				empties++;
			}
		}
		if (empties > 0) {
			res += '0' + empties;
			empties = 0;
		}

		if (r != 7) {
			res += '/';
		}
	}
	res += ' ';

	//Turn
	res += getTurn() == Turn::WHITE()? 'w' : 'b';
	res += ' ';

	//Castling
	string castleStr;
	if (getCanCastle(Turn::WHITE(), Side::RIGHT)) {
		castleStr += 'K';
	}
	if (getCanCastle(Turn::WHITE(), Side::LEFT)) {
		castleStr += 'Q';
	}
	if (getCanCastle(Turn::BLACK(), Side::RIGHT)) {
		castleStr += 'k';
	}
	if (getCanCastle(Turn::BLACK(), Side::LEFT)) {
		castleStr += 'q';
	}

	if (castleStr == "") {
		castleStr = "-";
	}
	res += castleStr;
	res += ' ';

	//enpeasent
	if (getEnpeasentColumn() != NO_ENPEASENT_COLUMN) {
		res += 'a' + getEnpeasentColumn();
		res += getTurn() == Turn::WHITE()? '6' : '3';
	} else {
		res += '-';
	}

	return res;
}

string GameConfiguration::str() const {
	string res = str_min();
	res += ' ';

	// counts
	res += to_string(getHalfMoveClock());
	res += ' ';
	res += to_string(getMoveNumber());


	return res;
}

