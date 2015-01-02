#pragma once
#include <string>
#include <vector>
#include <sstream>
namespace StringUtils {
	std::vector<std::string> split(const std::string& str, char delim);
	std::string getUnread(std::istringstream& ss);

	bool startsWith(const std::string& str, const std::string& prefix);
}
