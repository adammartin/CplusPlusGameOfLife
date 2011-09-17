#include "Board.h"
#include "Orchestrator.h"
#include "GenerationAccessor.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

namespace GameOfLife {

char toChar(bool val){
	return val? '*' : ' ';
};

Orchestrator::Orchestrator(GenerationAccessor &rAccessor, LineRenderer &rRenderer, Pattern pattern):accessor(rAccessor), renderer(rRenderer) {
	Board board;
	grid = board.build(pattern);
}

Orchestrator::~Orchestrator() {
}

void Orchestrator::nextGeneration(){
	printBoard();
	Grid &newGrid = accessor.access(*grid.get());
	grid = GridPtr(&newGrid);
}

void Orchestrator::printBoard(){
	renderer.clearScreen();
	for (Grid::iterator i = grid->begin(); i != grid->end(); i++) {
		string line;
		transform(i->begin(), i->end(), back_inserter(line), toChar);
		renderer.Render(line);
	}
	renderer.refreshScreen();
}

} /* namespace GameOfLife */
