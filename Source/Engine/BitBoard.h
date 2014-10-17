#pragma once
#include <cstdint>
#include <string>

// Represents a set of up to Positions
struct BitBoard
{


private:
	uint64_t value;
	BitBoard();
public:
	BitBoard(uint64_t value);
	~BitBoard();

	BitBoard const operator|(const BitBoard other);

	
	friend bool const operator==(const BitBoard bb1, const BitBoard bb2);
	const std::string str();
};

