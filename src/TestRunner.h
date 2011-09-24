#ifndef TESTRUNNER_H_
#define TESTRUNNER_H_

class TestRunner {
public:
	TestRunner();
	virtual ~TestRunner();
	virtual const int run(int argc, char* argv[]) const;
};

#endif /* TESTRUNNER_H_ */
