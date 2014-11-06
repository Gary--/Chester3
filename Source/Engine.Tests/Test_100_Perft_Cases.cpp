#include "stdafx.h"
#include "CppUnitTest.h"
#include "perft.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_100_Perft_Cases) {
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
	};
}