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



	void Test_Regular_Move0(const char* from, const char* to) {
		//http://www.chessvideos.tv/bimg/1nf6dm4t1nhqo.png
		GameConfiguration conf("r1b1kbnr/Npp1p1pp/8/2P5/2qp1p2/3P2PN/P1P1PP1P/R1BQKBnR w - - 0 1");
		Game::configure(conf);

		Move move = regular(from, to);

		Game::makeMove(move);
		Assert::AreEqual(Turn::BLACK(), Game::getTurn());
		Assert::AreEqual(Piece::EMPTY, Game::getPieceAt(move.getFrom()));
		Assert::AreEqual(move.getPiece(), Game::getPieceAt(move.getTo()));
		
		Assert::IsFalse(Game::getPlayerPieces(Turn::BLACK()).contains(move.getTo()));


		Game::undoMove();
		Assert::AreEqual(conf.str(), Game::getGameConfiguration().str());
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


	Move promotion(Piece piece,const char* from, const char* to) {
		Position fromPos(from);
		Position toPos(to);
		return Move(promoType(piece), fromPos, toPos, Piece::PAWN, Game::getPieceAt(toPos));
	}
	TEST_METHOD(Promotion_0) {
		GameConfiguration conf("rn1qkbnr/ppPpp1pp/8/8/8/3K3B/PP1PpPPP/RNBQ2NR w - -");
		Game::configure(conf);

		Game::makeMove(promotion(Piece::ROOK, "c7", "c8"));
		Assert::AreEqual(Piece::ROOK, Game::getPieceAt(Position("c8")));

		Game::makeMove(promotion(Piece::QUEEN, "e2", "e1"));
		Assert::AreEqual(Piece::QUEEN, Game::getPieceAt(Position("e1")));

		Game::undoMove();
		Game::undoMove();


		Game::makeMove(promotion(Piece::ROOK, "c7", "b8"));
		Assert::AreEqual(Piece::ROOK, Game::getPieceAt(Position("b8")));

		Game::makeMove(promotion(Piece::QUEEN, "e2", "d1"));
		Assert::AreEqual(Piece::QUEEN, Game::getPieceAt(Position("d1")));

		Game::undoMove();
		Game::undoMove();

	}

	TEST_METHOD(Moving_King_Voids_Castle) {
		GameConfiguration conf("r3k2r/pppppppp/8/8/8/8/PPPPPPPP/R3K2R w KQkq - 0 1");
		Game::configure(conf);

		Game::makeMove(regular("e1", "d1"));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::makeMove(regular("e8", "d8"));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::undoMove();
		Game::undoMove();
	}

	TEST_METHOD(Moving_Rook_Voids_Castle) {
		GameConfiguration conf("r3k2r/pppppppp/8/8/8/8/PPPPPPPP/R3K2R w KQkq - 0 1");
		Game::configure(conf);
		
		Game::makeMove(regular("a1", "b1"));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::makeMove(regular("a8", "b8"));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::makeMove(regular("h1", "g1"));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::makeMove(regular("h8", "g8"));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::undoMove();
		Game::undoMove();
		Game::undoMove();
		Game::undoMove();
	}

	TEST_METHOD(Rook_Getting_Captured_Voids_Castle){
		GameConfiguration conf("r3k2r/pBppppBp/8/8/8/8/PbPPPPbP/R3K2R b KQkq - 0 1");
		Game::configure(conf);

		Game::makeMove(regular("b2", "a1"));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::makeMove(regular("b7", "a8"));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::makeMove(regular("g2", "h1"));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsTrue(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::makeMove(regular("g7", "h8"));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::BLACK(), Side::RIGHT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::LEFT));
		Assert::IsFalse(Game::getCanCastle(Turn::WHITE(), Side::RIGHT));

		Game::undoMove();
		Game::undoMove();
		Game::undoMove();
		Game::undoMove();
	}

	TEST_METHOD(Caslting_0) {
		GameConfiguration conf("r3k2r/pppppppp/8/8/8/8/PPPPPPPP/R3K2R w KQkq - 0 1");
		Game::configure(conf);

		Game::makeMove(Move(MoveType::CASTLE_LEFT, Position("e1"), Position("c1"), Piece::KING, Piece::EMPTY));
		Assert::AreEqual(Piece::EMPTY, Game::getPieceAt(Position("a1")));
		Assert::AreEqual(Piece::ROOK, Game::getPieceAt(Position("d1")));

		Game::makeMove(Move(MoveType::CASTLE_LEFT, Position("e8"), Position("c8"), Piece::KING, Piece::EMPTY));
		Assert::AreEqual(Piece::EMPTY, Game::getPieceAt(Position("a8")));
		Assert::AreEqual(Piece::ROOK, Game::getPieceAt(Position("d8")));

		Game::undoMove();
		Game::undoMove();

		Game::makeMove(Move(MoveType::CASTLE_RIGHT, Position("e1"), Position("g1"), Piece::KING, Piece::EMPTY));
		Assert::AreEqual(Piece::EMPTY, Game::getPieceAt(Position("h1")));
		Assert::AreEqual(Piece::ROOK, Game::getPieceAt(Position("f1")));

		Game::makeMove(Move(MoveType::CASTLE_RIGHT, Position("e8"), Position("g8"), Piece::KING, Piece::EMPTY));
		Assert::AreEqual(Piece::EMPTY, Game::getPieceAt(Position("h8")));
		Assert::AreEqual(Piece::ROOK, Game::getPieceAt(Position("f8")));

		Game::undoMove();
		Game::undoMove();
	}

	};

}