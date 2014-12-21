#include "GameConfiguration.h"
#include <sstream>
#include "Game.h"
#include "AttackFields.h"

using namespace std;

namespace {
	bool inited = false;
}

void GameConfiguration::init() {
	if (inited) {
		return;
	}
	inited = true;
	AttackFields::init();// Needed for move generation and validation
}

GameConfiguration::GameConfiguration() 
{
	init();
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
		result.setPieceAt(pos.mirror(), !getOwnerAt(pos), getPieceAt(pos));
	}

	FOR_TURN(turn) {
		FOR_SIDE(side) {
			result.setCanCastle(!turn, !side, getCanCastle(turn,side));
		}
	}

	return result;
}



GameConfiguration::GameConfiguration(const std::string ForsythEdwardsNotation)
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
void GameConfiguration::setTurn(const Turn turn) {
	this->turn = turn;
}

Piece GameConfiguration::getPieceAt(const Position position) const {
	return pieces[position.index()];
}
void GameConfiguration::setPieceAt(const Position position, const Turn turn, const Piece piece) {
	pieces[position.index()] = piece;
	owners[position.index()] = turn;
}

void GameConfiguration::clearPieceAt(const Position position) {
	setPieceAt(position, Turn::BLACK(), Piece::EMPTY());
}


Turn GameConfiguration::getOwnerAt(const Position position) const {
	return owners[position.index()];
}

#pragma warning(disable:4800)//force to bool
bool GameConfiguration::getCanCastle(const Turn turn, const Side side) const {
	return canCastle[turn.asIndex()][(bool)side];
}
void GameConfiguration::setCanCastle(const Turn turn, const Side side, const bool value) {
	canCastle[turn.asIndex()][(bool)side] = value;
}
#pragma warning(default:4800)

int GameConfiguration::getHalfMoveClock() const {
	return halfMoveClock;
}
void GameConfiguration::setHalfMoveClock(const int value) {
	halfMoveClock = value;
}

int GameConfiguration::getMoveNumber() const {
	return moveNumber;
}
void GameConfiguration::setMoveNumber(const int value) {
	moveNumber = value;
}

int GameConfiguration::getEnpeasentColumn() const {
	return enpeasentColumn;
}
void GameConfiguration::setEnpeasentColumn(const int value) {
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
				res += getPieceAt(pos).asChar(getOwnerAt(pos));
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
	res += getTurn().isWhite()? 'w' : 'b';
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
		res += getTurn().isWhite()? '6' : '3';
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


BitBoard GameConfiguration::getPieces(const Turn turn,const Piece piece) const {
	BitBoard result;

	FOR_POSITION_64(pos) {
		if (getOwnerAt(pos) == turn && getPieceAt(pos) == piece) {
			result |= pos.asSingletonBitboard();
		}
	}

	return result;
}

BitBoard GameConfiguration::getPlayerPieces(const Turn turn) const {
	BitBoard result;
	FOR_PIECE_ALL(piece) {
		result |= getPieces(turn, piece);
	}
	return result;
}

BitBoard GameConfiguration::getAllPieces() const {
	return getPlayerPieces(Turn::WHITE()) | getPlayerPieces(Turn::BLACK());
}

bool GameConfiguration::isValid() const {
	FOR_TURN(turn) {
		// 1 king per side
		if (getPieces(turn, Piece::KING()).count() != 1) {
			return false;
		}

		// No pawns can be in first or last rank
		const BitBoard pawns = getPieces(turn, Piece::PAWN());
		if ((pawns&BitBoard::rowBits(0) | (pawns&BitBoard::rowBits(7))).isNotEmpty()) {
			return false;
		}
	}

	if (kingIsThreatened(!getTurn())) {
		return false;
	}

	return true;
}

bool GameConfiguration::posAttackedByJump(const Position position, const Turn turn) const{
	return (AttackFields::kingTargs(position) & getPieces(turn, Piece::KING())).isNotEmpty() ||
		(AttackFields::knightTargs(position) & getPieces(turn, Piece::KNIGHT())).isNotEmpty() ||
		(AttackFields::pawnTargs(position, !turn) & getPieces(turn, Piece::PAWN())).isNotEmpty();
}

bool GameConfiguration::posAttackedByLOS(const Position position, const Turn turn) const{
	const BitBoard ALL = getAllPieces();
	return (AttackFields::bishopTargs(position, ALL) & (getPieces(turn, Piece::BISHOP()) | getPieces(turn, Piece::QUEEN()))).isNotEmpty() ||
		(AttackFields::rookTargs(position, ALL) & (getPieces(turn, Piece::ROOK()) | getPieces(turn, Piece::QUEEN()))).isNotEmpty();
}

bool GameConfiguration::posAttackedBy(const Position position, const Turn turn) const{
	return posAttackedByJump(position, turn) || posAttackedByLOS(position, turn);
}

bool GameConfiguration::kingIsThreatened(const Turn turn) const{
	const Position kingPos = getPieces(turn, Piece::KING()).ToPosition();

	return posAttackedBy(kingPos, !turn);
}

const GameConfiguration GameConfiguration::INITIAL = GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");