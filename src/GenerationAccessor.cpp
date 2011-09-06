#include "rules.h"
#include "GenerationAccessor.h"
#include "boost/multi_array.hpp"
#include <iostream>

using namespace std;
using ::type_info;

namespace GameOfLife {
	Rules LivingRules;
	Rules DeadRules;

	GenerationAccessor::GenerationAccessor(const Rules &livingRules, const Rules &deadRules) {
		LivingRules = livingRules;
		DeadRules = deadRules;
	}

	GenerationAccessor::~GenerationAccessor() {
	}

	array_type GenerationAccessor::access(const array_type &board){
		array_type newBoard(boost::extents[board.size()][board.size()]);
		for(unsigned int x = 0; x < board.size(); x++){
			for(unsigned int y = 0; y < board.size(); y++){
				newBoard[x][y] = DeadRules.Apply(0);
			}
		}
		return newBoard;
	}

}
