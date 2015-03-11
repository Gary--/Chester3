#include "stdafx.h"
#include "CppUnitTest.h"
#include "Search_Transposition.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_TTEntry) {
public:
	TEST_METHOD(TTEntry_SetGet) {
		TTItem x;
		x.setMove(Move::INVALID());
		x.setDepth(129);
		x.setType((TT_Entry_Type)0);

		Assert::AreEqual(Move::INVALID(), x.getMove());
		Assert::AreEqual((uint8_t)129, x.getDepth());
		Assert::AreEqual((uint8_t)0, (uint8_t)x.getType());

		x.setType(TT_Entry_Type::LOWER_BOUND);
		x.setDepth(70);
		x.setMove(Move((uint32_t)3035346));

		Assert::AreEqual(Move((uint32_t)3035346), x.getMove());
		Assert::AreEqual((uint8_t)70, x.getDepth());
		Assert::AreEqual((uint8_t)TT_Entry_Type::LOWER_BOUND, (uint8_t)x.getType());
		
	}

	};


}