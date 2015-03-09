#include <iostream>
#include <string>
#include "UCI.h"

using namespace std;

int main() {


	string mode;
	while (cin >> mode) {
		if (mode == "uci") {
			UCI::run();
			break;
		}
	}

	//std::ifstream infile("TestPositions\\Win_at_Chess.epd");

	//StrengthTest::epdTest(infile, cout);
	////ConsoleMode::run();
	//system("pause");
}