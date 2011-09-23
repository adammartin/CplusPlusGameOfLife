#ifndef BOARD_H_
#define BOARD_H_

#include <boost/multi_array.hpp>
#include <boost/shared_ptr.hpp>

typedef boost::multi_array<bool, 2> Grid;
typedef boost::shared_ptr<Grid> GridPtr;

enum Pattern {BLINKER=1, TOAD=2, ACORN=3, LINE=4, GOSPER_GUN=5};

namespace GameOfLife {
	class Board {
	public:
		Board();
		explicit Board(const Grid &newBoard);
		virtual ~Board(){};
		const GridPtr build(Pattern pattern) const;
		unsigned short getNeighbors(unsigned short row, unsigned short column) const;
		bool operator==(const Board &other) const;
		bool operator!=(const Board &other) const;

	private:
		const Grid &boardData;
		short validRow(const short index) const;
		short validColumn(const short index) const;
		bool isAlive(unsigned short row, unsigned short column) const;
	};
}
#endif /* BOARD_H_ */
