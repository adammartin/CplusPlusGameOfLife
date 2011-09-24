#include "GameInitializer.h"
#include "OrchestratorFactory.h"
#include "NCursesLineRenderer.h"
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

const string printPatternOptions(){
	PatternMap map = buildPatterns();
	PatternMap::iterator iter = map.begin();
	string patternOptions("[ ");
	while(iter != map.end()){
		patternOptions += (iter++)->first;
		patternOptions += ((iter != map.end()) ? " | " : " ]");
	}
	return patternOptions;
}

const string usage(){
	string helpText("-help: help message\n");
	helpText += "-test: run tests\n";
	helpText += printPatternOptions();
	helpText += " NUMBER_OF_GENERATIONS: initial pattern to start with\n";
	return helpText;
}

const bool hasValidPattern(int argc, char* argv[]){
	if(argc == 3 && isdigit(*argv[2])){
		PatternMap patterns = buildPatterns();
		PatternMapIterator iter = patterns.find(string(argv[1]));
		return iter != patterns.end();
	}
	return false;
}

GameInitializer::GameInitializer(const GameRunner &rGameRunner):gameRunner(rGameRunner) {
}

GameInitializer::~GameInitializer() {
}

const string GameInitializer::execute(int argc, char* argv[]) const {
	if(hasValidPattern(argc, argv)) {
		PatternMap patterns = buildPatterns();
		PatternMapIterator iter = patterns.find(string(argv[1]));
		return runGame(iter->second, atoi(argv[2]));
	}
	return usage();
}

const string GameInitializer::runGame(const Pattern pattern, const int generations) const{
	OrchestratorFactory factory;
	NCursesLineRenderer renderer;
	OrchestratorPtr orchestrator = factory.create(renderer, pattern);
	gameRunner.run(orchestrator, generations);
	return string("");
}

} /* namespace GameOfLife */
