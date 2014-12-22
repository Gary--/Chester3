#pragma once

#include "BitBoard.h"
#include "Position.h"
#include "Chess.h"
#include "GameConfiguration.h"
#include <cstdint>
#include "Move.h"
#include "Game_MoveIterator.h"
#include <string>


struct Game_UndoData;
class GameMoveIteratorGenerator;
class Game {
public:

	static void configure(GameConfiguration conf);
	static GameConfiguration getGameConfiguration();
	static std::string getFEN();

	// The turn player.
	static Turn getTurn();

	// The pieces of that type owned by turn.
	static BitBoard getPieces(Turn turn, Piece piece);

	// All the pieces on the board.
	static BitBoard getAllPieces();

	// All pieces owned by turn.
	static BitBoard getPlayerPieces(Turn turn);

	// The piece type at the given position.
	static Piece getPieceAt(Position position);

	// The owner at the given position. Unspecified if getPieceAt(position)==Piece::EMPTY()
	static Turn getOwnerAt(Position position);

	// Does turn have castling rights?
	static bool getCanCastle(Turn turn, Side side);

	// Which column the turn player can enpeasent to. 8 For cannot enpeasent
	static int getEnpeasentColumn();

	// Is the turn player in check?
	static bool getCheck();

	// Hash including pieces, turn, enpeasent, caslting rights
	static uint64_t getHash();

	// How many full moves have been made.
	static int getMoveNumber();

	// Number of half moves since last capture or pawn move.
	static int getHalfMoveClock();

	// How many times this position has occurred. 1 if first time.
	static int getRepeatCount();

	// Get the move matching the given string. Example: e1e2, e7e8q (promotion)
	static Move getMoveUciString(std::string uciString);

	// Get the move matching the given string.
	static Move getMoveEpdString(std::string epdString);

	// Iterator generator to every move.
	static GameMoveIteratorGenerator getAllMoves();

	// Iterator generator to tactical moves: captures, promotions, enpeasent
	static GameMoveIteratorGenerator getTacticalMoves();

	// How many valid moves are available?
	static int getNumValidMoves();

	// A fast check of getNumValidMoves() > 0.
	static bool areMovesAvailable();
	
	// Alter the game state by making the move.
	static void makeMove(Move move);

	// Undo the previous makeMove. Returns the move being reverted.
	static Move undoMove();
private:
	static void init();
	static void reset();

	// === FIELDS
	static Turn curTurn;
	static BitBoard WK, WQ, WR, WB, WN, WP;
	static BitBoard BK, BQ, BR, BB, BN, BP;
	static BitBoard WA, BA;
	static BitBoard ALL;
	static Piece pieces[64];

	// Starts at 1. Incremented after Black's move.
	static int fullMoveCount;


#pragma region Move Manager
	static Game_UndoData cur;

	static int movePtr;

	static void resetMoveManager();
	static void addMove(Move move);
	static void addPawnMove(Move move);//accounts for promotions
	static void pushMove(Move move);// Called by makeMove to store this layer's info

	// Called at the very end of makeMove.
	static void postMoveUpdates();

	// Called by undoMove to restore this layer's info
	static void popMove();
	static bool isDefinitelyAMoveAvailable();//Tries to find a move

	static void generateAllMoves();
	static void generateTacticalMoves();
	static void generateMovesImpl(bool tacticalOnly);
	
#pragma endregion
	// === Private getters
	
	static BitBoard* s(Turn turn, Piece piece);
	static BitBoard* sp(Turn turn);
	static void setPieceAt(Position position, Piece piece);
	static void toggleBit(Turn turn, Position position, Piece piece);
	static void clearPieceAt(Position position);
	static void addPieceAt(Turn turn, Position position, Piece piece);

	// === misc
	//hypothetically, if that was the enpeasent column, could turn perform an EP?
	static bool canEnpeasent(Turn turn,int enpeasentCol);

	// === Debug
	static void integrityCheck();
	static void assertMovesAreUnique();
	

	
	static bool posAttackedBy(Position position, Turn turn);//Does turn attack the given position?
	static bool posAttackedByJump(Position position, Turn turn);
	static bool posAttackedByLOS(Position position, Turn turn);

	//For move generation only
	static BitBoard attackedByJump(Turn turn);


	Game();
	~Game();
};

