#pragma once
#include "BitBoard.h"



class BitBoard_BitBoard_Iterator {
public:
	BitBoard operator*() const;
	void operator++();
	bool operator!=(const BitBoard_BitBoard_Iterator& other) const;
private:
	explicit BitBoard_BitBoard_Iterator(const  BitBoard bit, const  BitBoard left);
	friend class BitBoard_BitBoard_Iterator_Generator;
	BitBoard bb, left;
};

class BitBoard_BitBoard_Iterator_Generator {
public:
	BitBoard_BitBoard_Iterator begin() const;
	BitBoard_BitBoard_Iterator end() const;
private:
	friend class BitBoard;
	friend class BitBoard_Position_Iterator_Generator;

	BitBoard_BitBoard_Iterator_Generator(BitBoard bitBoard);

	BitBoard bb;
};

class BitBoard_Position_Iterator {
public:
	Position operator*() const;
	void operator++();
	bool operator!=(const BitBoard_Position_Iterator& other) const;
private:
	explicit BitBoard_Position_Iterator(BitBoard_BitBoard_Iterator it);
	friend class BitBoard_Position_Iterator_Generator;
	BitBoard_BitBoard_Iterator it;
};

class BitBoard_Position_Iterator_Generator {
public:
	BitBoard_Position_Iterator begin() const;
	BitBoard_Position_Iterator end() const;
private:
	friend class BitBoard;
	explicit BitBoard_Position_Iterator_Generator(BitBoard_BitBoard_Iterator_Generator gen);
	BitBoard_BitBoard_Iterator_Generator gen;
};