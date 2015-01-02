#pragma once

enum class SearchTerminationCondition : char {
	DEPTH_REACHED, // Also includes mate found
	TIME_EXCEEDED, 
	STOP_REQUESTED, 
	INVALID,
};

class SearchThreadCallBack {
public:
	virtual void stCallbackFunction(SearchTerminationCondition condition) = 0;

	SearchThreadCallBack();
	~SearchThreadCallBack();
};

