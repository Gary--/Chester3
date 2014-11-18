#pragma once
#include "Move.h"

class Evaluation {
public:
	static void init();

	// 1 for full on lategame brawl, 0 for just started
	static double lateness();

	// Static piece score values.
	static int material(Turn turn);

	// [turn's mat - other's mat] and adjustments
	// Positive for white advantage.
	static int materialBalance();
	
	// Positive for white advantage.
	static int mobility();

	static int kingDanger(Turn turn);// positive values Turn's king is in danger
	static int pawns(Turn turn);
	static int center(Turn turn);
	static int misc(Turn turn);

	static void synchronize();
	static void notifyMove(Move move, Turn turn);
	static void notifyUndoMove(Move move, Turn turn);

	// Methods exposed for testing purposes
	static int DEBUG_knightExactMobility(Turn turn);
	static int DEBUG_knightRelativeMobility(Turn turn);
	static int DEBUG_bishopExactMobility(Turn turn);
	static int DEBUG_bishopRelativeMobility(Turn turn);
	static int DEBUG_rookExactMobility(Turn turn);
	static int DEBUG_rookRelativeMobility(Turn turn);
private:

	static void synchronizeMaterial();
	static void notifyMoveMaterial(Move move, Turn turn);
	static void notifyUndoMoveMaterial(Move move, Turn turn);


	static void initPawns();

	// If we have a pawn here, where opposite pawns could be to stop us
	static BitBoard opposingPawns(Position position, Turn turn);
};