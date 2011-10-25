#include "DeadRules.h"

namespace GameOfLife {

	DeadRules::DeadRules() {
	}

	DeadRules::~DeadRules() {
	}

	const bool DeadRules::Apply(const unsigned short neighbors) const {
		return (neighbors == 3);
	}

}
