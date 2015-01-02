#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Search_SearchResult.h"
#include "SearchThread.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(F_Search_basic_best_move) {
public:
	Move getBestMove(const char* FEN, int depth) {
		Game::configure(GameConfiguration(FEN));
		Search_Configuration conf;
		conf.maxTimeMs = 100*1000;
		conf.maxDepth = depth;

		SearchThread::setSearchConfiguration(conf);
		SearchThread::start();
		SearchThread::waitForFinish();


		return SearchThread::getSearchResult().pv.move;
	}

	TEST_METHOD(Obvious_Capture_0) {
		Assert::AreEqual(Position("e2"),
						 getBestMove("8/8/8/4k3/8/3K4/4r3/8 w - -", 1).getTo());
	}

	TEST_METHOD(Mate_In_1_0) {
		auto result = getBestMove("1k1r4/pp3R2/3q2pp/4p3/2B5/4Q3/PPP2B2/2K5 b - -", 1);
		Assert::AreEqual(Position("d1"),
						 result.getTo());
	}

	TEST_METHOD(Mate_In_3_0) {
		auto result = getBestMove("1k1r4/pp1b1R2/3q2pp/4p3/2B5/4Q3/PPP2B2/2K5 b - -", 5);
		Assert::AreEqual(Position("d1"),
						 result.getTo());
	}


	};
}