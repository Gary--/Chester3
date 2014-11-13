#include "stdafx.h"
#include "CppUnitTest.h"
#include "search.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Search_Basic_BestMove) {
public:
	AI_SearchResult getSearchResult(const char* FEN, int depth) {
		Search::configureGame(GameConfiguration(FEN));

		AI_SearchConfiguration searchConfig;
		searchConfig.maxDepth = depth;
		Search::startSearch(searchConfig);
		return Search::getSearchResult();
	}

	TEST_METHOD(Obvious_Capture_0) {
		Assert::AreEqual(Position("e2"),
						 getSearchResult("8/8/8/4k3/8/3K4/4r3/8 w - -",1).bestMove.getTo());
	}
	};
}