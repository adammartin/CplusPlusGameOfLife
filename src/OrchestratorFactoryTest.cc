#include "MockLineRenderer.h"
#include "Orchestrator.h"
#include "OrchestratorFactory.h"
#include "board/RuleBasedGenerationAccessor.h"
#include "board/rules/LivingRules.h"
#include "board/rules/DeadRules.h"
#include "board/Board.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Exactly;
using ::testing::_;

using namespace GameOfLife;

TEST(OrchestratorFactory, CanConstructAnOrchestrator){

	string blankLine = "                                                                                                                        ";
	string blinkLine = "              ***                                                                                                       ";

	OrchestratorFactory factory;
	MockLineRenderer renderer;

	OrchestratorPtr orchestratorPtr = factory.create(renderer, BLINKER);

	EXPECT_CALL(renderer, clearScreen()).Times(Exactly(1));
	EXPECT_CALL(renderer, Render(_)).Times(Exactly(30));
	EXPECT_CALL(renderer, refreshScreen()).Times(Exactly(1));

	orchestratorPtr->nextGeneration();
}




