#pragma once
#include "Move.h"

class Evaluation {
public:
	// [turn's mat - other's mat] and adjustments
	// Turn is just perspective.

	static double lateness();// 1 for full on lategame brawl, 0 for just started
	static int materialBalance(Turn turn);
	static int material(Turn turn);
	static int mobility(Turn turn);
	static int kingDanger(Turn turn);// positive values Turn's king is in danger
	static int pawns(Turn turn);
	static int center(Turn turn);
	static int misc(Turn turn);

	static void synchronize();
	static void notifyMove(Move move, Turn turn);
	static void notifyUndoMove(Move move, Turn turn);
private:

	static void synchronizeMaterial();
	static void notifyMoveMaterial(Move move, Turn turn);
	static void notifyUndoMoveMaterial(Move move, Turn turn);
};