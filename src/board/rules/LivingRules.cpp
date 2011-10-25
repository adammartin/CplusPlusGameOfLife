#include "LivingRules.h"

namespace GameOfLife {

	LivingRules::LivingRules() {
	}

	LivingRules::~LivingRules() {
	}

	const bool LivingRules::Apply(const unsigned short neighbors) const {
		return (neighbors >= 2 && neighbors < 4);
	}

}
