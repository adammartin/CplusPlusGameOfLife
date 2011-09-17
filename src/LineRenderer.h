#ifndef LINERENDERER_H_
#define LINERENDERER_H_

#include <string>
#include <curses.h>

using namespace std;

class LineRenderer {
public:
	LineRenderer(){};
	virtual ~LineRenderer(){};
	virtual void clearScreen(){};
	virtual void refreshScreen(){};
	virtual void Render(const string &line){};
};

#endif /* LINERENDERER_H_ */
