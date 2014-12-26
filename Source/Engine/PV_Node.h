#pragma once
#include <memory>
#include "Move.h"
class PV_Node {
public:
	Move move;
	std::shared_ptr<PV_Node> next;

	PV_Node();
	PV_Node(Move move, PV_Node next);
	~PV_Node();
};

