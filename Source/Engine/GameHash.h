#pragma once
#include "chess_consts.h"
#include <cstdint>
#include "GameConfiguration.h"

class GameHash {


public:
	explicit GameHash(const GameConfiguration& conf);
	static void init();

	void toggleTurn();
	void togglePiece(Position position,Turn player, Piece piece );
	void setEnpeasent(int column);
	void voidCastle(Turn player, Side side);

	//===== gets
	uint64_t toInt64() const;

	//================ LOOK AWAY!
private:
	GameHash();
	uint64_t hash;
	int enpeasent;
	bool canCastle[2][2];





};

