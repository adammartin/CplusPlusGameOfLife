#include "rules.h"
#include "LivingRules.h"
#include "DeadRules.h"
#include "Board.h"
#include "GenerationAccessor.h"
#include "boost/multi_array.hpp"
#include <iostream>

using namespace std;
using ::type_info;

namespace GameOfLife {
	Rules *LivingRules;
	Rules *DeadRules;

	GenerationAccessor::GenerationAccessor(Rules *livingRules, Rules *deadRules) {
		LivingRules = livingRules;
		DeadRules = deadRules;
	}

	GenerationAccessor::~GenerationAccessor() {
	}

	Grid GenerationAccessor::access(const Board &board){
		int size = board.size();
		Grid newBoard(boost::extents[size][size]);
		for(short x = 0; x < size; x++){
			for(short y = 0; y < size; y++){
				DeadRules->Apply(0);
			}
		}

		return newBoard;
	}

}
