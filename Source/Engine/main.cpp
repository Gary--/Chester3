
#include "ConsoleMode.h"
#include "StrengthTest.h"
#include <fstream>
#include "UCI.h"
using namespace std;

int main() {
	string modestr;
	while (cin >> modestr) {
		if (modestr == "uci") {
			UCI::run();
			break;
		}
	}

	//std::ifstream infile("TestPositions\\Win_at_Chess.epd");

	//StrengthTest::epdTest(infile, cout);
	////ConsoleMode::run();
	//system("pause");
}