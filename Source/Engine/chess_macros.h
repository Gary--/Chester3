#pragma once

#include "BitBoard.h"
#include "Position.h"

#define FOR_8(x) for (int x = 0; x < 8;++x)
#define FOR_64(x) for (int x = 0; x < 64;++x)

#define FOR_BIT(VAR,BITS) for(BitBoard BITS_COPY=(BITS),VAR=BitBoard::EMPTY; (VAR=BITS_COPY.LSB())!=BitBoard::EMPTY; BITS_COPY^=VAR)

//#define FOR_POSITION(VAR,BITS) 