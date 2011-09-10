#ifndef RULEBASEDGENERATIONACCESSOR_H_
#define RULEBASEDGENERATIONACCESSOR_H_

#include "rules.h"
#include "GenerationAccessor.h"
#include "Board.h"
#include "boost/multi_array.hpp"

namespace GameOfLife {

	class RuleBasedGenerationAccessor : public GenerationAccessor {
	public:
		RuleBasedGenerationAccessor(Rules &livingRules, Rules &deadRules);
		virtual ~RuleBasedGenerationAccessor();
		virtual Grid& access(const Grid &grid);
	private:
		Rules &LivingRules;
		Rules &DeadRules;
	};

} /* namespace GameOfLife */
#endif /* RULEBASEDGENERATIONACCESSOR_H_ */
