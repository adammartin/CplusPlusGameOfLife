#ifndef LINERENDERER_H_
#define LINERENDERER_H_

#include <string>
#include <curses.h>

class LineRenderer {
public:
	LineRenderer(){};
	virtual ~LineRenderer(){};
	virtual void clearScreen() const = 0;
	virtual void refreshScreen() const = 0;
	virtual void Render(const std::string &line) const = 0;
};

#endif /* LINERENDERER_H_ */
