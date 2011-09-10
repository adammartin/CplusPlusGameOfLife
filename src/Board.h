#ifndef BOARD_H_
#define BOARD_H_

#include "boost/multi_array.hpp"
#include <iostream>

using namespace std;

typedef boost::multi_array<bool, 2> Grid;

enum Pattern {BLINKER, TOAD, ACORN};

namespace GameOfLife {
	class Board {
	public:
		Board() :boardData(Grid(boost::extents[1][1])){
		}

		explicit Board(const Grid &newBoard):boardData(newBoard) {
		};

		virtual ~Board(){};

		Grid &build(Pattern pattern) {
			Grid *newGrid = new Grid(boost::extents[40][40]);
			switch(pattern){
			case BLINKER:
				(*newGrid)[20][19] = true;
				(*newGrid)[20][20] = true;
				(*newGrid)[20][21] = true;
				break;
			case TOAD:
				(*newGrid)[20][19] = true;
				(*newGrid)[20][20] = true;
				(*newGrid)[20][21] = true;
				(*newGrid)[21][18] = true;
				(*newGrid)[21][19] = true;
				(*newGrid)[21][20] = true;
				break;
			case ACORN:
				(*newGrid)[18][16] = true;
				(*newGrid)[19][18] = true;
				(*newGrid)[20][15] = true;
				(*newGrid)[20][16] = true;
				(*newGrid)[20][19] = true;
				(*newGrid)[20][20] = true;
				(*newGrid)[20][21] = true;
				break;
			default:
				break;
			}
			return *newGrid;
		}

		unsigned short getNeighbors(unsigned short row, unsigned short column){
			unsigned short count = 0;
			for(short rowPos = validPosition(row-1); rowPos <= validPosition(row+1); rowPos++){
				for(short columnPos = validPosition(column-1); columnPos <= validPosition(column+1); columnPos++){
					count += isAlive(rowPos, columnPos) && !(rowPos == row && columnPos == column)? 1 : 0;
				}
			}
			return count;
		};

		unsigned short size() const {
			return boardData.size();
		};
		bool operator==(const Board &other) const {
		    return boardData == other.boardData;
		}
		bool operator!=(const Board &other) const {
		    return boardData != other.boardData;
		}
	private:
		const Grid &boardData;
		short validPosition(const short index){
			short length = size();
			if(index < 0) {
				return 0;
			} else if (index >= length){
				return length-1;
			}
			return index;
		};

		bool isAlive(unsigned short row, unsigned short column){
			return boardData[row][column];
		}
	};
}
#endif /* BOARD_H_ */
