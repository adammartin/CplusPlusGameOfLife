#include "GameInitializer.h"
#include "MockTestRunner.h";
#include "MockGameRunner.h";
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

using ::testing::Exactly;
using ::testing::Return;
using ::testing::_;

using namespace GameOfLife;
using namespace std;

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

TEST_F(GameInitializerTest, CanPrintHelp){
	MockGameRunner gameRunner;
	GameInitializer initializer(gameRunner);

	int argc = 2;
	char *argv[argc+1];
	argv[0] = const_cast<char*>("GameOfLife");
	argv[1] = const_cast<char*>("-help");
	argv[2] = 0;

	EXPECT_CALL(gameRunner, run(_, _)).Times(Exactly(0));

	string result = initializer.execute(argc, argv);

	EXPECT_EQ(helpText, result);
}

TEST_F(GameInitializerTest, WillPrintHelpIfNoArgsGiven){
	MockGameRunner gameRunner;
	GameInitializer initializer(gameRunner);

	int argc = 1;
	char *argv[argc+1];
	argv[0] = const_cast<char*>("GameOfLife");
	argv[1] = 0;

	EXPECT_CALL(gameRunner, run(_, _)).Times(Exactly(0));

	string result = initializer.execute(argc, argv);

	EXPECT_EQ(helpText, result);
}

TEST_F(GameInitializerTest, CanAcornRunGame){
	MockGameRunner gameRunner;
	GameInitializer initializer(gameRunner);

	int argc = 3;
	char *argv[argc+1];
	argv[0] = const_cast<char*>("GameOfLife");
	argv[1] = const_cast<char*>("ACORN");
	argv[2] = const_cast<char*>("1");
	argv[3] = 0;

	EXPECT_CALL(gameRunner, run(_, 1)).Times(Exactly(1));

	string result = initializer.execute(argc, argv);

	EXPECT_EQ("", result);
}

TEST_F(GameInitializerTest, CanToadRunGame){
	MockGameRunner gameRunner;
	GameInitializer initializer(gameRunner);

	int argc = 3;
	char *argv[argc+1];
	argv[0] = const_cast<char*>("GameOfLife");
	argv[1] = const_cast<char*>("TOAD");
	argv[2] = const_cast<char*>("2");
	argv[3] = 0;

	EXPECT_CALL(gameRunner, run(_, 2)).Times(Exactly(1));

	string result = initializer.execute(argc, argv);

	EXPECT_EQ("", result);
}


