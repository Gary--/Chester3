#pragma once

#include "Position.h"
#include "BitBoard.h"

//NO FUNCTION AVAILABLE BEFORE MAIN
namespace AttackFields {
	void init();


	BitBoard kingTargs(Position position);
	BitBoard knightTargs(Position position);
	BitBoard pawnTargs(Turn turn, Position position);
	BitBoard bishopTargs(Position position, BitBoard blockers);
	BitBoard rookTargs(Position position, BitBoard blockers);
	BitBoard queenTargs(Position position, BitBoard blockers);

	////SLIDERS.
	//BB pinnedTargs(int kingInd, int pinnedPiece);
	//BB blockingTargs(int kingInd, int attacker);
	//BB lineThrough(int ind1, int ind2);//Line drawn through these locations. Undefined if not in line

	////CASTLING
	////CASTLING. side: false=queenSide, true=kingSide
	//int kingStartInd(Turn player);
	//int kingCastleDestInd(Turn player, bool side);
	//int rookStartInd(Turn player, bool side);
	//int rookCastleDestInd(Turn player, bool side);
	//BB emptyCastleSquares(Turn player, bool side);


	////PAWNS
	//extern const BB pawnPromoZone;
	//BB pawnStartRow(Turn player);
	//BB pawnTargs(Turn player, int ind);
	//BB enpeasentDest(Turn player, int enpeasentColumn);//TODO: as ind
	//BB enpeasentFrom(Turn player, int enpeasentColumn);//TODO: as ind
	//BB enpeasentCaptured(Turn player, int enpeasentColumn);//TODO: as ind

	////MISC
	//BB bishopForward(Turn player, int ind);
	//BB fullCross(int ind);
	//BB fullX(int ind);

	//extern const BB whiteSquares;
	//extern const BB blackSquares;

	////Places where if an enemy pawn were standing it could come kill this.
	//BB interferingPawns(Turn player, int ind);

	////Where enempy pawns are that would prevent ind from being a passed pawn.
	//BB passingPawnStoppers(Turn player, int ind);
}

