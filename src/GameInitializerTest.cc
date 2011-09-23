#include "MockLineRenderer.h"
#include "GameInitializer.h"
#include "MockTestRunner.h";
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

using ::testing::Exactly;
using ::testing::Return;
using ::testing::_;

using namespace GameOfLife;

class GameInitializerTest : public ::testing::Test {
protected:
	PatternMap buildPatterns(){
		PatternMap patterns;
		patterns["BLINKER"] = BLINKER;
		patterns["TOAD"] = TOAD;
		patterns["ACORN"] = ACORN;
		patterns["LINE"] = LINE;
		patterns["GOSPER_GUN"] = GOSPER_GUN;
		return patterns;
	}

	string printPatternOptions(){
		PatternMap map = buildPatterns();
		PatternMap::iterator iter = map.begin();
		string patternOptions("[ ");
		while(iter != map.end()){
			patternOptions += (iter++)->first;
			patternOptions += ((iter != map.end()) ? " | " : " ]");
		}
		return patternOptions;
	}

	string usage(){
		string helpText("-help: help message\n");
		helpText += "-test: run tests\n";
		helpText += printPatternOptions();
		helpText += " NUMBER_OF_GENERATIONS: initial pattern to start with\n";
		return helpText;
	}

	virtual void SetUp(){
		helpText = usage();
	}

	string helpText;

};

TEST_F(GameInitializerTest, CanRunTests){
	MockLineRenderer renderer;
	MockTestRunner testRunner;
	stringstream ostream;
	GameInitializer initializer(renderer, ostream, testRunner);

	int argc = 2;
	char *argv[3];
	argv[0] = const_cast<char*>("GameOfLife");
	argv[1] = const_cast<char*>("-test");
	argv[2] = 0;

	EXPECT_CALL(testRunner, executeTests(_, _)).Times(Exactly(1)).WillOnce(Return(0));

	int result = initializer.execute(argc, argv);

	EXPECT_EQ(0, result);
}

TEST_F(GameInitializerTest, CanPrintHelp){
	MockLineRenderer renderer;
	MockTestRunner testRunner;
	stringstream ostream;
	GameInitializer initializer(renderer, ostream, testRunner);

	int argc = 2;
	char *argv[3];
	argv[0] = const_cast<char*>("GameOfLife");
	argv[1] = const_cast<char*>("-help");
	argv[2] = 0;

	EXPECT_CALL(testRunner, executeTests(_, _)).Times(Exactly(0));

	int result = initializer.execute(argc, argv);
	EXPECT_EQ(helpText, ostream.str());

	EXPECT_EQ(0, result);
}


