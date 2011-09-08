#include "rules.h"
#include "Board.h"
#include "GenerationAccessor.h"
#include "boost/multi_array.hpp"
#include <iostream>

using namespace std;
using ::type_info;

namespace GameOfLife {
	GenerationAccessor::GenerationAccessor(Rules &livingRules, Rules &deadRules) :LivingRules(livingRules), DeadRules(deadRules) {
	}

	GenerationAccessor::~GenerationAccessor() {
	}

	Grid& GenerationAccessor::access(const Grid &grid){
		int size = grid.size();
		Board oldBoard(grid);
		Grid *newGrid = new Grid(boost::extents[size][size]);
		for(short x = 0; x < size; x++){
			for(short y = 0; y < size; y++){
				unsigned short neighbors = oldBoard.getNeighbors(x, y);
				(*newGrid)[x][y] = grid[x][y] ? LivingRules.Apply(neighbors) : DeadRules.Apply(neighbors);
			}
		}

		return *newGrid;
	}

}
