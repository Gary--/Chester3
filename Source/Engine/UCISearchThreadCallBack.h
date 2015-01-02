#pragma once
#include "SearchThreadCallBack.h"
class UCISearchThreadCallBack : public SearchThreadCallBack{
public:
	void stCallbackFunction(SearchTerminationCondition condition);

	static UCISearchThreadCallBack* getInstance();
private:
	static UCISearchThreadCallBack* instance;

	UCISearchThreadCallBack();
	~UCISearchThreadCallBack();
};

