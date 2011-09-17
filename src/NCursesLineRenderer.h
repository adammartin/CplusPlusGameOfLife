#ifndef NCURSESLINERENDERER_H_
#define NCURSESLINERENDERER_H_

#include "LineRenderer.h"

namespace GameOfLife {

class NCursesLineRenderer: public LineRenderer {
public:
	NCursesLineRenderer();
	virtual ~NCursesLineRenderer();
	void clearScreen();
	void refreshScreen();
	void Render(const string &line);
};

} /* namespace GameOfLife */
#endif /* NCURSESLINERENDERER_H_ */
