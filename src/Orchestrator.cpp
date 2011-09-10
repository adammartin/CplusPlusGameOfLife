#include "Board.h"
#include "Orchestrator.h"
#include "GenerationAccessor.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

namespace GameOfLife {

Orchestrator::Orchestrator(GenerationAccessor &rAccessor, LineRenderer &rRenderer, Pattern pattern):accessor(rAccessor), renderer(rRenderer) {
	Board board;
	Grid &rGrid = board.build(pattern);
	grid = &rGrid;
}

Orchestrator::~Orchestrator() {
	// TODO Auto-generated destructor stub
}

void Orchestrator::nextGeneration(){
	printBoard();
}

void Orchestrator::printBoard(){
	int size = (*grid).size();
	for(int i = 0; i < size; i++){
		char line[size+1];
		for(int j = 0; j < size; j++){
			bool val = (*grid)[i][j];
			line[j] = (val? '*' : ' ');
		}
		line[size] = '\0';
		renderer.Render(line);
	}
}

char Orchestrator::toChar(bool val){
	return val? 'x' : ' ';
};

} /* namespace GameOfLife */
