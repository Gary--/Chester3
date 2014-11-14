#pragma once
#include "Chess.h"
#include <cstdint>
#include "GameConfiguration.h"

class Game_Hash {


public:
	explicit Game_Hash(const GameConfiguration& conf);
	Game_Hash();//undefined
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

