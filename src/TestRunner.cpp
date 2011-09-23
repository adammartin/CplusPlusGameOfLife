#include "TestRunner.h"
#include <gtest/gtest.h>

TestRunner::TestRunner() {
}

TestRunner::~TestRunner() {
}

const int TestRunner::executeTests(int argc, char* argv[]) const {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

