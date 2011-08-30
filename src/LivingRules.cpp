/*
 * LivingRules.cpp
 *
 *  Created on: Aug 27, 2011
 *      Author: adammartin
 */

#include "LivingRules.h"

LivingRules::LivingRules() {
	// TODO Auto-generated constructor stub

}

LivingRules::~LivingRules() {
	// TODO Auto-generated destructor stub
}

bool LivingRules::Apply(const unsigned short neighbors) {
	return (neighbors >= 2 && neighbors < 4) ? true : false;
}
