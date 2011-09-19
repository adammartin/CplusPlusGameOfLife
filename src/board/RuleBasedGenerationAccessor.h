#ifndef RULEBASEDGENERATIONACCESSOR_H_
#define RULEBASEDGENERATIONACCESSOR_H_

#include "rules/Rules.h"
#include "GenerationAccessor.h"
#include "Board.h"
#include <boost/multi_array.hpp>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<GameOfLife::Rules> RulesPtr;

namespace GameOfLife {

	class RuleBasedGenerationAccessor : public GenerationAccessor {
	public:
		RuleBasedGenerationAccessor(RulesPtr livingRules, RulesPtr deadRules);
		virtual ~RuleBasedGenerationAccessor();
		virtual GridPtr access(const Grid &grid);
	private:
		RulesPtr LivingRules;
		RulesPtr DeadRules;
	};

} /* namespace GameOfLife */
#endif /* RULEBASEDGENERATIONACCESSOR_H_ */
