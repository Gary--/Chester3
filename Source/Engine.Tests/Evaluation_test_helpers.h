#pragma once
#include "GameConfiguration.h"
#include <string>
void confSync(GameConfiguration conf);
void confSync(const char* FEN);

extern std::string fenSamples[6809];