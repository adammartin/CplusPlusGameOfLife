#ifndef MOCKTESTRUNNER_H_
#define MOCKTESTRUNNER_H_

#include "TestRunner.h"
#include <gmock/gmock.h>


class MockTestRunner : public TestRunner {
public:
	MOCK_CONST_METHOD2(executeTests, const int(int argc, char* argv[]));
};

#endif /* MOCKTESTRUNNER_H_ */
