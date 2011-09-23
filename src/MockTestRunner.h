#include "TestRunner.h"
#include <gmock/gmock.h>

#ifndef MOCKTESTRUNNER_H_
#define MOCKTESTRUNNER_H_

class MockTestRunner : public TestRunner {
public:
	MOCK_METHOD2(executeTests, int(int argc, char* argv[]));
};

#endif /* MOCKTESTRUNNER_H_ */
