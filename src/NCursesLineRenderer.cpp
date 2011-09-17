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

void NCursesLineRenderer::clearScreen(){
	clear();
};
void NCursesLineRenderer::refreshScreen(){
	refresh();
};
void NCursesLineRenderer::Render(const string &line){
	const char *charLine = (char*)line.c_str();
	printw(charLine);
	printw("\n");
};
} /* namespace GameOfLife */
