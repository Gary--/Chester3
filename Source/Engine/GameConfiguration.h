#pragma once
#include "Position.h"
#include "BitBoard.h"
#include "Chess.h"
#include <string>
#include "Move.h"
#include "GameConfiguration_MoveIterator.h"
struct GameConfiguration {

	
public:
	GameConfiguration();
	GameConfiguration(std::string ForsythEdwardsNotation);
	~GameConfiguration();

	// Returns the mirrored position. 
	GameConfiguration mirror() const;

	// Clears castling and enpeasent flags if none are available.
	void clean();

	// Iterator generator for the legal moves for the turn player in this position.
	GameConfiguration_MoveIterator_Generator getMoves() const;

	// Get the move matching the given string. Example: e1e2, e7e8q (promotion)
	Move getMoveUciString(std::string uciString);

	// Get the move matching the given string.
	Move getMoveEpdString(std::string epdString);

	// Alters the configuration to what it would be after making the move.
	void makeMove(Move move);

	// The turn player.
	Turn getTurn() const;

	// Set the turn player.
	void setTurn(Turn turn);

	// Get the piece at the given position.
	Piece getPieceAt(Position position) const;

	// Get the owner of the piece at the given position. Unspecified if getPieceAt(position)==Piece::EMPTY()
	Turn getOwnerAt(Position position) const;

	// Set position to contain the piece owned by turn.
	void setPieceAt(Position position, Turn turn, Piece piece);

	// Set the piece type at the position to EMPTY()
	void clearPieceAt(Position position);

	// Pieces owned by turn of that type.
	BitBoard getPieces(Turn turn, Piece piece) const;

	// All pieces owned by turn.
	BitBoard getPlayerPieces(Turn turn) const;

	// All pieces on the board.
	BitBoard getAllPieces() const;

	// Castling rights.
	bool getCanCastle(Turn turn, Side side) const;

	// Castling rights.
	void setCanCastle(Turn turn, Side side, bool value);
	
	// Number of moves since the last capture/pawn push. 0 if the previous move was.
	int getHalfMoveClock() const;

	// Number of moves since the last capture/pawn push. 0 if the previous move was.
	void setHalfMoveClock(int value);

	// Starts at 1. Incremented after Black's move.
	int getMoveNumber() const;

	// Starts at 1. Incremented after Black's move.
	void setMoveNumber(int value);

	// Which column the turn player can EP to. NO_ENPEASENT_COLUMN if none available.
	int getEnpeasentColumn() const;

	// Which column the turn player can EP to. NO_ENPEASENT_COLUMN if none available.
	void setEnpeasentColumn(int value);

	// FEN representation.
	std::string str() const;

	// FEN representation without turn counts.
	std::string str_min() const;

	// Is this a legal chess position?
	// Has 1 king each, no pawns on rank1/rank8, cannot capture enemy king.
	bool isValid() const;

	//"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
	const static GameConfiguration INITIAL;
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

	void makeMoveImpl(Move move);
};

