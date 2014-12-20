#include "ExtendedPositionDescription.h"
#include <sstream>

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
}


ExtendedPositionDescription::~ExtendedPositionDescription() {}

GameConfiguration ExtendedPositionDescription::getGameConfiguration() const {
	return gameConf;
}
