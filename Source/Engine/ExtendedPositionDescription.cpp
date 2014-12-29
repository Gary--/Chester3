#include "ExtendedPositionDescription.h"
#include <sstream>
#include <vector>
#include "StringUtils.h"
using namespace std;

ExtendedPositionDescription::ExtendedPositionDescription() {}

ExtendedPositionDescription::ExtendedPositionDescription(std::string epdString) {
	istringstream ss(epdString);

	{
		string FEN;
		for (int i = 0; i < 4; i++) {
			string part;
			ss >> part;
			FEN += part + ' ';
		}
		FEN.pop_back();
		gameConf = GameConfiguration(FEN);
	}

	vector <string> items = StringUtils::split(StringUtils::getUnread(ss), ';');
	for (auto item : items) {
		processOperation(item);
	}

}

ExtendedPositionDescription::~ExtendedPositionDescription() {}

GameConfiguration ExtendedPositionDescription::getGameConfiguration() const {
	return gameConf;
}

void ExtendedPositionDescription::processOperation(std::string str) {
	istringstream ss(str);

	string opcode;
	ss >> opcode;

	if (opcode == "bm") {
		string moveStr;
		while (ss >> moveStr) {
			Move move = gameConf.getMoveEpdString(moveStr);
			bestMoves.push_back(move);
		}
	}
}
