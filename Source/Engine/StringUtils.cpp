#include "StringUtils.h"
#include <sstream>

using namespace std;

namespace {
	vector<std::string> &splitImpl(const string &s, char delim, vector<string> &elems) {
		stringstream ss(s);
		string item;
		while (std::getline(ss, item, delim)) {
			if (!item.empty()) {
				elems.push_back(item);
			}
		}
		return elems;
	}
}


vector<string> StringUtils:: split(const string &s, char delim) {
	std::vector<string> elems;
	splitImpl(s, delim, elems);
	return elems;
}

string StringUtils::getUnread(std::istringstream& ss) {
	return ss.str().substr(ss.tellg());
}

bool StringUtils::startsWith(const std::string& str, const std::string& prefix) {
	return str.substr(0, prefix.size()) == prefix;
}

