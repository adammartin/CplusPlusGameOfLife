#ifndef GAMERUNNER_H_
#define GAMERUNNER_H_

#include "Orchestrator.h"

typedef boost::shared_ptr<GameOfLife::Orchestrator> OrchestratorPtr;

namespace GameOfLife {

class GameRunner {
public:
	GameRunner();
	virtual ~GameRunner();
	virtual void run(const OrchestratorPtr orchestrator, const int generations) const;
};

} /* namespace GameOfLife */
#endif /* GAMERUNNER_H_ */
