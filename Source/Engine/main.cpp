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
	int count = Perft::perftFull("r3k2r/p1ppqpb1/bn2P1p1/4N3/Np2n3/5Q1p/PPPBB1PP/R3K2R b KQkq -", 5);
	time_t end = clock();
	cout << "# of leaves: " << count << endl;
	cout << "Time: " << (float(end - start) / CLOCKS_PER_SEC) << endl;
	system("pause");
	//cout << AttackFields::castleEmptySquares(Turn::WHITE, Side::LEFT).AsInt64() << endl;
	return 0;
}