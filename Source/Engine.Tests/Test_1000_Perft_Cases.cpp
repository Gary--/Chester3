#include "stdafx.h"
#include "CppUnitTest.h"
#include "perft.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_1000_Perft_Cases) {
public:



	TEST_METHOD(gentest_1) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_2) {
		const char* FEN = "rnbqkbnr/pp1ppppp/2p5/8/6P1/2P5/PP1PPP1P/RNBQKBNR b KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(463, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11138, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(274234, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7290026, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_3) {
		const char* FEN = "rnb1kbnr/ppq1pppp/2pp4/8/6P1/2P5/PP1PPPBP/RNBQK1NR w KQkq -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(734, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20553, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(579004, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16988496, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_4) {
		const char* FEN = "rnb1kbnr/p1q1pppp/1ppp4/8/4B1P1/2P5/PPQPPP1P/RNB1K1NR b KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(837, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22536, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(699777, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(19118920, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_5) {
		const char* FEN = "rn2kbnr/p1q1ppp1/1ppp3p/8/4B1b1/2P4P/PPQPPP2/RNB1K1NR w KQkq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(827, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24815, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(701084, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21819626, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_6) {
		const char* FEN = "rn1qkbnr/p3ppp1/1ppp2Qp/3B4/6b1/2P4P/PP1PPP2/RNB1K1NR b KQkq -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(976, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23465, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(872551, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21984216, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_7) {
		const char* FEN = "rnkq1bnr/p3ppp1/1ppp3p/3B4/6b1/2PQ3P/PP1PPP2/RNB1K1NR w KQ -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(957, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33542, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(891412, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(31155934, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_8) {
		const char* FEN = "rnkq1bnr/p3ppp1/1ppp3p/5b2/8/2PQ3P/PP1PPPB1/RNB1K1NR b KQ -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(927, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25822, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(832461, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23480361, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_9) {
		const char* FEN = "rn1q1bnr/p2kppp1/2pp3p/1p3b2/1P6/2PQ3P/P2PPPB1/RNB1K1NR w KQ -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(834, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25926, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(715605, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22575950, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_10) {
		const char* FEN = "rn1q1bnr/3kppp1/p1pp3p/1p3b2/1P6/2P2N1P/P1QPPPB1/RNB1K2R b KQ -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(900, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25008, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(781431, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22075119, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_11) {
		const char* FEN = "rn1q1bnr/3kppp1/2pp3p/pp6/1P2b3/2PQ1N1P/P2PPPB1/RNB1K2R w KQ -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(856, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26922, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(784949, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25488551, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_12) {
		const char* FEN = "rn1q1bnr/3kpp2/2pp2pp/pp6/1P2b2N/2PQ3P/P2PPP2/RNB1KB1R b KQ -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(839, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25287, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(743330, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22844888, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_13) {
		const char* FEN = "rnkq1bnr/4pp2/2pQ2pp/pp6/1P5N/2P4P/P2PPP2/RNB1KB1b w Q -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(857, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29373, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(807330, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26996998, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_14) {
		const char* FEN = "rnk2bnr/2q1pp2/2pQ2pp/pp6/1P5N/2PPP2P/P4P2/RNB1KB1b b Q -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1002, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27640, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(960905, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28434554, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_15) {
		const char* FEN = "rn3bnr/1kq1pp2/2pQ2Np/pp6/1P6/2PPPb1P/P4P2/RNB1KB2 w Q -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1122, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38831, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1259372, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43220869, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_16) {
		const char* FEN = "rn3bnr/1kq1p3/2pQ2pp/Pp6/8/N1PPPb1P/P4P2/R1B1KB2 b Q -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(983, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29665, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(924296, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28997034, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_17) {
		const char* FEN = "rn3b1r/1kq1p3/2pQ1npp/Pp6/4b3/2PPP2P/P4P2/RNB1KB2 w Q -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1196, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38978, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1342725, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42582894, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_18) {
		const char* FEN = "rn3b1r/1kq1p3/2p2npp/Pp3b2/7Q/2PPP2P/P4P2/RNB1KB2 b Q -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1234, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49419, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1463588, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57455473, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_19) {
		const char* FEN = "r4b1r/1k2p3/n1p2npp/Pp3b2/5Q2/2PPP1qP/P4P2/RNB1KB2 w Q -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1470, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44165, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1909468, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(56317737, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_20) {
		const char* FEN = "r4br1/1k2p3/n1p2npp/Pp1Q1b2/8/2PPP1qP/P4P2/RNB1KB2 b Q -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1687, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(73846, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2271390, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(95410956, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_21) {
		const char* FEN = "r4br1/1k2p3/2p2npp/PpnQ4/P5b1/2PPP1qP/5P2/RNB1KB2 w Q -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1935, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(61403, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2903019, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(89326625, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_22) {
		const char* FEN = "r4br1/4p3/k1p2npp/PpnQ4/P5b1/2PPP1qP/5P2/RNB1KB2 b Q -";
		Assert::AreEqual(53, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1796, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(84197, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2567078, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(113930150, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_23) {
		const char* FEN = "r4br1/8/k1p2npp/Ppn1p3/P7/2PPP1qP/4bPQ1/RNB1KB2 w Q -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1036, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25308, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1095789, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27999381, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_24) {
		const char* FEN = "r4br1/8/2Q2npp/Pkn1p3/8/2PPP1qP/4bP2/RNB1KB2 b Q -";
		Assert::AreEqual(1, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(18, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(888, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(16244, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(779306, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_25) {
		const char* FEN = "r4br1/8/3k1npp/P1n1p3/8/2PPP1qP/4bPB1/RNB1K3 w Q -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1155, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26440, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1218982, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27780951, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_26) {
		const char* FEN = "r4br1/8/3k2pp/P1nnp3/6P1/2PPP2P/4b1B1/RNB1K3 b Q -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(877, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33568, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(756910, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28087359, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_27) {
		const char* FEN = "r4b2/6r1/3k2pp/P2np3/4n1P1/R1PPP2P/4b1B1/1NB1K3 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(778, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15302, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(631901, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13282551, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_28) {
		const char* FEN = "r4b2/4r3/3k2pp/P2np3/4n1P1/R1PPPB1P/3Nb3/2B1K3 b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(890, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34042, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(751251, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28408063, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_29) {
		const char* FEN = "r4b2/2n1r3/3k2pp/P3p3/6P1/R1PPPBnP/1B1Nb3/4K3 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(824, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21597, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(697477, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18277943, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_30) {
		const char* FEN = "B4b2/2nkr3/6pp/P3p3/6P1/2PPP1nP/1B1Nb3/R3K3 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(826, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24543, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(660957, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(19956404, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_31) {
		const char* FEN = "4n3/3kr1b1/6pp/P3p3/4B1P1/2PPP1nP/1B1Nb3/R3K3 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(669, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18695, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(483244, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13436830, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_32) {
		const char* FEN = "B3n3/4r1b1/3k2pp/P3p3/6P1/2PPP1nP/RB1Nb3/4K3 b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(720, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18852, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(489620, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13402409, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_33) {
		const char* FEN = "B3n3/6b1/3kr1pp/P3p3/4n1P1/2PPP2P/R2Nb3/B3K3 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(494, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11765, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(281677, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6961428, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_34) {
		const char* FEN = "4n3/6b1/4r1pp/P1k1p3/4B1P1/2PPP2P/R3b3/B3KN2 b - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(574, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12583, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(337049, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7727643, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_35) {
		const char* FEN = "4n3/6b1/r6p/P1k1p1p1/4B1P1/2PPP2P/R3b2N/B3K3 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(557, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13980, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(314612, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7936760, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_36) {
		const char* FEN = "8/6b1/r2n2Bp/P1k1p1p1/6P1/2PPP2P/1R2b2N/B3K3 b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(660, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15951, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(415723, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10139775, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_37) {
		const char* FEN = "2n5/6bB/r7/P1k1p1pp/6P1/2PPP2P/1R2b2N/B3K3 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(652, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16626, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(412224, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10731721, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_38) {
		const char* FEN = "8/n5bB/r7/P1k1p1pp/1R4PP/2PPP3/4b2N/B3K3 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(706, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16548, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(439782, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10469492, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_39) {
		const char* FEN = "8/n6B/r4b2/P1k1p1pp/1R4bP/2PPP3/8/B3KN2 w - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(596, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15759, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(362146, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9601859, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_40) {
		const char* FEN = "8/nR5B/r1k2b2/P3p1pp/6bP/2PPP3/8/B3KN2 b - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(579, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12243, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(318916, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7127386, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_41) {
		const char* FEN = "2n5/1R5B/r1k2b2/P3p1pp/3P3P/2P1P3/4b3/B3KN2 w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(729, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21803, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(509994, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14720753, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_42) {
		const char* FEN = "2n5/3Rb2B/r1k5/P3p1pp/3P3P/2P1P3/3Kb3/B4N2 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(701, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16816, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(442872, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10918832, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_43) {
		const char* FEN = "2n5/3R3B/r1kb4/P3p2p/3P3p/2P1P3/4b3/B1K2N2 w - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(621, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16508, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(392378, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10462755, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_44) {
		const char* FEN = "2n5/3R4/r1kb4/P3p2p/3P3p/2PbP3/1K6/BB3N2 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(633, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15810, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(355398, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8842726, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_45) {
		const char* FEN = "8/1R6/rn1b4/Pk2p2p/3P3p/2PbP3/1K6/BB3N2 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(565, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12698, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(327247, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7504855, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_46) {
		const char* FEN = "6R1/8/rn1b4/P3p2p/2kP3p/2PbP3/1K6/BB3N2 b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(680, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16989, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(386325, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9821066, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_47) {
		const char* FEN = "5b2/8/rn6/P3p2p/2kP2Rp/2P1P3/1K2b3/BB3N2 w - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(577, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13661, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(322047, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7601839, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_48) {
		const char* FEN = "5b2/8/rn6/P2Pp3/2k1B1pp/2P1P3/1K2b3/B4N2 b - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(379, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8948, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(143529, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3601361, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_49) {
		const char* FEN = "8/8/r6b/P2np3/2k3pp/2P1P3/1KB1b3/B4N2 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(443, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7038, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(187436, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2928081, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_50) {
		const char* FEN = "8/8/5r1b/P2np3/2k3pp/2P1P1N1/K1B1b3/B7 b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(664, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(19608, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(348692, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10006963, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_51) {
		const char* FEN = "8/8/1r5b/P3p3/1nk3pp/K1P1P1N1/2B1b3/B7 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(585, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10957, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(287677, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5057569, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_52) {
		const char* FEN = "8/8/r6b/P3p2N/1nk3pp/K1PBP3/4b3/B7 b - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(72, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1904, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(29157, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(786112, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_53) {
		const char* FEN = "8/8/r6b/P3pb2/1nk3pp/K1P1P1N1/8/B7 w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(361, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3590, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(108753, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1152635, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_54) {
		const char* FEN = "8/8/r6b/P3p3/1nk1b1pp/K1P1P3/1B6/7N b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(246, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8542, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(74867, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2469417, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_55) {
		const char* FEN = "8/6b1/r7/P3pb2/1nk3pp/K1P1P3/1B3N2/8 w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(361, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3628, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(108745, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1192409, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_56) {
		const char* FEN = "8/6b1/6r1/P3pb2/1nk3Np/K1P1P3/8/B7 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(348, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10253, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(109696, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3244070, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_57) {
		const char* FEN = "8/6b1/7r/P3p3/1nk3Np/K1P1P3/1B6/1b6 w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(296, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3301, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(85445, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(976836, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_58) {
		const char* FEN = "8/6b1/7r/Pk2p3/1n4Np/K1P1P3/1B6/1b6 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(377, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10572, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(125127, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3449824, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_59) {
		const char* FEN = "8/6b1/5N1r/Pk2p3/1n5p/K1P1P3/1B6/1b6 w - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(418, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5061, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(133804, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1609522, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_60) {
		const char* FEN = "8/6b1/7r/Pk2p3/1n5p/K1PbP1N1/1B6/8 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(434, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13169, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(153820, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4443875, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_61) {
		const char* FEN = "8/6b1/5r2/Pk2p3/7p/1KPbP1N1/1Bn5/8 w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(429, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5040, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(157837, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1921415, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_62) {
		const char* FEN = "8/6b1/5r2/Pk2p3/7p/1KP1P3/2n1b3/2B4N b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(372, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12010, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(135981, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4297511, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_63) {
		const char* FEN = "5b2/8/8/Pk2p3/7p/1KP1Pr2/1Bn1b3/7N w - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(291, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2992, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(90496, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1013174, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_64) {
		const char* FEN = "5b2/8/8/Pk2p3/2b4p/2P1Pr2/1Bn5/1K5N b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(331, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11927, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(120416, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4169323, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_65) {
		const char* FEN = "5b2/8/8/Pk2p3/2b5/B1P1P1rp/2n5/1K5N w - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(490, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6278, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(208386, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2800497, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_66) {
		const char* FEN = "5b2/5b2/3B4/Pk2p3/8/2P1P1Np/2n5/1K6 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(478, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11790, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(204499, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4930059, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_67) {
		const char* FEN = "8/5b2/P2b4/1k2p3/8/2P1n1Np/8/1K6 w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(338, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3510, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(99518, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1095683, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_68) {
		const char* FEN = "B7/5b2/3b4/1k2p3/8/2P3Np/2n5/1K6 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(477, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12371, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(202322, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4997277, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_69) {
		const char* FEN = "8/8/4b3/1k2p3/4B3/b1P3Np/2n5/1K6 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(481, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8111, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(198356, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3210337, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_70) {
		const char* FEN = "8/8/4b3/k3p2N/8/b1PB3p/2n5/1K6 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(412, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10548, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(163093, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4116528, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_71) {
		const char* FEN = "8/8/8/k3pb1N/8/b1P5/2B4p/1K6 w - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(238, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3078, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(70356, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1038374, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_72) {
		const char* FEN = "8/8/6b1/k3p2N/8/b1PB4/K6p/8 b - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(361, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8211, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(128257, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3061565, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_73) {
		const char* FEN = "1b6/8/6B1/k3p2N/8/2P5/K6p/8 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(209, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3734, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(54477, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(954283, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_74) {
		const char* FEN = "1b2B3/8/1k6/4p3/5N2/2P5/K6p/8 b - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(302, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4537, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(84303, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1448252, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_75) {
		const char* FEN = "1b2B3/8/1k6/8/4pN2/1KP5/8/7q w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(623, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11654, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(322322, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5523536, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_76) {
		const char* FEN = "1b5q/3B4/1k6/8/2P1pN2/1K6/8/8 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(656, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18160, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(342342, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9440766, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_77) {
		const char* FEN = "8/3B4/1k1b4/8/2P1pN2/8/1K6/8 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(394, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8219, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(116986, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2283351, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_78) {
		const char* FEN = "8/2kB4/3b4/8/2P1p3/2K5/6N1/8 b - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(246, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3728, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(62176, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(876278, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_79) {
		const char* FEN = "3b4/2k5/2B5/8/2P1p3/2K5/6N1/8 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(186, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3184, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(40252, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(679381, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_80) {
		const char* FEN = "3b4/8/3k4/8/B1P1pN2/2K5/8/8 b - -";
		Assert::AreEqual(12, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(223, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2387, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(43315, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(514348, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_81) {
		const char* FEN = "8/2k5/8/2P5/B3pN1b/2K5/8/8 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(267, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5178, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(60640, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1146671, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_82) {
		const char* FEN = "3k4/8/2B5/2P5/2K1pN1b/8/8/8 b - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(219, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2313, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(47069, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(535923, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_83) {
		const char* FEN = "3k4/8/2B5/2PN4/2K1pb2/8/8/8 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(250, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4795, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(54526, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1028885, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_84) {
		const char* FEN = "3k4/8/2B5/2P5/4p3/2K1N3/7b/8 b - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(213, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2332, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(47793, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(551787, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_85) {
		const char* FEN = "3k4/8/8/2PBb3/4p3/2K1N3/8/8 w - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(90, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1950, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(27716, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(585553, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_86) {
		const char* FEN = "1b1k4/1B6/8/2P5/4p3/4N3/3K4/8 b - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(222, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2552, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(48238, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(595884, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_87) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_88) {
		const char* FEN = "rnbqkbnr/1ppppppp/8/p7/2P5/P7/1P1PPPPP/RNBQKBNR b KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(441, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10227, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(242685, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6164778, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_89) {
		const char* FEN = "2bqkbnr/rppppppp/n7/p7/2P5/PP6/3PPPPP/RNBQKBNR w KQk -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(398, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8820, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(204573, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5072498, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_90) {
		const char* FEN = "2bqkbnr/rpp1pppp/n2p4/p7/2P3P1/PP5P/3PPP2/RNBQKBNR b KQk -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(470, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13090, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(284308, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8296635, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_91) {
		const char* FEN = "2bqkbnr/rpp1p1pp/n2p4/5p2/p1PP2P1/PP5P/4PP2/RNBQKBNR w KQk -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(666, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18637, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(493990, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14425855, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_92) {
		const char* FEN = "2bqkbnr/rpp1p2p/n2p4/5pp1/p1PP2P1/PP2P2P/1B3P2/RN1QKBNR b KQk -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(703, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18885, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(549873, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15608368, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_93) {
		const char* FEN = "2b1kbnr/rppqp3/n2p3p/5pp1/p1PP2P1/PP2P2P/1B2QP2/RN2KBNR w KQk -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(576, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15712, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(417380, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12214998, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_94) {
		const char* FEN = "2b1kbnB/rppqp3/3p3p/3P1pp1/pnP3P1/PP2P2P/4QP2/RN2KBNR b KQ -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(729, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20665, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(613681, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18161673, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_95) {
		const char* FEN = "2b1kbnB/r1pqp3/n2p3p/1p1P1pp1/p1P3P1/PP2P2P/Q4P2/RN2KBNR w KQ -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(689, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21830, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(556204, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18152100, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_96) {
		const char* FEN = "2b1kbn1/r1pqp3/n2p3p/3P1pp1/ppP3P1/PPB1P2P/Q4P2/RN2KBNR b KQ -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(685, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17480, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(532817, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14672791, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_97) {
		const char* FEN = "2bq1bn1/r1pkp3/n2p3p/3P1pp1/ppP3P1/PPB1P2P/2Q2P2/RN2KBNR w KQ -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(662, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23474, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(495417, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17463335, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_98) {
		const char* FEN = "2bq1bn1/1rpkp3/n2p3p/3P1pp1/ppP3P1/PPB1P2P/3QNP2/RN2KB1R b KQ -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(636, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14063, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(465740, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11130165, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_99) {
		const char* FEN = "1rbq1b2/2pkp3/n2p1n1p/3P1pp1/ppP3P1/PPB1P2P/3Q1P2/RN2KBNR w KQ -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(772, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24764, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(635387, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21077449, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_100) {
		const char* FEN = "1rbq1bn1/2pkp3/n2p3p/3P1pp1/ppP3P1/PPBQP2P/3N1P2/R3KBNR b KQ -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(718, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15726, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(568525, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13492527, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_101) {
		const char* FEN = "2bq1b2/2pkp3/nr1p1n1p/3P1pp1/ppP3P1/PPBQP2P/3N1P2/1R2KBNR w K -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(832, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28170, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(725952, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25411630, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_102) {
		const char* FEN = "2bq1b2/3kp3/nrpp1n1p/3P1pp1/pBP3P1/PP1QP2P/3NKP2/1R3BNR b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(869, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24309, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(776907, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22423608, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_103) {
		const char* FEN = "2b1qb2/3kp3/nrpp1n2/3P1ppp/pBP3P1/PP1QP2P/3NKP1R/1R3BN1 w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(913, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30583, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(914591, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(31569084, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_104) {
		const char* FEN = "2b1qb2/2k1p3/nrpp1n2/3P1Qpp/pBP3P1/PP2P2P/3NKP1R/R4BN1 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1365, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43571, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1698889, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(55573497, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_105) {
		const char* FEN = "2bkq3/4p3/nrpp1nQb/3P2pp/pBP3P1/PP2P2P/3NKP1R/R4BN1 w - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1463, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(57483, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1957673, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(75078346, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_106) {
		const char* FEN = "2bkq3/4p3/1rpp1nQb/2nP2pp/pBP3P1/PP2PN1P/3NKP1R/2R2B2 b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1639, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(59995, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2356499, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(83330544, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_107) {
		const char* FEN = "2bkq3/2n1p3/1rpp1Q1b/3P2pp/pBP3P1/PP2PN1P/3NKP1R/2R2B2 w - -";
		Assert::AreEqual(47, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1401, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(61866, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1846425, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(77925512, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_108) {
		const char* FEN = "2bkq2Q/2n1p3/1r1p3b/2pP2pp/pBP3P1/PP2PN1P/3NKP1R/2R2B2 b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1105, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(31573, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1166929, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33886402, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_109) {
		const char* FEN = "2bkq2Q/2n1p3/r2p3b/3P2pp/ppP3P1/PP2PN1P/3NKPR1/2R2B2 w - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1032, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38687, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1086397, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(39629374, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_110) {
		const char* FEN = "3kqQ2/2n1p3/r2p3b/3P1bpp/ppP3P1/PP2PN1P/3NKP2/2R2BR1 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1031, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29103, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1011703, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(29467967, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_111) {
		const char* FEN = "n1k1qQ2/4p3/r2p3b/3P1bpp/ppP3P1/PP2P2P/3NKP2/2R1NBR1 w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1043, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36054, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1077115, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(37817626, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_112) {
		const char* FEN = "n1k1q3/4Q3/3p3b/r2P1bpp/ppP1N1P1/PP2P2P/4KP2/2R1NBR1 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1326, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36039, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1522310, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43510151, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_113) {
		const char* FEN = "n1kq4/4Q3/3p3b/r2P1bpp/p1P1NPP1/pP2P2P/4K3/2R1NBR1 w - -";
		Assert::AreEqual(48, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1259, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(55261, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1564035, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(65933246, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_114) {
		const char* FEN = "2kq4/4Q3/1n1p3b/r1NP1bpp/pPP2PP1/p3P2P/4K3/2R1NBR1 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1452, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43353, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1829511, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(55661262, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_115) {
		const char* FEN = "2kq4/4Q3/1n1pN2b/1r1P1bp1/pPP2PPp/p3P2P/4K3/2R1NBR1 w - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1035, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39949, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1063673, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(40527181, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_116) {
		const char* FEN = "3q4/3k4/1n1pN2b/1r1P1bp1/pPP2PPp/p3P2P/4K3/R3NBR1 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(899, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28647, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(777314, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25288947, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_117) {
		const char* FEN = "n2q4/3k4/3pN2b/1r1P1bp1/pPP2PPp/4P2P/p3K1B1/R3N1R1 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(977, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28242, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(913433, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26506034, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_118) {
		const char* FEN = "n2q1b2/3k4/3pN3/1r1P1bp1/pPP1PPPp/7P/p1N1K1B1/R5R1 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1155, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33718, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1183963, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35762316, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_119) {
		const char* FEN = "n1kq4/8/3p3b/1rNP1bp1/pPP1PPPp/7P/p1N1K1B1/R5R1 w - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1231, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43211, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1394054, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(46113152, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_120) {
		const char* FEN = "n1kq1b2/8/3pN3/1r1P1bp1/pPP1PPPp/7P/p1N1K1B1/3R2R1 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1245, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41818, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1463252, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(50111373, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_121) {
		const char* FEN = "2k2b2/2n5/3pNq2/1r1P1bp1/pPP1PPPp/7P/p1N1K3/3R2RB w - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1613, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(56983, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2271336, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(75105477, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_122) {
		const char* FEN = "1rkN1b2/2n5/3p1q2/3P1bp1/pPP1PPPp/7P/p1N2K2/3R2RB b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1382, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(54678, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1746961, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(67741175, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_123) {
		const char* FEN = "2kN1b2/2n5/3p4/3Pqbp1/prP1PPPp/N6P/p4K2/3R2RB w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1390, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40062, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1688989, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(47729045, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_124) {
		const char* FEN = "2kN1b2/2n5/3p4/3P1bp1/prP1qPPp/7P/p1NR1K2/6RB b - -";
		Assert::AreEqual(47, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1206, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(55482, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1477788, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66177203, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_125) {
		const char* FEN = "2kNnb2/8/3p4/3P1bp1/prP2PPp/4K2P/p1NR4/6RB w - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1070, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33425, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1055159, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32170746, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_126) {
		const char* FEN = "2k1nb2/8/3p4/3P1bp1/pNP2PPp/4K2P/2NR4/b5RB b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(846, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22764, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(677190, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17633051, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_127) {
		const char* FEN = "1k2nb2/8/3p4/3Pbbp1/p1P2PPp/3NK2P/2NR4/6RB w - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(973, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29936, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(799546, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24115604, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_128) {
		const char* FEN = "1kb1nb2/8/3p4/3Pb1p1/p1P2PPp/4K2P/3R1N2/4N1RB b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(651, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16436, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(415339, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10419772, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_129) {
		const char* FEN = "1kb1nb2/8/3p3b/3P1Pp1/p1P3Pp/4K2P/3R1N2/4N1RB w - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(423, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11278, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(192816, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5135792, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_130) {
		const char* FEN = "1kb2b2/8/3p1n1b/3P1Pp1/p1P1B1Pp/4K2P/2R2N2/4N1R1 b - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(517, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9926, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(255650, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4902072, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_131) {
		const char* FEN = "2b2bn1/1k6/3p3b/3P1Pp1/p1P3Pp/3BK2P/2R2N2/4N1R1 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(365, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9418, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(157288, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4171305, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_132) {
		const char* FEN = "2b2bn1/1k4b1/3p4/3P1Pp1/p1P3Pp/4K2P/4RN2/1B2N1R1 b - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(549, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12382, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(317430, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7313495, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_133) {
		const char* FEN = "2b2bn1/1k4b1/3p4/3P1Pp1/p1P3Pp/4K2P/4R3/1B1NN1R1 w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(615, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17316, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(385647, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10752347, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_134) {
		const char* FEN = "2b2bn1/1k4b1/3p4/3P1Pp1/2P3Pp/p3K2P/4R3/1B1NN1R1 b - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(612, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13947, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(388284, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9118411, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_135) {
		const char* FEN = "k1b3n1/4b1b1/3p4/3P1Pp1/2P3Pp/p3K2P/5R2/1B1NN1R1 w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(706, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20059, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(442218, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12196892, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_136) {
		const char* FEN = "k5n1/4b1b1/3pb3/3P1Pp1/2P2RPp/p1N1K2P/8/1B2N1R1 b - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(656, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14616, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(420458, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9669579, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_137) {
		const char* FEN = "k5n1/4b3/3pb3/3PbPp1/2P2RPp/p1N1KN1P/8/1B4R1 w - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(732, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22209, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(494428, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14925069, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_138) {
		const char* FEN = "6n1/1k2b3/3pb3/2PPbPp1/3R2Pp/p1N1KN1P/8/1B4R1 b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(938, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22393, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(801728, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(19301945, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_139) {
		const char* FEN = "3b2n1/1k6/4b3/2pPbPp1/3R2Pp/p3KN1P/8/1B1N2R1 w - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1085, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33909, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1007127, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(31133588, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_140) {
		const char* FEN = "3b2n1/1k6/8/2pbbPp1/2R3PN/p3K2P/8/1B1N2R1 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1065, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37400, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1024337, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33993440, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_141) {
		const char* FEN = "6n1/1k6/8/b1pbbP2/2R3Pp/p3K2P/6R1/1B1N4 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1115, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29174, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1018724, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26075468, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_142) {
		const char* FEN = "6n1/1k6/1b6/2pbbP2/2RR2Pp/p3K2P/8/1B1N4 b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(781, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24865, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(626245, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18862068, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_143) {
		const char* FEN = "1k4n1/8/1b6/2p1bP2/R2R2Pp/p3K2P/b7/1B1N4 w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(808, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23384, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(578656, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16615826, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_144) {
		const char* FEN = "1k4n1/b7/8/2p1bP2/R2R2Pp/p2BK2P/b7/3N4 b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(703, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16129, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(461885, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10699069, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_145) {
		const char* FEN = "6n1/b1k5/8/4bP2/R2p2Pp/p2B3P/b3K3/3N4 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(599, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14581, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(360665, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8848786, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_146) {
		const char* FEN = "6n1/bk6/5P2/4b3/3p2Pp/R2B3P/b3K3/3N4 b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(669, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15146, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(424101, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10000078, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_147) {
		const char* FEN = "k5n1/b7/5P2/8/3p2Pp/R2B2bP/b3KN2/8 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(441, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11824, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(226618, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6019782, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_148) {
		const char* FEN = "1k4n1/b7/5P2/8/3p2Pp/5RbP/b3KN2/1B6 b - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(519, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12057, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(281430, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6789205, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_149) {
		const char* FEN = "1k4n1/b7/5P2/3b4/3p1bPp/6RP/4KN2/1B6 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(757, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16968, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(487323, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10978571, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_150) {
		const char* FEN = "1k6/b3n3/5P2/3b4/3pNbPp/3K2RP/8/1B6 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(494, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14774, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(261280, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7396506, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_151) {
		const char* FEN = "2k5/b3n3/5P2/2Nb4/3p1bP1/3K2pP/8/1B6 w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(524, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7752, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(228853, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3558624, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_152) {
		const char* FEN = "2k5/4n3/5P2/2bb4/3p1bP1/3K2NP/8/1B6 b - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(504, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17647, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(252394, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8215987, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_153) {
		const char* FEN = "2k5/4n3/5P2/3b2b1/1b1p2P1/3K3P/4N3/1B6 w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(461, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6186, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(204517, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2999408, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_154) {
		const char* FEN = "2k5/4P3/8/2bb2b1/3p2PP/3K4/4N3/1B6 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(449, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11755, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(187665, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4839227, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_155) {
		const char* FEN = "2k5/4P3/8/6b1/3p2PP/b2K4/B3N1b1/8 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(515, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10768, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(253977, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5304799, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_156) {
		const char* FEN = "2kbR3/8/8/8/2Bp2PP/b2K4/4N1b1/8 b - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(519, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10177, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(268014, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5651562, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_157) {
		const char* FEN = "1k1bRb2/8/B7/8/3p2PP/3K4/4N1b1/8 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(451, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10668, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(222543, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5466380, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_158) {
		const char* FEN = "3b1R2/k7/B7/8/3p2PP/2NK4/6b1/8 b - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(579, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10086, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(269977, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4652556, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_159) {
		const char* FEN = "5R2/8/k7/6b1/N2p2PP/3K4/6b1/8 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(457, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9669, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(179032, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3718663, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_160) {
		const char* FEN = "8/8/k7/7R/N2p1bPP/3K4/6b1/8 b - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(376, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6889, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(126337, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2301021, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_161) {
		const char* FEN = "8/8/k7/2R5/N2p2PP/3K2b1/8/5b2 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(71, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1453, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(24579, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(498115, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_162) {
		const char* FEN = "8/8/k2b4/2R5/N5PP/2K5/8/5b2 b - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(330, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5564, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(110536, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1917159, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_163) {
		const char* FEN = "8/2R5/8/k7/N5PP/2K5/8/5b2 w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(192, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4350, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(41007, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(924804, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_164) {
		const char* FEN = "8/7R/b7/k7/N5PP/2K5/8/8 b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(180, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1762, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(36864, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(382021, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_165) {
		const char* FEN = "8/6R1/8/8/k5PP/2Kb4/8/8 w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(203, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3537, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(39090, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(706790, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_166) {
		const char* FEN = "8/3R4/8/1k6/6PP/3b4/1K6/8 b - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(356, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4905, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(98651, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1256790, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_167) {
		const char* FEN = "8/8/8/1k6/3R2PP/3b4/1K6/8 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(230, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4259, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(53654, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1006739, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_168) {
		const char* FEN = "8/8/8/1k4P1/R1b4P/8/1K6/8 b - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(250, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3185, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(58314, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(757259, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_169) {
		const char* FEN = "8/8/6P1/8/1kb4P/8/1K6/8 w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(100, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(649, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(10016, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(77697, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_170) {
		const char* FEN = "8/8/6P1/8/2b4P/2k5/8/3K4 b - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(73, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1091, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(6579, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(97531, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_171) {
		const char* FEN = "8/8/4b1P1/7P/8/3k4/8/3K4 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(66, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(359, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(5458, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42728, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_172) {
		const char* FEN = "8/5b1P/6P1/8/8/3k4/8/3K4 b - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(105, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1314, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(15092, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(189534, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_173) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_174) {
		const char* FEN = "rnbqkbnr/ppppp1pp/8/5p2/2P5/P7/1P1PPPPP/RNBQKBNR b KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(420, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9328, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(221495, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5414634, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_175) {
		const char* FEN = "rnbqkb1r/ppppp1pp/5n2/8/P1P2p2/8/1P1PPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(504, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12116, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(307209, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8108637, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_176) {
		const char* FEN = "rnbqkb1r/ppp1p1pp/5n2/3p4/P1P2p2/R2P4/1P2PPPP/1NBQKBNR b Kkq -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(920, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30671, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(880242, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(29878598, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_177) {
		const char* FEN = "rnbqkb1r/ppp4p/5n2/3pp1p1/P1P2p2/R2P3P/1P2PPP1/1NBQKBNR w Kkq -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1077, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29576, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1166930, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33211447, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_178) {
		const char* FEN = "rnbq1b1r/ppp2k1p/5n2/3pp1p1/P1P2p2/R2PB2P/1P1QPPP1/1N2KBNR b K -";
		Assert::AreEqual(46, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1319, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(58968, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1756740, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(76415132, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_179) {
		const char* FEN = "rn1q1b1r/ppp2k2/1B3n2/3pp1pp/P1P2p2/R2P3b/1P1QPPP1/1N2KBNR w K -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1690, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(59735, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2688254, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(94521406, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_180) {
		const char* FEN = "rn1q3r/ppp2k2/1B3n2/3pp1pp/PbP2p2/1P1P3b/R2QPPP1/1N2KBNR b K -";
		Assert::AreEqual(54, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1565, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(78731, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2361793, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(112535344, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_181) {
		const char* FEN = "rn5r/ppp2k2/1B3n2/3qp1pp/Pb3p2/1P1P3b/R2QPPP1/1N2KBNR w K -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1630, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45668, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2552421, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(75207612, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_182) {
		const char* FEN = "rB5r/pp4k1/5n2/3qp1pp/Pb3p2/1P1P3b/R2QPPP1/1N2KBNR b K -";
		Assert::AreEqual(60, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1513, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(84307, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2325605, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(121928751, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_183) {
		const char* FEN = "rB5r/pp4k1/5n2/q3p2p/Pb3pp1/1P1P3N/R2QPPP1/1N2KB1R w K -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1010, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25041, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1067873, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28954450, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_184) {
		const char* FEN = "r6r/pp3k2/3B1n2/q3p2p/Pb3pp1/1P1P3N/1R1QPPP1/1N2KB1R b K -";
		Assert::AreEqual(46, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1093, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46923, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1207848, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(51220974, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_185) {
		const char* FEN = "r6r/pp3k2/3B4/q3p2p/Pb3pp1/1PnP3N/1R1QPPP1/1N2KBR1 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1076, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27378, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1159671, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30382685, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_186) {
		const char* FEN = "r7/pp3k1r/8/q1B1p2p/Pb3pp1/1PnPQ2N/1R2PPP1/1N2KBR1 b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(994, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40592, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1034200, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42152761, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_187) {
		const char* FEN = "r7/p6r/1p3k2/q1B1p2p/Pb3pp1/1PnPQ2N/1R2PPP1/1N2KB1R w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1122, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29265, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1127423, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30696481, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_188) {
		const char* FEN = "r7/p3B2r/1p4k1/q3p2p/Pb3pp1/1PnPQ2N/1R1KPPP1/1N3B1R b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1026, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39620, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1073189, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41804862, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_189) {
		const char* FEN = "5r2/p6r/1p3k2/q3p2p/PB3pp1/1PnPQ2N/1R1KPPP1/1N3B1R w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1133, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33454, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1191780, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(36482906, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_190) {
		const char* FEN = "5r2/p6r/1Q6/q3pk1p/PB3pp1/1PnPP2N/1R1K1PP1/1N3B1R b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1505, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(54434, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1992851, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(71884126, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_191) {
		const char* FEN = "5r2/p4r2/1Q6/q3pk1p/PB3pp1/1PnPP2N/1RK2PP1/1N3B1R w - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1356, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(53762, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1834477, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(69678895, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_192) {
		const char* FEN = "4Qr2/p4r2/8/q3pk2/PB3ppp/1PnPP2N/1RK2PP1/1N3B1R b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1302, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39311, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1423025, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45146902, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_193) {
		const char* FEN = "4Qr2/p1q2r2/8/4pk2/PB4pp/1PnPpP1N/1RK3P1/1N3B1R w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1130, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34217, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1153685, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38123678, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_194) {
		const char* FEN = "5r2/p1qQ1r2/5k2/4p3/PB4pp/1PnPpP1N/1RK3P1/1N3BR1 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1155, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37366, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1189959, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(39705631, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_195) {
		const char* FEN = "5r2/q2Q1r2/5k2/p3p3/PB4pp/1PnPpP1N/1RK3P1/1N3B1R w - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1156, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44934, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1370682, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(50975284, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_196) {
		const char* FEN = "4r3/q4r2/5k2/p3p3/PB1Q2pp/1PnPpP1N/1RKN2P1/5B1R b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1665, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(60577, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2166254, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(78077692, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_197) {
		const char* FEN = "4r3/5r2/1q3k2/p3p3/PB1Q3p/1PnPppPN/1RKN4/5B1R w - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1482, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(57365, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2157199, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(82324145, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_198) {
		const char* FEN = "8/4rr2/1q3k2/p3p3/P2Q3p/1PnPppPN/1RKN2B1/7R b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1614, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(56616, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2105288, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(74901981, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_199) {
		const char* FEN = "8/3r3r/1q3k2/p3p3/P2Q3p/1PnPppPN/1RKN2B1/6R1 w - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1630, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(61802, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2460084, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(91326769, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_200) {
		const char* FEN = "3r4/7r/1q3k2/p3p3/PP1Q3p/2nPppPN/1RKN2B1/1R6 b - -";
		Assert::AreEqual(54, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(2201, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(97281, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(3835695, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(164009993, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_201) {
		const char* FEN = "3r4/7r/q4k2/p3p3/PP1Q3p/2nPppP1/1RKN2B1/1R4N1 w - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1838, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(73310, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(3155675, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(122724141, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_202) {
		const char* FEN = "8/7r/q4k2/p3p3/PP1r2Pp/1KnPpp2/1R1N2B1/1R4N1 b - -";
		Assert::AreEqual(52, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1176, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(54270, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1298865, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(58692925, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_203) {
		const char* FEN = "8/8/q4k2/p6r/PP1rp1Pp/1KnPpp2/R2N2B1/1R4N1 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1329, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36309, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1585324, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42328242, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_204) {
		const char* FEN = "8/8/q4k2/p5r1/PP1rp1PN/1KnPp3/R2N2B1/1R6 b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1262, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(51858, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1450959, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(59987641, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_205) {
		const char* FEN = "8/q7/5k2/p5r1/PP1rp1P1/1KnP1N2/R2Np1B1/1R6 w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1474, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43511, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1979363, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(56738280, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_206) {
		const char* FEN = "8/q7/5k2/p5r1/PP1rp1P1/1K1P4/2RNp1B1/1n2N3 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(952, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37264, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(889038, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35400629, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_207) {
		const char* FEN = "8/q7/5k2/p2r3r/PP2p1P1/1K1P1N2/2R1p1B1/1n2N3 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1319, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36032, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1514645, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(39420646, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_208) {
		const char* FEN = "8/q7/5k2/p2r3r/PP2p1P1/2KP4/2Rnp1B1/4N1N1 b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(928, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42944, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(823315, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(36611625, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_209) {
		const char* FEN = "8/q7/5k2/p7/PP1rp1P1/2KP3B/2Rnp2r/4N1N1 w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(586, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9555, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(366670, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6577001, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_210) {
		const char* FEN = "8/8/5k2/p1q5/PP1rp1P1/3P1N1B/2RKp2r/6N1 b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(763, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28895, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(566531, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21004779, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_211) {
		const char* FEN = "8/8/5k2/p1q1N2r/PP1rp1P1/3P4/2RKp3/6N1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(939, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(19604, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(753644, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16026136, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_212) {
		const char* FEN = "8/8/5k2/p1q1N1N1/PP1rp1P1/3P4/2RKp3/7r b - -";
		Assert::AreEqual(47, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(934, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36151, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(744017, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28368703, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_213) {
		const char* FEN = "8/6kN/8/2q1N3/Pp1rp1P1/3P4/2RKp3/7r w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(861, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15432, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(656842, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12401507, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_214) {
		const char* FEN = "8/6kN/8/2q5/Pp1rp1P1/2RP1N2/3Kp3/1r6 b - -";
		Assert::AreEqual(47, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(851, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36652, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(670900, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27100645, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_215) {
		const char* FEN = "8/6kN/8/6q1/Pp1rp3/2RP1N2/3Kp3/1r6 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(155, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2848, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(103116, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1935527, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_216) {
		const char* FEN = "8/6k1/8/2q3N1/Pp1rp3/2RP1N2/4K3/1r6 b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(900, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35044, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(740651, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28133646, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_217) {
		const char* FEN = "3r4/6k1/8/6N1/Ppq1p3/2RP1N2/5K2/1r6 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1090, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24178, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(988061, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21767914, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_218) {
		const char* FEN = "3r4/6k1/8/6N1/Pp1qp2N/2RP4/6K1/1r6 b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(870, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33611, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(703958, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27706331, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_219) {
		const char* FEN = "3r4/5k2/4N3/3q4/Pp2p2N/2RP4/6K1/1r6 w - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1075, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24878, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(983771, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22462613, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_220) {
		const char* FEN = "3r4/5k2/4N1N1/3q4/P1R1p3/1p1P4/6K1/1r6 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1077, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38667, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(930928, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33841449, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_221) {
		const char* FEN = "8/5k2/4N1N1/3r2q1/P1R1p3/1p1P4/7K/1r6 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(997, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(19921, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(723494, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14319437, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_222) {
		const char* FEN = "8/5kN1/8/3rq3/P1R1pN2/1p1P4/7K/1r6 b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(758, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29302, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(593298, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22591938, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_223) {
		const char* FEN = "5k2/2R3q1/8/3r4/P3pN2/1p1P4/7K/1r6 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(889, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15980, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(580215, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10173527, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_224) {
		const char* FEN = "5k2/4R1q1/8/5r2/P3p3/1p1P4/6NK/1r6 b - -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(627, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22862, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(343776, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12401221, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_225) {
		const char* FEN = "5k2/4R1q1/8/8/P3p2r/1p1P4/7K/1r6 w - -";
		Assert::AreEqual(0, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_226) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_227) {
		const char* FEN = "rnbqkbnr/ppppppp1/7p/8/7P/7N/PPPPPPP1/RNBQKB1R b KQkq -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(418, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8955, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(213604, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5117449, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_228) {
		const char* FEN = "rnbqkbnr/1pppp1p1/p6p/5p2/7P/7N/PPPPPPP1/RNBQKBR1 w Qkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(358, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8094, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(165912, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4158765, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_229) {
		const char* FEN = "rnbqkbnr/1p1pp1p1/p6p/2p2p2/7P/2P4N/PP1PPPP1/RNBQKB1R b Qkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(458, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10414, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(264849, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6615556, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_230) {
		const char* FEN = "rnbqkbnr/1p1p2p1/4p2p/p1p2p2/7P/2P2P1N/PP1PP1P1/RNBQKB1R w Qkq -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(667, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16857, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(482676, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13132163, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_231) {
		const char* FEN = "rnbqkbnr/1p4p1/3pp2p/p1p2p2/7P/2PP1P1N/PP1NP1P1/R1BQKB1R b Qkq -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(784, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23151, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(638663, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(19171633, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_232) {
		const char* FEN = "r1b1kbnr/1pq3p1/2npp2p/p1p2p2/4P2P/2PP1P1N/PP1N2P1/R1BQKB1R w Qkq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1031, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30910, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1053636, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32507370, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_233) {
		const char* FEN = "r1b1kb1r/1pq1n1p1/2npp2p/p1p2p2/4P2P/2PP1P1N/PP1NB1P1/R1BQ1K1R b kq -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(955, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(31153, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(930788, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30422817, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_234) {
		const char* FEN = "r1bqkb1r/1p2n1p1/2npp2p/2p2p2/p3PN1P/2PP1P2/PP1NB1P1/R1BQ1K1R w kq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(927, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28090, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(904102, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28404510, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_235) {
		const char* FEN = "r2qkb1r/1p1bn1p1/2npp2p/2p2p2/Q3P2P/2PP1P1N/PP1NB1P1/R1B2K1R b kq -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1306, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45609, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1642686, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57784259, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_236) {
		const char* FEN = "r2q1b1r/1p1bnk2/2npp2p/2p2pp1/2Q1P2P/2PP1P1N/PP1NB1P1/R1B2K1R w - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1352, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(47686, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1883115, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(67964398, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_237) {
		const char* FEN = "r4b1r/1p1bnk2/1qnpp2p/2p2pp1/2Q1PN1P/2PP1P2/PP1N2P1/R1BB1K1R b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1782, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(75177, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2963978, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(122154431, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_238) {
		const char* FEN = "r3kb1r/1p1b4/1qnpp2p/2pn1pp1/2Q1PN1P/1NPP1P2/PP4P1/R1BB1K1R w - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1770, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(69135, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2979618, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(118000269, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_239) {
		const char* FEN = "r3kb1r/1p1b4/1qnpp2p/2p2pp1/1nQ1P2P/PNPP1P2/1P2N1P1/R1BB1K1R b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1586, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(62376, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2469594, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(96645684, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_240) {
		const char* FEN = "1n1rkb1r/1p1b4/1q1pp2p/N1p2pp1/1nQ1P2P/P1PP1P2/1P2N1P1/R1BB1K1R w - -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1336, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(57177, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1827435, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(77485100, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_241) {
		const char* FEN = "1n1rkb1r/1p1bN3/1q1pp2p/2p3p1/1nQ1p2P/P1PP1P2/1P2N1P1/R1BB1K1R b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1526, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(50921, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2304898, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(77407932, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_242) {
		const char* FEN = "1n1rkbr1/1p1bN3/3pp2p/q1p3p1/1n2p2P/PQPP1P2/1P2N1P1/R1BB1K1R w - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1604, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(67090, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2472800, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(102681196, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_243) {
		const char* FEN = "1n1rkbr1/3bN3/3pp2p/qpp3p1/1nQ1P2P/P1PP4/1P2N1P1/R1BB1K1R b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1307, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41463, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1749150, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(56037855, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_244) {
		const char* FEN = "1n1rkbr1/3bN3/1n1pp2p/qpp3p1/2Q1P2P/P1PP4/1P2N1P1/1RBB1K1R w - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1291, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(54224, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1707683, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(71201771, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_245) {
		const char* FEN = "1n1rkbr1/q2bN3/1n1pp2p/1pp3p1/Q3P2P/PPPP4/4N1P1/1RBB1K1R b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1178, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37124, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1414056, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45263132, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_246) {
		const char* FEN = "1n1rkb2/1q1b4/1nNpp1rp/1pp3p1/Q3P2P/PPPP4/4N1P1/1RBB1K1R w - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1276, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49983, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1557524, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(59937854, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_247) {
		const char* FEN = "1n1rkb2/1q1b4/2Npp1rp/1pp3p1/2n1P2P/PPPPQ3/4N1P1/1RBB1K1R b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1188, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37951, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1458071, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(47493366, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_248) {
		const char* FEN = "1n1rkb2/1q1b4/2Npp2r/1pp5/2n1P2p/PPPP4/4N1P1/1RBB1K1R w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1128, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36638, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1187713, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38885470, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_249) {
		const char* FEN = "1n1rkb2/1q1b4/2Npp2r/1pp5/4P2p/nPPP4/4N1P1/1RBB1K1R b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(924, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27889, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(903728, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28816272, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_250) {
		const char* FEN = "3rkb2/1q1b4/3pp2r/1pp1n3/7p/nPPP4/4N1P1/1RBB1K1R w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1038, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26307, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1026466, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26898917, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_251) {
		const char* FEN = "3rkb2/1q1b4/3pp2r/1pp5/2P3np/nP1P4/4N1P1/1RBB1KR1 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(700, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27571, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(565643, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22591540, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_252) {
		const char* FEN = "3rk3/1q1b2b1/3pp2r/1pp5/2n3np/1P1PB3/4N1P1/1R1B1KR1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1155, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25157, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1168595, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27015735, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_253) {
		const char* FEN = "3rk3/1q1b2b1/4p2r/1ppp4/B1P3np/3PB3/4N1P1/1R3KR1 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1183, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48140, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1333706, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(54321267, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_254) {
		const char* FEN = "3rk3/1q1b2b1/7r/1p1pp3/BpP3np/3PB3/4N1P1/5KR1 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1073, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24664, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1023884, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23347785, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_255) {
		const char* FEN = "3rk3/1q4b1/4b2r/1pPpp3/Bp4np/3PB3/4N1P1/5K1R b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1041, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42598, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1030120, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42505078, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_256) {
		const char* FEN = "4k3/3r2b1/1q2b2r/1pPpp3/Bp4np/3P4/4N1P1/5KBR w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(846, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17253, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(697548, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14989357, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_257) {
		const char* FEN = "3rk3/6b1/1q2b2r/1pPpp3/Bp1P2np/7R/4N1P1/5KB1 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(936, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36904, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(848525, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(34188112, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_258) {
		const char* FEN = "4k3/r5b1/1q2b2r/1pPpp3/Bp1P2nR/8/4N1P1/5KB1 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(952, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20825, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(902369, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20850061, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_259) {
		const char* FEN = "3k4/r5b1/1qP1b2r/1p1pp3/Bp1P2n1/8/4N1PR/5KB1 b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(782, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33700, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(678556, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(29075113, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_260) {
		const char* FEN = "3k4/r5b1/2P4r/1pqppb2/Bp1P2n1/2N5/6PR/5KB1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1217, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28126, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1367656, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32157613, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_261) {
		const char* FEN = "3k1q2/r5b1/2P4r/1pNppb2/Bp1P2n1/8/6PR/5KB1 b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(944, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41179, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(884926, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38583900, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_262) {
		const char* FEN = "3k4/4qrb1/2P4r/1p1ppb2/Bp1PN1n1/8/6PR/5KB1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1038, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22391, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(935521, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21164231, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_263) {
		const char* FEN = "2k5/2P1qrb1/3N3r/1p1ppb2/Bp1P2n1/8/6PR/5KB1 b - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(82, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3432, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(67484, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2774078, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_264) {
		const char* FEN = "2k2q2/2P2rb1/3r4/1p1ppb2/Bp1P2n1/8/5BPR/5K2 w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(854, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16866, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(690173, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14231684, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_265) {
		const char* FEN = "2k2q2/2P2rb1/2r5/1p1ppb2/1p1P2n1/8/5BPR/3BK3 b - -";
		Assert::AreEqual(46, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1000, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44644, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(988428, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43744967, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_266) {
		const char* FEN = "2k2q2/2Pb1rb1/2r5/1p1pp3/1p1P2B1/8/5BPn/4K3 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(647, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10395, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(405980, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6580211, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_267) {
		const char* FEN = "2k2q2/2P2rb1/2r1b3/1p1pP3/1p6/7B/5BPn/4K3 b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(604, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23621, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(362345, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14501179, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_268) {
		const char* FEN = "2k2q2/2P3b1/1B2b3/1p1pP3/1pr2r2/7B/6Pn/4K3 w - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(598, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8478, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(348811, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5126989, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_269) {
		const char* FEN = "2k2q2/2P3b1/4b3/1p1pP3/1p2rr2/4B2B/4K1Pn/8 b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(345, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12216, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(156664, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5957085, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_270) {
		const char* FEN = "2k4q/2P3b1/4b3/1p1pP3/1p2rr2/4B2B/6P1/4Kn2 w - -";
		Assert::AreEqual(7, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(227, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2279, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(83063, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1058901, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_271) {
		const char* FEN = "2k4q/2P3b1/4b3/1p1pP3/1p3r2/4r3/4B1P1/4Kn2 b - -";
		Assert::AreEqual(50, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(231, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10830, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(89503, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4053167, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_272) {
		const char* FEN = "2k5/2P3b1/4b3/1p1pPr2/1p4P1/4r3/4B3/4Kn1q w - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(129, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(780, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(33059, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(294542, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_273) {
		const char* FEN = "2k5/2P3b1/4b3/1p1pPP2/1p6/8/4r3/3K1n1q b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(144, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5362, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(22408, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(814651, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_274) {
		const char* FEN = "2k5/2P3b1/4P3/1p1pP3/1p6/5r2/8/3K1n1q w - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(176, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(853, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(28484, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(173557, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_275) {
		const char* FEN = "2k5/2P1P1b1/8/1p1pP3/1p3r2/8/4K3/5n1q b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(259, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7388, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(57305, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1706116, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_276) {
		const char* FEN = "8/2PkP1b1/8/1p1pP3/1p3r2/3K4/3n4/7q w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(391, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4619, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(143831, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1790560, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_277) {
		const char* FEN = "8/2k1P1b1/8/1p1pP3/1p3rB1/3K4/3n4/7q b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(670, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27239, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(387368, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14833983, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_278) {
		const char* FEN = "5b2/4P3/1k6/1p1pPB2/1p3r2/3K4/3n4/7q w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(914, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15366, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(606454, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9781151, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_279) {
		const char* FEN = "8/8/1k2N3/1p2PB2/1p1p1r2/3K4/3n4/7q b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(533, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(19260, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(269972, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9265806, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_280) {
		const char* FEN = "8/8/1k2N3/1p2P3/1p1p2B1/3K1r2/3n4/7q w - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(184, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2372, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(84596, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1195641, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_281) {
		const char* FEN = "8/8/1k2N3/1p2P2q/1p1p4/3K4/3nB3/8 b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(358, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9704, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(130810, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3452986, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_282) {
		const char* FEN = "1q6/8/1k6/1pN5/1p1p4/3K4/3nB3/8 w - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(358, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5524, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(141931, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2104055, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_283) {
		const char* FEN = "8/8/1k6/1pN1q2B/1p1p4/8/2Kn4/8 b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(572, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16501, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(255150, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7231284, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_284) {
		const char* FEN = "8/8/1k6/1pNq4/1p1p4/8/2K1B3/5n2 w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(606, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9294, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(257475, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3939591, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_285) {
		const char* FEN = "8/8/1kq5/1pN5/1p1p4/5B2/8/3K1n2 b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(459, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11626, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(193250, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5047908, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_286) {
		const char* FEN = "8/2k5/8/1pq5/1p1p4/5B2/4K3/5n2 w - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(371, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4346, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(118591, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1264240, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_287) {
		const char* FEN = "8/2k5/2B5/1pq5/3p4/1p6/8/5K2 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(307, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7692, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(84262, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2139087, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_288) {
		const char* FEN = "8/1B6/4k3/1pq5/3p4/1p6/8/5K2 w - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(360, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4279, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(105537, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1212767, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_289) {
		const char* FEN = "8/8/1qB1k3/1p6/3p4/1p6/8/4K3 b - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(247, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5330, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(67662, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1591099, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_290) {
		const char* FEN = "8/8/1qB1k3/1p6/3p4/1p6/4K3/8 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(296, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4165, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(91405, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1151927, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_291) {
		const char* FEN = "8/1B6/2q1k3/1p6/3p4/1p6/8/3K4 b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(239, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5525, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(53185, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1275362, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_292) {
		const char* FEN = "8/1B6/8/1p1qk3/3p4/1p6/4K3/8 w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(236, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2332, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(54943, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(558376, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_293) {
		const char* FEN = "8/8/8/1p2k3/3p4/1p6/6B1/5K2 b - -";
		Assert::AreEqual(8, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(95, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(876, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(11946, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(118080, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_294) {
		const char* FEN = "8/8/8/1p3k2/3p4/1p6/5KB1/8 w - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(138, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1959, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(18301, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(257152, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_295) {
		const char* FEN = "8/8/2B5/5k2/1p1p4/1p6/8/6K1 b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(144, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1302, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(18073, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(166603, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_296) {
		const char* FEN = "8/5k2/8/8/1p1p4/1p6/6B1/6K1 w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(123, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1650, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(14461, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(197310, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_297) {
		const char* FEN = "8/8/4k3/8/1p1p4/1p6/8/5B1K b - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(97, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(883, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(9837, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(91520, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_298) {
		const char* FEN = "8/8/4k3/8/1p1p4/8/6B1/1b5K w - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(138, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1576, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(22649, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(269252, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_299) {
		const char* FEN = "8/8/8/3Bk3/1p1p4/8/7K/1b6 b - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(231, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3329, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(45501, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(665962, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_300) {
		const char* FEN = "8/8/4b3/4k3/1p1pB3/8/7K/8 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(284, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3835, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(60566, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(784800, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_301) {
		const char* FEN = "8/8/8/4kb2/1p1p4/8/8/1B5K b - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(139, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2115, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(21809, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(329081, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_302) {
		const char* FEN = "8/8/6b1/3k1B2/1p1p4/8/8/7K w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(170, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1925, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(25908, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(307807, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_303) {
		const char* FEN = "8/8/4k3/7B/1p1p4/8/8/7K b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(90, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(762, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(8933, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(74705, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_304) {
		const char* FEN = "8/5B2/8/4k3/1p6/3p4/8/7K w - -";
		Assert::AreEqual(12, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(99, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1177, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(10020, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(121190, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_305) {
		const char* FEN = "8/8/8/1B2k3/8/1p1p4/8/7K b - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(102, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(947, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(10553, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(104312, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_306) {
		const char* FEN = "8/8/8/8/2B2k2/1p1p4/8/7K w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(99, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1149, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(10014, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(117631, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_307) {
		const char* FEN = "6B1/8/8/8/6k1/1p1p4/6K1/8 b - -";
		Assert::AreEqual(7, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(89, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(720, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(8957, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(80437, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_308) {
		const char* FEN = "6B1/8/8/8/7k/1p1p1K2/8/8 w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(56, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(730, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(5198, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(69538, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_309) {
		const char* FEN = "8/8/8/6k1/8/1B1p2K1/8/8 b - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(95, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(631, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(9412, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(74180, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_310) {
		const char* FEN = "8/5B2/8/6k1/8/6K1/8/3n4 w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(111, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1549, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(15421, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(206318, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_311) {
		const char* FEN = "8/8/7k/8/8/6K1/B7/3n4 b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(121, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1165, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(15779, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(154490, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_312) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_313) {
		const char* FEN = "rnbqkbnr/ppp1pppp/8/3p4/6P1/5P2/PPPPP2P/RNBQKBNR b KQkq -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(541, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15438, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(338556, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10132901, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_314) {
		const char* FEN = "rnbqkbnr/p1p2ppp/8/1p1pp3/6P1/1P3P2/P1PPP2P/RNBQKBNR w KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(798, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17622, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(654393, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15501201, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_315) {
		const char* FEN = "r1bqkbnr/p1p2ppp/2n5/1p1pp3/6P1/PP3P2/2PPP1BP/RNBQK1NR b KQkq -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(759, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29231, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(624373, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24042145, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_316) {
		const char* FEN = "r2qkbnr/p1p2ppp/2n5/1p2pb2/3p2P1/PP3P2/2PPP2P/RNBQKBNR w KQkq -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(811, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16324, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(671745, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14627325, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_317) {
		const char* FEN = "r2qkbnr/p1p2ppp/2n5/1p3b2/3pp1PP/PPN2P2/2PPP3/R1BQKBNR b KQkq -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1001, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41787, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1002742, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41026679, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_318) {
		const char* FEN = "r3kb1r/p1p2ppp/2n4n/1p3bq1/P2pp1PP/1PN2P2/2PPP3/R1BQKBNR w KQkq -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1166, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30119, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1307169, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(34774744, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_319) {
		const char* FEN = "r3kbr1/p1p2ppp/2n4n/1p3bq1/P2pp1PP/1PN2P1R/2PPPK2/R1BQ1BN1 b q -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1146, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49887, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1305153, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(55459530, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_320) {
		const char* FEN = "r1bnkbr1/p1p2ppp/7n/1p4q1/P2pp1PP/1PN2P1R/1BPPPK2/R2Q1BN1 w q -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1346, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38069, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1631657, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(47004887, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_321) {
		const char* FEN = "r1bnk1r1/p1p2ppp/7n/1p4q1/Pb1pp1PP/BPN2P1R/2PPPK2/RQ3BN1 b q -";
		Assert::AreEqual(49, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1329, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(61475, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1710636, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(75644036, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_322) {
		const char* FEN = "r1bnk2r/p1p2ppp/7n/1p5q/Pb1pp1PP/BPN2P1R/Q1PPPK2/R4BN1 w q -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1306, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36695, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1580613, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45452027, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_323) {
		const char* FEN = "r1bn3r/p1pk1ppp/7n/1P1N3q/1b1pp1PP/BP3P1R/Q1PPPK2/R4BN1 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1290, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49739, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1580965, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(61328183, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_324) {
		const char* FEN = "r1bn3r/p1pk1ppp/7n/1P1N4/1b1ppqPP/BP3P1R/Q1PPPK2/4RBN1 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1248, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34827, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1433971, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41976876, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_325) {
		const char* FEN = "r1bn3r/p1p2ppp/1N1k3n/1P4P1/1b1ppq1P/BP3P1R/Q1PPPK2/4RBN1 b - -";
		Assert::AreEqual(46, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1114, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46048, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1185296, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(49263201, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_326) {
		const char* FEN = "r1bn3r/2p3pp/1N1k2Pn/pP3p2/1b1ppq1P/BP3P1R/Q1PPPK2/4RBN1 w - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(977, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23522, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(878297, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22336924, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_327) {
		const char* FEN = "r2n3r/1bp3pp/1N1k2Pn/pP3p2/1b1ppq1P/BP3P1R/2PPPK2/1Q1R1BN1 b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(925, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34689, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(851149, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32863577, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_328) {
		const char* FEN = "r2n3r/1bp3pp/1N1k2Pn/pP3p2/1b1ppq1P/BP3P1R/2PPPK2/1Q2RBN1 w - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(979, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23124, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(875724, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21832529, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_329) {
		const char* FEN = "r2n3r/1bp3pp/1N1k2Pn/pP3p2/1b1pp2P/BP3PqR/2PPP1B1/1Q2RKN1 b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1135, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45297, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1200334, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(48267173, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_330) {
		const char* FEN = "r1Nn3r/1bpk2pp/6P1/pP3p2/1b1pp1nP/BP3PqR/2PPP1B1/1Q2RKN1 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1345, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33864, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1604160, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42047385, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_331) {
		const char* FEN = "r2n3r/1bp1k1pp/1N4P1/pP3p2/1b1pp1nP/BP1P1PqR/2P1P1B1/1Q2RKN1 b - -";
		Assert::AreEqual(49, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1242, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(55490, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1445881, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(64846110, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_332) {
		const char* FEN = "r6r/1bp1knpp/1N4P1/pP3p2/1b1p2nP/BP1P1pqR/1QP1P1B1/4RKN1 w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1603, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45495, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2263658, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66584818, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_333) {
		const char* FEN = "r6r/1bpk1npp/6P1/pP1N1p2/1b1p2nP/BP1P1pqR/2P1P1B1/Q3RKN1 b - -";
		Assert::AreEqual(61, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1963, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(106893, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(3419587, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(176942430, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_334) {
		const char* FEN = "r2n3r/1bpk2pp/6P1/pP1N1p2/1b1p1qnP/1P1P1p1R/2P1P1B1/Q1B1RKN1 w - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1758, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(58970, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2740662, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(91290830, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_335) {
		const char* FEN = "r2n3r/1bNk2pp/6P1/pP3p2/3pPqnP/1P1P1p1R/2P3B1/Q1B1bKN1 b - e3";
		Assert::AreEqual(50, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1630, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(76411, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2468318, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(113665410, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_336) {
		const char* FEN = "r2n3r/1bNk2pp/6P1/pP3p2/3pPq1P/1P1PB2R/2P3p1/Q3bKN1 w - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(129, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4008, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(165481, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5247775, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_337) {
		const char* FEN = "r2n1r2/1bNk2pp/6P1/pP3p2/3pPq1P/1P1PBR2/2P3p1/Q3K1N1 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1418, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(53579, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1901192, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(71359399, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_338) {
		const char* FEN = "r2n1r2/1bNk2pp/6P1/pP3p2/Q2pP2P/1P1PBR1q/2P3p1/4K1N1 w - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1222, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44683, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1415044, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(51039263, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_339) {
		const char* FEN = "r1bn1r2/2Nk2pp/6P1/pP3p2/3QP2P/1P1PBR1q/2P1N1p1/4K3 b - -";
		Assert::AreEqual(2, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(95, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2475, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(101758, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2829591, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_340) {
		const char* FEN = "r1bn1r2/2k3p1/6p1/pP3p2/4P2P/1P1PBR1q/2P1N1p1/Q3K3 w - -";
		Assert::AreEqual(47, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1384, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(53146, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1648415, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(60262481, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_341) {
		const char* FEN = "r1bn1r2/2k3p1/6p1/pP3p2/4P2P/1P1P3R/2P1NB2/Q3K1n1 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1086, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26365, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1002897, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25397051, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_342) {
		const char* FEN = "r1b2r2/3k2p1/2n3p1/pP3p2/3BP2P/1P1P3R/2P1N3/Q3K1n1 w - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1256, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49324, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1412942, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(53460187, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_343) {
		const char* FEN = "r1br4/3k2p1/2n3p1/pP3p2/Q2BP2P/1P1P2R1/2P1N3/4K1n1 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1029, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26726, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1027974, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27262148, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_344) {
		const char* FEN = "r1br4/2k3p1/6p1/pP3p2/1Q1nP2P/1P1P2R1/2P1N3/4K1n1 w - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(895, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27829, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(750360, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23299508, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_345) {
		const char* FEN = "r1br4/2k3p1/6p1/pn3pR1/1Q1PP2P/1P6/2P1N3/4K1n1 b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1023, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26693, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(845722, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22174914, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_346) {
		const char* FEN = "r1b1r3/1k4p1/6p1/pn3pR1/2QPP2P/1P6/2P1N3/4K1n1 w - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(863, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28827, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(712577, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23430242, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_347) {
		const char* FEN = "r1Qr4/1k4p1/6p1/pn3R2/3PP2P/1P6/2P1N3/4K1n1 b - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(164, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3975, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(117042, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2911569, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_348) {
		const char* FEN = "r1kr4/6p1/6p1/p4R2/3PP2P/1Pn5/4N3/4K1n1 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(693, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15435, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(405444, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8652645, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_349) {
		const char* FEN = "r1kr4/6p1/6p1/R7/1P1PP2P/8/4N3/3nK1n1 b - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(572, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14373, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(307219, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8220109, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_350) {
		const char* FEN = "2kr4/6p1/6p1/r6P/1P1PP3/8/4N3/3nK1n1 w - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(453, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5864, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(183278, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2284288, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_351) {
		const char* FEN = "2k2r2/6p1/6p1/r6P/1P1PP3/8/3K4/3n2N1 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(496, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16452, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(209109, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6595995, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_352) {
		const char* FEN = "2k2r2/6p1/8/r3P1pP/1P1P4/2n5/3K4/6N1 w - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(494, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6047, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(200017, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2462141, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_353) {
		const char* FEN = "2k2r2/6p1/4P3/r5pP/1P1P4/7N/n2K4/8 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(421, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12241, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(165001, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4667154, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_354) {
		const char* FEN = "1k3r2/6p1/4P3/r6P/1P1P2p1/3K3N/n7/8 w - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(509, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6757, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(211370, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2824791, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_355) {
		const char* FEN = "2k2r2/6p1/4P3/r2P3P/1P4p1/7N/n1K5/8 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(405, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11863, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(153995, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4376351, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_356) {
		const char* FEN = "5r2/1k4p1/4P3/r2P3P/1P4p1/7N/nK6/8 w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(452, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5805, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(183104, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2418232, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_357) {
		const char* FEN = "5r2/1k6/4P3/r2P2pP/1P2N1p1/8/nK6/8 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(540, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14857, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(222436, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6016135, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_358) {
		const char* FEN = "2k2r2/8/r3P3/1P1P2pP/4N1p1/8/nK6/8 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(431, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6641, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(166016, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2435861, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_359) {
		const char* FEN = "2k5/4P3/r7/1PNP2pP/6p1/5r2/nK6/8 b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(579, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14803, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(250268, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6055912, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_360) {
		const char* FEN = "2k1N3/8/r7/1PNP2pP/6p1/5r2/nK6/8 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(549, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9244, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(245377, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3898537, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_361) {
		const char* FEN = "2k1N3/1N6/r7/1P1P2pP/8/5rp1/n7/K7 b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(393, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9985, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(124304, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3169457, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_362) {
		const char* FEN = "2kNN3/r7/8/1P1P2pP/8/2n2rp1/8/K7 w - -";
		Assert::AreEqual(1, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(36, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(474, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(15018, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(207452, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_363) {
		const char* FEN = "2kNN3/r7/8/1P1P2pP/8/2n1r1p1/2K5/8 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(519, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16477, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(237605, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7169511, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_364) {
		const char* FEN = "2kNN3/5r2/7P/1P1n2p1/8/4r1p1/2K5/8 w - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(512, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7303, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(231451, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3380632, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_365) {
		const char* FEN = "2Nk4/5r2/7P/1P1n2p1/8/4r1p1/2K5/8 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(393, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14022, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(141087, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4652254, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_366) {
		const char* FEN = "2Nk4/4r3/7P/1P1n2p1/8/6p1/1K6/4r3 w - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(363, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3612, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(118116, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1235124, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_367) {
		const char* FEN = "3k4/N2r4/7P/1P1n2p1/8/K5p1/8/4r3 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(261, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8089, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(68491, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2120030, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_368) {
		const char* FEN = "4k3/5r2/2N4P/1P1n2p1/8/K5p1/8/4r3 w - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(554, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6287, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(226773, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2559080, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_369) {
		const char* FEN = "4k2R/5r2/2N1r3/1P1n2p1/8/K5p1/8/8 b - -";
		Assert::AreEqual(2, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(49, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1451, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(30786, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(924634, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_370) {
		const char* FEN = "6R1/3k1r2/2N1r3/1P1n2p1/8/K7/6p1/8 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(763, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15176, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(498458, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9562680, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_371) {
		const char* FEN = "6R1/3kNr2/4r3/1P1n4/6p1/8/1K4p1/8 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(851, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30034, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(604944, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20553909, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_372) {
		const char* FEN = "3R4/4Nr2/1k2r3/1P1n4/6p1/8/1K4p1/8 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(759, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15841, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(530768, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10662729, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_373) {
		const char* FEN = "3R4/4Nr2/1kr5/1P1n4/6p1/1K6/6p1/8 b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(818, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26483, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(527481, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17042884, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_374) {
		const char* FEN = "8/k3Nr2/2rR4/1P1n4/6p1/1K6/8/6n1 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(576, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11472, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(334167, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6738685, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_375) {
		const char* FEN = "8/k4r2/3r4/1P1N4/K5p1/8/8/6n1 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(362, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10487, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(116524, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3333637, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_376) {
		const char* FEN = "8/k2rN3/5r2/1P6/K5p1/8/8/6n1 w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(270, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2907, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(79975, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(845937, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_377) {
		const char* FEN = "3r4/k3N3/5r2/1P6/6p1/2K5/8/6n1 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(410, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10880, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(130245, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3590156, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_378) {
		const char* FEN = "5r2/k7/8/1P3N2/6p1/2Kr4/8/6n1 w - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(146, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1846, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(52164, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(578940, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_379) {
		const char* FEN = "r7/k5N1/8/1P6/6p1/3r4/2K5/6n1 b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(245, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6241, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(60472, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1612682, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_380) {
		const char* FEN = "1r6/k5N1/3r4/1P6/6p1/8/8/1K4n1 w - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(279, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2755, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(75567, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(775187, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_381) {
		const char* FEN = "1r1N4/k7/8/1P1r4/6p1/8/8/1K4n1 b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(213, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4894, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(44352, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1127021, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_382) {
		const char* FEN = "1r6/k7/8/1P6/6p1/8/8/K2r2n1 w - -";
		Assert::AreEqual(2, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(58, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(298, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(7794, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43230, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_383) {
		const char* FEN = "1r6/k7/8/1P6/6p1/2K5/8/r5n1 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(210, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5621, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(33228, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(893481, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_384) {
		const char* FEN = "8/k7/4r3/1P6/2K3p1/8/8/r5n1 w - -";
		Assert::AreEqual(8, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(229, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1330, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(37234, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(213803, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_385) {
		const char* FEN = "4r3/k7/1P6/8/6p1/3K4/8/r5n1 b - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(28, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(892, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(5233, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(164652, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_386) {
		const char* FEN = "k3r3/r7/1P6/8/6p1/8/2K5/6n1 w - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(278, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1711, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(43734, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(274876, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_387) {
		const char* FEN = "k3r3/r7/1P6/8/6p1/7n/2K5/8 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(281, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7970, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(47817, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1264909, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_388) {
		const char* FEN = "k3r3/8/1P6/3r4/6p1/3K3n/8/8 w - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(102, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(582, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(16090, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(99719, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_389) {
		const char* FEN = "k3r3/8/1P6/r7/1K4p1/7n/8/8 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(167, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4261, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(25673, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(691794, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_390) {
		const char* FEN = "r7/1k6/1P6/K7/6p1/7n/8/8 w - -";
		Assert::AreEqual(2, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(45, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(217, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(4558, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26972, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_391) {
		const char* FEN = "5r2/1k6/1P6/8/K5p1/7n/8/8 b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(118, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2615, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(15008, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(328754, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_392) {
		const char* FEN = "5r2/1P6/1k6/8/K5p1/7n/8/8 w - -";
		Assert::AreEqual(7, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(132, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1222, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(24270, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(261782, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_393) {
		const char* FEN = "1r6/8/1k6/8/1K4p1/7n/8/8 b - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(91, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2085, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(10276, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(243225, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_394) {
		const char* FEN = "7r/8/1k6/6n1/2K3p1/8/8/8 w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(168, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1027, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(27110, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(159509, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_395) {
		const char* FEN = "7r/1k6/3K4/6n1/6p1/8/8/8 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(136, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3428, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(16684, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(405669, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_396) {
		const char* FEN = "k7/3K4/8/6n1/6p1/8/7r/8 w - -";
		Assert::AreEqual(7, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(163, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(801, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(17800, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(93543, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_397) {
		const char* FEN = "k2K4/8/8/6n1/6p1/8/4r3/8 b - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(81, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1767, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(7499, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(165426, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_398) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_399) {
		const char* FEN = "rnbqkbnr/1ppppppp/p7/8/8/1P6/PBPPPPPP/RN1QKBNR b KQkq -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(511, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10922, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(294596, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7042743, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_400) {
		const char* FEN = "rnbqkbnr/1p1p1ppp/p1p5/4p3/P7/1P6/1BPPPPPP/RN1QKBNR w KQkq -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(778, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20611, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(621649, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17065425, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_401) {
		const char* FEN = "rnbqkb1r/1p1p1ppp/p1p2n2/4p3/P7/1P2P1P1/1BPP1P1P/RN1QKBNR b KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1026, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30801, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1095857, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(34245244, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_402) {
		const char* FEN = "rnb1kb1r/1p1p1ppp/p1p2n2/1q2p3/P5P1/1P2P3/1BPP1P1P/RN1QKBNR w KQkq -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1156, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36880, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1281512, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41147926, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_403) {
		const char* FEN = "rnb1kb1r/1p1p1ppp/p1p2n2/4p3/P5P1/1qB1P3/2PPNP1P/RN1QKB1R b KQkq -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1008, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38047, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1102194, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41379431, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_404) {
		const char* FEN = "rnb1k2r/1p1p1ppp/pbp2n2/4p3/P4PP1/1qB1P3/2PPN2P/RN1QKB1R w KQkq -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1093, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(31648, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1264174, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38255332, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_405) {
		const char* FEN = "rnb2k1r/1p1p1ppp/pbp2n2/4p3/P4PP1/1qB1P3/2PPQ2P/RN2KBNR b KQ -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1225, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(47546, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1530762, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(58722822, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_406) {
		const char* FEN = "rnb2k1r/1p1p1pp1/p1p2n1p/2b1p1P1/P4P2/1qB1P3/2PPQ2P/RN2KBNR w KQ -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1559, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(56128, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2293549, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(83128822, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_407) {
		const char* FEN = "rnb2k1r/1p1p1pp1/2p2n1p/1pb1pPP1/P7/1qB1P3/2PP3P/RN2KBNR b KQ -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1334, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(57679, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1681259, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(70241389, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_408) {
		const char* FEN = "rnb2k2/1p1p1p1r/2p2nPp/1pb1p1P1/P7/1qB1P3/2PP3P/RN2KBNR w KQ -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1422, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44995, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1884769, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(58929251, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_409) {
		const char* FEN = "rnb2k2/bp1p1p1P/2p2P1p/1p2p3/P7/1qB1P3/2PP3P/RN2KBNR b KQ -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(746, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18235, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(534014, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13642878, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_410) {
		const char* FEN = "r1b2k2/bp1p1p1P/n1p2P1p/4B3/Pp6/1q2P3/2PP3P/RN2KBNR w KQ -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(967, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32474, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(835636, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27121398, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_411) {
		const char* FEN = "r1b1k2Q/bp1p1p2/n1pB1P1p/8/Pp6/1q2P3/2PP3P/RN2KBNR b KQ -";
		Assert::AreEqual(0, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_412) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_413) {
		const char* FEN = "rnbqkbnr/pppp1ppp/4p3/8/4P3/5P2/PPPP2PP/RNBQKBNR b KQkq -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(751, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22822, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(586355, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18209820, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_414) {
		const char* FEN = "rnbqkbnr/1ppp1pp1/4p2p/p7/4P3/5P2/PPPP1KPP/RNBQ1BNR w kq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(866, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24021, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(726774, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20567096, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_415) {
		const char* FEN = "rnbqkbnr/1ppp1pp1/4p3/p6p/1P2P3/5P2/P1PPQKPP/RNB2BNR b kq -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(866, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28056, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(807478, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26471915, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_416) {
		const char* FEN = "rnbqkbnr/1ppp4/4p1p1/p4p1p/1P2P3/5P2/P1PP1KPP/RNBQ1BNR w kq -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1082, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32640, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1107158, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33509021, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_417) {
		const char* FEN = "rnbqk1nr/1ppp4/4p1p1/pPb2p1p/3PP3/5P2/P1P2KPP/RNBQ1BNR b kq -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1142, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38630, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1279346, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43362539, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_418) {
		const char* FEN = "rnbqk2r/1ppp4/1b2p1pn/pP3p1p/3PP3/5PK1/P1P3PP/RNBQ1BNR w kq -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(979, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27778, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(885259, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25516750, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_419) {
		const char* FEN = "rnbq3r/1ppp1k2/1b2p1pn/pP3p1p/3PP3/5PK1/P1P1Q1PP/RNB2BNR b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1012, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35127, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(999959, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(34334271, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_420) {
		const char* FEN = "rnbq1r2/1ppp1k2/1b2p2n/pP3ppp/3PP3/5PK1/PBP1Q1PP/RN3BNR w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(800, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21175, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(664118, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18469608, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_421) {
		const char* FEN = "rnb2r2/1pppqk2/1b2p2n/pP3ppp/P2PP3/5PK1/1BPNQ1PP/R4BNR b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(918, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(31948, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(885742, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(31053279, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_422) {
		const char* FEN = "rnb2r2/1pppqk2/1b2p3/pP3pp1/P2PP1np/5P1K/1BPNQ1PP/R4BNR w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(927, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24504, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(878056, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24452479, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_423) {
		const char* FEN = "rnbr4/1pppqk2/1b2p3/pP3pp1/P2PP1np/3Q1P1K/1BPN2PP/1R3BNR b - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(951, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35039, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(971596, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35437733, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_424) {
		const char* FEN = "rnbr4/1pppq3/1b2pk2/pP4p1/P2Pp1np/1Q3P1K/1BPN2PP/1R3BNR w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1008, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30917, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1021059, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(31850214, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_425) {
		const char* FEN = "rnbr4/1pppq1k1/1b2p3/pP4p1/P2Pp1np/1QB2P1K/2PNB1PP/1R4NR b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1179, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44865, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1395850, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(52005447, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_426) {
		const char* FEN = "rnbr4/1ppp2k1/1b2pq2/pP4p1/P2Pp2p/1QB1nP1K/1RPNB1PP/6NR w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(983, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24318, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(985905, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26550774, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_427) {
		const char* FEN = "r1br4/1ppp2k1/nb2pq2/pP4p1/P2Pp2p/1QB1nPPK/1RPN3P/5BNR b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1049, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45233, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1173998, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(48617793, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_428) {
		const char* FEN = "r1b3r1/1ppp2k1/nb2p3/pP4p1/P2qp2p/Q1B1nPPK/1RPN3P/5BNR w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(968, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28357, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1022796, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30845505, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_429) {
		const char* FEN = "r1b2r2/1ppp2k1/nb2p3/pP4p1/P2qp2p/2B1nPPK/QRP4P/1N3BNR b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1033, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43072, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1133069, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(47837258, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_430) {
		const char* FEN = "r1b2r2/1p1p2k1/nbp5/pP2p1p1/P2qp2p/2B1nPPK/1RP4P/QN3BNR w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1158, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27536, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1327163, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33923949, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_431) {
		const char* FEN = "r1b2r2/1p1p2k1/nbp5/pP2p1p1/P1Bq3p/2B1npPK/R1P4P/QN4NR b - -";
		Assert::AreEqual(50, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1134, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(55446, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1328245, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(63238046, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_432) {
		const char* FEN = "r1b2r2/1p1p2k1/nb1q4/pp2p1p1/P1B4p/2B1npPK/RQP4P/1N4NR w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1545, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45221, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2206800, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66434953, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_433) {
		const char* FEN = "r1b2r2/1p1p2k1/nb1q4/p3p1p1/PBp4p/4npPK/1QP4P/RN4NR b - -";
		Assert::AreEqual(53, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1229, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(59419, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1447371, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(67473824, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_434) {
		const char* FEN = "r1b2r2/1p1p2k1/nb6/Bq2p1p1/P1p4p/4npPK/1QP4P/RN4NR w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1143, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28100, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1262752, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33064961, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_435) {
		const char* FEN = "r1b3r1/1p1p2k1/nb6/Bq2p1p1/P1pQ3p/4nNPK/2P4P/RN5R b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1738, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(72622, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2673665, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(108481201, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_436) {
		const char* FEN = "r1b3rk/1p6/nb6/Bq1pp1p1/P1pQ3p/4n1PK/2PN3P/RN5R w - -";
		Assert::AreEqual(2, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(84, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2188, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(90540, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2575658, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_437) {
		const char* FEN = "r1b3rk/1p6/n7/Bqbpp1p1/P1p3Qp/4n1PK/2PN3P/RN3R2 b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1369, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(61162, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1868162, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(82296949, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_438) {
		const char* FEN = "1rb3rk/1p6/n7/Bqbpp1p1/P1p3Qp/5NPK/2P3nP/RN3R2 w - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1384, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43908, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1804816, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(58331759, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_439) {
		const char* FEN = "1r4rk/1p6/n7/Bqbppbp1/P1p2RQN/6PK/2P3nP/RN6 b - -";
		Assert::AreEqual(56, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1468, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(73406, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2127541, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(100047354, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_440) {
		const char* FEN = "1r4rk/1p6/n7/Bq1pp1p1/P1p1R1bN/6PK/2P3nP/RN4b1 w - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(134, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3418, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(145880, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3891950, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_441) {
		const char* FEN = "1r4rk/1p6/n7/B2pp1p1/P1p3KN/4R1P1/1qP3nP/RN4b1 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1146, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46801, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1268638, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(52497963, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_442) {
		const char* FEN = "1r4rk/1p6/n7/B2pp1p1/P5KN/1p4P1/2q3nP/RN4b1 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(965, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17940, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(837242, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16630421, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_443) {
		const char* FEN = "r5rk/1p6/n7/3pp1p1/PB4K1/1p4P1/2q3NP/RN4b1 b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1072, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(51344, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1076950, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(49277574, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_444) {
		const char* FEN = "r5rk/1p6/n7/3pp1pq/PB6/1p4PK/6NP/RN4b1 w - -";
		Assert::AreEqual(1, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(43, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(699, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(29691, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(518142, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_445) {
		const char* FEN = "r5rk/1p2B3/n7/3pp1p1/P6N/1p3qPK/7P/RN4b1 b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(840, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35919, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(667974, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28414999, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_446) {
		const char* FEN = "6rk/rp6/n7/2bpp1B1/P6N/1p3qPK/7P/RN6 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(754, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13861, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(578135, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11631715, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_447) {
		const char* FEN = "6rk/rp2B3/n7/2bpp3/P6N/1p4P1/6KP/RN6 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(649, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17913, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(415486, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11689292, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_448) {
		const char* FEN = "7k/rp2B3/n7/2bpp3/P6N/Rp4P1/5rKP/1N6 w - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(99, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1581, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(46619, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(884321, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_449) {
		const char* FEN = "7k/rp2B3/n7/2bpp3/P4r1N/1p4PK/7P/RN6 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(648, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(19066, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(401858, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11963081, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_450) {
		const char* FEN = "6k1/rp6/n4B2/2bpp3/P4r1N/1p4PK/7P/RN6 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(647, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13388, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(429517, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9678090, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_451) {
		const char* FEN = "6k1/rp6/n4B2/P1bppr2/8/1p4PK/6NP/RN6 b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(559, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17012, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(358440, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11237335, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_452) {
		const char* FEN = "6k1/rp6/n4B1r/P1bpp3/6K1/1p4P1/6NP/RN6 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(687, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15366, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(481170, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11439721, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_453) {
		const char* FEN = "6k1/rp6/nb3B1r/P2pp1K1/8/1p4P1/7P/RN2N3 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(527, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14687, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(314442, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9022442, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_454) {
		const char* FEN = "6k1/rp6/1b3B1r/P1npp1K1/8/6P1/1p1N3P/R3N3 w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(966, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24207, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(819564, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20541761, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_455) {
		const char* FEN = "5k2/rp6/Pb3B1r/R1npp1K1/8/6P1/1p1N3P/4N3 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(730, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22270, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(557140, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17811926, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_456) {
		const char* FEN = "5k2/rp6/P4B1r/R2pp1K1/8/1n4P1/1p3b1P/1N2N3 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(773, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18845, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(583930, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14490257, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_457) {
		const char* FEN = "3B1k2/rp6/P6r/R2pp1K1/8/1n1N2P1/1p5P/1N4b1 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(961, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32290, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(855487, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28282354, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_458) {
		const char* FEN = "3B1k2/rp6/P7/R2pp1K1/8/6Pr/1p5P/nN2N1b1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(614, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14400, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(401456, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9893959, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_459) {
		const char* FEN = "5k2/1pB5/r7/3pp1K1/R7/6Pr/1p5P/nN2N1b1 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(916, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30634, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(769341, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25811439, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_460) {
		const char* FEN = "5k2/2B5/r7/1p1pp1K1/R7/1n4Pr/1p4NP/1N4b1 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1048, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25792, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(933062, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22890658, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_461) {
		const char* FEN = "5k2/2B5/6r1/Rp1ppK2/8/1n4Pr/1p4NP/1N4b1 b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(847, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30439, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(689748, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24444089, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_462) {
		const char* FEN = "5k2/2B5/6rr/1p1ppK2/8/Rn4P1/1p4N1/1N4b1 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(782, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17013, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(622484, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14164651, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_463) {
		const char* FEN = "1B3k2/6r1/7r/1p1ppK2/5N2/Rn4P1/1p6/1N4b1 b - -";
		Assert::AreEqual(47, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1046, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40904, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(950815, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35914680, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_464) {
		const char* FEN = "1B3k2/6r1/7r/1p1ppK2/4n3/R5P1/1p4N1/1N4b1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1085, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22792, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(941251, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20505827, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_465) {
		const char* FEN = "1B3k1r/6r1/8/1p1ppK2/4n3/6P1/Rp1N2N1/6b1 b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1019, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42497, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1010455, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(40610868, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_466) {
		const char* FEN = "1B3k2/6r1/8/1p1ppK1r/4N3/6P1/Rp4N1/6b1 w - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(109, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2464, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(83244, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2042045, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_467) {
		const char* FEN = "1B3k2/6r1/8/1p1pp1N1/6K1/6P1/Rp4N1/6br b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(639, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21088, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(464595, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15122478, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_468) {
		const char* FEN = "1B3k2/2r5/1b6/1p1pp1N1/6K1/R5P1/1p4N1/7r w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1050, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25959, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(997991, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24921881, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_469) {
		const char* FEN = "1B6/2r1k3/1b6/1p1pp1N1/8/R3NKP1/1p6/7r b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1200, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44895, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1202493, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43888003, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_470) {
		const char* FEN = "1Br5/4k3/1b6/1p1pp3/8/R3NKPN/1p6/7r w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1199, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32682, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1227470, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32198356, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_471) {
		const char* FEN = "2rb4/4k3/8/1p1pB3/6P1/R3NK1N/1p6/7r b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1159, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35286, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1182713, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(37556207, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_472) {
		const char* FEN = "2rb4/2r1k3/8/1p1pB3/6P1/R4K1N/1p6/3N4 w - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(764, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26054, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(645794, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20670048, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_473) {
		const char* FEN = "r2b4/2r1k3/8/1p1p4/6P1/R1N2KBN/1p6/8 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(867, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23435, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(724771, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21123838, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_474) {
		const char* FEN = "r2b4/2r2k2/8/1p6/3p2P1/R1N2KB1/1p6/6N1 w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1089, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32899, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1122931, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32840477, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_475) {
		const char* FEN = "r2b4/r4k2/8/1p6/3p1KP1/R1N3B1/1p6/6N1 b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(795, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25501, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(640016, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21060669, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_476) {
		const char* FEN = "2rb4/r7/6k1/1p6/3p1KP1/R1N2NB1/1p6/8 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1027, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27793, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(944594, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25173921, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_477) {
		const char* FEN = "2rb4/r7/6k1/1p6/3p1KP1/R1N2NB1/8/1r6 b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1206, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46058, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1228059, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(46344569, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_478) {
		const char* FEN = "r1rb4/8/5k2/1p2N3/3p1KP1/R1N3B1/8/1r6 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(776, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21947, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(625979, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17198382, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_479) {
		const char* FEN = "r1rb4/6k1/8/1p6/2Np1KP1/1RN3B1/8/1r6 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1123, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44226, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1220378, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(47268334, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_480) {
		const char* FEN = "r1r5/6k1/5b2/1p6/2Np2P1/1RN2KB1/8/1r6 w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1488, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48819, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1988941, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(62158299, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_481) {
		const char* FEN = "r1r5/8/5b1k/1p6/2Np2PB/1RN5/5K2/1r6 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1078, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40711, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1103781, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(40946471, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_482) {
		const char* FEN = "2r5/8/5b1k/rp6/3p2PB/1RN5/1N3K2/3r4 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(844, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20081, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(723373, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17822644, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_483) {
		const char* FEN = "2r5/8/5b1k/rp6/2Np2PB/1R6/5K2/1N2r3 b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1164, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46155, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1156641, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43837150, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_484) {
		const char* FEN = "2r5/8/5b1k/1p6/2Np2P1/1R4B1/5K2/rN5r w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1216, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33106, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1290524, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(34686893, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_485) {
		const char* FEN = "r7/8/5b1k/1p6/2Np2P1/1R4B1/5K2/rN5r b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1204, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46796, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1250103, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(46526861, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_486) {
		const char* FEN = "r7/8/5b1k/1p6/2Np2P1/1R4B1/8/1r3K2 w - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(173, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4616, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(140147, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3573384, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_487) {
		const char* FEN = "r7/7k/5b2/1p6/2Np2P1/1R4B1/5K2/1r6 b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(968, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33837, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(840135, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27718872, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_488) {
		const char* FEN = "8/7k/5b2/1p6/3p2P1/1R4B1/r2N1K2/3r4 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(628, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13176, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(401420, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8993982, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_489) {
		const char* FEN = "r7/7k/5b2/1p2B3/3p2P1/1R6/3N1K2/3r4 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(963, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(31019, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(795144, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24844344, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_490) {
		const char* FEN = "8/7k/5b2/1R2B3/3p2P1/5r2/3N1K2/3r4 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(107, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2670, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(67966, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1751559, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_491) {
		const char* FEN = "8/7k/5b2/R3B3/3p2P1/5r2/3N2K1/r7 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(863, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27164, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(704821, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21080918, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_492) {
		const char* FEN = "8/7k/8/4B3/6Pb/3p1r2/R2N2K1/r7 w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(831, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22318, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(611079, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16378640, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_493) {
		const char* FEN = "8/7k/8/8/6Pb/3p1KB1/r2N4/8 b - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(378, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8535, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(148900, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3412147, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_494) {
		const char* FEN = "8/5k2/8/8/6Pb/1N1p1KB1/r7/8 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(520, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9529, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(239797, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4298508, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_495) {
		const char* FEN = "8/5k2/8/N7/6Pb/3p2B1/5K2/8 b - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(184, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2480, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(41627, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(586258, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_496) {
		const char* FEN = "8/1N6/6k1/8/6Pb/3p2B1/5K2/8 w - -";
		Assert::AreEqual(12, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(132, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2104, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(25265, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(426963, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_497) {
		const char* FEN = "8/1N6/7k/8/6Pb/3pK1B1/8/8 b - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(182, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2124, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(36294, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(458273, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_498) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_499) {
		const char* FEN = "rnbqkbnr/pp1ppppp/8/2p5/8/P2P4/1PP1PPPP/RNBQKBNR b KQkq -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(551, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13511, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(352927, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9475535, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_500) {
		const char* FEN = "rnbqkbnr/p2ppp1p/8/1pp3p1/8/P2P1N2/1PP1PPPP/RNBQKB1R w KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(674, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18621, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(490486, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13982737, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_501) {
		const char* FEN = "rnbqkb1r/p2ppp1p/5n2/1pp3p1/5B2/P2P4/1PPNPPPP/RN1QKB1R b KQkq -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(738, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21187, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(600908, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18123208, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_502) {
		const char* FEN = "rnb1kb1r/p2ppp1p/1q3n2/1pp5/5p2/PP1P4/2PNPPPP/RN1QKB1R w KQkq -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(612, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12915, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(430332, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9900651, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_503) {
		const char* FEN = "rn2kb1r/p2ppp1p/bq3n2/1pp5/1P3p2/P1PP4/3NPPPP/RN1QKB1R b KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(589, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17940, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(411320, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13071714, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_504) {
		const char* FEN = "rn2kbnr/p2ppp2/bq6/1pp4p/1P3p2/P1PP4/3NPPPP/RNQ1KB1R w KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(634, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14586, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(444924, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10977201, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_505) {
		const char* FEN = "rn2kbnr/p2pp3/bq3p2/1pp4p/1P3p1P/P1PP1N2/4PPP1/RNQ1KB1R b KQkq -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(649, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16924, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(457760, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12650259, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_506) {
		const char* FEN = "r3kbnr/p3p3/bqnp1p2/1pp4p/1P3p1P/P1PP1N2/3KPPP1/RNQ2B1R w kq -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(789, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20061, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(630780, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16454035, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_507) {
		const char* FEN = "r3k1nr/p3p3/bqnp1p1b/1pp4p/1P3p1P/P1PP1N2/4PPPR/RNQK1B2 b kq -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(808, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25081, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(674056, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21250071, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_508) {
		const char* FEN = "r2nk1nr/p3p3/b1qp1p1b/1pp4p/1P3pPP/P1PP1N2/4PP1R/RNQK1B2 w kq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(864, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25072, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(784614, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23018537, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_509) {
		const char* FEN = "r2nk1nr/p3p3/b1qp1p2/1pp3bp/1P3pPP/P1PP3B/4PP1R/RNQK4 b kq -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(739, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25045, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(612529, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21085951, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_510) {
		const char* FEN = "r2nk1nr/p3p3/b1qp1p2/1pp3bp/PP3pPP/2PP3B/4PP1R/RNQK4 w kq -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(914, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25380, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(879811, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25368396, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_511) {
		const char* FEN = "r2nk1nr/p3p3/b1qp1p2/2p3Pp/pP3pP1/2PP3B/3NPP1R/R1QK4 b kq -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1104, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42014, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1265833, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(48090138, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_512) {
		const char* FEN = "r1bnk1nr/p3p3/1q1p1p2/2p3Pp/pP3pP1/2PP1N1B/4PP1R/R1QK4 w kq -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1224, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41033, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1509358, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(51196131, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_513) {
		const char* FEN = "r1bnk1n1/p3p3/1q1p1p1r/2p3Pp/pPPN1pP1/3P3B/4PP1R/R1QK4 b q -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1311, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48570, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1679934, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(61104658, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_514) {
		const char* FEN = "r1bnk1n1/p7/q2p1p1r/2p1p1Pp/pPPN1pP1/3P4/4PP1R/R1QK1B2 w q -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1295, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48099, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1676557, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(61212990, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_515) {
		const char* FEN = "r1bnk1n1/p7/q2p3P/2p1pp1p/pPPN1pP1/3P3R/4PP2/R1QK1B2 b q -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1187, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37765, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1407813, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45620115, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_516) {
		const char* FEN = "r2nk1n1/p7/q1bp3P/2p1pp1p/pPPN1pP1/3P3R/2K1PP2/R1Q2B2 w q -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1394, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(53196, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1816796, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(68205186, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_517) {
		const char* FEN = "r3k1n1/p7/q1bpn2P/2p1pp1p/pPPN1pP1/3P3R/1QK1PP2/2R2B2 b q -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1470, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(58548, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2074049, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(79693536, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_518) {
		const char* FEN = "r5n1/p2bk3/q2pn2P/2p1pp1p/pPPN1pP1/Q2P3R/2K1PP2/2R2B2 w - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1361, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49022, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1748549, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(63042782, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_519) {
		const char* FEN = "r5n1/p2bk3/q2pn2P/2p1pp2/pPP2pPp/QN1P3R/2K1PP2/R4B2 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1169, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41663, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1400040, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(50483823, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_520) {
		const char* FEN = "5rn1/p1nbk3/q2p3P/2p1pp2/pPP2pPp/Q2P3R/2KNPP2/R4B2 w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1309, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45420, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1619451, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(56095614, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_521) {
		const char* FEN = "5rn1/p1n1k3/q1bp3P/2P1pp2/p1P2pPp/Q2PR3/2KNPP2/R4B2 b - -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1427, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(55608, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1830415, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(69683095, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_522) {
		const char* FEN = "b4rn1/p3k3/q2pn2P/2P1pp2/p1P1NpPp/Q2PR3/2K1PP2/R4B2 w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1280, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43912, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1598746, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(55160111, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_523) {
		const char* FEN = "b4rn1/p3k3/q2N3P/2P1ppn1/p1P2pPp/Q2PR3/4PP2/R2K1B2 b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1236, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44338, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1470793, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(53449688, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_524) {
		const char* FEN = "b4rn1/p3k3/2qN3P/2P1pp2/p1P2pPp/Q2PRn2/4PP2/R1K2B2 w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(994, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30816, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1077938, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(34929896, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_525) {
		const char* FEN = "b4rn1/p3k3/2qN3P/2P1p3/p1P2ppp/Q2PRP2/1K3P2/R4B2 b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(996, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(31658, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(984666, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(31668153, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_526) {
		const char* FEN = "b4rn1/p2k4/2qN3P/2P1p3/p1P2p1p/1Q1PRPp1/1K3P2/R4B2 w - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1355, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(50445, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1658139, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(59671035, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_527) {
		const char* FEN = "b1r3n1/p2k4/2qN3P/2P1p3/p1P2p1p/3PRPp1/1K3P2/3QRB2 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(876, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27912, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(800872, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26277620, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_528) {
		const char* FEN = "b1r3n1/p2k4/2qN3P/2P1p3/p1PP1p1p/4RPp1/1K3P2/3QRB2 w - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1213, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41741, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1332829, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(46079785, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_529) {
		const char* FEN = "b1r5/p2k4/2q4n/2P1p3/p1PPNp1p/4RPp1/1K3PB1/3QR3 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1191, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41749, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1399507, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(50230465, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_530) {
		const char* FEN = "2r5/p2k4/2b4n/2Pqp3/p1PPNp1p/4RPp1/1K2RPB1/3Q4 w - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1265, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42992, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1484687, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(49576074, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_531) {
		const char* FEN = "2r5/p1k5/2b4n/2Pqp3/Q1PPNp1p/4RPpB/1K2RP2/8 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1454, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49837, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1936628, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66737875, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_532) {
		const char* FEN = "6nr/p1k5/2b5/2Pqp3/Q1PPNp1p/4RPPB/1K2R3/8 w - -";
		Assert::AreEqual(48, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1352, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(60364, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1851755, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(79393107, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_533) {
		const char* FEN = "6nr/p1k5/2bN4/2P1p3/2PPqp1p/4RPPB/QK2R3/8 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1223, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37493, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1475983, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(46876636, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_534) {
		const char* FEN = "6nr/2kB4/3N4/pbP1p3/2PPqp1p/4RPP1/QK2R3/8 w - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1332, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(53426, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1633892, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(65135791, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_535) {
		const char* FEN = "6nr/3k4/3N4/QbP1p3/2PPqp1p/R4PP1/1K2R3/8 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1270, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36593, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1484959, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43636980, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_536) {
		const char* FEN = "3r4/3k4/3N3n/QbP1p3/2PPqp1p/5PP1/1K2R3/R7 w - -";
		Assert::AreEqual(52, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1664, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(73587, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2381671, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(100355765, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_537) {
		const char* FEN = "q2r4/3k4/3N3n/1QP1p3/2PP1p1p/5PP1/1K2R3/R7 b - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(203, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5223, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(229959, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6243951, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_538) {
		const char* FEN = "r7/3k4/2qN3n/1QP1p3/2PP1p1p/K4PP1/4R3/R7 w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(177, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6958, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(190288, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7255870, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_539) {
		const char* FEN = "r7/3k1n2/2qN4/2P1p3/Q1PPRp1p/K4PP1/8/R7 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(796, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20049, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(637847, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16701244, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_540) {
		const char* FEN = "r7/2k2n2/2qN4/2PPp3/Q1P1R2p/K4Pp1/8/R7 w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(884, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27225, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(722822, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22952081, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_541) {
		const char* FEN = "6r1/2k2n2/2qN4/2PPp3/Q1P3Rp/K4Pp1/8/6R1 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1228, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33462, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1197005, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(31677869, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_542) {
		const char* FEN = "1k4r1/3q1n2/3N4/Q1PPp3/2P3Rp/K4Pp1/8/6R1 w - -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1107, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44317, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1128050, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(43684916, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_543) {
		const char* FEN = "1k4r1/3q1n2/3N4/Q1PPp3/1KP2R2/5Ppp/8/6R1 b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1117, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28978, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1038527, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26646996, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_544) {
		const char* FEN = "1k6/qN3n2/8/Q1PPp1r1/1KP2R2/5Ppp/8/6R1 w - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(756, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22664, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(524984, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15944039, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_545) {
		const char* FEN = "1k6/q4n2/3N4/1QPPp2r/1KP2R2/5Ppp/8/6R1 b - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(127, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2617, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(77806, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1667741, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_546) {
		const char* FEN = "1k6/5n2/1q6/1QPPpNr1/1KP2R2/5Ppp/8/6R1 w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(575, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16879, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(368728, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11310748, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_547) {
		const char* FEN = "1k6/8/1q1N3n/1QPPp1r1/1KP2R2/5Ppp/8/3R4 b - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(549, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10812, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(318541, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6854465, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_548) {
		const char* FEN = "1k6/8/1q1N3n/1QPPp1r1/1KP2R2/5Ppp/8/2R5 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(540, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15892, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(317762, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9660295, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_549) {
		const char* FEN = "1k2N3/8/1q5n/1QPP2r1/1KP1p2R/5Ppp/8/2R5 b - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(619, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13644, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(405817, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9378506, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_550) {
		const char* FEN = "8/2k5/1q5n/1QPP2r1/1KP1p2R/5Ppp/8/2R5 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(707, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18469, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(489546, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13982868, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_551) {
		const char* FEN = "8/2k5/7n/1qPP2r1/2P1p2R/K4Ppp/8/6R1 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(633, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21212, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(389992, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12702469, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_552) {
		const char* FEN = "8/2k5/q6R/2PP4/2P1p1r1/K4Ppp/8/6R1 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(114, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2752, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(72095, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1705461, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_553) {
		const char* FEN = "8/2k5/7R/2PP4/2q1p1r1/K4Ppp/8/6R1 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(578, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16384, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(315221, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9092224, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_554) {
		const char* FEN = "8/2k5/7R/2PP4/K3p2r/3q1Ppp/8/6R1 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(679, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12157, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(333002, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6347514, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_555) {
		const char* FEN = "8/2k5/q6R/2PP4/4p2r/1K3Ppp/6R1/8 b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(733, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20740, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(450219, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12472237, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_556) {
		const char* FEN = "8/2k5/5q1R/2PP4/4p2r/2K2Pp1/6p1/8 w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(220, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3574, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(108187, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1777632, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_557) {
		const char* FEN = "8/2k5/8/2PP1R2/4p3/2K2Ppr/6p1/8 b - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(321, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5845, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(101623, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1937042, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_558) {
		const char* FEN = "1r6/2k5/8/2PP1R2/4p3/1K3Pp1/6p1/8 w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(144, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1997, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(38907, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(577253, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_559) {
		const char* FEN = "1r1k4/8/8/2PP2R1/4p3/2K2Pp1/6p1/8 b - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(310, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6168, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(97160, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1946616, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_560) {
		const char* FEN = "3k4/8/8/2PP2R1/2K1p3/5Pp1/5rp1/8 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(286, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4720, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(84434, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1384633, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_561) {
		const char* FEN = "8/3k2R1/8/2PP4/2K1p3/5Pp1/5rp1/8 b - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(63, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(918, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(17198, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(286153, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_562) {
		const char* FEN = "2k5/6R1/8/2PP4/1K2p3/5Pp1/4r1p1/8 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(331, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6471, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(109499, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1971975, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_563) {
		const char* FEN = "8/3k4/4R3/2PP4/1K2p3/5Pp1/4r1p1/8 b - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(327, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5476, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(100882, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1850653, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_564) {
		const char* FEN = "8/3k4/8/2PPR3/1K2p3/5rp1/6p1/8 w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(228, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3362, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(60162, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(941052, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_565) {
		const char* FEN = "8/4k3/8/2PPR3/1K2p3/5rp1/6p1/8 b - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(65, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1122, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(16510, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(295812, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_566) {
		const char* FEN = "4R3/5k2/8/2PP4/1K2p3/6p1/5rp1/8 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(350, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6200, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(116104, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1986787, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_567) {
		const char* FEN = "7R/5k2/8/2PP4/1K2p3/5rp1/6p1/8 b - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(381, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7227, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(128697, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2567429, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_568) {
		const char* FEN = "7R/8/6k1/2PP4/K3p3/5rp1/8/6q1 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(571, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8706, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(251525, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3735223, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_569) {
		const char* FEN = "6R1/8/6k1/2PP4/K3p3/6p1/8/5rq1 b - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(114, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2400, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(39585, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(987959, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_570) {
		const char* FEN = "6R1/5k2/8/2PP4/1K2p3/6p1/8/2r3q1 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(429, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6486, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(162599, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2387313, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_571) {
		const char* FEN = "8/5k2/6R1/2PP4/1K2p3/4q1p1/8/2r5 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(398, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11462, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(152924, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4437250, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_572) {
		const char* FEN = "8/5k2/6R1/1KPP4/4p3/6p1/3q4/2r5 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(587, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8282, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(251768, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3542311, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_573) {
		const char* FEN = "8/5k2/4R3/2PP4/1K2p3/6p1/8/2r5 b - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(269, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4244, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(70169, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1134633, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_574) {
		const char* FEN = "8/5k2/4R3/K1PP4/4p3/6p1/8/4r3 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(251, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4063, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(61735, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1000153, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_575) {
		const char* FEN = "8/5k2/7R/2PP4/1K6/4p1p1/8/4r3 b - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(322, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4949, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(92733, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1502868, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_576) {
		const char* FEN = "8/6k1/8/2PP4/1K6/6p1/4p2R/4r3 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(253, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4342, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(73129, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1219256, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_577) {
		const char* FEN = "5k2/8/3P4/2P5/1K5R/6p1/4p3/4r3 b - -";
		Assert::AreEqual(12, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(231, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3626, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(64660, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1125148, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_578) {
		const char* FEN = "5k2/8/3P4/2P5/7R/1K4pr/4p3/8 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(268, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4995, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(83131, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1457624, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_579) {
		const char* FEN = "5k2/3P4/8/2P4r/1R6/1K4p1/4p3/8 b - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(475, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8926, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(196892, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4009634, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_580) {
		const char* FEN = "8/3Pk3/8/2P4r/6R1/1K4p1/8/4b3 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(458, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9974, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(198348, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4257218, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_581) {
		const char* FEN = "3k4/3P4/8/2P4R/8/1K4p1/8/4b3 b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(172, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1860, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(35972, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(420229, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_582) {
		const char* FEN = "3k4/3P4/8/2P5/7R/1K6/8/4b1b1 w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(298, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5635, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(84820, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1583235, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_583) {
		const char* FEN = "3Q4/4k3/8/2P5/1R6/1K6/8/4b1b1 b - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(96, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1197, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(38271, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(515558, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_584) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_585) {
		const char* FEN = "rnbqkbnr/pppppp1p/6p1/8/2P5/8/PPQPPPPP/RNB1KBNR b KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(589, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13630, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(407090, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10272819, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_586) {
		const char* FEN = "rnbqkbnr/p1pppp2/6pp/1p6/2P5/N7/PPQPPPPP/R1B1KBNR w KQkq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(601, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18344, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(419743, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13267029, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_587) {
		const char* FEN = "rnbqkbnr/p1p1pp2/3p2pp/1pP5/2N5/8/PPQPPPPP/R1B1KBNR b KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(966, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26087, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(909494, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25244240, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_588) {
		const char* FEN = "rnb1qbnr/p1pkpp2/3p2pp/1pP5/2N5/4P3/PPQP1PPP/R1B1KBNR w KQ -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(799, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29496, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(673655, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24832541, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_589) {
		const char* FEN = "rnb1qbnr/2pkpp2/p2p2Qp/1pP5/2N5/4P3/PP1P1PPP/R1B1KBNR b KQ -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(915, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18268, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(750848, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16451990, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_590) {
		const char* FEN = "rnb2bnr/2pkp1Q1/p2p2qp/1pP2p2/2N5/4P3/PP1P1PPP/R1B1KBNR w KQ -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1053, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41060, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1101005, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41749488, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_591) {
		const char* FEN = "rnb2bnr/2p1p3/p2pk1qQ/1pP2p2/2N5/4P2P/PP1P1PP1/R1B1KBNR b KQ -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(817, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22759, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(775616, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22959346, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_592) {
		const char* FEN = "rnb3nr/2p1p1b1/p3k1qQ/1pPp1p2/8/N3P2P/PP1P1PP1/R1B1KBNR w KQ -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(915, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30346, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(896972, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(29698234, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_593) {
		const char* FEN = "rnb3nr/2p1p3/p3k1q1/1pPp1p2/4PQ2/N1b4P/PP1P1PP1/R1B1KBNR b KQ -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1465, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49680, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1790569, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(60208933, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_594) {
		const char* FEN = "rnb3nr/2p1p3/p3k3/1pPp1pq1/4P1Q1/N6P/PP1b1PP1/R1B1KBNR w KQ -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(108, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3572, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(118738, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4095070, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_595) {
		const char* FEN = "rnb3nr/2p1p3/4k3/ppPp1pq1/4P1Q1/N5PP/PP1bKP2/R1B2BNR b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1052, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37630, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1083773, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38177755, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_596) {
		const char* FEN = "1nb3nr/2p1p3/r3k3/ppP2pq1/1P1pP1Q1/N5PP/P2bKP2/R1B2BNR w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(949, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25775, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(924987, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27022030, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_597) {
		const char* FEN = "1nb3nr/2p1pk2/r7/ppP2pq1/1P1pP1Q1/N4KPP/P2b1P2/1RB2BNR b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1276, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(55688, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1531221, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(63713833, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_598) {
		const char* FEN = "1nb3nr/2p1p3/4r1k1/ppP2pq1/1P1pP1Q1/N4KPP/P2b1P1R/1RB2BN1 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(950, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26067, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(902176, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26008811, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_599) {
		const char* FEN = "1nb3nr/2p1p3/P1r3k1/1pP2pq1/3pP1Q1/N4KPP/P2b1P1R/1RB2BN1 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1074, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37344, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1091367, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38479725, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_600) {
		const char* FEN = "1nb3nr/2p1p3/P4rk1/bpP2pq1/3pP1Q1/N2B1KPP/P4P1R/1RB3N1 w - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1088, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35253, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1159999, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38919041, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_601) {
		const char* FEN = "1n4nr/P1p1p3/4brk1/bpP2pq1/3pP1Q1/N2BBKPP/P4P1R/1R4N1 b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1350, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44148, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1725479, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57637540, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_602) {
		const char* FEN = "1n4nr/P1p1p3/4brk1/bpP2pq1/4P1QP/N2B1KP1/P3pP1R/1R4N1 w - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1297, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(47008, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1586826, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57385066, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_603) {
		const char* FEN = "1n4nr/P1p1p1k1/4br2/bpP1Ppq1/6QP/N2B1KP1/P3pP1R/R5N1 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1571, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(61211, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2366746, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(93763186, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_604) {
		const char* FEN = "6nr/P1p1p3/n3br1k/bpP1Ppq1/6QP/N2B1KP1/P3pP2/R5NR w - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1429, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49163, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1766663, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(62368666, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_605) {
		const char* FEN = "6nr/P1p1p3/n3br1k/bpP1P1q1/6pP/N5P1/P1B1pPK1/R5NR b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1272, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(53461, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1630260, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(69613559, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_606) {
		const char* FEN = "B4rnr/2p1p3/n6k/bpP1Pbq1/6pP/N5P1/P1B1pPK1/R5NR w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1390, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43247, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1892584, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(58837205, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_607) {
		const char* FEN = "1r4nr/2p1p3/n6k/bpP1Pbq1/4B1pP/N5P1/P3pPK1/RB4NR b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1003, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41323, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1024405, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42787168, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_608) {
		const char* FEN = "1r4nr/2p1p3/7k/1pn1Pbq1/1b2B1pP/N2B2P1/P3pPK1/R5NR w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1407, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43563, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1973950, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(61811749, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_609) {
		const char* FEN = "1r4nr/2p1p3/n6k/1p2Pbq1/1b2B1pP/3B2P1/P1N1pPK1/4R1NR b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1246, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48104, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1566387, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(61713502, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_610) {
		const char* FEN = "1r4nr/2p1p3/n3b2k/1p2P3/1b2B1pP/3B2P1/P1NqNPK1/4R2R w - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1421, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(52767, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2066184, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(75165867, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_611) {
		const char* FEN = "6nr/2p1p2B/nr2b2k/1p2P3/1b4pP/3B2P1/P1Nq1PK1/4R1NR b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1152, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45195, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1408784, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57123858, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_612) {
		const char* FEN = "6nr/2p1p2B/nrq1b2k/1p2P3/1b4pP/3B2P1/P4PK1/1R4NR w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(220, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6280, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(235680, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6894924, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_613) {
		const char* FEN = "6nr/2p1p2B/nr2b2k/1p2P3/1bq3pP/6P1/P4P1K/1R3BNR b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1036, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42166, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1120504, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(46697652, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_614) {
		const char* FEN = "6nr/2pbp2B/nr5k/1B2P3/1b4pP/6P1/q4P1K/1R4NR w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1251, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35692, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1536493, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(44721962, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_615) {
		const char* FEN = "6nr/2pbp2B/Br5k/4P3/1b4pP/q5P1/5P1K/3R2NR b - -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1324, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(55899, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1651559, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(70120828, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_616) {
		const char* FEN = "6nr/3bp3/Br5k/2p1P3/6pP/q2B2P1/3b1P1K/3R2NR w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1286, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36219, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1588037, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45330228, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_617) {
		const char* FEN = "2B3nr/q2bp3/1r5k/2p1P3/6pP/3B2P1/3b1P1K/5RNR b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1138, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48127, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1263011, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(52656097, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_618) {
		const char* FEN = "1rB3nr/q3p3/6Bk/1bp1P3/6pP/6P1/3b1P1K/5RNR w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1072, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29615, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1170122, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32433595, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_619) {
		const char* FEN = "2r3nr/q3p3/6Bk/1bp1P3/6pP/6P1/3b1P1K/R5NR b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1133, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45899, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1188864, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(47655295, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_620) {
		const char* FEN = "2r3nr/4p3/q5Bk/1bp1P3/5PpP/4b1P1/7K/R5NR w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1038, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25041, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1003013, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24170623, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_621) {
		const char* FEN = "2r3nr/4p1k1/q7/1bp1P3/4BPpP/4b1P1/7K/1R4NR b - -";
		Assert::AreEqual(47, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1210, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(56249, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1424338, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(65251704, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_622) {
		const char* FEN = "q1r3nr/4p1k1/8/1bp1P3/4BPpP/4b1P1/1R5K/6NR w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1276, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32245, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1413398, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35289421, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_623) {
		const char* FEN = "q1r3nr/4p1k1/8/2p1P3/4BPpP/3bb1P1/R5K1/6NR b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(996, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42817, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1052959, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45801761, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_624) {
		const char* FEN = "2r3nr/1q2pk2/8/2p1P3/4BPpP/3bb1P1/6K1/R5NR w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1112, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26628, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1151941, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28828957, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_625) {
		const char* FEN = "5rnr/1q2pk2/R7/2p1P3/4BPpP/3bb1P1/6K1/6NR b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1126, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44914, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1129389, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45124428, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_626) {
		const char* FEN = "2r4r/1q2pk2/5n2/2p1P3/R3BPpP/3bb1P1/6K1/6NR w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1298, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(31534, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1601708, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41055255, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_627) {
		const char* FEN = "2r4r/4pk2/1q3PB1/2p5/R4PpP/3bb1P1/6K1/6NR b - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(152, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7277, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(171569, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7822919, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_628) {
		const char* FEN = "2r4r/4p3/bq3Pk1/2p5/R4PpP/4bNP1/6K1/7R w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1455, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39071, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1823581, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(48122640, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_629) {
		const char* FEN = "2r4r/4p3/b4Pk1/2p5/R4PpP/4b1PN/6K1/1q5R b - -";
		Assert::AreEqual(58, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1141, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(57474, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1213332, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57817209, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_630) {
		const char* FEN = "4r2r/4p3/b4P1k/2p2P2/R5pP/4b1PN/6K1/1q5R w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1214, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25750, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1132776, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25481402, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_631) {
		const char* FEN = "4r2r/4p3/b4P1k/2p2P2/7P/4b1Pp/R6K/1q5R b - -";
		Assert::AreEqual(48, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(932, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42362, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(879131, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38747941, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_632) {
		const char* FEN = "4r2r/4p3/b4P1k/2p2P2/7P/1q4Pp/R6K/6R1 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1091, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25284, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1017732, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23915442, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_633) {
		const char* FEN = "4r2r/4p3/b4P1k/1qp2P2/5R1P/6Pp/7K/6R1 b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(680, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24218, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(540242, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(19983808, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_634) {
		const char* FEN = "2b1r2r/4p3/5P1k/2p2P2/5R1P/6Pp/4q2K/4R3 w - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(169, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3488, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(116716, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2570969, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_635) {
		const char* FEN = "2br3r/4R3/5P1k/2p2P2/5R1P/6Pp/7K/8 b - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(565, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12122, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(310283, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7247204, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_636) {
		const char* FEN = "2b4r/6R1/5P1k/2p2P2/5R1P/6Pp/7K/1r6 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(566, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12675, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(301555, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6888912, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_637) {
		const char* FEN = "2b4r/R7/5P1k/2p2P2/2R4P/6Pp/7K/r7 b - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(589, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14350, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(343882, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8833468, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_638) {
		const char* FEN = "7r/R7/5P1k/2p2P2/7P/1b4Pp/2R4K/r7 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(820, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20556, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(580549, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14196509, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_639) {
		const char* FEN = "1r6/8/R4P1k/2p2P2/7P/1b4Pp/7K/r1R5 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(765, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22465, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(529164, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15303046, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_640) {
		const char* FEN = "1r6/8/R4P1k/2p2P2/1rR4P/1b4Pp/7K/8 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(625, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15674, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(414173, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10103837, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_641) {
		const char* FEN = "8/8/1r3P1k/2p2P2/1rR4P/1b4Pp/8/R6K b - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(476, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11479, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(263895, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7096491, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_642) {
		const char* FEN = "8/8/1r3P1k/1rp2P2/4R2P/1b4P1/7p/R6K w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(652, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17565, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(410826, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10382438, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_643) {
		const char* FEN = "8/1r3P2/4R2k/1rp2P2/7P/1b4P1/7p/R6K b - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(130, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2653, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(75293, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1715152, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_644) {
		const char* FEN = "8/1r3P1k/4b3/1rp2P1P/8/6P1/7p/R6K w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(554, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11092, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(277220, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5548946, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_645) {
		const char* FEN = "5R2/1r5k/4b3/2p2P1P/8/R5P1/1r5p/7K b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(782, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22770, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(508390, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14341477, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_646) {
		const char* FEN = "1R6/7k/4b3/2p2P1P/1r6/R5P1/r6p/7K w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(778, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17459, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(499386, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11020029, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_647) {
		const char* FEN = "1R6/7k/R3b3/2p2P1P/6P1/8/rr5p/7K b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(641, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16310, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(345849, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8807395, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_648) {
		const char* FEN = "2b3R1/7k/R7/2p2P1P/6P1/r7/1r5p/7K w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(616, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12333, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(313582, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6253574, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_649) {
		const char* FEN = "R1b3R1/7k/8/2p2PPP/8/r7/6rp/7K b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(524, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12090, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(219413, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5076860, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_650) {
		const char* FEN = "R1b2R2/7k/8/2p2PPP/8/8/6rp/r6K w - -";
		Assert::AreEqual(2, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(42, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(863, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(15507, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(323820, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_651) {
		const char* FEN = "2b2R2/7k/8/2p2PPP/8/8/7p/6RK b - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(165, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1615, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(30796, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(317946, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_652) {
		const char* FEN = "5R2/3b3k/8/2p2PPP/8/8/8/6K1 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(134, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2249, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(20076, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(351255, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_653) {
		const char* FEN = "7k/3b1R2/8/2p2PPP/8/8/6K1/8 b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(159, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1412, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(24740, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(231421, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_654) {
		const char* FEN = "7k/5R2/8/2p2PPP/b7/8/5K2/8 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(167, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3131, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(28902, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(542300, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_655) {
		const char* FEN = "7k/5R2/6P1/2p2P1P/8/5K2/2b5/8 b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(146, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1254, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(22130, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(195136, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_656) {
		const char* FEN = "7k/R7/6P1/2p2P1P/8/3b1K2/8/8 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(231, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4515, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(42845, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(828407, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_657) {
		const char* FEN = "7k/R7/5PP1/2p4P/4K3/8/8/5b2 b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(166, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1421, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(26060, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(228912, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_658) {
		const char* FEN = "7k/R7/b4PP1/2p2K1P/8/8/8/8 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(130, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2303, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(19191, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(352746, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_659) {
		const char* FEN = "2b4k/R7/5PP1/2p4P/5K2/8/8/8 b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(194, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1757, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(36352, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(332795, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_660) {
		const char* FEN = "2b4k/5R2/5PP1/2p4P/5K2/8/8/8 w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(114, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1925, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(16295, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(293745, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_661) {
		const char* FEN = "1R5k/3b4/5PP1/2p4P/5K2/8/8/8 b - -";
		Assert::AreEqual(2, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(40, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(167, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(3519, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28882, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_662) {
		const char* FEN = "1Rb3k1/8/5PP1/2p4P/8/5K2/8/8 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(103, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1955, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(16797, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(324733, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_663) {
		const char* FEN = "2b3k1/8/5PP1/7P/2p5/5K2/8/R7 b - -";
		Assert::AreEqual(10, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(202, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1918, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(38487, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(375945, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_664) {
		const char* FEN = "6k1/8/5PP1/7P/2p3K1/8/8/R6b w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(207, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4187, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(43843, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(844924, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_665) {
		const char* FEN = "7k/8/5PP1/7P/2p5/7K/8/3R3b b - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(169, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1712, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(30745, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(304830, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_666) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_667) {
		const char* FEN = "rnbqkbnr/pp1ppppp/2p5/8/8/1P6/PBPPPPPP/RN1QKBNR b KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(563, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13521, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(361756, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9624190, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_668) {
		const char* FEN = "rnbqkbnr/pp2p1pp/2p5/3p1p2/2P5/1P6/PB1PPPPP/RN1QKBNR w KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(754, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21381, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(611204, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17818988, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_669) {
		const char* FEN = "rnbqkbnr/pp2p1p1/2p5/3p1p1p/1PP5/7N/PB1PPPPP/RN1QKB1R b KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(833, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24569, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(743804, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22819719, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_670) {
		const char* FEN = "rnbqkbnr/pp2p1p1/8/3p1p1p/PpP5/7N/1B1PPPPP/RN1QKB1R w KQkq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(840, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25175, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(776716, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24252616, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_671) {
		const char* FEN = "rnbqkbnr/pp6/8/3pBp1p/PpP5/7N/3PPPPP/RN1QKB1R b KQkq -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1167, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42290, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1365627, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(50088360, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_672) {
		const char* FEN = "rBb1kbnr/p7/1p6/3p1p1p/PpP4q/7N/3PPPPP/RN1QKB1R w KQkq -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(969, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26990, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1007791, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30138364, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_673) {
		const char* FEN = "rB2kbnr/pb6/1p6/3p1p1p/PpP3Pq/1Q5N/3PPP1P/RN2KB1R b KQkq -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1213, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43008, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1538359, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(56636332, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_674) {
		const char* FEN = "rB2kbnr/pb6/1p3q2/5p1P/PpPp4/1Q5N/3PPP1P/RN2KB1R w KQkq -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1385, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48116, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1913479, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66836437, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_675) {
		const char* FEN = "r3kbnr/p7/1p1B1q2/3b1p1P/PpPp4/2Q4N/3PPP1P/RN2KB1R b KQkq -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1613, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(68653, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2455013, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(103210254, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_676) {
		const char* FEN = "r2k1b1r/p3n3/1p1B1q2/3b1p1P/PpPp4/2Q5/3PPP1P/RN2KBNR w KQ -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1530, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(57196, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2238341, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(81922447, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_677) {
		const char* FEN = "r2k1bbr/p3n3/1p1B1q2/5p1P/PpPp4/2Q2N2/3PPPBP/RN2K2R b KQ -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1423, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(50450, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2010203, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(72481104, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_678) {
		const char* FEN = "r4bbr/3kB3/1p3q2/p4p1P/PpPp4/2Q2N2/3PPPBP/RN2K2R w KQ -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1394, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(52523, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1941947, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(73701340, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_679) {
		const char* FEN = "5bbr/3kB3/rp3q2/p4p1P/PpPpP3/3Q1N2/3P1PBP/RN2K2R b KQ e3";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1251, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41369, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1511211, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(51194727, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_680) {
		const char* FEN = "5b1r/4k3/rp2bq2/p4p1P/PpPpP3/1Q3N2/3P1PBP/RN2K2R w KQ -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(972, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(31822, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1044616, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(34070549, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_681) {
		const char* FEN = "5b2/4k3/rp2bqN1/p4p1r/PpPpP3/1Q6/3P1PBP/RN2K2R b KQ -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(228, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7993, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(286832, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10472297, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_682) {
		const char* FEN = "5b2/8/rp2bqN1/p1k2p1r/PpPpP3/1Q5P/3P1PB1/RN2K2R w KQ -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1169, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40063, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1365571, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45338825, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_683) {
		const char* FEN = "5b2/7r/rp2bqN1/p1k2p2/PpPpP3/1Q3P1P/3P4/RN2KB1R b KQ -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1212, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44109, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1333688, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(48557393, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_684) {
		const char* FEN = "2b2b1N/7r/rp6/p1k2pq1/PpPpP3/1Q3P1P/3P4/RN2KB1R w KQ -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1160, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29370, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1133362, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(29375186, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_685) {
		const char* FEN = "2b5/7r/rp1b2N1/p1k2pq1/PpPpP3/1Q3P1P/3PK3/RN3B1R b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1234, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49323, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1339193, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(51726362, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_686) {
		const char* FEN = "2b5/6r1/rp1b2N1/p1k2p2/PpPpP3/3Q1PqP/3PK3/RN3B1R w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(886, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(19692, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(724429, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17275655, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_687) {
		const char* FEN = "2b5/6r1/rp1b2N1/p1k2p2/PpPpP3/3Q1q1P/3P4/RN2KBR1 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(953, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37293, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(941740, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(36019488, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_688) {
		const char* FEN = "2b5/r5r1/1p4N1/p1k1bp2/PpPpP3/R2Q1q1P/3P4/1N2KBR1 w - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1237, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30597, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1331284, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35125268, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_689) {
		const char* FEN = "2b5/6r1/rp4N1/p1k1bp2/PpPpP3/RQ1B1q1P/3P4/1N2K1R1 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(894, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35891, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(836880, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33193321, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_690) {
		const char* FEN = "2b5/6r1/rp1k2N1/p3bpR1/PpPpP3/RQ1B3P/3P4/1N2K2q w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(144, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3583, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(124471, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3308688, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_691) {
		const char* FEN = "2b5/6r1/rpk5/p3bpR1/PpPpPN2/RQ1B3P/3PK3/1N5q b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(894, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33679, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(831921, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30816591, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_692) {
		const char* FEN = "8/3b2r1/rpk5/p3bpR1/PpPpPN2/R2B3P/2QPK3/1Nq5 w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(977, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25721, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(906323, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24719727, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_693) {
		const char* FEN = "8/3b2r1/rpk3N1/p4pR1/PpPpPb2/R1QB3P/3PK3/1Nq5 b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1039, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38267, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1037122, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(37881269, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_694) {
		const char* FEN = "8/3b2r1/rpk3N1/p4pR1/PpP1Pb2/R1pB3P/3P4/1N3K2 w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(780, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22272, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(631726, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(17876289, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_695) {
		const char* FEN = "1b6/3b2r1/rpk3N1/p4p2/PpP1P3/2RB3P/3P2R1/1N3K2 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(713, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18454, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(501921, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13608909, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_696) {
		const char* FEN = "1b6/5br1/rpk3N1/p4p2/PpP1P3/2RB2RP/3P4/1N3K2 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(724, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20153, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(546153, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15182580, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_697) {
		const char* FEN = "1b4r1/5b2/rpk3N1/p4p2/PpP1P3/2RB2RP/3P4/1N2K3 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(802, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22842, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(630254, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18218858, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_698) {
		const char* FEN = "1b6/5b2/rp4r1/p1k1Pp2/PpP5/2RB2RP/3P4/1N2K3 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(610, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15191, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(398930, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10339869, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_699) {
		const char* FEN = "rb6/5b2/1p4r1/p1k1Pp2/PpP1B3/2R4P/3P4/1N2K1R1 b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(936, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26101, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(809039, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22760867, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_700) {
		const char* FEN = "rb6/5b2/1p2r3/p1k1P3/PpP1p3/2R4P/3P4/1N1K2R1 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(601, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14926, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(380530, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9411099, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_701) {
		const char* FEN = "rb6/5b2/1pr5/p1k1P3/PpP1p3/5R1P/3P2R1/1N1K4 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(805, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20801, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(594908, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15813689, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_702) {
		const char* FEN = "rb6/5b2/1pr5/p3P3/PpP1p3/3k3P/3P2R1/1N1K4 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(435, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7198, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(186885, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3171862, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_703) {
		const char* FEN = "rb4R1/8/1pr5/p1PbP3/Pp2p3/3k3P/3P4/1N1K4 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(501, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13291, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(241871, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6700328, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_704) {
		const char* FEN = "rb4b1/8/1pr5/p1P1P3/Pp2p3/3k3P/3P2R1/1N1K4 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(428, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7297, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(187709, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3309691, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_705) {
		const char* FEN = "rb4b1/2r5/1p6/p1P1P3/Pp2p3/N2k3P/3P3R/3K4 b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(346, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9009, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(131423, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3408701, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_706) {
		const char* FEN = "rb4b1/r7/1p6/pNP1P3/Pp6/3kp2P/3P3R/3K4 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(401, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6786, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(170907, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3055105, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_707) {
		const char* FEN = "rb4b1/r7/1p6/p1P1P3/P1N5/1p1kp2P/3P3R/3K4 b - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(387, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9543, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(159754, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4237329, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_708) {
		const char* FEN = "rb6/r6b/8/p1p1P3/P1N4P/1p1kp3/3P3R/3K4 w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(299, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4863, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(112040, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1870449, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_709) {
		const char* FEN = "rb6/r6b/8/p1p1P3/P1Nk3P/1p2p3/3P3R/3K4 b - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(395, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10195, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(171137, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4683236, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_710) {
		const char* FEN = "r7/2b3rb/8/p1p1P3/P1Nk3P/1p2p3/3P1R2/3K4 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(804, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16668, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(556785, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11143090, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_711) {
		const char* FEN = "r7/2b3r1/8/2p1Pb2/P1Nk3P/1p2p3/3P1R2/3K4 b - -";
		Assert::AreEqual(47, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(922, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36407, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(710752, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26168619, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_712) {
		const char* FEN = "r7/2b3r1/8/2p1P3/P1N1b2P/1p1kp3/3P4/3K1R2 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(871, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17442, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(663724, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12921060, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_713) {
		const char* FEN = "r7/2b3r1/1N6/2p1PR2/P3b2P/3kp3/1p1P4/3K4 b - -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(694, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28661, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(488211, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(19356588, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_714) {
		const char* FEN = "r7/2b3r1/1N2P3/2p2R2/P3b2P/3kp3/1p1P4/3K4 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(941, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17464, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(716501, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13018294, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_715) {
		const char* FEN = "r7/2b3r1/1N2P3/2p5/P2kb2P/4p3/1p1PR3/3K4 b - -";
		Assert::AreEqual(50, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(734, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32641, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(522561, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22121775, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_716) {
		const char* FEN = "8/r1b3r1/1N2P3/2pb3P/P2k4/4p3/1p1PR3/3K4 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(700, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11608, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(463155, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8112779, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_717) {
		const char* FEN = "8/r2N2r1/4P3/P1pbb2P/3k4/4p3/1p1PR3/3K4 b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(705, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28954, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(485603, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(19176918, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_718) {
		const char* FEN = "8/r2N3r/4P3/P2bb2P/2pk4/4p3/1p1P2R1/3K4 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(865, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18040, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(650532, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13185490, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_719) {
		const char* FEN = "8/r2N3r/2b1P3/P3b2P/2pk4/3Pp3/1p2R3/3K4 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(734, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29636, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(534017, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20685051, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_720) {
		const char* FEN = "8/3N2r1/2b1P3/r3b2P/2pk4/3Pp3/1p1R4/3K4 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(832, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13987, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(621807, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10890239, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_721) {
		const char* FEN = "6r1/3N4/2b1P3/r3b2P/2pk4/3Pp3/1p1R4/3K4 b - -";
		Assert::AreEqual(53, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(833, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39246, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(663557, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(29460549, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_722) {
		const char* FEN = "8/3N2r1/2b1P3/r3b2P/2pk4/3Pp3/1p1R4/4K3 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(880, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15233, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(677830, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11979320, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_723) {
		const char* FEN = "8/3NP1r1/2b5/r3b2P/2pk4/3Pp3/3RK3/1q6 b - -";
		Assert::AreEqual(59, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(857, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45340, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(732001, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(36909396, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_724) {
		const char* FEN = "1b6/3NP1r1/2b5/r6P/2pk4/3Pp3/3R4/4K3 w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1034, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22796, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(943368, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21428318, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_725) {
		const char* FEN = "1b6/4P1r1/2b5/r3N2P/2Pk4/8/3Rp3/4K3 b - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(120, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4152, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(93562, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3176622, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_726) {
		const char* FEN = "1b6/4P3/2b3r1/r3k2P/2P5/8/3RpK2/8 w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(753, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14098, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(510503, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9526733, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_727) {
		const char* FEN = "1b2b3/1R2P3/6r1/r3k2P/2P5/8/4pK2/8 b - -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(669, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25688, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(411283, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15083911, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_728) {
		const char* FEN = "1b2b3/4P1r1/8/4k2P/r1P5/8/4pK2/1R6 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(735, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11872, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(430917, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6978868, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_729) {
		const char* FEN = "1b2b3/4P1r1/8/4k2P/2P5/r7/2R1pK2/8 b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(454, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17395, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(225320, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8434542, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_730) {
		const char* FEN = "1b6/4P1r1/6b1/7P/2P1k3/r7/2R1p3/4K3 w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(498, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7816, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(249515, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4169392, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_731) {
		const char* FEN = "1b2b3/4P1r1/8/7P/2P1k3/r7/3RpK2/8 b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(614, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23058, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(331202, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12347165, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_732) {
		const char* FEN = "1b2b3/4P3/6r1/7P/2Pk4/r7/4pK2/8 w - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(230, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1328, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(57202, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(397717, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_733) {
		const char* FEN = "1b2Q3/5b2/6r1/2P4P/3k4/r7/4pK2/8 b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(994, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34157, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(666227, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22254444, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_734) {
		const char* FEN = "1b2Q3/5b2/8/2P4P/3kr3/r7/4p1K1/8 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(680, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13227, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(450064, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8857033, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_735) {
		const char* FEN = "1b6/2Q2b2/8/2k4P/4r3/r7/4p1K1/8 b - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(108, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3381, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(68691, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2212402, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_736) {
		const char* FEN = "1b6/5b2/8/3k3P/5r2/r7/4p1KQ/8 w - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(403, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6027, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(212940, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3704648, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_737) {
		const char* FEN = "1b2b3/8/8/3k3P/3Q4/r7/4p1K1/8 b - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(66, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1720, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(35998, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(942198, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_738) {
		const char* FEN = "4b3/8/7P/8/3k4/r5b1/4p1K1/8 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(160, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(648, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(23341, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(138593, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_739) {
		const char* FEN = "4b3/8/7P/8/3k4/5rb1/4p3/7K b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(114, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4442, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(18544, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(650665, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_740) {
		const char* FEN = "4b3/2b5/7P/8/3k1r2/8/4p1K1/8 w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(210, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(948, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(33632, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(182087, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_741) {
		const char* FEN = "4b3/2b4P/8/8/3k1r2/8/7K/4n3 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(221, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7072, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(48020, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1552093, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_742) {
		const char* FEN = "4b3/2b4P/8/4k3/8/8/5r2/4n1K1 w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(152, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1177, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(32729, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(350834, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_743) {
		const char* FEN = "2R5/2b2b2/8/4k3/8/8/5r2/4n1K1 b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(375, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12600, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(159834, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5126867, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_744) {
		const char* FEN = "8/2R5/8/4kb2/8/8/5r2/4n1K1 w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(436, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6025, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(161706, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2231443, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_745) {
		const char* FEN = "2R5/8/4k3/5b2/8/8/5r2/4n2K b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(392, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10475, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(137131, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3658019, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_746) {
		const char* FEN = "8/8/2k5/5b2/8/8/5r2/4n2K w - -";
		Assert::AreEqual(1, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(33, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(65, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1905, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4927, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_747) {
		const char* FEN = "8/8/8/3k1b2/8/8/5K2/4n3 b - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(133, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2709, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(12275, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(244644, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_748) {
		const char* FEN = "8/8/8/2k5/8/8/8/1b2nK2 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(72, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(368, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(6792, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32474, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_749) {
		const char* FEN = "8/8/8/8/3k4/8/5K2/1b2n3 b - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(95, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1685, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(7835, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(142682, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_750) {
		const char* FEN = "8/8/8/3k4/8/8/2b5/4n1K1 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(80, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(313, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(6072, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26973, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_751) {
		const char* FEN = "8/8/8/3k4/4b3/6K1/8/4n3 b - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(110, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2306, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(10487, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(216268, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_752) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_753) {
		const char* FEN = "rnbqkb1r/pppppppp/7n/8/P2P4/8/1PP1PPPP/RNBQKBNR b KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(579, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12934, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(390277, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9653490, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_754) {
		const char* FEN = "rnbqkb1r/pppp1ppp/8/4pn2/P2PP3/8/1PP2PPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1341, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(51966, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1729845, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66597786, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_755) {
		const char* FEN = "rnbqkb1r/pppp1ppp/8/4p3/P2PPB2/4n3/1PP1QPPP/RN2KBNR b KQkq -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1236, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44982, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1592016, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57305859, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_756) {
		const char* FEN = "rnbqkbr1/pppp1ppp/8/4p3/P2PPB2/3Q4/1PP2PPP/RN2KnNR w KQq -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1421, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(57831, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1904130, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(74966717, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_757) {
		const char* FEN = "rnbqkbr1/ppp2ppp/3p4/4p3/P2PP3/3Q4/1PPB1PPP/RN2KnNR b KQq -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1480, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(51711, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2081723, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(73436472, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_758) {
		const char* FEN = "r1bqkbr1/p1p2ppp/n2p4/1p2p3/P2PP3/3Q4/1PPB1PPP/RN3KNR w q -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1266, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(51786, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1630302, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(64926234, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_759) {
		const char* FEN = "r1b1kbr1/p1p2ppp/n2p4/1p2p1B1/P2PP2q/2NQ4/1PP2PPP/R4KNR b q -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1503, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(52112, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2173716, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(76943929, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_760) {
		const char* FEN = "r1b1kbr1/p1p2ppp/n2p4/1N2p1B1/P2PP3/3Q4/1PP2PP1/R4KNq w q -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1240, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49371, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1487011, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57699450, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_761) {
		const char* FEN = "r1b1k1r1/p1p1bppp/n2p4/1N2p1B1/P2PP2Q/8/1PP2PP1/R4KNq b q -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1230, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40206, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1490246, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(49869256, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_762) {
		const char* FEN = "r1b1k1r1/p1p1bppp/n2p4/1N2p1B1/P2PP3/8/1PP2PPQ/R4KNq w q -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1242, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46297, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1463119, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(53289845, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_763) {
		const char* FEN = "r1b1k1r1/p1p1b1pp/n2p1p2/1N2P1B1/P3P3/2P5/1P3PPQ/R4KNq b q -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1113, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33822, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1176938, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(37085293, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_764) {
		const char* FEN = "r2bk1r1/p1p3pp/n2p1p2/1N2P1B1/P3P1b1/2P5/1P3PPQ/2R2KNq w q -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1105, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35094, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1103649, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35143317, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_765) {
		const char* FEN = "r1bbk1r1/p1p3pp/n2p1B2/1N2P3/P3P3/2P3P1/1P3P1Q/2R2KNq b q -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(918, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28050, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(845727, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27221324, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_766) {
		const char* FEN = "r1b3r1/p1p1k1pp/n2p1b2/1N2P3/P3P3/2P3PQ/1P3P2/2R2KNq w - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1069, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32070, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1076320, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32085484, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_767) {
		const char* FEN = "r1b3r1/p1p1k1pp/n2pQ3/PN2P3/4P2b/2P3P1/1P3P2/2R2KNq b - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(114, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3199, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(81989, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2538855, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_768) {
		const char* FEN = "r1b2kr1/p1p3pp/n2p1b2/PN2P3/4P3/2P3P1/1P3P2/2R2KNq w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(741, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14527, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(526835, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10691219, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_769) {
		const char* FEN = "r1b2kr1/p1p3pp/n2N1b2/P3P3/4P3/2P3P1/1P3Pq1/2R1K1N1 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(719, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25124, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(525365, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18988779, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_770) {
		const char* FEN = "1r3kr1/p1p3pp/n2Nbb2/P3P3/4P3/2P3P1/1P3Pq1/3RK1N1 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1153, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26746, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1148563, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25894699, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_771) {
		const char* FEN = "1r3kr1/p1p3pp/n3bb2/P3PN2/4P3/2P3P1/1P3P1q/1R2K1N1 b - -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(968, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41615, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(915715, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38781964, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_772) {
		const char* FEN = "1r4r1/p1p2kpp/n3b3/P3PNb1/4P3/2P3P1/1P3P1q/R3K1N1 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1190, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26884, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1251801, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27236046, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_773) {
		const char* FEN = "r5r1/p1p2kpp/n3b3/P3PNb1/4P3/R1P2PP1/1P5q/4K1N1 b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(913, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40756, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(731549, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32350563, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_774) {
		const char* FEN = "rr6/p1p2kpp/n3b3/P3PNb1/4P3/2P2PP1/1P4q1/R3K1N1 w - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(980, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17399, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(813221, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(14308845, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_775) {
		const char* FEN = "r2r4/p1p2kpp/n3b3/P3PNb1/4P3/1PP2PP1/4N1q1/R3K3 b - -";
		Assert::AreEqual(50, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(909, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41339, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(742625, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33881608, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_776) {
		const char* FEN = "r3r3/p1p2kp1/n3b2p/P3PNb1/4P3/1PP2PP1/4N1q1/1R2K3 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(804, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13765, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(573582, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10051509, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_777) {
		const char* FEN = "rr6/p1p2kp1/n3b2p/P3PNb1/4P3/1PP2PP1/2K1N1q1/1R6 b - -";
		Assert::AreEqual(44, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(932, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38469, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(826913, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(34875817, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_778) {
		const char* FEN = "r7/p1p2kp1/n3b2p/Pr2PN2/2P1P3/1P2bPP1/2K1N1q1/1R6 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1121, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26128, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1200208, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27816556, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_779) {
		const char* FEN = "6r1/p1p2kp1/n3b2p/Pr2PN2/2P1P1P1/1P1KbP2/4N1q1/1R6 b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1319, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(61300, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1459426, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66532275, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_780) {
		const char* FEN = "1r6/p1p2kp1/n3b2p/Pr2PN2/2P1P1P1/1P1KbP2/1R2N2q/8 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1266, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27946, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1312957, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28720751, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_781) {
		const char* FEN = "1r6/p1p2kp1/n3b2p/Pr2P3/2PbP1P1/1P3PN1/1RK1N2q/8 b - -";
		Assert::AreEqual(52, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(834, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41984, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(756019, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(36789367, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_782) {
		const char* FEN = "3r4/p1p2kp1/n6p/Pr2P1P1/2bbP3/1P3PN1/1RK1N2q/8 w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(788, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13461, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(664806, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12309454, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_783) {
		const char* FEN = "3r4/p1p2kp1/n3P2p/P1r3P1/2bbP3/1P3PN1/2K1N2q/1R6 b - -";
		Assert::AreEqual(7, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(132, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6209, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(116813, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5463241, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_784) {
		const char* FEN = "3r4/p1p3p1/n3P1kp/Pr4P1/2bbP3/1P3PN1/2K1N2q/2R5 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1093, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21816, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1126348, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23615827, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_785) {
		const char* FEN = "3r4/p1p3p1/n3P1kp/Pr4Pq/2bbP3/1P3PN1/2K1N3/2R5 b - -";
		Assert::AreEqual(51, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1141, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(54590, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1261196, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(59145434, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_786) {
		const char* FEN = "3r4/p1p3p1/n3P1kp/Pr4P1/3bP1q1/1P1b1PN1/3KN3/2R5 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1572, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40938, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2029965, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(49416145, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_787) {
		const char* FEN = "3r4/p1p3p1/n3P1kp/P1r1P1P1/3b2q1/1P1b1PN1/4N3/2RK4 b - -";
		Assert::AreEqual(50, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1019, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48239, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(982370, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(45731875, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_788) {
		const char* FEN = "3r4/p1p3p1/n2bP1kp/P1r3P1/6P1/1P1b2N1/4N3/2RK4 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(711, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14694, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(528837, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11064418, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_789) {
		const char* FEN = "3r4/p1p3p1/n2bP1kp/P1r2bP1/2R3P1/1P6/4N3/3K3N b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(619, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20575, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(395355, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13625393, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_790) {
		const char* FEN = "3r4/p1p3p1/n3P1kp/P1r2bP1/2Rb2P1/1P6/4N3/2K4N w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(515, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8886, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(299385, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5681601, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_791) {
		const char* FEN = "3r4/p1p3p1/n1r1P1kP/P4b2/2Rb2P1/1P6/3KN3/7N b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(754, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27560, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(563613, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20412337, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_792) {
		const char* FEN = "3r4/p1p3p1/2r1P1kP/P1n5/2Rb2P1/1P1b2N1/3K4/7N w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(914, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(19692, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(787111, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16827842, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_793) {
		const char* FEN = "1r6/p1p3p1/2r1P1kP/P1n3P1/2Rb4/1P1b2N1/3K1N2/8 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1039, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41579, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1045754, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(40518821, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_794) {
		const char* FEN = "1r6/p1p3pP/2r1P1k1/P1n3P1/2Rb4/1P1b2N1/3K1N2/8 w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1124, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30265, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1114960, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30332340, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_795) {
		const char* FEN = "1r5B/p1p3p1/2r1P1k1/P5P1/n1Rb4/1P1N2N1/3K4/8 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1080, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33407, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(955027, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28808431, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_796) {
		const char* FEN = "2r4B/p1p3p1/2r1P1k1/P5P1/nR6/1P1N2N1/1b1K4/8 w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(865, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24190, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(682484, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18683538, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_797) {
		const char* FEN = "5r1B/pRp3p1/2r1P1k1/P5P1/n7/1P1N4/1b1K4/7N b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(845, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28482, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(627496, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20695467, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_798) {
		const char* FEN = "4r2B/R1p3p1/2r1P3/P5k1/n7/1P1N4/1b1K4/7N w - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(815, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16921, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(577005, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12175689, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_799) {
		const char* FEN = "4r2B/R1p5/P1r1P1p1/6k1/n7/1P6/1b1K4/4N2N b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(669, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21598, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(439712, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13950513, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_800) {
		const char* FEN = "4r2B/R1p5/Pnr1P1p1/8/6k1/1P6/1b6/3KN2N w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(659, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13249, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(442552, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9483903, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_801) {
		const char* FEN = "4r3/R1p5/Pn2P1p1/2r1B3/6k1/1P1N4/1b6/3K3N b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1011, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35305, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(895695, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30405944, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_802) {
		const char* FEN = "5r2/R1p5/Pn2P1p1/2r1B3/6k1/1P1N4/8/b3K2N w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1092, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27654, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(993462, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25312502, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_803) {
		const char* FEN = "5r1B/R1p5/Pn2P1p1/8/6k1/1PrN4/4K3/b6N b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(843, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26784, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(627264, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20006111, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_804) {
		const char* FEN = "7B/R1p5/Pn2P1p1/5k2/8/1PrN4/4KN2/b7 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(565, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15064, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(323289, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8712791, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_805) {
		const char* FEN = "8/R1p5/Pn2P1p1/5k2/2r5/1PBNK3/5N2/b7 b - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(615, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13865, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(364371, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8314187, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_806) {
		const char* FEN = "n7/R1p5/P3P1p1/5k2/1r6/1P1NK3/3B1N2/b7 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(527, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12249, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(275169, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6880513, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_807) {
		const char* FEN = "n7/R7/P1p1P1p1/5k2/1r6/1PB1K3/5N2/b1N5 b - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(601, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11937, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(337483, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6921478, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_808) {
		const char* FEN = "8/R1n5/P1p1P3/5kp1/1r6/1PB5/4KN2/b1N5 w - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(737, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20603, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(495482, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13689029, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_809) {
		const char* FEN = "4n3/R7/P1p1P3/5kp1/1r6/1PB5/3K4/b1N4N b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(658, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14793, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(392706, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8854557, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_810) {
		const char* FEN = "4n3/R7/P1p1P3/5kp1/2r5/1PBN4/3K4/b6N w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(742, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22598, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(474259, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13599865, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_811) {
		const char* FEN = "4n3/R7/P1p1P3/5kp1/4r3/1PB5/2NK4/b6N b - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(645, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13941, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(375337, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8229836, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_812) {
		const char* FEN = "4n3/R7/P1p1k3/6p1/r7/1PB3N1/2NK4/b7 w - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(736, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23971, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(485800, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15127092, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_813) {
		const char* FEN = "4n3/R7/P1p5/5kp1/r7/1PB5/2N1K3/b4N2 b - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(826, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17283, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(548022, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11651093, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_814) {
		const char* FEN = "4n3/7R/P1p5/5kp1/r7/1PB5/2N1K3/b4N2 w - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(974, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36916, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(781489, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26903945, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_815) {
		const char* FEN = "4n3/8/P1p5/5kp1/5r2/1PB3N1/2N1K2R/b7 b - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(114, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2633, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(86862, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2006577, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_816) {
		const char* FEN = "8/8/P1pnk3/6p1/5r2/1P4N1/2NBK2R/b7 w - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1121, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34998, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1080330, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33380097, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_817) {
		const char* FEN = "8/8/P1pnk3/4b1pR/1P3r2/6N1/2NBK3/8 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(958, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30742, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(872153, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26820789, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_818) {
		const char* FEN = "8/1n6/P1p1k3/4b1pR/1P6/N5N1/3BKr2/8 w - -";
		Assert::AreEqual(5, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(164, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4367, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(129359, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3553310, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_819) {
		const char* FEN = "8/1n3k2/P1p5/4b1pR/1P6/6N1/2NB1r2/3K4 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(961, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29537, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(831422, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23896361, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_820) {
		const char* FEN = "5k1b/1n6/P1p5/6p1/1P6/6N1/2NB1r2/3K4 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(603, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12498, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(336313, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7036144, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_821) {
		const char* FEN = "5k2/1n6/P1p2b2/6p1/1P6/N7/3B1r2/3K1N2 b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(502, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14735, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(272058, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7859477, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_822) {
		const char* FEN = "3n1k1b/8/P1p5/6p1/1P6/N7/3B1r2/2K2N2 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(469, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8009, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(217778, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3964108, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_823) {
		const char* FEN = "3n1k2/8/P1p5/1P4p1/8/N1b5/3B1r2/3K1N2 b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(541, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16355, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(295741, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8617166, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_824) {
		const char* FEN = "3n4/5kb1/P1p5/1P4p1/1B6/N7/5r2/3K1N2 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(615, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12065, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(357128, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7205845, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_825) {
		const char* FEN = "3n4/4Bkb1/PPp2r2/6p1/8/N7/8/3K1N2 b - -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(403, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9542, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(193649, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4853137, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_826) {
		const char* FEN = "3n4/4Bk2/PPpr4/6p1/8/N7/1b2K3/5N2 w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(535, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10685, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(283609, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5953899, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_827) {
		const char* FEN = "3n4/4Bk2/PPp5/6p1/3r4/N5N1/1b6/4K3 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(537, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14862, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(305189, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8301932, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_828) {
		const char* FEN = "3n4/4B1k1/PPp5/6p1/r7/N5N1/1b3K2/8 w - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(637, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15364, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(386364, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9157069, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_829) {
		const char* FEN = "3n4/6k1/PPp2b2/2B3pN/r7/N7/5K2/8 b - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(144, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3492, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(79514, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1965833, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_830) {
		const char* FEN = "3n4/4Bk2/PPp2b2/6pN/2r5/N7/5K2/8 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(635, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13737, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(351284, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7605590, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_831) {
		const char* FEN = "3n4/4Bk2/PPp2b2/1Nr3pN/8/8/8/6K1 b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(506, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11858, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(245958, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5884571, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_832) {
		const char* FEN = "3n4/N3Bk2/PPp2b2/6pN/8/7r/8/6K1 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(485, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8668, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(228750, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4326269, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_833) {
		const char* FEN = "3n4/N3Bk2/PPp2b2/6p1/8/1r6/4N3/6K1 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(564, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15863, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(313040, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(8566382, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_834) {
		const char* FEN = "3nk3/N3B3/PPp2b2/1r4p1/8/2N5/8/6K1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(553, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11534, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(267416, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5502750, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_835) {
		const char* FEN = "3nk3/N3B3/PPp2b2/5rp1/8/8/4N3/7K b - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(468, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12003, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(231027, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5912261, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_836) {
		const char* FEN = "4k3/N4n2/PPpB1b2/6p1/8/5r2/4N3/7K w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(692, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14174, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(396185, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7904201, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_837) {
		const char* FEN = "3k4/N4n2/PPp2b2/6p1/8/B4rN1/8/7K b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(454, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11363, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(205955, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5246998, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_838) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_839) {
		const char* FEN = "rnbqkbnr/1ppppppp/8/p7/2P5/7N/PP1PPPPP/RNBQKB1R b KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(462, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10715, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(264284, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6710109, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_840) {
		const char* FEN = "r1bqkbnr/1pppp1pp/2n2p2/p7/2P5/8/PP1PPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(483, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11840, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(279425, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7412572, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_841) {
		const char* FEN = "r1bqkbnr/1pppp1pp/2n5/p4p2/2PP4/4P3/PP3PPP/RNBQKBNR b KQkq -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(760, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18400, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(594770, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15652187, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_842) {
		const char* FEN = "r1bqkbnr/2ppp2p/1pn3p1/p4p2/P1PP4/4P3/1P3PPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(770, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24802, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(644780, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20969518, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_843) {
		const char* FEN = "r2qkbnr/2ppp2p/bpn3p1/p4p2/P1PP4/3BP3/1P1B1PPP/RN1QK1NR b KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1012, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29612, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1063746, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32482656, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_844) {
		const char* FEN = "r2qkbnr/1bppp2p/1p4p1/p4p2/P1Pn4/3BPP2/1P1B2PP/RN1QK1NR w KQkq -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1084, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33167, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1139047, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(36288287, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_845) {
		const char* FEN = "r2qk1nr/1bppp2p/1p4pb/p4p2/P1PnP3/1Q1B1P2/1P1B2PP/RN2K1NR b KQkq -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1228, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44288, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1488363, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(53036938, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_846) {
		const char* FEN = "r2qkb1r/1bppp2p/1p3np1/p4p2/P1PnP3/3B1P2/1P1B2PP/RN1QK1NR w KQkq -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1287, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41535, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1586816, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(52624933, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_847) {
		const char* FEN = "1r1qkb1r/1bppp2p/1p3np1/p4p2/P1PnP3/3BBP1N/1P4PP/RN1QK2R b KQk -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1386, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(50077, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1857193, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66431176, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_848) {
		const char* FEN = "1r1qkbr1/1bp1p2p/1p3np1/p2p1p2/P1PnP3/3BBP1N/1P1K2PP/RN1Q3R w - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1503, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(55186, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2071481, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(76342260, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_849) {
		const char* FEN = "1r1qkbr1/2p1p2p/1pb2np1/p2pPB2/P1Pn4/4BP1N/1P1K2PP/RN1Q3R b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1403, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46565, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1888807, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(63497648, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_850) {
		const char* FEN = "br1qkbr1/2p1p2p/1p4p1/p2pPBN1/P1Pnn3/4BP2/1P1K2PP/RN1Q3R w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(191, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8093, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(248065, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10392067, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_851) {
		const char* FEN = "br1qk1r1/2p1p2p/1p4pb/p2pPB2/P1PnN3/2K1BP2/1P4PP/RN1Q3R b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1569, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48215, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2161223, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(67363691, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_852) {
		const char* FEN = "1r1q1kr1/2pBp2p/1pb3pb/p2pP3/P1PnN3/2K1BP2/1P4PP/RN1Q3R w - -";
		Assert::AreEqual(52, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1569, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(71952, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2231378, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(98395737, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_853) {
		const char* FEN = "1r1q1kr1/2p1p1bp/1pb1B1p1/p2pP3/P1PnN3/1PK1BP2/6PP/RN1Q3R b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1540, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49050, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2254043, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(71761494, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_854) {
		const char* FEN = "1r1q1kr1/1bp1p1bp/1p4p1/p2BP3/P1P1N3/1PK1BP2/2n3PP/RN1Q3R w - -";
		Assert::AreEqual(49, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1515, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(67510, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2134230, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(90566926, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_855) {
		const char* FEN = "1r3kr1/1bp1p1bp/1p1qB1p1/p3P3/P1P1NB2/1PK2P2/2n3PP/RN1Q3R b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1648, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(63682, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2506103, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(93151491, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_856) {
		const char* FEN = "1r3kr1/1bpqp2p/1p2Bbp1/p3P3/P1P1NB2/1PK2P1P/2n3P1/RN1Q3R w - -";
		Assert::AreEqual(48, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(2020, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(86389, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(3381653, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(141417069, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_857) {
		const char* FEN = "r4kr1/1bpqp2p/1p2Bbp1/p3P3/P1P1NB2/1P3P1P/2K3P1/RN2Q2R b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1822, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(64991, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2946452, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(100680530, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_858) {
		const char* FEN = "r2qk1r1/1bp1p2p/1p2Bbp1/p1P1P3/P3NB2/1P3P1P/2K3P1/RN2Q2R w - -";
		Assert::AreEqual(53, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1624, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(73859, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2233879, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(99276190, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_859) {
		const char* FEN = "r3k1r1/1bp1p2p/1p2Bbp1/p1P1P3/P3NB2/1PN2P1P/3K2P1/R3Q2R b - -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1364, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32117, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1637698, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38133256, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_860) {
		const char* FEN = "r3k1Br/1bp1p2p/5bp1/ppP1P3/P3NB2/1PN2P1P/3K2P1/R3Q2R w - -";
		Assert::AreEqual(53, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1250, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(61848, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1456522, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(70166848, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_861) {
		const char* FEN = "2r1k1Br/1bp1p2p/5bp1/ppP1P3/P3NB2/1PN2P1P/3K2P1/3RQ1R1 b - -";
		Assert::AreEqual(23, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(950, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20523, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(851494, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18603401, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_862) {
		const char* FEN = "2r1k1Br/2p4p/4pbp1/ppP1P3/P3bB2/1PN1QP1P/3K2P1/3R2R1 w - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1019, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39081, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(976763, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(38290606, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_863) {
		const char* FEN = "2r1k1Br/2p4p/4pbp1/ppP1P3/P4B2/1PNRQP1P/4K1P1/6R1 b - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(778, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13766, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(599779, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10957687, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_864) {
		const char* FEN = "3rk1Br/2p5/4pbp1/ppP1P1Bp/P7/1PNRQP1P/4K1P1/6R1 w - -";
		Assert::AreEqual(46, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(917, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(41939, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(861677, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(39011957, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_865) {
		const char* FEN = "4k1Br/2p5/4pbp1/ppP1P1Bp/P2Q4/1PNR1P1P/5KP1/6R1 b - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(702, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9381, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(447828, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6089455, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_866) {
		const char* FEN = "4k1B1/7r/2p1pbp1/ppP1P1Bp/P2Q4/1PNRKP1P/6P1/6R1 w - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(834, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(36659, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(595169, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26274204, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_867) {
		const char* FEN = "4k1B1/8/2p1pbpr/ppP1P1Bp/PP1Q4/3RKP1P/6P1/1N4R1 b - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(537, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6368, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(271719, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3456146, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_868) {
		const char* FEN = "4k1B1/r7/2pQpbp1/ppP1P1Bp/PP6/3RKP1P/6P1/1N4R1 w - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(685, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29809, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(432380, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18828183, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_869) {
		const char* FEN = "3Qk1B1/r7/2p1p1p1/ppP1P1Bp/PP6/3RKP1P/6P1/1N4R1 b - -";
		Assert::AreEqual(0, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(0, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_870) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_871) {
		const char* FEN = "r1bqkbnr/pppppppp/2n5/8/1P2P3/8/P1PP1PPP/RNBQKBNR b KQkq -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(679, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16154, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(504493, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(12885948, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_872) {
		const char* FEN = "r1bqkbnr/pppp1p1p/2n1p1p1/8/1P2P3/3B4/P1PP1PPP/RNBQK1NR w KQkq -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(987, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30343, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(986600, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(30790429, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_873) {
		const char* FEN = "r1bqkbnr/p1pp1p1p/2n1p1p1/1p6/1P2P1P1/3B3N/P1PP1P1P/RNBQK2R b KQkq -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(858, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28143, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(754184, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25044456, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_874) {
		const char* FEN = "r1bqkbnr/p1p2p1p/4p1p1/1p1p2N1/1n2P1P1/3B4/P1PP1P1P/RNBQK2R w KQkq -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1033, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30258, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1055955, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(31780406, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_875) {
		const char* FEN = "r1bqkbnr/p1p2p1p/4p1p1/1p1p2N1/4P1PP/3B4/P1nPKP2/RNBQ3R b kq -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1152, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42968, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1303940, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(48259807, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_876) {
		const char* FEN = "r1b1kb1r/p1p1np1p/4p1p1/1p1p2q1/4P1PP/N2B4/P1nPKP2/R1BQ3R w kq -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(976, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24471, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(924900, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24820328, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_877) {
		const char* FEN = "r1b1kbnr/p1p2p1p/4p1p1/1p1p2q1/4P1PP/N2B4/P1QPKP2/R1B2R2 b kq -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1144, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42044, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1238842, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(44463477, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_878) {
		const char* FEN = "r3kbnr/p1p2p1p/b3p1p1/1p1pq3/4P1PP/N2B4/P1QPKP2/R1B3R1 w kq -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1284, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40641, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1562977, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(50184262, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_879) {
		const char* FEN = "r3kbnr/p1p2p1p/b3p1p1/1p1p4/4PqPP/N2B1P2/P1QPK3/R1BR4 b kq -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1047, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40566, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1092681, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41252950, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_880) {
		const char* FEN = "r2k2nr/p1p2p1p/b3p1pb/1p1p4/2B1PqPP/N4P2/P1QPK3/R1BR4 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(996, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25861, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(922972, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25691235, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_881) {
		const char* FEN = "r2k2nr/p1p2p1p/b3p1pb/1p1pq3/2B1P1PP/N4P2/P2P1K2/RQBR4 b - -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1108, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42086, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1198266, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(44215504, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_882) {
		const char* FEN = "2rk2nr/pbp2p1p/4p1pb/1p1pq3/2B1P1PP/N4P2/P2P1K2/RQB4R w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1311, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39216, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1529770, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(47319600, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_883) {
		const char* FEN = "2rk2nr/pbp2p1p/4p1pb/1p1p4/4PqPP/N2B1P2/P2P1K1R/RQB5 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(830, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30525, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(793217, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(29223297, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_884) {
		const char* FEN = "2r3nr/pbp1kp1p/4p1pb/1N1p4/4PqPP/3B1P2/P2P1K1R/RQB5 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1109, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(32317, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1190580, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(37136260, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_885) {
		const char* FEN = "2r3nr/1bN1kp1p/p3p1pb/3p3P/4PqP1/3B1P2/P2P1K1R/RQB5 b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1203, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(43053, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1437122, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(51608214, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_886) {
		const char* FEN = "2r3nr/2N1kp1p/p1b1p1pb/7P/2p1PqP1/5P2/P2P1K1R/RQB5 w - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1304, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40336, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1554006, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(49854585, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_887) {
		const char* FEN = "2r3nr/4kp1p/N3p1pb/7P/b1p1PqP1/B4P2/P2P1K1R/RQ6 b - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(236, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8450, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(293895, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10690348, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_888) {
		const char* FEN = "2r3nr/3k1p1p/N3p1pb/7P/bQp1PqP1/B4P2/P2P1K1R/R7 w - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1407, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(52842, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1838047, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(69969537, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_889) {
		const char* FEN = "6nr/3k1p1p/N1r1p1pb/7P/b1p1PqP1/B4P2/PQ1P1K1R/R7 b - -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1469, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(52988, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2038434, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(74722661, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_890) {
		const char* FEN = "6nQ/3k1p1p/N3p1pb/2r4P/2p1PqP1/B4P2/P1bP1K1R/R7 w - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1577, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(54363, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2159564, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(75644935, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_891) {
		const char* FEN = "6nQ/3k1p1p/N3p1pb/3r3P/2p1PqP1/B4P2/P1bP1K1R/R7 b - -";
		Assert::AreEqual(46, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1616, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(66750, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2365262, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(93888092, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_892) {
		const char* FEN = "1Nk3nQ/7p/4pppb/3r3P/2p1PqP1/B4P2/P1bP1K1R/R7 w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1514, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(48255, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1888637, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(61176911, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_893) {
		const char* FEN = "1Nk3nQ/7p/4pppb/3r3P/b1p1PqP1/5P2/P2P1K1R/2B4R b - -";
		Assert::AreEqual(45, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1113, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45270, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1204805, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(46966414, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_894) {
		const char* FEN = "1Nk3nQ/7p/4pppb/3rq2P/2pPP1P1/1b3P2/P4K1R/2B4R w - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1178, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37646, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1306811, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42995408, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_895) {
		const char* FEN = "1Nk3nQ/7p/4pppb/3r3P/2pPPqP1/1b3P2/PR6/2B1K2R b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1227, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(45437, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1419154, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(50366572, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_896) {
		const char* FEN = "1Nk3nQ/7p/5ppb/4P2P/2p1PqP1/1b3P2/PR1r4/2B1K2R w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(881, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22399, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(758890, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21045625, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_897) {
		const char* FEN = "1Nk3nQ/7p/4Pppb/7P/2p1PqP1/5P2/b2r4/1RB1K2R b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(879, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30855, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(835835, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28891064, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_898) {
		const char* FEN = "1Nk3nQ/7p/4Pppb/7P/2p1P1P1/8/b2r2q1/1RB1K1R1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(792, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17863, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(604921, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15387352, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_899) {
		const char* FEN = "1Nk3n1/6Qp/4Pppb/6PP/2p1P3/5q2/b2r4/1RB1K1R1 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1167, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39014, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1116594, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(36602767, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_900) {
		const char* FEN = "1Nk5/4n2p/4PppQ/6PP/4P3/2p2q2/b2r4/1RB1K1R1 w - -";
		Assert::AreEqual(25, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1027, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22583, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(870486, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21228081, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_901) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_902) {
		const char* FEN = "rnbqkbnr/ppppppp1/8/7p/8/P3P3/1PPP1PPP/RNBQKBNR b KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(607, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(14114, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(420571, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10689894, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_903) {
		const char* FEN = "rnbqkbnr/pp2ppp1/2pp4/1B5p/8/P3P3/1PPP1PPP/RNBQK1NR w KQkq -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(873, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27875, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(788727, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25350405, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_904) {
		const char* FEN = "rnb1kbnr/ppq1ppp1/2pp4/7p/B5P1/P3P3/1PPP1P1P/RNBQK1NR b KQkq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(718, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20965, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(546835, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(16479302, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_905) {
		const char* FEN = "rnb1kbnr/p1q1ppp1/2p5/1p1p3P/B7/P3P3/1PPP1P1P/RNBQK1NR w KQkq -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(906, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23310, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(860387, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(23378066, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_906) {
		const char* FEN = "rnb1kbnr/p1q1ppp1/8/1ppp3P/5P2/PB2P3/1PPP3P/RNBQK1NR b KQkq -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(919, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33880, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(910152, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33388279, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_907) {
		const char* FEN = "rn2kbnr/p1q2pp1/8/1pppp2P/5Pb1/PB2P3/1PPPQ2P/RNB1K1NR w KQkq -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1260, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38967, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1574750, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(49489054, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_908) {
		const char* FEN = "r3kbnr/p1qn1pp1/8/1ppBp2P/3P1Pb1/P3P3/1PP1Q2P/RNB1K1NR b KQkq -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1824, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(76218, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(3085274, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(128355299, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_909) {
		const char* FEN = "r3kbnr/2qn2p1/8/pppBpp1P/3P1Pb1/P1P1P3/1P2Q2P/RNB1K1NR w KQkq -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1674, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(67202, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2613497, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(100202988, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_910) {
		const char* FEN = "r4bnr/1Bqnk1p1/8/ppp1pp1P/3P1Pb1/P1P1P3/1P3Q1P/RNB1K1NR b KQ -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1450, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(57711, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2016071, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(80287095, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_911) {
		const char* FEN = "r4bnr/1Bq1k1p1/5n2/1pp1pp1P/p2PPPb1/P1P5/1P3Q1P/RNB1K1NR w KQ -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1499, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(50901, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(2159399, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(73338011, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_912) {
		const char* FEN = "r4bn1/2q1k1pr/B4n2/1pp1pp1P/p2PPPb1/P1P2Q2/1P5P/RNB1K1NR b KQ -";
		Assert::AreEqual(42, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1449, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(60445, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1999837, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(82648526, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_913) {
		const char* FEN = "r4bn1/2q1k1pr/B4n2/1p3p1P/p1ppPPb1/P1P2Q2/1P2N2P/RNB1K2R w KQ -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1417, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(46496, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1937881, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(63036784, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_914) {
		const char* FEN = "r4bn1/4k1pr/B1q2n2/1p3p1P/p1ppPPb1/P1P4Q/1P2N2P/RNB1K2R b KQ -";
		Assert::AreEqual(43, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1308, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(56010, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1684462, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(71290393, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_915) {
		const char* FEN = "r3qbn1/4k1pr/B4n2/1p3p1P/p1ppPP2/P1P1Q3/1P2b2P/RNB1K2R w KQ -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1055, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30337, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1145504, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(33824421, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_916) {
		const char* FEN = "r3qbn1/4k1p1/B4n2/1p3p1r/p1ppPP1P/P1P1Q3/1P2b3/RNB1K2R b KQ -";
		Assert::AreEqual(40, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1082, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(42274, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1191891, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(47109958, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_917) {
		const char* FEN = "4qbn1/r3k3/B4np1/1p3p1r/p1ppPP1P/P1P1Q3/1P1Bb3/RN2K2R w KQ -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(920, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24030, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(942258, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25977085, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_918) {
		const char* FEN = "5bn1/r3kq2/5np1/1B3p1r/p1ppPP1P/P1P1Q3/1P1Bb2R/RN2K3 b Q -";
		Assert::AreEqual(38, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1068, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39399, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1143719, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(42760633, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_919) {
		const char* FEN = "r4bn1/4k2q/5np1/1B3p1r/p1pQPP1P/P1P5/1P1Bb2R/RN2K3 w Q -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(855, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29114, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(783225, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26628255, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_920) {
		const char* FEN = "r1Qk1bn1/7q/5np1/1B3p1r/p1p1PP1P/P1P5/1P1Bb2R/RN2K3 b Q -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(74, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2316, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(58257, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1911810, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_921) {
		const char* FEN = "2rk2n1/7q/5np1/1B3p1r/p1p1PP1P/b1P1B3/1P2b2R/RN2K3 w Q -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1147, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34668, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1318644, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(39544580, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_922) {
		const char* FEN = "2rk1bn1/7q/5np1/5p1r/p1B1PP1P/2P1B3/1P2R3/RN2K3 b Q -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1347, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(50280, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1709325, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(64721021, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_923) {
		const char* FEN = "r2k2n1/7q/3b1np1/5p1r/pPB1PP1P/2P1B3/4R3/RN2K3 w Q -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1382, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49409, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1886876, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(66700353, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_924) {
		const char* FEN = "r2k2n1/4b2q/B4np1/5p1r/pP2PP1P/2P1B3/R3R3/1N2K3 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(938, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27397, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(923566, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(29717881, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_925) {
		const char* FEN = "r3k1n1/4b3/BB3npq/5p1r/pP2PP1P/2P5/R3R3/1N2K3 w - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1044, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(37452, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1140855, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(39636217, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_926) {
		const char* FEN = "r3kbn1/8/B4npq/5p1r/pP2PP1P/2P1B3/R3R3/1N1K4 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1051, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(33069, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1129379, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(37262089, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_927) {
		const char* FEN = "3k1bn1/B7/r4npq/5p1r/pP2PP1P/2P5/R3R3/1N1K4 w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(945, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(28031, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(912105, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(26445337, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_928) {
		const char* FEN = "1B1k2n1/6b1/r4npq/5p1r/pP2PP1P/2P5/R2NR3/3K4 b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(758, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(23120, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(632491, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(20300347, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_929) {
		const char* FEN = "1B1k2n1/6b1/2r3pq/5p1r/pPN1nP1P/2P5/R3R3/3K4 w - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1038, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30010, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(986616, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(28472117, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_930) {
		const char* FEN = "1B1k2n1/6b1/2r3pq/4Rp1r/pPN2P1P/2P3n1/1R6/3K4 b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(967, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27127, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(856910, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(25705613, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_931) {
		const char* FEN = "1B1k2n1/2r3b1/6p1/4Rp1r/pPN2q1P/2P3n1/8/1R1K4 w - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1155, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27515, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1145512, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(27370605, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_932) {
		const char* FEN = "1B1k2n1/2r3b1/3q2p1/3R1p1r/pPN4P/2P3n1/8/2RK4 b - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(771, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(27001, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(613078, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22005639, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_933) {
		const char* FEN = "1B1k2nb/2r5/3q2p1/N2R1p1r/pP5P/2P5/8/2RK3n w - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(549, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(11903, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(381715, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9186417, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_934) {
		const char* FEN = "1B4nb/2r1k3/3R2p1/N4p1r/pP5P/2P5/4K3/2R4n b - -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(957, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26119, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(849952, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24011371, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_935) {
		const char* FEN = "1B4nb/4k3/2rR2p1/N4p1r/pP5P/2P2Kn1/8/2R5 w - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(847, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26958, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(756848, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24207528, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_936) {
		const char* FEN = "1B1R2n1/4k1b1/2r3p1/5p1r/pPN4P/2P2Kn1/8/2R5 b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1285, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38772, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1384200, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41149080, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_937) {
		const char* FEN = "1B6/4k1b1/2r2np1/5p1r/pPN4P/2PR1K2/4n3/2R5 w - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1192, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39986, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1338700, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(44096137, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_938) {
		const char* FEN = "1B6/3R2b1/2r1knp1/5p1r/pP5P/2P1NK2/4n3/2R5 b - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1224, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39842, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1372259, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(44887534, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_939) {
		const char* FEN = "1B6/5Rb1/2r1k1p1/5pnr/pP5P/2P1NK2/4n3/2R5 w - -";
		Assert::AreEqual(4, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(125, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4502, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(137632, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4698549, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_940) {
		const char* FEN = "1B6/5R2/2r1kbp1/5pnr/pP5P/2P5/2N1nK2/2R5 b - -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1091, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34735, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1080890, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35000364, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_941) {
		const char* FEN = "1B6/5R1n/2r1kbp1/5p1r/pP5P/2P5/2N5/2R3K1 w - -";
		Assert::AreEqual(33, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(788, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24484, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(608485, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18929152, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_942) {
		const char* FEN = "5R2/2B4n/2r1kbp1/5p1r/1P5P/p1P5/2N5/2R3K1 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(863, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21889, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(688129, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(18157347, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_943) {
		const char* FEN = "3b2R1/2B4n/2r1k1p1/7r/1P3p1P/p1P5/2N5/2R3K1 w - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(873, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(26246, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(744728, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(22659788, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_944) {
		const char* FEN = "6R1/7n/2r1kbp1/BP5r/5p1P/p1P5/2N5/2R3K1 b - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1113, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(35010, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1058997, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(32221473, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_945) {
		const char* FEN = "1r6/7n/4kbp1/BP5r/5p1P/p1P5/2N5/2R3K1 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(779, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(17314, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(582348, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(13340507, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_946) {
		const char* FEN = "8/1r5n/4kbp1/BP5r/2P2p1P/p7/8/2R1N1K1 b - -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(824, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(29318, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(646579, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21686967, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_947) {
		const char* FEN = "7b/1r5n/1B2k3/1P4pr/2P2p1P/p7/8/2R1N1K1 w - -";
		Assert::AreEqual(24, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(709, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16725, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(479734, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11429311, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_948) {
		const char* FEN = "7b/2r4n/4k3/1P4pr/2P2p1P/p7/8/3RN1K1 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(636, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(18167, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(377699, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10774027, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_949) {
		const char* FEN = "8/2r4n/4k3/1P2b1pr/2P4P/p4p2/8/2R1N1K1 w - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(521, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8037, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(266372, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4428855, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_950) {
		const char* FEN = "8/3r3n/4k3/1P2b1pr/2P4P/p4R2/8/4N1K1 b - -";
		Assert::AreEqual(35, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(786, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24664, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(512675, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(15810487, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_951) {
		const char* FEN = "8/3rk2n/3b1R2/1P4pr/2P4P/p7/8/4N1K1 w - -";
		Assert::AreEqual(22, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(444, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8877, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(220699, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4375912, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_952) {
		const char* FEN = "8/3rk2n/3b1R2/1P4P1/2P5/p6r/6K1/4N3 b - -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(577, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(16407, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(319050, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(9580962, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_953) {
		const char* FEN = "3r4/4k2n/8/1Pb3P1/2P5/p6r/5RK1/4N3 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(719, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12370, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(422575, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(7569345, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_954) {
		const char* FEN = "3r4/b3k2n/8/1P4P1/2P4N/p6r/5RK1/8 b - -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(714, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(21368, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(376906, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(11231938, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_955) {
		const char* FEN = "8/b3k3/5n2/1P3RP1/2Pr3N/p6r/6K1/8 w - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(584, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9838, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(302133, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5158998, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_956) {
		const char* FEN = "8/b3k3/5n2/1P4P1/2Pr3N/p4R2/7r/6K1 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(637, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(20416, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(320688, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(10091997, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_957) {
		const char* FEN = "6n1/b3k3/8/1PP3P1/5r1N/p4R2/7r/6K1 w - -";
		Assert::AreEqual(17, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(472, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(7642, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(208161, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3437633, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_958) {
		const char* FEN = "6n1/b3k3/1P6/2P3P1/5r1N/p4R2/r7/5K2 b - -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(390, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9560, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(155903, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3965045, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_959) {
		const char* FEN = "6n1/4k3/1b4P1/2P5/7N/p4r2/r7/5K2 w - -";
		Assert::AreEqual(3, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(89, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(648, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(16923, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(133477, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_960) {
		const char* FEN = "6n1/4k3/2P3P1/b7/7N/p4r2/r7/6K1 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(202, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5981, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(44474, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1307352, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_961) {
		const char* FEN = "6n1/4k3/2P3P1/8/7N/p4r2/1r6/4b2K w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(207, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1628, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(52222, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(497487, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_962) {
		const char* FEN = "6n1/2P5/3k2P1/8/8/p4N2/1r6/4b2K b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(454, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(12230, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(170429, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4216711, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_963) {
		const char* FEN = "2N3n1/2k5/6P1/b7/8/p4N2/1r6/7K w - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(396, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4843, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(125909, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1602532, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_964) {
		const char* FEN = "6n1/2k1N3/6P1/b7/8/p7/6rN/7K b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(244, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(6076, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(65824, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1701333, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_965) {
		const char* FEN = "6n1/2k1N3/6P1/b7/8/p3r3/7N/6K1 w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(333, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4238, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(112618, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1475389, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_966) {
		const char* FEN = "6n1/2k1N3/6P1/b7/8/p5K1/7N/8 b - -";
		Assert::AreEqual(15, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(220, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3634, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(53299, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(939606, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_967) {
		const char* FEN = "8/2k1N3/6P1/b6n/8/p4NK1/8/8 w - -";
		Assert::AreEqual(6, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(96, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1668, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(28564, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(474143, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_968) {
		const char* FEN = "1k6/4N3/6P1/b3N2n/8/p7/7K/8 b - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(264, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3986, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(66521, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1101718, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_969) {
		const char* FEN = "1k6/4N3/6P1/4N2n/1b6/8/p7/7K w - -";
		Assert::AreEqual(16, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(277, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(4154, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(81048, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1247918, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_970) {
		const char* FEN = "1k6/4N3/6P1/7n/1b6/8/8/q5NK b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(298, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9418, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(98381, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3272603, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_971) {
		const char* FEN = "1k4N1/8/6P1/2b1q2n/8/8/8/6NK w - -";
		Assert::AreEqual(8, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(329, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3089, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(118429, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1231357, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_972) {
		const char* FEN = "1k6/4N1q1/6P1/2b4n/8/7N/8/7K b - -";
		Assert::AreEqual(31, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(327, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10093, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(114605, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3696030, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_973) {
		const char* FEN = "1k6/4b3/6P1/7n/8/2q5/5N2/7K w - -";
		Assert::AreEqual(9, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(382, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3394, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(129047, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1173362, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_974) {
		const char* FEN = "1k5q/4b3/6P1/7n/8/3N4/7K/8 b - -";
		Assert::AreEqual(32, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(348, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10942, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(111965, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(3545673, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_975) {
		const char* FEN = "1k6/4b3/6P1/7n/8/2q5/1N5K/8 w - -";
		Assert::AreEqual(8, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(331, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2805, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(104699, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(940746, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_976) {
		const char* FEN = "1k6/4b3/6P1/N6n/8/5q2/7K/8 b - -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(238, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8034, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(61268, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2105490, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_977) {
		const char* FEN = "2k5/4b3/2N3P1/3q3n/8/8/7K/8 w - -";
		Assert::AreEqual(11, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(384, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3310, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(117291, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(1090545, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_978) {
		const char* FEN = "2k5/4b1P1/8/4Nq1n/8/8/7K/8 b - -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(470, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(15133, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(189922, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6075778, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_979) {
		const char* FEN = "2k3B1/4bq2/8/4N2n/8/8/7K/8 w - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(442, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(5883, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(182221, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(2492352, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_980) {
		const char* FEN = "2k1q1B1/4b3/8/7n/8/8/5N1K/8 b - -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(428, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(13236, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(200078, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6556289, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_981) {
		const char* FEN = "2k5/8/8/1q5n/2B4b/8/5N1K/8 w - -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(652, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10772, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(354795, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5488694, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_982) {
		const char* FEN = "2k5/8/2B2n2/8/7b/8/5N1K/8 b - -";
		Assert::AreEqual(14, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(248, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3640, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(61542, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(965398, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_983) {
		const char* FEN = "2k5/8/2B5/8/7b/8/5nK1/8 w - -";
		Assert::AreEqual(13, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(171, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(2247, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(34848, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(445209, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_984) {
		const char* FEN = "2k5/8/8/8/B6b/3n4/8/5K2 b - -";
		Assert::AreEqual(19, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(186, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3305, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(37066, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(667377, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_985) {
		const char* FEN = "k7/8/8/8/7b/3n4/2B5/5K2 w - -";
		Assert::AreEqual(8, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(136, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(1431, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(23130, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(264436, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_986) {
		const char* FEN = "k7/8/6B1/8/5n1b/8/8/6K1 b - -";
		Assert::AreEqual(18, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(190, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(3199, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(35738, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(616637, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_987) {
		const char* FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -";
		Assert::AreEqual(20, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(400, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(8902, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(197281, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(4865609, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_988) {
		const char* FEN = "rnbqkbnr/p1pppppp/1p6/8/7P/P7/1PPPPPP1/RNBQKBNR b KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(420, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(9700, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(219822, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(5547801, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_989) {
		const char* FEN = "rnbqkb1r/p2ppppp/1pp2n2/7P/8/P7/1PPPPPP1/RNBQKBNR w KQkq -";
		Assert::AreEqual(21, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(441, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(10464, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(244919, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(6367151, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_990) {
		const char* FEN = "rnb1kb1r/p1qppppp/1pp2n2/7P/8/P1NP4/1PP1PPP1/R1BQKBNR b KQkq -";
		Assert::AreEqual(28, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(857, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(25426, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(788005, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(24212778, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_991) {
		const char* FEN = "rnb1kb2/p1qppppr/1pp2n1p/7P/8/P1NP4/1PP1PPPR/R1BQKBN1 w Qq -";
		Assert::AreEqual(30, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(807, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(24603, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(702291, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(21660693, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_992) {
		const char* FEN = "rnb1kb2/p2ppppr/1pp2n1p/3P3P/5q2/P1N5/1PP1PPPR/R1BQKBN1 b Qq -";
		Assert::AreEqual(39, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1078, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(38592, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1162500, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(40117094, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_993) {
		const char* FEN = "rnb1kb2/p2ppp1r/1p3npp/3p3P/5q2/P1N5/1PP1PPP1/R1BQKBNR w Qq -";
		Assert::AreEqual(29, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1119, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(34519, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1237879, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(41229289, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_994) {
		const char* FEN = "rnb1kb2/p2p1p1r/1p3npp/3pp2P/5q1R/P1N5/1PPBPPP1/R2QKBN1 b Qq -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1233, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(47984, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1515114, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(57006554, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_995) {
		const char* FEN = "rnb1kb2/p2p1p1r/6pp/1p1pp2P/4nq2/P1N5/1PPBPPP1/R2QKBNR w Qq -";
		Assert::AreEqual(27, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1110, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(30509, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1225510, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(35626649, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_996) {
		const char* FEN = "rnb1kb2/p2p3r/6pp/1pNppp1P/5q2/P7/1PPBPPP1/R2QKBNR b Qq -";
		Assert::AreEqual(37, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1231, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(44605, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1487719, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(52687565, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_997) {
		const char* FEN = "rnb1kb2/p2p3r/7p/1pNppppP/2q5/P7/1PPBPPP1/R1Q1KBNR w Qq -";
		Assert::AreEqual(34, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1274, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(40740, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1466876, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(46463114, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_998) {
		const char* FEN = "r1b1kb2/p2p3r/n3N2p/1p1ppppP/2q5/P7/1PPBPPP1/RQ2KBNR b Qq -";
		Assert::AreEqual(41, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1381, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(49785, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1626177, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(56933097, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_999) {
		const char* FEN = "r1b1kb2/p2p3r/4N2p/1p1ppppP/1n2q3/P3P3/1PPB1PP1/RQ2KBNR w Qq -";
		Assert::AreEqual(36, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(1187, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(39412, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(1330569, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(44063374, Perft::perftLazy(FEN, 5));
	}
	TEST_METHOD(gentest_1000) {
		const char* FEN = "r1b1kb2/p2p3r/4N2p/1p1ppppP/1n6/P3P2R/1PPB2P1/RQ2KBN1 b Qq -";
		Assert::AreEqual(26, Perft::perftLazy(FEN, 1));
		Assert::AreEqual(891, Perft::perftLazy(FEN, 2));
		Assert::AreEqual(22229, Perft::perftLazy(FEN, 3));
		Assert::AreEqual(781301, Perft::perftLazy(FEN, 4));
		Assert::AreEqual(19901798, Perft::perftLazy(FEN, 5));
	}

	};


}