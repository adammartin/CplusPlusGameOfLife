#ifndef GAMEINITIALIZER_H_
#define GAMEINITIALIZER_H_

#include <iostream>
#include <string>
#include <map>
#include "board/board.h"
#include "LineRenderer.h"
#include "TestRunner.h"

typedef std::map<std::string, Pattern> PatternMap;

namespace GameOfLife {


class GameInitializer {
public:
	GameInitializer(const LineRenderer &rRenderer, std::ostream &rOss, const TestRunner &rRunner);
	virtual ~GameInitializer();
	int execute(int argc, char* argv[]) const;
private:
	const LineRenderer &renderer;
	std::ostream &oss;
	const TestRunner &runner;
};

} /* namespace GameOfLife */
#endif /* GAMEINITIALIZER_H_ */
