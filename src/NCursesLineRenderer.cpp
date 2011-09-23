#include <string>
#include <curses.h>
#include "NCursesLineRenderer.h"

namespace GameOfLife {

	NCursesLineRenderer::NCursesLineRenderer() {
		initscr();
	}

	NCursesLineRenderer::~NCursesLineRenderer() {
		endwin();
	}

	void NCursesLineRenderer::clearScreen() const {
		clear();
	};
	void NCursesLineRenderer::refreshScreen() const {
		refresh();
	};
	void NCursesLineRenderer::Render(const std::string &line) const {
		const char *charLine = (char*)line.c_str();
		printw(charLine);
		printw("\n");
	};
} /* namespace GameOfLife */
