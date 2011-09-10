#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockLineRenderer.h"
#include "MockGenerationAccessor.h"
#include "GenerationAccessor.h"
#include "Orchestrator.h"
#include "Board.h"

using ::testing::Exactly;
using ::testing::Return;
using namespace GameOfLife;

TEST(Orchestrator, CanRenderGenerationProperly){
	MockLineRenderer renderer;
	MockGenerationAccessor accessor;
	Orchestrator orchestrator(accessor, renderer, BLINKER);
}



