#pragma once

#include "BitBoard.h"
#include "Position.h"
#include "chess_consts.h"
#include "GameConfiguration.h"
#include "GameResult.h"
#include <cstdint>
#include "Move.h"
#include "GameHash.h"

class Game {
public:
	//Initing / Configure
	static void init();
	static void reset();//Invalidates the position.
	static void configure(const GameConfiguration& conf);
	static GameConfiguration getGameConfiguration();

	//Game state query
	static Turn getTurn();
	static BitBoard getPieces(Turn turn, Piece piece);
	static BitBoard getAllPieces();
	static BitBoard getPlayerPieces(Turn turn);
	static Piece getPieceAt(Position position);
	static Turn getOwnerAt(Position position);

	static bool getCanCastle(Turn turn, Side side);
	static int getEnpeasentColumn();

	//static bool getCheck();
	static GameResult getState();

	static uint64_t getHash();
	static int getHalfMoveClock();
	static int getMoveNumber();
	//static int getRepeatCount(uint64_t hash);

	////Move making
	//static void computeMoves();
	//static void computeOnlyMaterialChangeMoves();
	//static int numValidMoves();
	//static Move getMove(int n);//0<= n <numValidMoves()

	//static void makeMove(Move move);
	//static void undoMove();
private:
	// === FIELDS
	static Turn curTurn;
	static BitBoard WK, WQ, WR, WB, WN, WP;
	static BitBoard BK, BQ, BR, BB, BN, BP;
	static BitBoard WA, BA;
	static BitBoard ALL;
	static Piece pieces[64];

	static GameResult result;
	static GameHash hash;
	static int halfMoveCount;
	static int moveCount;


	// === Private getters
	
	static BitBoard* s(Turn turn, Piece piece);
	static BitBoard* sp(Turn turn);
	static void setPieceAt(Position position, Piece piece);
	static void toggleBit(Turn turn, Position position, Piece piece);

	// === Private setters


	Game();
	~Game();
};

