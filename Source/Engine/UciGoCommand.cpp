#include "UciGoCommand.h"
#include <sstream>

using namespace std;

UciGoCommand::UciGoCommand() {
	ponder = false;
	infinite = false;
}

UciGoCommand::UciGoCommand(std::string str) :UciGoCommand() {
	istringstream cin(str);

	string op;
	while (cin >> op) {
		if (op == "ponder") {
			ponder = true;
		} else if (op == "infinite") {
			infinite = true;
		}
	}
}


UciGoCommand::~UciGoCommand() {}
