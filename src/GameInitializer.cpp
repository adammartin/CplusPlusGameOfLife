#include "GameInitializer.h"
#include <string>

using namespace std;

namespace GameOfLife {

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

GameInitializer::GameInitializer(LineRenderer &rRenderer, std::ostream &rOss, TestRunner &rRunner):renderer(rRenderer), oss(rOss), runner(rRunner) {
}

GameInitializer::~GameInitializer() {
}

int GameInitializer::execute(int argc, char* argv[]) const {
	char* arg = argv[1];
	if(!strcmp(arg,"-test")){
		return runner.executeTests(argc, argv);
	}
	oss << usage();
	return 0;
}

} /* namespace GameOfLife */
