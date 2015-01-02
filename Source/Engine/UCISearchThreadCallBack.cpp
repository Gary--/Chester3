#include "UCISearchThreadCallBack.h"
#include <iostream>
#include "UCI.h"
using namespace std;

UCISearchThreadCallBack* UCISearchThreadCallBack::instance = nullptr;


UCISearchThreadCallBack::UCISearchThreadCallBack() {}
UCISearchThreadCallBack::~UCISearchThreadCallBack() {}


void UCISearchThreadCallBack::stCallbackFunction(SearchTerminationCondition condition)
{
	UCI::searchCallback(condition);
}


UCISearchThreadCallBack* UCISearchThreadCallBack::getInstance() {
	if (!instance) {
		instance = new UCISearchThreadCallBack();
	}
	return instance;
}