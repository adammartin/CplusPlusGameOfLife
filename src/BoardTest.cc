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

TEST(Board, CanBuildGosperGun) {
	GridPtr expected(new Grid(boost::extents[30][120]));
	(*expected)[6][2] = true;
	(*expected)[6][3] = true;
	(*expected)[7][2] = true;
	(*expected)[7][3] = true;

	(*expected)[6][12] = true;
	(*expected)[7][12] = true;
	(*expected)[8][12] = true;

	(*expected)[5][13] = true;
	(*expected)[9][13] = true;

	(*expected)[4][14] = true;
	(*expected)[4][15] = true;
	(*expected)[10][14] = true;
	(*expected)[10][15] = true;

	(*expected)[7][16] = true;

	(*expected)[5][17] = true;
	(*expected)[9][17] = true;

	(*expected)[6][18] = true;
	(*expected)[7][18] = true;
	(*expected)[8][18] = true;

	(*expected)[7][19] = true;

	(*expected)[4][22] = true;
	(*expected)[5][22] = true;
	(*expected)[6][22] = true;
	(*expected)[4][23] = true;
	(*expected)[5][23] = true;
	(*expected)[6][23] = true;

	(*expected)[3][24] = true;
	(*expected)[7][24] = true;

	(*expected)[2][26] = true;
	(*expected)[3][26] = true;
	(*expected)[7][26] = true;
	(*expected)[8][26] = true;

	(*expected)[4][36] = true;
	(*expected)[5][36] = true;
	(*expected)[4][37] = true;
	(*expected)[5][37] = true;

	Board board;

	EXPECT_EQ(*expected, *board.build(GOSPER_GUN));
}


TEST(Board, CanBuildLine) {
	GridPtr expected(new Grid(boost::extents[30][120]));
	(*expected)[14][41] = true;
	(*expected)[14][42] = true;
	(*expected)[14][43] = true;
	(*expected)[14][44] = true;
	(*expected)[14][45] = true;
	(*expected)[14][46] = true;
	(*expected)[14][47] = true;
	(*expected)[14][48] = true;

	(*expected)[14][50] = true;
	(*expected)[14][51] = true;
	(*expected)[14][52] = true;
	(*expected)[14][53] = true;
	(*expected)[14][54] = true;

	(*expected)[14][58] = true;
	(*expected)[14][59] = true;
	(*expected)[14][60] = true;

	(*expected)[14][67] = true;
	(*expected)[14][68] = true;
	(*expected)[14][69] = true;
	(*expected)[14][70] = true;
	(*expected)[14][71] = true;
	(*expected)[14][72] = true;
	(*expected)[14][73] = true;

	(*expected)[14][75] = true;
	(*expected)[14][76] = true;
	(*expected)[14][77] = true;
	(*expected)[14][78] = true;
	(*expected)[14][79] = true;

	Board board;

	EXPECT_EQ(*expected, *board.build(LINE));
}



