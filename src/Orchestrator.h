#ifndef ORCHESTRATOR_H_
#define ORCHESTRATOR_H_

#include "LineRenderer.h"
#include "GenerationAccessor.h"
#include "Board.h"

namespace GameOfLife {

class Orchestrator {
public:
	Orchestrator(GenerationAccessor &accessor, LineRenderer &renderer, Pattern pattern);
	virtual ~Orchestrator();
};

}
#endif /* ORCHESTRATOR_H_ */
