#include "gtest/gtest.h"
#include "Board.h"

using namespace GameOfLife;

TEST(Board, CanGetBoardSize){
	Grid base(boost::extents[3][3]);
	Board board(base);

	EXPECT_EQ(3, board.size());
}

TEST(Board, EqualOperatorIsBasedOnInternalGrids){
	Grid base(boost::extents[3][3]);
	Grid base2(boost::extents[3][3]);
	Board board(base);
	Board board2(base2);

	EXPECT_EQ(board2, board);
}

TEST(Board, EqualOperatorIsNotEqualBasedOnInternalGrids){
	Grid base(boost::extents[3][3]);
	Grid base2(boost::extents[2][2]);
	Board board(base);
	Board board2(base2);

	ASSERT_FALSE(board2 == board);
}

TEST(Board, NotEqualUsingNotOperatorBasedOnInteralGrids){
	Grid base(boost::extents[3][3]);
	Grid base2(boost::extents[2][2]);
	Board board(base);
	Board board2(base2);

	ASSERT_NE(board2, board);
}

TEST(Board, CanGetCountOfZeroLivingNeighbors){
	Grid base(boost::extents[3][3]);
	Board board(base);

	EXPECT_EQ(0, board.getNeighbors(1,1));
}

TEST(Board, CanGetCountOfOneLivingNeighbors){
	Grid base(boost::extents[3][3]);
	base[0][1] = true;

	Board board(base);

	EXPECT_EQ(1, board.getNeighbors(1,1));
}

TEST(Board, CanGetCountOfTwoLivingNeighbors){
	Grid base(boost::extents[3][3]);
	base[0][1] = true;
	base[0][0] = true;

	Board board(base);

	EXPECT_EQ(2, board.getNeighbors(1,1));
}

TEST(Board, CanGetCountOfOneLivingNeighborAndNotCountSelf){
	Grid base(boost::extents[3][3]);
	base[0][1] = true;
	base[0][0] = true;

	Board board(base);

	EXPECT_EQ(1, board.getNeighbors(0,0));
}

TEST(Board, CanNotGetCountOutOfBounds){
	Grid base(boost::extents[3][3]);

	Board board(base);

	EXPECT_EQ(0, board.getNeighbors(0,3));
}

TEST(Board, CanBuildBlinker) {
	Grid expected(boost::extents[40][40]);
	expected[20][19] = true;
	expected[20][20] = true;
	expected[20][21] = true;

	Board board;

	EXPECT_EQ(expected, board.build(BLINKER));
}

TEST(Board, CanBuildToad) {
	Grid expected(boost::extents[40][40]);
	expected[20][19] = true;
	expected[20][20] = true;
	expected[20][21] = true;
	expected[21][18] = true;
	expected[21][19] = true;
	expected[21][20] = true;

	Board board;

	EXPECT_EQ(expected, board.build(TOAD));
}

TEST(Board, CanBuildAcorn) {
	Grid expected(boost::extents[40][40]);
	expected[18][16] = true;
	expected[19][18] = true;
	expected[20][15] = true;
	expected[20][16] = true;
	expected[20][19] = true;
	expected[20][20] = true;
	expected[20][21] = true;

	Board board;

	EXPECT_EQ(expected, board.build(ACORN));
}



