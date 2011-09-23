#ifndef DEADRULES_H_
#define DEADRULES_H_

#include "Rules.h"

namespace GameOfLife {

	class DeadRules: public Rules {
	public:
		DeadRules();
		virtual ~DeadRules();
		bool Apply(const unsigned short neighbors) const;
	};

}
#endif /* DEADRULES_H_ */
