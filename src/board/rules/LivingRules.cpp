#include "LivingRules.h"

namespace GameOfLife {

	LivingRules::LivingRules() {
	}

	LivingRules::~LivingRules() {
	}

	bool LivingRules::Apply(const unsigned short neighbors) {
		return (neighbors >= 2 && neighbors < 4) ? true : false;
	}

}