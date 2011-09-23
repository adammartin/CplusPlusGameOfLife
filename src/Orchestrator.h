#ifndef ORCHESTRATOR_H_
#define ORCHESTRATOR_H_

#include "LineRenderer.h"
#include "board/GenerationAccessor.h"
#include "board/Board.h"
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<GameOfLife::GenerationAccessor> AccessorPtr;

namespace GameOfLife {

	class Orchestrator {
	public:
		Orchestrator(AccessorPtr accessor, const LineRenderer &rRenderer, const Pattern pattern);
		virtual ~Orchestrator();
		void nextGeneration();
	private:
		void printBoard() const;
		GridPtr grid;
		AccessorPtr accessorPtr;
		const LineRenderer &renderer;
	};

}
#endif /* ORCHESTRATOR_H_ */
