#include <iostream>
#include <string>
#include <map>
#include "board/board.h"
#include "LineRenderer.h"
#include "TestRunner.h"

#ifndef GAMEINITIALIZER_H_
#define GAMEINITIALIZER_H_

typedef std::map<std::string, Pattern> PatternMap;

namespace GameOfLife {


class GameInitializer {
public:
	GameInitializer(LineRenderer &rRenderer, std::ostream &rOss, TestRunner &rRunner);
	virtual ~GameInitializer();
	int execute(int argc, char* argv[]) const;
private:
	LineRenderer &renderer;
	std::ostream &oss;
	TestRunner &runner;
};

} /* namespace GameOfLife */
#endif /* GAMEINITIALIZER_H_ */
