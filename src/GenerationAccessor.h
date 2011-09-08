#ifndef GENERATIONACCESSOR_H_
#define GENERATIONACCESSOR_H_

#include "rules.h"
#include "Board.h"
#include "boost/multi_array.hpp"

namespace GameOfLife {

	class GenerationAccessor {
	public:
		GenerationAccessor(Rules *livingRules, Rules *deadRules);
		virtual ~GenerationAccessor();
		Grid access(const Grid &grid);
	private:
		Rules *LivingRules;
		Rules *DeadRules;
	};

} /* namespace GameOfLife */
#endif /* GENERATIONACCESSOR_H_ */
