#ifndef NCURSESLINERENDERER_H_
#define NCURSESLINERENDERER_H_

#include "LineRenderer.h"
#include <string>

namespace GameOfLife {

	class NCursesLineRenderer: public LineRenderer {
	public:
		NCursesLineRenderer();
		virtual ~NCursesLineRenderer();
		void clearScreen() const;
		void refreshScreen() const;
		void Render(const std::string &line) const;
	};

	} /* namespace GameOfLife */
#endif /* NCURSESLINERENDERER_H_ */
