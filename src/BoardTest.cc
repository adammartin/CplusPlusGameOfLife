#include <limits.h>
#include "rules.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(Board, CanInstantiateBoard){

}

class DeadRules: public Rules {
public:
	DeadRules();
	virtual ~DeadRules();
	bool Apply(const unsigned short neighbors);
};


