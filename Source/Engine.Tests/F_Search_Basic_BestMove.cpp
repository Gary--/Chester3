#include "stdafx.h"
#include "CppUnitTest.h"
#include "AI.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(F_Search_basic_best_move) {
public:
	AI_SearchResult getSearchResult(const char* FEN, int depth) {
		AI::configureGame(GameConfiguration(FEN));

		AI_SearchConfiguration searchConfig;
		searchConfig.maxDepth = depth;

		AI::configureSearch(searchConfig);
		AI::startSearch();

		return AI::getSearchResult();
	}

	TEST_METHOD(Obvious_Capture_0) {
		Assert::AreEqual(Position("e2"),
						 getSearchResult("8/8/8/4k3/8/3K4/4r3/8 w - -",1).bestMove.getTo());
	}

	TEST_METHOD(Mate_In_1_0) {
		auto result = getSearchResult("1k1r4/pp3R2/3q2pp/4p3/2B5/4Q3/PPP2B2/2K5 b - -", 1);
		Assert::AreEqual(Position("d1"),
						 result.bestMove.getTo());
	}

	TEST_METHOD(Mate_In_3_0) {
		auto result = getSearchResult("1k1r4/pp1b1R2/3q2pp/4p3/2B5/4Q3/PPP2B2/2K5 b - -", 5);
		Assert::AreEqual(Position("d1"),
						 result.bestMove.getTo());
	}


	};
}