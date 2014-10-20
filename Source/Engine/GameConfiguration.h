#pragma once
#include "Position.h"
#include "BitBoard.h"
#include "chess_consts.h"
#include <string>
struct GameConfiguration {

	
public:
	GameConfiguration();
	GameConfiguration(std::string ForsythEdwardsNotation);
	~GameConfiguration();

	Turn getTurn() const;
	void setTurn(Turn turn);

	Piece getPieceAt(Position position) const;
	Turn getOwnerAt(Position position) const;
	void setPieceAt(Position position, Turn turn, Piece piece);
	void clearPieceAt(Position position);

	bool getCanCastle(Turn turn, Side side) const;
	void setCanCastle(Turn turn, Side side, bool value);
	

	int getHalfMoveClock() const;
	void setHalfMoveClock(int value);

	int getMoveNumber() const;
	void setMoveNumber(int value);

	int getEnpeasentColumn() const;
	void setEnpeasentColumn(int value);

	std::string str() const;



	const static int NO_ENPEASENT_COLUMN;
private:
	Piece pieces[64];
	Turn owners[64];

	Turn turn;
	bool canCastle[2][2];
	int halfMoveClock;
	int moveNumber;
	int enpeasentColumn;


};

