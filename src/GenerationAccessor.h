#ifndef GENERATIONACCESSOR_H_
#define GENERATIONACCESSOR_H_

#include "rules.h"
#include "boost/multi_array.hpp"

typedef boost::multi_array<bool, 2> array_type;
// TODO: typedef array_type::index array_index;


namespace GameOfLife {

	class GenerationAccessor {
	public:
		GenerationAccessor(Rules *livingRules, Rules *deadRules);
		virtual ~GenerationAccessor();
		array_type access(const array_type &board);
	private:
		Rules *LivingRules;
		Rules *DeadRules;
	};

} /* namespace GameOfLife */
#endif /* GENERATIONACCESSOR_H_ */
