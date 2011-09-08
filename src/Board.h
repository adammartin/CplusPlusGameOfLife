#ifndef BOARD_H_
#define BOARD_H_

#include "boost/multi_array.hpp"
#include <iostream>

using namespace std;

typedef boost::multi_array<bool, 2> Grid;

namespace GameOfLife {
	class Board {
	public:
		Board(const Grid &newBoard) {
			boardData = &newBoard;
		};
		Board(const Board &other) {
			boardData = new Grid(*other.boardData);
		};

		virtual ~Board(){};

		unsigned short getNeighbors(unsigned short x, unsigned short y){
			unsigned short count = 0;
			for(short xPos = validPosition(x-1); xPos <= validPosition(x+1); xPos++){
				for(short yPos = validPosition(y-1); yPos <= validPosition(y+1); yPos++){
					count += isAlive(xPos, yPos) && !(xPos == x && yPos == y)? 1 : 0;
				}
			}
			return count;
		};

		unsigned short size() const {
			return (*boardData).size();
		};
		bool operator==(const Board &other) const {
		    return (*boardData) == (*other.boardData);
		}
		bool operator!=(const Board &other) const {
		    return (*boardData) != (*other.boardData);
		}
	private:
		const Grid *boardData;
		short validPosition(const short index){
			short length = size();
			if(index < 0) {
				return 0;
			} else if (index > length){
				return length;
			}
			return index;
		};

		bool isAlive(unsigned short x, unsigned short y){
			return (*boardData)[x][y];
		}
	};
}
#endif /* BOARD_H_ */
