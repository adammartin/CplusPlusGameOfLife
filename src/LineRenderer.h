#ifndef LINERENDERER_H_
#define LINERENDERER_H_

#include <string>
#include <curses.h>

using namespace std;

class LineRenderer {
public:
	LineRenderer(){
		initscr();
	};
	virtual ~LineRenderer(){
		endwin();
	};
	virtual void clearScreen(){
		clear();
	};
	virtual void refreshScreen(){
		refresh();
	};
	virtual void Render(const string &line){
		const char *charLine = (char*)line.c_str();
		printw(charLine);
		printw("\n");
	};
};

#endif /* LINERENDERER_H_ */
