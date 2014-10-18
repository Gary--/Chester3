#include "chess_consts.h"

// === TURN ITERATOR
Turn operator!(Turn turn) {
#pragma warning(disable : 4800) //Forcing to bool
	return (Turn)(!(bool)turn);
#pragma warning(default : 4800)
}