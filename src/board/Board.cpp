#include <boost/multi_array.hpp>
#include <boost/shared_ptr.hpp>
#include "Board.h"

using namespace std;
using namespace boost;

namespace GameOfLife {
	short Board::validRow(const short index) const {
		short length = boardData.shape()[0];
		if(index < 0) {
			return 0;
		} else if (index >= length){
			return length-1;
		}
		return index;
	};
	short Board::validColumn(const short index) const {
		short length = boardData.shape()[1];
		if(index < 0) {
			return 0;
		} else if (index >= length){
			return length-1;
		}
		return index;
	};

	bool Board::isAlive(unsigned short row, unsigned short column) const {
		return boardData[row][column];
	}

	Board::Board() :boardData(Grid(boost::extents[1][1])){
	}

	Board::Board(const Grid &newBoard):boardData(newBoard) {
	};

	const GridPtr Board::build(Pattern pattern) const {
		GridPtr newGrid(new Grid(boost::extents[30][120]));
		switch(pattern){
		case BLINKER:
			(*newGrid)[15][14] = true;
			(*newGrid)[15][15] = true;
			(*newGrid)[15][16] = true;
			break;
		case TOAD:
			(*newGrid)[15][14] = true;
			(*newGrid)[15][15] = true;
			(*newGrid)[15][16] = true;
			(*newGrid)[16][13] = true;
			(*newGrid)[16][14] = true;
			(*newGrid)[16][15] = true;
			break;
		case ACORN:
			(*newGrid)[13][26] = true;
			(*newGrid)[14][28] = true;
			(*newGrid)[15][25] = true;
			(*newGrid)[15][26] = true;
			(*newGrid)[15][29] = true;
			(*newGrid)[15][30] = true;
			(*newGrid)[15][31] = true;
			break;
		case LINE:
			(*newGrid)[14][41] = true;
			(*newGrid)[14][42] = true;
			(*newGrid)[14][43] = true;
			(*newGrid)[14][44] = true;
			(*newGrid)[14][45] = true;
			(*newGrid)[14][46] = true;
			(*newGrid)[14][47] = true;
			(*newGrid)[14][48] = true;
			(*newGrid)[14][50] = true;
			(*newGrid)[14][51] = true;
			(*newGrid)[14][52] = true;
			(*newGrid)[14][53] = true;
			(*newGrid)[14][54] = true;
			(*newGrid)[14][58] = true;
			(*newGrid)[14][59] = true;
			(*newGrid)[14][60] = true;
			(*newGrid)[14][67] = true;
			(*newGrid)[14][68] = true;
			(*newGrid)[14][69] = true;
			(*newGrid)[14][70] = true;
			(*newGrid)[14][71] = true;
			(*newGrid)[14][72] = true;
			(*newGrid)[14][73] = true;
			(*newGrid)[14][75] = true;
			(*newGrid)[14][76] = true;
			(*newGrid)[14][77] = true;
			(*newGrid)[14][78] = true;
			(*newGrid)[14][79] = true;
			break;
		case GOSPER_GUN:
			(*newGrid)[6][2] = true;
			(*newGrid)[6][3] = true;
			(*newGrid)[7][2] = true;
			(*newGrid)[7][3] = true;
			(*newGrid)[6][12] = true;
			(*newGrid)[7][12] = true;
			(*newGrid)[8][12] = true;
			(*newGrid)[5][13] = true;
			(*newGrid)[9][13] = true;
			(*newGrid)[4][14] = true;
			(*newGrid)[4][15] = true;
			(*newGrid)[10][14] = true;
			(*newGrid)[10][15] = true;
			(*newGrid)[7][16] = true;
			(*newGrid)[5][17] = true;
			(*newGrid)[9][17] = true;
			(*newGrid)[6][18] = true;
			(*newGrid)[7][18] = true;
			(*newGrid)[8][18] = true;
			(*newGrid)[7][19] = true;
			(*newGrid)[4][22] = true;
			(*newGrid)[5][22] = true;
			(*newGrid)[6][22] = true;
			(*newGrid)[4][23] = true;
			(*newGrid)[5][23] = true;
			(*newGrid)[6][23] = true;
			(*newGrid)[3][24] = true;
			(*newGrid)[7][24] = true;
			(*newGrid)[2][26] = true;
			(*newGrid)[3][26] = true;
			(*newGrid)[7][26] = true;
			(*newGrid)[8][26] = true;
			(*newGrid)[4][36] = true;
			(*newGrid)[5][36] = true;
			(*newGrid)[4][37] = true;
			(*newGrid)[5][37] = true;
			break;
		default:
			break;
		}
		return newGrid;
	}

	unsigned short Board::getNeighbors(unsigned short row, unsigned short column) const {
		unsigned short count = 0;
		for(short rowPos = validRow(row-1); rowPos <= validRow(row+1); rowPos++){
			for(short columnPos = validColumn(column-1); columnPos <= validColumn(column+1); columnPos++){
				count += isAlive(rowPos, columnPos) && !(rowPos == row && columnPos == column)? 1 : 0;
			}
		}
		return count;
	};

	bool Board::operator==(const Board &other) const {
		return boardData == other.boardData;
	}
	bool Board::operator!=(const Board &other) const {
		return boardData != other.boardData;
	}

}

