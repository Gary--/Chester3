#include <iostream>
#include "Position.h"
#include "BitBoard.h"
#include "Game.h"
#include "perft.h"
#include <time.h>
#include "attack_fields.h"

using namespace std;

int main() {
	//Game::init();
	clock_t start = clock();
	Perft::perftLazy("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 5);
	time_t end = clock();
	cout << "Time: " << (float(end - start) / CLOCKS_PER_SEC) << endl;
	system("pause");
	//cout << AttackFields::castleEmptySquares(Turn::WHITE, Side::LEFT).AsInt64() << endl;
	return 0;
}