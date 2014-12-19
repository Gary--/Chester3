#pragma once
#include "GameConfiguration.h"
#include <string>
class ExtendedPositionDescription {
public:
	ExtendedPositionDescription();

	explicit ExtendedPositionDescription(std::string epdString);

	~ExtendedPositionDescription();


private:
	GameConfiguration gameConf;
};

