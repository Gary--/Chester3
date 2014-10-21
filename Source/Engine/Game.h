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
	static void configure(GameConfiguration conf);
	static GameConfiguration getGameConfiguration();

	//Game state query
	static Turn getTurn();
	static BitBoard getPieces(Turn turn, Position position);
	static BitBoard getAllPieces();
	static BitBoard getPlayerPieces(Turn turn);
	static Piece getPieceAt(Position position);
	static Turn getOwnerAt(Position position);

	static bool getCastle(Turn turn, Side side);
	static bool getCheck();
	static GameResult getState();

	static uint64_t getHash();
	static int getHalfMoveCount();
	static int getMoveNumber();
	static int getRepeatCount(uint64_t hash);

	//Move making
	void computeMoves();
	void computeOnlyMaterialChangeMoves();
	int numValidMoves();
	Move getMove(int n);//0<= n <numValidMoves()

	static void makeMove(Move move);
	static void undoMove();
private:
	static int getEnpeasentColumn();

	static Turn turn;
	static BitBoard WK, WQ, WR, WB, WN, WP;
	static BitBoard BK, BQ, BR, BB, BN, BP;
	static BitBoard WA, BA;
	static BitBoard ALL;

	Game();
	~Game();
};

