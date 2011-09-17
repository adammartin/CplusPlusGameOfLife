#include <boost/multi_array.hpp>
#include <boost/shared_ptr.hpp>
#include "Board.h"

using namespace std;
using namespace boost;

namespace GameOfLife {
	short Board::validPosition(const short index){
		short length = boardData.size();
		if(index < 0) {
			return 0;
		} else if (index >= length){
			return length-1;
		}
		return index;
	};

	bool Board::isAlive(unsigned short row, unsigned short column){
		return boardData[row][column];
	}

	Board::Board() :boardData(Grid(boost::extents[1][1])){
	}

	Board::Board(const Grid &newBoard):boardData(newBoard) {
	};

	GridPtr Board::build(Pattern pattern) {
		GridPtr newGrid(new Grid(boost::extents[30][30]));
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
			(*newGrid)[13][11] = true;
			(*newGrid)[14][13] = true;
			(*newGrid)[15][10] = true;
			(*newGrid)[15][11] = true;
			(*newGrid)[15][14] = true;
			(*newGrid)[15][15] = true;
			(*newGrid)[15][16] = true;
			break;
		default:
			break;
		}
		return newGrid;
	}

	unsigned short Board::getNeighbors(unsigned short row, unsigned short column){
		unsigned short count = 0;
		for(short rowPos = validPosition(row-1); rowPos <= validPosition(row+1); rowPos++){
			for(short columnPos = validPosition(column-1); columnPos <= validPosition(column+1); columnPos++){
				count += isAlive(rowPos, columnPos) && !(rowPos == row && columnPos == column)? 1 : 0;
			}
		}
		return count;
	};

	unsigned short Board::size() const {
		return boardData.size();
	};
	bool Board::operator==(const Board &other) const {
		return boardData == other.boardData;
	}
	bool Board::operator!=(const Board &other) const {
		return boardData != other.boardData;
	}

}

