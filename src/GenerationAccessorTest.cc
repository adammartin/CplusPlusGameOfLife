#include "GenerationAccessor.h"
#include "Board.h"
#include "MockRules.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "boost/multi_array.hpp"
#include <iostream>

using ::testing::Exactly;
using ::testing::Return;
using ::testing::_;
using namespace GameOfLife;
using namespace std;

TEST(GenerationAccessor, CanValidateBoardIsAllDead){
	const int data_size=3;

	MockRules livingRules;
	MockRules deadRules;

	GenerationAccessor accessor(livingRules, deadRules);

	Grid firstGen(boost::extents[data_size][data_size]);
	Grid expectedGrid(boost::extents[data_size][data_size]);

	EXPECT_CALL(deadRules, Apply(0)).Times(Exactly(9)).WillRepeatedly(Return(false));

	const Grid& response = accessor.access(firstGen);

	EXPECT_EQ(expectedGrid, response);

	delete &response;
}

TEST(GenerationAccessor, CanValidateBoardCallCorrectRulesForAllAlive){
	const int data_size=3;

	MockRules livingRules;
	MockRules deadRules;

	GenerationAccessor accessor(livingRules, deadRules);

	Grid firstGen(boost::extents[data_size][data_size]);
	Grid expectedGrid(boost::extents[data_size][data_size]);

	for(short x = 0; x < data_size; x++){
		for(short y = 0; y < data_size; y++){
			firstGen[x][y] = true;
		}
	}

	EXPECT_CALL(livingRules, Apply(3)).Times(Exactly(4)).WillRepeatedly(Return(false));
	EXPECT_CALL(livingRules, Apply(5)).Times(Exactly(4)).WillRepeatedly(Return(false));
	EXPECT_CALL(livingRules, Apply(8)).Times(Exactly(1)).WillRepeatedly(Return(false));

	const Grid& response = accessor.access(firstGen);

	EXPECT_EQ(expectedGrid, response);

	delete &response;
}

TEST(GenerationAccessor, WillSetBoardBasedOnRules){
	const int data_size=3;

	MockRules deadRules;
	MockRules livingRules;

	GenerationAccessor accessor(livingRules, deadRules);

	Grid firstGen(boost::extents[data_size][data_size]);
	Grid expectedGrid(boost::extents[data_size][data_size]);

	for(short x = 0; x < data_size; x++){
		for(short y = 0; y < data_size; y++){
			firstGen[x][y] = true;
		}
	}

	expectedGrid[1][1] = true;

	EXPECT_CALL(livingRules, Apply(3)).Times(Exactly(4)).WillRepeatedly(Return(false));
	EXPECT_CALL(livingRules, Apply(5)).Times(Exactly(4)).WillRepeatedly(Return(false));
	EXPECT_CALL(livingRules, Apply(8)).Times(Exactly(1)).WillRepeatedly(Return(true));


	const Grid& response = accessor.access(firstGen);

	EXPECT_EQ(expectedGrid, response);

	delete &response;
}

TEST(GenerationAccessor, CanValidateBoardCallCorrectRulesForMixed){
	const int data_size=3;

	MockRules livingRules;
	MockRules deadRules;

	GenerationAccessor accessor(livingRules, deadRules);

	Grid firstGen(boost::extents[data_size][data_size]);
	Grid expectedGrid(boost::extents[data_size][data_size]);

	firstGen[0][0] = true;
	firstGen[0][1] = true;

	EXPECT_CALL(deadRules, Apply(0)).Times(Exactly(3)).WillRepeatedly(Return(false));
	EXPECT_CALL(deadRules, Apply(1)).Times(Exactly(2)).WillRepeatedly(Return(false));
	EXPECT_CALL(deadRules, Apply(2)).Times(Exactly(2)).WillRepeatedly(Return(false));
	EXPECT_CALL(livingRules, Apply(1)).Times(Exactly(2)).WillRepeatedly(Return(false));

	const Grid& response = accessor.access(firstGen);

	EXPECT_EQ(expectedGrid, response);

	delete &response;
}

TEST(GenerationAccessor, WillApplyCorrectRulesForMixed){
	const int data_size=3;

	MockRules livingRules;
	MockRules deadRules;

	GenerationAccessor accessor(livingRules, deadRules);

	Grid firstGen(boost::extents[data_size][data_size]);
	Grid expectedGrid(boost::extents[data_size][data_size]);

	firstGen[0][0] = true;
	firstGen[0][1] = true;

	expectedGrid[2][0] = true;
	expectedGrid[2][1] = true;
	expectedGrid[2][2] = true;

	EXPECT_CALL(deadRules, Apply(0)).Times(Exactly(3)).WillRepeatedly(Return(true));
	EXPECT_CALL(deadRules, Apply(1)).Times(Exactly(2)).WillRepeatedly(Return(false));
	EXPECT_CALL(deadRules, Apply(2)).Times(Exactly(2)).WillRepeatedly(Return(false));
	EXPECT_CALL(livingRules, Apply(1)).Times(Exactly(2)).WillRepeatedly(Return(false));

	const Grid& response = accessor.access(firstGen);

	EXPECT_EQ(expectedGrid, response);

	delete &response;
}


