#pragma once
#include "PV_Node.h"

class Search_Parameters {

public:
	Search_Parameters();
	bool isQuiesce() const;

	int alpha, beta;
	int ply;

	// Depth remaining.
	int depth;
	PV_Node pv;

	static const int QUIESCE_DEPTH = -1000;
	static const int MAX_NORMAL_PLY = 20;
	static const int MAX_QUIESCE_PLY = 6;
private:
};