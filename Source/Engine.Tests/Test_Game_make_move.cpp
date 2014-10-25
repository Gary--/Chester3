#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Game_make_move) {
public:
	TEST_CLASS_INITIALIZE(Call_Game_Init) {
		Game::init();
	}

	TEST_METHOD(Resigning) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		Game::configure(conf);
		Game::makeMove(Move::RESIGN());

		Assert::AreEqual(conf.str(), GameConfiguration::extractFromGame().str());
		Assert::AreEqual(GameResult::BLACK_WIN, Game::getState());

		conf.setTurn(Turn::BLACK);
		Game::configure(conf);
		Game::makeMove(Move::RESIGN());

		Assert::AreEqual(conf.str(), GameConfiguration::extractFromGame().str());
		Assert::AreEqual(GameResult::WHITE_WIN, Game::getState());
	}

	TEST_METHOD(Knight_c3) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		Game::configure(conf);
		Game::makeMove(Move::RESIGN());

		Assert::AreEqual(conf.str(), GameConfiguration::extractFromGame().str());
		Assert::AreEqual(GameResult::BLACK_WIN, Game::getState());

		conf.setTurn(Turn::BLACK);
		Game::configure(conf);
		Game::makeMove(Move::RESIGN());

		Assert::AreEqual(conf.str(), GameConfiguration::extractFromGame().str());
		Assert::AreEqual(GameResult::WHITE_WIN, Game::getState());
	}

	void Test_Regular_Move0(const char* from, const char* to) {
		//http://www.chessvideos.tv/bimg/1nf6dm4t1nhqo.png
		GameConfiguration conf("r1b1kbnr/Npp1p1pp/8/2P5/2qp1p2/3P2PN/P1P1PP1P/R1BQKBnR w - - 0 1");
		Game::configure(conf);

		Move move = regular(from, to);

		Game::makeMove(move);
		Assert::AreEqual(Turn::BLACK, Game::getTurn());
		Assert::AreEqual(Piece::EMPTY, Game::getPieceAt(move.getFrom()));
		Assert::AreEqual(move.getPiece(), Game::getPieceAt(move.getTo()));
		
		Assert::IsFalse(Game::getPlayerPieces(Turn::BLACK).contains(move.getTo()));
		Assert::AreEqual(1, Game::getMoveNumber());


		Game::undoMove();
		Assert::AreEqual(conf.str(), GameConfiguration::extractFromGame().str());
	}
	Move regular(const char* from, const char* to) {
		Position fromPos(from);
		Position toPos(to);
		return Move(MoveType::REGULAR, fromPos, toPos, Game::getPieceAt(fromPos), Game::getPieceAt(toPos));
	}
	TEST_METHOD(Regular_Move) {
		Test_Regular_Move0("a1", "b1");
		Test_Regular_Move0("h1", "g1");
		Test_Regular_Move0("d3", "c4");
	}


	TEST_METHOD(Enpeasent_0) {
		GameConfiguration conf("rnbqkbnr/ppp1p1pp/8/8/3p1p2/8/PPPPPPPP/RNBQKBNR w - -");
		Game::configure(conf);

		Game::makeMove(Move(MoveType::PAWN_JUMP, Position("e2"), Position("e4"), Piece::PAWN, Piece::EMPTY));
		Assert::AreEqual(4, Game::getEnpeasentColumn());

		Game::makeMove(Move(MoveType::ENPEASENT, Position("d4"), Position("e3"), Piece::PAWN, Piece::EMPTY));
		Assert::AreEqual(Piece::EMPTY, Game::getPieceAt(Position("e4")));
		Assert::AreEqual(GameConfiguration::NO_ENPEASENT_COLUMN, Game::getEnpeasentColumn());

		Game::undoMove();
		Game::undoMove();
	}

	TEST_METHOD(Enpeasent_1) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/2P1P3/8/8/PP1P1PPP/RNBQKBNR b - -");
		Game::configure(conf);

		Game::makeMove(Move(MoveType::PAWN_JUMP, Position("d7"), Position("d5"), Piece::PAWN, Piece::EMPTY));
		Assert::AreEqual(3, Game::getEnpeasentColumn());

		Game::makeMove(Move(MoveType::ENPEASENT, Position("e5"), Position("d6"), Piece::PAWN, Piece::EMPTY));
		Assert::AreEqual(Piece::EMPTY, Game::getPieceAt(Position("d5")));
		Assert::AreEqual(GameConfiguration::NO_ENPEASENT_COLUMN, Game::getEnpeasentColumn());

		Game::undoMove();
		Game::undoMove();
	}

	};

}