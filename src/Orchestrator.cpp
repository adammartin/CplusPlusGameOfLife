#include "board/Board.h"
#include "Orchestrator.h"
#include "board/GenerationAccessor.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

namespace GameOfLife {

	char toChar(bool val){
		return val? '*' : ' ';
	};

	Orchestrator::Orchestrator(AccessorPtr accessor, LineRenderer &rRenderer, Pattern pattern):accessorPtr(accessor), renderer(rRenderer) {
		Board board;
		grid = board.build(pattern);
	}

	Orchestrator::~Orchestrator() {
	}

	void Orchestrator::nextGeneration(){
		printBoard();
		grid = (*accessorPtr).access(*grid.get());
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
