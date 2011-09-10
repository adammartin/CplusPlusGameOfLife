#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockLineRenderer.h"
#include "MockGenerationAccessor.h"
#include "GenerationAccessor.h"
#include "Orchestrator.h"
#include "Board.h"
#include <string>

using ::testing::Exactly;
using ::testing::Return;
using namespace GameOfLife;
using namespace std;

TEST(Orchestrator, CanRenderGenerationProperly){
	string blankLine = "                                        ";
	string blinkLine = "                   ***                  ";
	MockLineRenderer renderer;
	MockGenerationAccessor accessor;
	Orchestrator orchestrator(accessor, renderer, BLINKER);

	EXPECT_CALL(renderer, Render(blankLine)).Times(Exactly(39));
	EXPECT_CALL(renderer, Render(blinkLine)).Times(Exactly(1));

	orchestrator.nextGeneration();
}



