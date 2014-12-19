#pragma once
#include "Move.h"
#include <string>
class MoveResolver {
public:

	// Returns matching move in Game. Example: e2e3, e7e8q. Move::INVALID() if none.
	static Move resolveUCI(std::string uciString);



private:
};

