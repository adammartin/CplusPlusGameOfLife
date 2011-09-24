#ifndef GAMEINITIALIZER_H_
#define GAMEINITIALIZER_H_

#include "board/board.h"
#include "GameRunner.h"
#include <map>
#include <string>

typedef std::map<std::string, Pattern> PatternMap;
typedef PatternMap::iterator PatternMapIterator;

namespace GameOfLife {


class GameInitializer {
public:
	GameInitializer(const GameRunner &rGameRunner);
	virtual ~GameInitializer();
	const std::string execute(int argc, char* argv[]) const;
private:
	const std::string runGame(const Pattern pattern, const int generations) const;
	const GameRunner &gameRunner;
};

} /* namespace GameOfLife */
#endif /* GAMEINITIALIZER_H_ */
