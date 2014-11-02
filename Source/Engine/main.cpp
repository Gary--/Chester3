#include <iostream>
#include "Position.h"
#include "BitBoard.h"
#include "Game.h"
#include "perft.h"
#include <time.h>
#include "attack_fields.h"

using namespace std;


namespace {
	BitBoard diag7() {
		return BitBoard(0x102040810204080);
	}
	BitBoard diag8to14() {
		return BitBoard(0xfefcf8f0e0c08000);
	}
	BitBoard diag0to7() {
		return BitBoard(~(diag7() | diag8to14()));
	}
}
int main() {

 
	return 0;
}