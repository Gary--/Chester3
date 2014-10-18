#include "ChessAssert.h"
#include <crtdbg.h>


namespace ChessAssert {
	void Assert_64(int x) {
		_ASSERTE(0 <= x && x < 64);
	}


	void Assert_8(int x) {
		_ASSERTE(0 <= x && x < 8);
	}
}