#ifndef GENERATIONACCESSOR_H_
#define GENERATIONACCESSOR_H_

#include "Board.h"
#include "boost/multi_array.hpp"

namespace GameOfLife {

	class GenerationAccessor {
	public:
		GenerationAccessor(){};
		virtual ~GenerationAccessor(){};
		virtual Grid& access(const Grid &grid){
			return *(new Grid);
		};
	};

} /* namespace GameOfLife */


#endif /* GENERATIONACCESSOR_H_ */
