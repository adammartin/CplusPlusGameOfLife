#include "board/board.h"
#include "OrchestratorFactory.h"
#include "NCursesLineRenderer.h"
#include <gtest/gtest.h>
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

void runGame(OrchestratorPtr orchestrator, int generations){
	for(int i = 0; i < generations; i++){
		orchestrator->nextGeneration();
		usleep(100000);
	}
}

int runGame(Pattern pattern, int generations){
	OrchestratorFactory factory;
	NCursesLineRenderer renderer;
	OrchestratorPtr orchestrator = factory.create(renderer, pattern);
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

	map<string, Pattern>::iterator i = patterns.find(string(arg));
	if (argc == 3 && i != patterns.end() && isdigit(*argv[2])) {
		return runGame(i->second, atoi(argv[2]));
	}
	cout << arg << endl;
	return usage();
}

int main(int argc, char* argv[]) {
	if(argc > 1){
		return executeOption(argc, argv);
	}
	return usage();
}
