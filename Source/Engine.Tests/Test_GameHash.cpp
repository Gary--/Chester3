#include "stdafx.h"
#include "CppUnitTest.h"
#include "chess_macros.h"
#include "GameHash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_GameHash) {
public:
	TEST_CLASS_INITIALIZE(Call_GameHashInit) {
		GameHash::init();
	}

	TEST_METHOD(Hash_Seems_To_Change) {
		GameHash hash(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));

		uint64_t value = hash.toInt64();
		Assert::AreNotEqual((uint64_t)0, value);

		hash.togglePiece(Position(5),Turn::BLACK, Piece::KING );
		Assert::AreNotEqual(value, hash.toInt64());
	}

	TEST_METHOD(Hash_Does_Not_Use_Turn_Counts) {
		GameConfiguration conf1("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		GameConfiguration conf2("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 13 37");
		Assert::AreEqual(GameHash(conf1).toInt64(), GameHash(conf2).toInt64());
	}

	TEST_METHOD(Piece_Toggling) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		GameHash hash(conf);
		uint64_t value0 = hash.toInt64();

		Position pos1(20);
		conf.setPieceAt(pos1, Turn::WHITE, Piece::QUEEN);
		hash.togglePiece(pos1, Turn::WHITE, Piece::QUEEN);
		Assert::AreNotEqual(value0, hash.toInt64());
		Assert::AreEqual(hash.toInt64(), GameHash(conf).toInt64());
	}

	TEST_METHOD(Piece_Toggling_2) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		GameHash hash(conf);
		uint64_t value0 = hash.toInt64();

		Position pos("a8");
		conf.setPieceAt(pos, Turn::WHITE, Piece::QUEEN);
		hash.togglePiece(pos, Turn::BLACK, Piece::ROOK);
		hash.togglePiece(pos, Turn::WHITE, Piece::QUEEN);
		Assert::AreNotEqual(value0, hash.toInt64());
		Assert::AreEqual(hash.toInt64(), GameHash(conf).toInt64());
	}

	TEST_METHOD(Toggle_Turn) {
		GameConfiguration conf1("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
		GameHash hash(conf1);
		uint64_t value = hash.toInt64();

		hash.toggleTurn();
		Assert::AreNotEqual(value, hash.toInt64());
	}

	TEST_METHOD(Pawn_e4) {
		GameConfiguration conf1("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
		
		GameConfiguration conf2("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		GameHash hash(conf2);
		hash.togglePiece(Position("e2"), Turn::WHITE, Piece::PAWN);
		hash.togglePiece(Position("e4"), Turn::WHITE, Piece::PAWN);
		hash.setEnpeasent(4);
		hash.toggleTurn();

		Assert::AreEqual(GameHash(conf1).toInt64(), hash.toInt64());

	}

	TEST_METHOD(Castling_Rights) {
		GameHash hash(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
		uint64_t prev = hash.toInt64();
		FOR_TURN(turn) {
			FOR_SIDE(side) {
				hash.voidCastle(turn, side);
				Assert::AreNotEqual(prev, hash.toInt64());
				prev = hash.toInt64();

				hash.voidCastle(turn, side);
				Assert::AreEqual(prev, hash.toInt64());
			}
		}
	}

	//TEST CLASS END
	};



}