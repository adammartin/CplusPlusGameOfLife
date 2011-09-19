#include "rules/Rules.h"
#include "Board.h"
#include "RuleBasedGenerationAccessor.h"
#include <boost/multi_array.hpp>

using namespace std;
using ::type_info;

namespace GameOfLife {
	RuleBasedGenerationAccessor::RuleBasedGenerationAccessor(RulesPtr livingRules, RulesPtr deadRules) :LivingRules(livingRules), DeadRules(deadRules) {
	}

	RuleBasedGenerationAccessor::~RuleBasedGenerationAccessor() {
	}

	GridPtr RuleBasedGenerationAccessor::access(const Grid &grid){
		const Grid::size_type *shape = grid.shape();
		Board oldBoard(grid);
		GridPtr newGrid(new Grid(boost::extents[shape[0]][shape[1]]));
		for(unsigned short row = 0; row < shape[0]; row++){
			for(unsigned short column = 0; column < shape[1]; column++){
				unsigned short neighbors = oldBoard.getNeighbors(row, column);
				(*newGrid)[row][column] = grid[row][column] ? LivingRules->Apply(neighbors) : DeadRules->Apply(neighbors);
			}
		}

		return newGrid;
	}

}
