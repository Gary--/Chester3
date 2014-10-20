#include <iostream>
#include "Position.h"
#include "BitBoard.h"
#include "chess_consts.h"
using namespace std;

int main() {

	cout << BitBoard::FULL().AsInt64() << endl;
	return 0;
}