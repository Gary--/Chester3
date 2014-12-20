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

private:
	GameConfiguration gameConf;

	std::string id;
	std::string bestMoveString;

	std::vector<std::string> comments;
};

