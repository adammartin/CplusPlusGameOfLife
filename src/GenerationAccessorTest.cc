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

	Grid firstGen(boost::extents[data_size][data_size]);
	Grid expectedGrid(boost::extents[data_size][data_size]);

	MockRules livingRules;
	MockRules deadRules;

	EXPECT_CALL(deadRules, Apply(0)).Times(Exactly(9));

	GenerationAccessor accessor(livingRules, deadRules);

	EXPECT_EQ(Board(expectedGrid), accessor.access(firstGen));
}


