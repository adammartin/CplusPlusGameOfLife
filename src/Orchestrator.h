#ifndef ORCHESTRATOR_H_
#define ORCHESTRATOR_H_

#include "LineRenderer.h"
#include "GenerationAccessor.h"
#include "Board.h"

namespace GameOfLife {

class Orchestrator {
public:
	Orchestrator(GenerationAccessor &rAccessor, LineRenderer &rRenderer, Pattern pattern);
	virtual ~Orchestrator();
	void nextGeneration();
private:
	void printBoard();
	Grid* grid;
	GenerationAccessor &accessor;
	LineRenderer &renderer;
};

}
#endif /* ORCHESTRATOR_H_ */
