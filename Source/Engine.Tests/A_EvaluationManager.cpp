#include "stdafx.h"
#include "CppUnitTest.h"
#include "EvaluationManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_EvaluationManager) {
public:

	TEST_METHOD(Can_Eval_Things) {
		Game::configure(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"));
		EvaluationManager::synchronize();

		auto score = EvaluationManager::getScore();
		Assert::IsTrue(score.isValid());
		Assert::AreEqual(0, score.getRelativeMobility(Turn::WHITE()));
		Assert::AreNotEqual(0, score.getMisc(Turn::WHITE()));
	}
	

	};
}

