#include "board.h"
#include "gtest/gtest.h"
#include "Orchestrator.h"
#include "RuleBasedGenerationAccessor.h"
#include "LivingRules.h"
#include "DeadRules.h"
#include "NCursesLineRenderer.h"
#include <string>
#include <map>
#include <iostream>
#include <ctype.h>

using namespace std;
using namespace GameOfLife;

int usage(){
	cout << "-help: help message" << endl;
	cout << "-test: run tests" << endl;
	cout << "[BLINKER | TOAD | ACORN | LINE | GOSPER_GUN] NUMBER_OF_GENERATIONS: initial pattern to start with" << endl;
	return 0;
}

void runGame(Orchestrator &orchestrator, int generations){
	for(int i = 0; i < generations; i++){
		orchestrator.nextGeneration();
		usleep(100000);
	}
}

int runGame(Pattern pattern, int generations){
	LivingRules livingRules;
	DeadRules deadRules;
	RuleBasedGenerationAccessor accessor(livingRules, deadRules);
	NCursesLineRenderer renderer;
	Orchestrator orchestrator(accessor, renderer, pattern);
	runGame(orchestrator, generations);
	return 0;
}

map<string, Pattern>& buildPatterns(){
	map<string, Pattern> *patterns = new map<string, Pattern>();
	(*patterns)["BLINKER"] = BLINKER;
	(*patterns)["TOAD"] = TOAD;
	(*patterns)["ACORN"] = ACORN;
	(*patterns)["LINE"] = LINE;
	(*patterns)["GOSPER_GUN"] = GOSPER_GUN;
	return *patterns;
}

int executeOption(int argc, char* argv[]){
	map<string, Pattern> &patterns = buildPatterns();
	char* arg = argv[1];
	if(!strcmp(arg,"-test")) {
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
	if(argc == 3 && patterns[string(arg)] && isdigit(*argv[2])){
		return runGame(patterns[string(arg)], atoi(argv[2]));
	}
	cout << arg << endl;
	return usage();
}

int runOptions(int argc, char* argv[]){
	if(argc > 1){
		return executeOption(argc, argv);
	}
	return usage();
}

int main(int argc, char* argv[]) {
	if(argc > 1) {
		return runOptions(argc, argv);
	}
	return 0;
}
