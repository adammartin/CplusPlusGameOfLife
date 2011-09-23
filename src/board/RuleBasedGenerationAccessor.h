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
		RuleBasedGenerationAccessor(const RulesPtr livingRules, const RulesPtr deadRules);
		virtual ~RuleBasedGenerationAccessor();
		const GridPtr access(const Grid &grid) const;
	private:
		const RulesPtr LivingRules;
		const RulesPtr DeadRules;
	};

} /* namespace GameOfLife */
#endif /* RULEBASEDGENERATIONACCESSOR_H_ */
