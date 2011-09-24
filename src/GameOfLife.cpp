#include "GameInitializer.h"
#include "GameRunner.h"
#include "TestRunner.h"
#include <gtest/gtest.h>

using namespace std;
using namespace GameOfLife;

int main(int argc, char* argv[]) {
	if(argc > 1 && !strcmp(argv[1],"-test")) {
		TestRunner runner;
		return runner.run(argc, argv);
	}
	GameRunner gRunner;
	GameInitializer intializer(gRunner);
	cout << intializer.execute(argc, argv);
	return 0;
}
