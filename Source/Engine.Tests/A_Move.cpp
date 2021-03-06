#include "stdafx.h"
#include "CppUnitTest.h"
#include "Move.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Move) {
public:

	TEST_METHOD(Construct_From_Value_uint32) {
		Move a((uint32_t)(-1));
		Assert::AreEqual(a.asInt32(), (uint32_t)(-1));

		Assert::AreEqual(Move(45345).asInt32(), (uint32_t)45345);
	}

	TEST_METHOD(Getters) {
		Move move(MoveType::REGULAR, Position(11), Position(12), Piece::KING(), Piece::PAWN());
		Assert::AreEqual((uint8_t)MoveType::REGULAR, (uint8_t)move.getType());
		Assert::AreEqual(Position(11), move.getFrom());
		Assert::AreEqual(Position(12), move.getTo());
		Assert::AreEqual(Piece::KING(), move.getPiece());
		Assert::AreEqual(Piece::PAWN(), move.getTarg());

		Assert::IsFalse(move.isPromotion());
		Assert::IsTrue(move.isCapture());
	}

	TEST_METHOD(Promotion) {
		Move move(MoveType::PROMO_ROOK, Position("a7"), Position("a8"), Piece::PAWN(), Piece::EMPTY());
		Assert::IsTrue(move.isPromotion());
		Assert::AreEqual(Piece::ROOK(), move.promotionPiece());
	}

	TEST_METHOD(Promo_Type) {
		FOR_PIECE(promo, Piece::KNIGHT(), Piece::QUEEN()) {
			Move move(promoType(promo), Position("a7"), Position("a8"), Piece::PAWN(), Piece::EMPTY());
		}
	}

	TEST_METHOD(ToString) {
		Assert::AreEqual("e4e5", Move(MoveType::REGULAR, Position("e4"), Position("e5"), Piece::PAWN(), Piece::EMPTY()).str().c_str());
		Assert::AreEqual("a7a8r", Move(MoveType::PROMO_ROOK, Position("a7"), Position("a8"), Piece::PAWN(), Piece::EMPTY()).str().c_str());
	}

	};


}