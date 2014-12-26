#include "PV_Node.h"

using namespace std;

PV_Node::PV_Node(Move move, PV_Node next) {
	this->move = move;
	this->next = make_shared<PV_Node>(next);
}

PV_Node::PV_Node() {
	this->move = Move::INVALID();
	this->next = nullptr;
}


PV_Node::~PV_Node() {}
