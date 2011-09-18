#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockLineRenderer.h"
#include "board/MockGenerationAccessor.h"
#include "board/GenerationAccessor.h"
#include "Orchestrator.h"
#include "board/Board.h"
#include <string>

using ::testing::Exactly;
using ::testing::Return;
using namespace GameOfLife;
using namespace std;

TEST(Orchestrator, CanRenderGenerationProperly){

	Board board;
	string blankLine = "                                                                                                                        ";
	string blinkLine = "              ***                                                                                                       ";
	GridPtr resultGrid(new Grid(boost::extents[30][60]));
	(*resultGrid)[14][15] = true;
	(*resultGrid)[15][15] = true;
	(*resultGrid)[16][15] = true;

	MockLineRenderer renderer;
	MockGenerationAccessor accessor;
	Orchestrator orchestrator(accessor, renderer, BLINKER);
	GridPtr gPointer = board.build(BLINKER);
	Grid &blinker = *(gPointer.get());

	EXPECT_CALL(renderer, clearScreen()).Times(Exactly(1));
	EXPECT_CALL(renderer, Render(blankLine)).Times(Exactly(29));
	EXPECT_CALL(renderer, Render(blinkLine)).Times(Exactly(1));
	EXPECT_CALL(accessor, access(blinker)).Times(Exactly(1)).WillRepeatedly(Return(resultGrid));
	EXPECT_CALL(renderer, refreshScreen()).Times(Exactly(1));

	orchestrator.nextGeneration();
}



