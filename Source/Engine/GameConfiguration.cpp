#include "GameConfiguration.h"
#include <sstream>
#include "AttackFields.h"
#include <regex>
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
	init();
	return posAttackedByJump(position, turn) || posAttackedByLOS(position, turn);
}

bool GameConfiguration::kingIsThreatened(const Turn turn) const{
	const Position kingPos = getPieces(turn, Piece::KING()).ToPosition();

	return posAttackedBy(kingPos, !turn);
}

void GameConfiguration::makeMoveImpl(const Move move) {
	init();
	const Turn turn = getTurn();

#pragma region Unpack move
	const MoveType type = move.getType();
	const Position fromPos = move.getFrom();
	const Position toPos = move.getTo();
	const Piece piece = move.getPiece();
	const Piece targ = move.getTarg();
#pragma endregion

	clearPieceAt(fromPos);
	setPieceAt(toPos, turn, piece);
	setEnpeasentColumn(NO_ENPEASENT_COLUMN);

	if (type == MoveType::PAWN_JUMP) {
		setEnpeasentColumn(toPos.col());

	} else if (type == MoveType::ENPEASENT) {
		Position capturedPos = toPos.shiftBackward(turn);
		clearPieceAt(capturedPos);

	} else if (piece == Piece::KING()) {

		setCanCastle(turn, Side::LEFT, false);
		setCanCastle(turn, Side::RIGHT, false);

		if (type == MoveType::CASTLE_LEFT || type == MoveType::CASTLE_RIGHT) {
			int baseRow = turn.isWhite() ? 7 : 0;
			Position rookFrom(baseRow, type == MoveType::CASTLE_LEFT ? 0 : 7);
			Position rookTo(baseRow, type == MoveType::CASTLE_LEFT ? 3 : 5);

			clearPieceAt(rookFrom);
			setPieceAt(rookTo,turn, Piece::ROOK());

		}
	} else if (move.isPromotion()) {
		Piece promo = move.promotionPiece();
		setPieceAt(toPos, turn, promo);
	}

	if (toPos == Position("a1") || fromPos == Position("a1")) {
		setCanCastle(Turn::WHITE(), Side::LEFT, false);
	}
	if (toPos == Position("h1") || fromPos == Position("h1")) {
		setCanCastle(Turn::WHITE(), Side::RIGHT, false);
	}
	if (toPos == Position("a8") || fromPos == Position("a8")) {
		setCanCastle(Turn::BLACK(), Side::LEFT, false);
	}
	if (toPos == Position("h8") || fromPos == Position("h8")) {
		setCanCastle(Turn::BLACK(), Side::RIGHT, false);
	}

	if (turn.isBlack()) {
		setMoveNumber(getMoveNumber() + 1);
	}
	if (piece != Piece::PAWN() && targ == Piece::EMPTY()) {
		setHalfMoveClock(getHalfMoveClock() + 1);
	} else {
		setHalfMoveClock(0);
	}

	setTurn(!turn);
}

void GameConfiguration::makeMove(Move move) {
	init();
	makeMoveImpl(move);
	clean();
}

void GameConfiguration::clean() {
	bool isEnpeasent = false;
	for (Move move : getMoves()) {
		if (move.getType() == MoveType::ENPEASENT) {
			isEnpeasent = true;
		}
	}
	if (!isEnpeasent) {
		setEnpeasentColumn(NO_ENPEASENT_COLUMN);
	}


}

GameConfiguration_MoveIterator_Generator GameConfiguration::getMoves() const {
	init();
	return GameConfiguration_MoveIterator_Generator(*this);
}

Move GameConfiguration::getMoveUciString(std::string uciString) {
	for (Move move : getMoves()) {
		if (move.str() == uciString) {
			return move;
		}
	}
	return Move::INVALID();
}

Move GameConfiguration::getMoveEpdString(const std::string s) {
	const regex e("^(O-O-O|O-O)|([QKRBN]?)([abcdefgh]?)([12345678]?)(x?)([abcdefgh])([12345678])([QKRBN]?)(\\+|\\#)?$");

	smatch match;
	regex_match(s, match, e);

	if (match.empty()) {
		return Move::INVALID();
	}

	int i = 1;
	
	const string s_castle = match[i++];//(O-O-O|O-O)
	const char c_piece = match[i].length() ? match[i].str()[0] : '\0'; i++;// ([QKRBN]?)
	const char c_colFrom = match[i].length() ? match[i].str()[0] : '\0'; i++;// ([abcdefgh]?)
	const char c_rowFrom = match[i].length() ? match[i].str()[0] : '\0'; i++;// ([12345678]?)
	i++;// (x?)
	const char c_colTo = match[i].length() ? match[i].str()[0] : '\0'; i++;// ([abcdefgh])
	const char c_rowTo = match[i].length() ? match[i].str()[0] : '\0'; i++;// ([12345678])
	const char c_promoPiece = match[i].length() ? match[i].str()[0] : '\0'; i++;// ([QKRBN]?)
	i++;// (\+|\#)?


	if (s_castle.size()) {
		for (Move move : getMoves()) {
			if ((s_castle == "O-O-O" && move.getType() == MoveType::CASTLE_LEFT) ||
				(s_castle == "O-O" && move.getType() == MoveType::CASTLE_RIGHT)) {
				return move;
			}
		}

		return Move::INVALID();
	}

	const int any = -1;
	const Piece piece = c_piece ? Piece::fromChar(c_piece) : Piece::PAWN();
	const int colFrom = ('a' <= c_colFrom && c_colFrom <= 'h') ? c_colFrom - 'a' : any;
	const int rowFrom = ('1' <= c_rowFrom && c_rowFrom <= '8') ? '8' - c_rowFrom : any;
	const int colTo = c_colTo - 'a';
	const int rowTo = '8' - c_rowTo;
	const Position to(rowTo, colTo);

	const Piece promo = c_promoPiece ? Piece::fromChar(c_promoPiece) : Piece::INVALID();

	int numMatching = 0;
	Move result = Move::INVALID();
	for (Move move : getMoves()) {
		if (move.getPiece() == piece &&
			move.getTo() == to &&
			(!move.isPromotion() || move.promotionPiece() == promo) &&
			(rowFrom == any || move.getFrom().row() == rowFrom) &&
			(colFrom == any || move.getFrom().col() == colFrom)) {
			result = move;
			numMatching++;
		}
	}

	// String is ambiguous.
	if (numMatching > 1) {
		return Move::INVALID();
	}

	return result;
	//{
	//	string toRemove("x+#-");
	//	string ns;
	//	for (char c : s) {
	//		if (toRemove.find(c) == string::npos) {
	//			ns += c;
	//		}
	//	}
	//	s = ns;
	//}
	//if (s == "OOO" || s == "OO") {
	//	for (Move move : getMoves()) {
	//		if ((s == "OOO" && move.getType() == MoveType::CASTLE_LEFT) ||
	//			(s == "OO" && move.getType() == MoveType::CASTLE_RIGHT)) {
	//			return move;
	//		}

	//	}

	//	return Move::INVALID();
	//}

	//if (s.size() < 2) {
	//	return Move::INVALID();
	//}

	//Piece promo = Piece::fromChar(s.back());
	//if (promo != Piece::INVALID()) {
	//	s = s.substr(0, s.size() - 2);
	//}

	//if (s.size() < 2) {
	//	return Move::INVALID();
	//}

	//Piece piece = Piece::INVALID();
	//
	//if (s.size() > 2) {
	//	piece = Piece::fromChar(s[0]);
	//	s = s.substr(1);
	//}
	//if (piece == Piece::INVALID()) {
	//	piece == Piece::PAWN();
	//}

	//if (s.size() < 2) {
	//	return Move::INVALID();
	//}

	//Position to(s.substr(s.size() - 2));
	//s = s.substr(0, s.size() - 2);

	//int row = -1, col = -1;
	//for (char c : s) {
	//	if ('a' <= c && c <= 'h') {
	//		col = c - 'a';
	//	}

	//	if ('1' <= c && c <= '8') {
	//		row = '8' - c;
	//	}
	//}

	//int numMatching = 0;
	//Move result = Move::INVALID();
	//for (Move move : getMoves()) {
	//	if (move.getPiece() == piece &&
	//		move.getTo() == to &&
	//		(!move.isPromotion() || move.promotionPiece() == promo) &&
	//		(row == -1 || move.getFrom().row() == row) &&
	//		(col == -1 || move.getFrom().col() == col)) {
	//		result = move;
	//		numMatching++;
	//	}
	//}
	//if (numMatching > 1) {
	//	return Move::INVALID();
	//}

	//return result;
}

const GameConfiguration GameConfiguration::INITIAL = GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");