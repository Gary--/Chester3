#include "stdafx.h"
#include "CppUnitTest.h"
#include "chess_macros.h"
#include "attack_fields.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Attack_Fields) {
public:
	TEST_CLASS_INITIALIZE(CallAttackFieldInit) {
		AttackFields::init();
	}

	TEST_METHOD(Defaults) {
		GameConfiguration conf;
		Assert::AreEqual(Turn::WHITE(), conf.getTurn());
		Assert::AreEqual(0, conf.getHalfMoveClock());
		Assert::AreEqual(1, conf.getMoveNumber());

		Assert::IsFalse(conf.getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsFalse(conf.getCanCastle(Turn::WHITE(), Side::RIGHT));
		Assert::IsFalse(conf.getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsFalse(conf.getCanCastle(Turn::BLACK(), Side::RIGHT));

		Assert::AreEqual(GameConfiguration::NO_ENPEASENT_COLUMN, conf.getEnpeasentColumn());

		FOR_POSITION_64(pos) {
			Assert::AreEqual(Piece::EMPTY(), conf.getPieceAt(pos));
		}
	}



	TEST_METHOD(Getters_Setters) {
		GameConfiguration conf;

		conf.setTurn(Turn::BLACK());
		Assert::AreEqual(Turn::BLACK(), conf.getTurn());
		conf.setTurn(Turn::WHITE());
		Assert::AreEqual(Turn::WHITE(), conf.getTurn());

		conf.setHalfMoveClock(42);
		Assert::AreEqual(42, conf.getHalfMoveClock());

		conf.setMoveNumber(42);
		Assert::AreEqual(42, conf.getMoveNumber());

		conf.setEnpeasentColumn(3);
		Assert::AreEqual(3, conf.getEnpeasentColumn());

		Position pos1(10);
		conf.setPieceAt(pos1, Turn::WHITE(), Piece::KING());
		Assert::AreEqual(Turn::WHITE(), conf.getOwnerAt(pos1));
		Assert::AreEqual(Piece::KING(), conf.getPieceAt(pos1));

		Position pos2(10);
		conf.setPieceAt(pos2, Turn::BLACK(), Piece::PAWN());
		Assert::AreEqual(Turn::BLACK(), conf.getOwnerAt(pos2));
		Assert::AreEqual(Piece::PAWN(), conf.getPieceAt(pos2));
	}

	TEST_METHOD(Char_PieceConversions) {
		int c = 0;
		FOR_PIECE(piece, Piece::EMPTY(), Piece::KING()) {
			c++;
			FOR_TURN(turn) {
				char rep = ChessUtils::charFromPieceTurn(turn, piece);
				Assert::AreEqual(piece, ChessUtils::pieceFromChar(rep));

				if (piece != Piece::EMPTY()) {
					Assert::AreEqual(turn, Turn::fromChar(rep));
				}
			}
		}

		Assert::AreEqual(7, c);
	}



	TEST_METHOD(FEN_PieceSet) {
		//Starting configuration
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

		FOR_BIT(bit, BitBoard::rowBits(1) | BitBoard::rowBits(6)) {
			Position pos = bit.ToPosition();
			Assert::AreEqual(Piece::PAWN(), conf.getPieceAt(pos));
		}

		FOR_BIT(bit, BitBoard::rowBits(0) | BitBoard::rowBits(1)) {
			Position pos = bit.ToPosition();
			Assert::AreEqual(Turn::BLACK(), conf.getOwnerAt(pos));
		}

		FOR_BIT(bit, BitBoard::rowBits(6) | BitBoard::rowBits(7)) {
			Position pos = bit.ToPosition();
			Assert::AreEqual(Turn::WHITE(), conf.getOwnerAt(pos));
		}
	}

	TEST_METHOD(FEN_Optional_TurnCounts) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -");
		Assert::AreEqual(0,conf.getHalfMoveClock());
		Assert::AreEqual(1, conf.getMoveNumber());
	}

	TEST_METHOD(FEN_TurnSet) {
		{
			GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -");
			Assert::AreEqual(Turn::WHITE(), conf.getTurn());
		}

		{
		    GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq -");
		    Assert::AreEqual(Turn::BLACK(), conf.getTurn());
	    }
	}
	
	TEST_METHOD(FEN_Castling) {

		GameConfiguration conf0("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		GameConfiguration conf1("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1");
		FOR_TURN(turn) {
			FOR_SIDE(side) {
				Assert::IsTrue(conf0.getCanCastle(turn, side));
				Assert::IsFalse(conf1.getCanCastle(turn, side));
			}
		}
	}

	TEST_METHOD(FEN_Enpeasent) {
		{
			GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
			Assert::AreEqual(GameConfiguration::NO_ENPEASENT_COLUMN, conf.getEnpeasentColumn());
		} 
		{
		    GameConfiguration conf("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
			Assert::AreEqual(4, conf.getEnpeasentColumn());
	    }
	}

	TEST_METHOD(FEN_TurnCounts) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 42 41");
		Assert::AreEqual(42, conf.getHalfMoveClock());
		Assert::AreEqual(41, conf.getMoveNumber());
	}


	void testConvert(std::string FEN) {
		Assert::AreEqual(FEN, GameConfiguration(FEN).str());
		Assert::AreEqual(FEN, GameConfiguration(FEN).mirror().mirror().str());
	}
	TEST_METHOD(FEN_Generate) {
		testConvert("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		testConvert("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
		testConvert("rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2");
		testConvert("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
		testConvert("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1");
		testConvert("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1");
		testConvert("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1");
		testConvert("r2q1rk1/pP1p2pp/Q4n2/bbp1p3/Np6/1B3NBn/pPPP1PPP/R3K2R b KQ - 0 1");
	}


	TEST_METHOD(GameConfiguration_mirror) {
		Assert::AreEqual(std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ -"),
						 GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b kq -").mirror().str_min());

		Assert::AreEqual(std::string("rnbqkbnr/ppp1pppp/8/8/3pP3/8/PPPP1PPP/RNBQKBNR b KQkq e3"),
						 GameConfiguration("rnbqkbnr/pppp1ppp/8/3Pp3/8/8/PPP1PPPP/RNBQKBNR w KQkq e6").mirror().str_min());


	}
	//TEST CLASS END
	};



}