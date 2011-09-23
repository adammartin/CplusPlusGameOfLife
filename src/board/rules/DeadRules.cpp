#include "DeadRules.h"

namespace GameOfLife {

	DeadRules::DeadRules() {
	}

	DeadRules::~DeadRules() {
	}

	bool DeadRules::Apply(const unsigned short neighbors) const {
		return (neighbors == 3) ? true : false;
	}

}
