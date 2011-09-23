#ifndef ORCHESTRATORFACTORY_H_
#define ORCHESTRATORFACTORY_H_

#include "Orchestrator.h"

typedef boost::shared_ptr<GameOfLife::Orchestrator> OrchestratorPtr;

namespace GameOfLife {

class OrchestratorFactory {
	public:
		OrchestratorFactory();
		virtual ~OrchestratorFactory();
		OrchestratorPtr create(const LineRenderer &renderer, const Pattern pattern) const;
	};

} /* namespace GameOfLife */
#endif /* ORCHESTRATORFACTORY_H_ */
