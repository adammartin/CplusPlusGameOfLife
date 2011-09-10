#include "Board.h"
#include "Orchestrator.h"
#include "GenerationAccessor.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

namespace GameOfLife {

char toChar(bool val){
	return val? '*' : ' ';
};

Orchestrator::Orchestrator(GenerationAccessor &rAccessor, LineRenderer &rRenderer, Pattern pattern):accessor(rAccessor), renderer(rRenderer) {
	Board board;
	Grid &rGrid = board.build(pattern);
	grid = &rGrid;
}

Orchestrator::~Orchestrator() {
}

void Orchestrator::nextGeneration(){
	printBoard();
	grid = &accessor.access(*grid);
}

void Orchestrator::printBoard(){
	for (Grid::iterator i = grid->begin(); i != grid->end(); i++) {
		string line;
		transform(i->begin(), i->end(), back_inserter(line), toChar);
		renderer.Render(line);
	}
}

} /* namespace GameOfLife */
