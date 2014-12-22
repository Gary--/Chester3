#pragma once
#include "Position.h"
#include "BitBoard.h"
#include "Chess.h"
#include <string>
#include "Move.h"

struct GameConfiguration {

	
public:
	GameConfiguration();
	GameConfiguration(std::string ForsythEdwardsNotation);
	~GameConfiguration();

	GameConfiguration mirror() const;

	// Clears castling and enpeasent flags if none are available.
	void clean();

	// Alters the configuration to what it would be after making the move.
	void makeMove(Move move);

	Turn getTurn() const;
	void setTurn(Turn turn);

	Piece getPieceAt(Position position) const;
	Turn getOwnerAt(Position position) const;
	void setPieceAt(Position position, Turn turn, Piece piece);
	void clearPieceAt(Position position);
	BitBoard getPieces(Turn turn, Piece piece) const;
	BitBoard getPlayerPieces(Turn turn) const;
	BitBoard getAllPieces() const;

	bool getCanCastle(Turn turn, Side side) const;
	void setCanCastle(Turn turn, Side side, bool value);
	

	int getHalfMoveClock() const;
	void setHalfMoveClock(int value);

	int getMoveNumber() const;
	void setMoveNumber(int value);

	int getEnpeasentColumn() const;
	void setEnpeasentColumn(int value);

	std::string str() const;
	std::string str_min() const;//without turn counts

	// Is this a legal chess position?
	// Has 1 king each, no pawns on rank1/rank8, cannot capture enemy king.
	bool isValid() const;


	const static GameConfiguration INITIAL;//"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
	const static int NO_ENPEASENT_COLUMN;
private:
	friend class GameConfiguration_MoveIterator_Generator;
	static void init();

	Piece pieces[64];
	Turn owners[64];

	Turn turn;
	bool canCastle[2][2];
	int halfMoveClock;
	int moveNumber;
	int enpeasentColumn;

	bool posAttackedBy(Position position, Turn turn) const;//Does turn attack the given position?
	bool posAttackedByJump(Position position, Turn turn) const;
	bool posAttackedByLOS(Position position, Turn turn) const;

	// Is turn's king under attack?
	bool kingIsThreatened(const Turn turn) const;

};

