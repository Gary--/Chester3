#include "display.h"
#include "Game.h"
#include <iostream>
#include "chess_consts.h"

using namespace std;


void Display::display() {
	cout << Game::getFEN() << endl;
	if (Game::getCheck()) {
		cout << "CHECK. ";
	}
	cout << (Game::getTurn() == Turn::WHITE() ? "White" : "Black") << "'s turn." << endl;
	cout << endl;
	for (int r = 0; r < 8; r++) {
		cout << char('8' - r) << " ";
		for (int c = 0; c < 8; c++) {
			Position pos(r, c);
			cout << Game::getPieceAt(pos).asChar(Game::getOwnerAt(pos)) << endl;
		}
		cout << endl;
	}
	cout << endl;
	cout << "  ";
	for (char l = 'A'; l <= 'H'; ++l) {
		cout << l;
	}
	cout << endl;

	

}