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
	int count = Perft::perftLazy("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 6);
	time_t end = clock();
	cout << "# of leaves: " << count << endl;
	cout << "Time: " << (float(end - start) / CLOCKS_PER_SEC) << endl;
	system("pause");
	//cout << AttackFields::castleEmptySquares(Turn::WHITE, Side::LEFT).AsInt64() << endl;
	return 0;
}