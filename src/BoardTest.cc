#include "gtest/gtest.h"
#include "Board.h"

using namespace GameOfLife;

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
	GridPtr expected(new Grid(boost::extents[30][120]));
	(*expected)[15][14] = true;
	(*expected)[15][15] = true;
	(*expected)[15][16] = true;

	Board board;

	EXPECT_EQ(*expected, *board.build(BLINKER));
}

TEST(Board, CanBuildToad) {
	GridPtr expected(new Grid(boost::extents[30][120]));
	(*expected)[15][14] = true;
	(*expected)[15][15] = true;
	(*expected)[15][16] = true;
	(*expected)[16][13] = true;
	(*expected)[16][14] = true;
	(*expected)[16][15] = true;

	Board board;

	EXPECT_EQ(*expected, *board.build(TOAD));
}

TEST(Board, CanBuildAcorn) {
	GridPtr expected(new Grid(boost::extents[30][120]));
	(*expected)[13][26] = true;
	(*expected)[14][28] = true;
	(*expected)[15][25] = true;
	(*expected)[15][26] = true;
	(*expected)[15][29] = true;
	(*expected)[15][30] = true;
	(*expected)[15][31] = true;

	Board board;

	EXPECT_EQ(*expected, *board.build(ACORN));
}



