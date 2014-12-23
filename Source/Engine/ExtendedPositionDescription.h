#pragma once
#include "GameConfiguration.h"
#include <string>
#include "Move.h"
#include <vector>

class ExtendedPositionDescription {
public:
	ExtendedPositionDescription();

	explicit ExtendedPositionDescription(std::string epdString);

	~ExtendedPositionDescription();

	GameConfiguration getGameConfiguration() const;

	Move bestMove;
	GameConfiguration gameConf;
private:


	void processOperation(std::string str);
};

