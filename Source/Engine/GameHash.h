#pragma once
#include "chess_consts.h"
#include <cstdint>
#include "GameConfiguration.h"

class GameHash {


public:
	explicit GameHash(const GameConfiguration& conf);
	GameHash();//undefined
	static void init();

	void toggleTurn();
	void togglePiece(Position position,Turn player, Piece piece );
	void setEnpeasent(int column);
	void voidCastle(Turn player, Side side);

	bool getCanCastle(Turn player, Side side) const;
	int getEnpeasent() const;
	//===== gets
	uint64_t toInt64() const;


private:
	
	uint64_t hash;
	int enpeasent;
	bool canCastle[2][2];





};

