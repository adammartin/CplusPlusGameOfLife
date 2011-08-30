#include "DeadRules.h"

DeadRules::DeadRules() {
	// TODO Auto-generated constructor stub

}

DeadRules::~DeadRules() {
	// TODO Auto-generated destructor stub
}

bool DeadRules::Apply(const unsigned short neighbors) {
	return (neighbors == 3) ? true : false;
}
