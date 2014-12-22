#pragma once
#include "BitBoard.h"

class BitBoard_Position_Iterator {
public:
	Position operator*() const;
	void operator++();
	bool operator!=(const BitBoard_Position_Iterator& other) const;
private:
	explicit BitBoard_Position_Iterator(const  BitBoard bit, const  BitBoard left);
	friend class BitBoard;
	BitBoard bb, left;
};
