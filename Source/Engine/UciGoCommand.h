#pragma once
#include <string>

struct UciGoCommand {
public:
	UciGoCommand();
	explicit UciGoCommand(std::string str);
	~UciGoCommand();


	bool ponder;
	bool infinite;

private:
};

