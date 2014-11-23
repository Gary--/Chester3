#include "ChessAssert.h"
#include <crtdbg.h>


namespace ChessAssert {
	void Assert_64(const int x) {
		_ASSERTE(0 <= x && x < 64);
	}


	void Assert_8(const int x) {
		_ASSERTE(0 <= x && x < 8);
	}
}