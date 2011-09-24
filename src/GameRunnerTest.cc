#include "Orchestrator.h"
#include "MockLineRenderer.h"
#include "board/MockGenerationAccessor.h"
#include "GameRunner.h"
#include "board/Board.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<GameOfLife::MockGenerationAccessor> MockGenerationAccessorPtr;

using ::testing::Exactly;
using ::testing::Pointee;
using namespace GameOfLife;

namespace GameOfLife {

class StubOrchestrator : public Orchestrator {
 public:
  int count;
  StubOrchestrator(AccessorPtr accessorPtr, LineRenderer &rRenderer, Pattern pattern) : Orchestrator(accessorPtr, rRenderer, pattern){
	  count = 0;
  };
  void nextGeneration(){
	  count++;
  };
};

}  // namespace GameOfLife

typedef boost::shared_ptr<GameOfLife::StubOrchestrator> MockOrchestratorPtr;

TEST(GameRunner, WhenToldToRunOnceItWillRunOnce){
	MockGenerationAccessorPtr accessorPtr(new MockGenerationAccessor());
	MockLineRenderer renderer;
	MockOrchestratorPtr orchestratorPtr(new StubOrchestrator(accessorPtr, renderer, ACORN));
	GameRunner runner;
	int iterations = 1;

	runner.run(orchestratorPtr, iterations);

	EXPECT_EQ(orchestratorPtr->count, iterations);
}

TEST(GameRunner, WhenToldToRunTwiceItWillRunTwice){
	MockGenerationAccessorPtr accessorPtr(new MockGenerationAccessor());
	MockLineRenderer renderer;
	MockOrchestratorPtr orchestratorPtr(new StubOrchestrator(accessorPtr, renderer, ACORN));
	GameRunner runner;
	int iterations = 2;

	runner.run(orchestratorPtr, iterations);

	EXPECT_EQ(orchestratorPtr->count, iterations);
}

