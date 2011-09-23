#include "OrchestratorFactory.h"
#include "Orchestrator.h"
#include "board/RuleBasedGenerationAccessor.h"
#include "board/rules/LivingRules.h"
#include "board/rules/DeadRules.h"

using namespace GameOfLife;

namespace GameOfLife {

	OrchestratorFactory::OrchestratorFactory() {

	}

	OrchestratorFactory::~OrchestratorFactory() {
	}

	const OrchestratorPtr OrchestratorFactory::create(const LineRenderer &renderer, const Pattern pattern) const{
		RulesPtr livingRules(new LivingRules());
		RulesPtr deadRules(new DeadRules());
		AccessorPtr accessor(new RuleBasedGenerationAccessor(livingRules, deadRules));
		OrchestratorPtr orchestratorPtr(new Orchestrator(accessor, renderer, pattern));

		return orchestratorPtr;
	}

} /* namespace GameOfLife */
