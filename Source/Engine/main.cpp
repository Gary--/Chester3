
#include "ConsoleMode.h"
#include "StrengthTest.h"
#include <fstream>
using namespace std;

int main() {

	std::ifstream infile("TestPositions\\Win_at_Chess.epd");

	StrengthTest::epdTest(infile, cout);
	//ConsoleMode::run();
	system("pause");
}