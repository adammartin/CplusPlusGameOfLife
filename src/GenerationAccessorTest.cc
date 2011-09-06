#include "MockRules.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GenerationAccessor.h"
#include "boost/multi_array.hpp"

using ::testing::Exactly;
using ::testing::Return;
using ::testing::_;
using namespace GameOfLife;

TEST(GenerationAccessor, CanValidateBoardIsAllDead){
	const int data_size=3;

	array_type firstGen(boost::extents[data_size][data_size]);
	array_type expectedGen(boost::extents[data_size][data_size]);

	MockRules livingRules;
	MockRules deadRules;

	EXPECT_CALL(deadRules, Apply(0)).Times(Exactly(9));

	GenerationAccessor accessor(&livingRules, &deadRules);

	EXPECT_EQ(expectedGen, accessor.access(firstGen));
}

