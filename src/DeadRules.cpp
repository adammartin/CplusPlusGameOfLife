#include "DeadRules.h"

DeadRules::DeadRules() {
}

DeadRules::~DeadRules() {
}

bool DeadRules::Apply(const unsigned short neighbors) {
	return (neighbors == 3) ? true : false;
}
