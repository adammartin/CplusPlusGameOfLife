#ifndef NCURSESLINERENDERER_H_
#define NCURSESLINERENDERER_H_

#include "LineRenderer.h"
#include <string>

namespace GameOfLife {

class NCursesLineRenderer: public LineRenderer {
public:
	NCursesLineRenderer();
	virtual ~NCursesLineRenderer();
	void clearScreen();
	void refreshScreen();
	void Render(const std::string &line);
};

} /* namespace GameOfLife */
#endif /* NCURSESLINERENDERER_H_ */
