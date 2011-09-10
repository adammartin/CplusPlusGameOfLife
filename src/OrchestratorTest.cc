#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockLineRenderer.h"
#include "MockGenerationAccessor.h"
#include "GenerationAccessor.h"
#include "Orchestrator.h"
#include "Board.h"
#include <string>

using ::testing::Exactly;
using ::testing::ReturnRef;
using namespace GameOfLife;
using namespace std;

TEST(Orchestrator, CanRenderGenerationProperly){
	Board board;
	string blankLine = "                                        ";
	string blinkLine = "                   ***                  ";
	Grid resultGrid(boost::extents[40][40]);
	resultGrid[19][20] = true;
	resultGrid[20][20] = true;
	resultGrid[21][20] = true;

	MockLineRenderer renderer;
	MockGenerationAccessor accessor;
	Orchestrator orchestrator(accessor, renderer, BLINKER);

	EXPECT_CALL(renderer, Render(blankLine)).Times(Exactly(39));
	EXPECT_CALL(renderer, Render(blinkLine)).Times(Exactly(1));
	EXPECT_CALL(accessor, access(board.build(BLINKER))).Times(Exactly(1)).WillRepeatedly(ReturnRef(resultGrid));

	orchestrator.nextGeneration();
}



