#include "static_exchange.h"

namespace {


	int8_t SEE[7][256][256] = { 0 };

	int8_t SEE_min[256][256] = { 0 };

	bool inited = false;
}


void SEE::init() {
	if (inited) {
		return;
	}
	inited = true;
}