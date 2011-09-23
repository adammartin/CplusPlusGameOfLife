#ifndef LIVINGRULES_H_
#define LIVINGRULES_H_

#include "Rules.h"

namespace GameOfLife {

	class LivingRules: public Rules {
	public:
		LivingRules();
		virtual ~LivingRules();
		const bool Apply(const unsigned short neighbors) const;
	};

}
#endif /* LIVINGRULES_H_ */
