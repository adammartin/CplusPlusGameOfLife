#include "RuleBasedGenerationAccessor.h"
#include "Board.h"
#include "rules/MockRules.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <boost/shared_ptr.hpp>

using ::testing::Exactly;
using ::testing::Return;
using namespace GameOfLife;

typedef boost::shared_ptr<GameOfLife::MockRules> MockRulesPtr;

const int DATA_SIZE = 3;

class RuleBasedGenerationAccessorTest : public ::testing::Test {
public:
	MockRulesPtr livingRules;
	MockRulesPtr deadRules;
	RuleBasedGenerationAccessor *accessor;

	virtual void SetUp() {
		livingRules = MockRulesPtr(new MockRules());
		deadRules = MockRulesPtr(new MockRules());
		accessor = new RuleBasedGenerationAccessor(livingRules, deadRules);
	}

	virtual void TearDown(){
		delete accessor;
	}
};

TEST_F(RuleBasedGenerationAccessorTest, CanValidateBoardIsAllDead){
	Grid firstGen(boost::extents[DATA_SIZE][DATA_SIZE]);
	Grid expectedGrid(boost::extents[DATA_SIZE][DATA_SIZE]);

	EXPECT_CALL(*deadRules, Apply(0)).Times(Exactly(9)).WillRepeatedly(Return(false));

	const GridPtr response = accessor->access(firstGen);

	EXPECT_EQ(expectedGrid, *response);
}

TEST_F(RuleBasedGenerationAccessorTest, CanValidateBoardCallCorrectRulesForAllAlive){
	Grid firstGen(boost::extents[DATA_SIZE][DATA_SIZE]);
	Grid expectedGrid(boost::extents[DATA_SIZE][DATA_SIZE]);

	for(short x = 0; x < DATA_SIZE; x++){
		for(short y = 0; y < DATA_SIZE; y++){
			firstGen[x][y] = true;
		}
	}

	EXPECT_CALL(*livingRules, Apply(3)).Times(Exactly(4)).WillRepeatedly(Return(false));
	EXPECT_CALL(*livingRules, Apply(5)).Times(Exactly(4)).WillRepeatedly(Return(false));
	EXPECT_CALL(*livingRules, Apply(8)).Times(Exactly(1)).WillRepeatedly(Return(false));

	const GridPtr response = accessor->access(firstGen);

	EXPECT_EQ(expectedGrid, *response);
}

TEST_F(RuleBasedGenerationAccessorTest, WillSetBoardBasedOnRules){
	Grid firstGen(boost::extents[DATA_SIZE][DATA_SIZE]);
	Grid expectedGrid(boost::extents[DATA_SIZE][DATA_SIZE]);

	for(short x = 0; x < DATA_SIZE; x++){
		for(short y = 0; y < DATA_SIZE; y++){
			firstGen[x][y] = true;
		}
	}

	expectedGrid[1][1] = true;

	EXPECT_CALL(*livingRules, Apply(3)).Times(Exactly(4)).WillRepeatedly(Return(false));
	EXPECT_CALL(*livingRules, Apply(5)).Times(Exactly(4)).WillRepeatedly(Return(false));
	EXPECT_CALL(*livingRules, Apply(8)).Times(Exactly(1)).WillRepeatedly(Return(true));

	const GridPtr response = accessor->access(firstGen);

	EXPECT_EQ(expectedGrid, *response);
}

TEST_F(RuleBasedGenerationAccessorTest, CanValidateBoardCallCorrectRulesForMixed){
	Grid firstGen(boost::extents[DATA_SIZE][DATA_SIZE]);
	Grid expectedGrid(boost::extents[DATA_SIZE][DATA_SIZE]);

	firstGen[0][0] = true;
	firstGen[0][1] = true;

	EXPECT_CALL(*deadRules, Apply(0)).Times(Exactly(3)).WillRepeatedly(Return(false));
	EXPECT_CALL(*deadRules, Apply(1)).Times(Exactly(2)).WillRepeatedly(Return(false));
	EXPECT_CALL(*deadRules, Apply(2)).Times(Exactly(2)).WillRepeatedly(Return(false));
	EXPECT_CALL(*livingRules, Apply(1)).Times(Exactly(2)).WillRepeatedly(Return(false));

	const GridPtr response = accessor->access(firstGen);

	EXPECT_EQ(expectedGrid, *response);
}

TEST_F(RuleBasedGenerationAccessorTest, WillApplyCorrectRulesForMixed){
	Grid firstGen(boost::extents[DATA_SIZE][DATA_SIZE]);
	Grid expectedGrid(boost::extents[DATA_SIZE][DATA_SIZE]);

	firstGen[0][0] = true;
	firstGen[0][1] = true;

	expectedGrid[2][0] = true;
	expectedGrid[2][1] = true;
	expectedGrid[2][2] = true;

	EXPECT_CALL(*deadRules, Apply(0)).Times(Exactly(3)).WillRepeatedly(Return(true));
	EXPECT_CALL(*deadRules, Apply(1)).Times(Exactly(2)).WillRepeatedly(Return(false));
	EXPECT_CALL(*deadRules, Apply(2)).Times(Exactly(2)).WillRepeatedly(Return(false));
	EXPECT_CALL(*livingRules, Apply(1)).Times(Exactly(2)).WillRepeatedly(Return(false));

	const GridPtr response = accessor->access(firstGen);

	EXPECT_EQ(expectedGrid, *response);
}


