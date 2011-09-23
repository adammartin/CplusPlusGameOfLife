#ifndef GENERATIONACCESSOR_H_
#define GENERATIONACCESSOR_H_

#include "Board.h"
#include <boost/multi_array.hpp>

namespace GameOfLife {

	class GenerationAccessor {
	public:
		GenerationAccessor(){};
		virtual ~GenerationAccessor(){};
		virtual GridPtr access(const Grid &grid) const = 0;
	};

} /* namespace GameOfLife */


#endif /* GENERATIONACCESSOR_H_ */
