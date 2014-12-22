#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation.h"
#include "Evaluation_test_helpers.h"
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


namespace EngineTests {
	TEST_CLASS(A_Evaluation_symmetry) {
public:

	void assertSymmetry(string FEN) {
		FOR_TURN(turn) {
			const Turn other = !turn;
			GameConfiguration conf(FEN);

			confSync(conf);
			int material = Evaluation::material(turn);
			int materialBalence = Evaluation::materialBalance();
			int mobility = Evaluation::mobility();
			int kingDanger = Evaluation::kingDanger(turn);
			int misc = Evaluation::misc(turn);
			int center = Evaluation::center();
			int pawns = Evaluation::pawns(turn);
			double lateness = Evaluation::lateness();

			confSync(conf.mirror());
			Assert::AreEqual(lateness, Evaluation::lateness());

			Assert::AreEqual(material, Evaluation::material(other));
			Assert::AreEqual(-materialBalence, Evaluation::materialBalance());
			Assert::AreEqual(-mobility, Evaluation::mobility());
			Assert::AreEqual(kingDanger, Evaluation::kingDanger(other));
			Assert::AreEqual(misc, Evaluation::misc(other));
			Assert::AreEqual(-center, Evaluation::center());
			Assert::AreEqual(pawns, Evaluation::pawns(other));
			
		}
	}


	TEST_METHOD(Symmetry) {
#ifdef DEBUG
		int numToDo = 20;
#else
		int numToDo = _countof(fenSamples);
#endif
		for (int i = 0; i < numToDo;++i)
		{
			assertSymmetry(fenSamples[i]);
		}
	}

	};
}

