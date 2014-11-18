#include <iostream>
#include "BitBoard.h"

using namespace std;

int main() {
	cout << BitBoard(0x00007E7E7E7E0000ULL).str() << endl;
	system("pause");
	return 0;
}