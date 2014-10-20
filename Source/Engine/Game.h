#pragma once

#include "BitBoard.h"
#include "Position.h"
#include "chess_consts.h"
#include "GameConfiguration.h"
#include "GameState.h"
#include <cstdint>
#include "Move.h"

class Game {
public:
	//Initing
	static void init();
	static void configure(GameConfiguration conf);


	//Game state query
	static Turn getTurn();
	static BitBoard getPieces(Turn turn, Position position);
	static BitBoard getAllPieces();
	static BitBoard getPlayerPieces(Turn turn);
	static Piece getPieceAt(Position position);

	static bool getCastle(Turn turn, Side side);
	static bool isInCheck();
	static GameState getState();

	static uint64_t getHash();
	static int getHalfMoveCount();
	static int getMoveNumber();

	//Move making
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

