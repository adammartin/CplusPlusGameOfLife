#include "GameRunner.h"

namespace GameOfLife {

GameRunner::GameRunner() {

}

GameRunner::~GameRunner() {
}

void GameRunner::run(const OrchestratorPtr orchestrator, const int generations) const{
	for(int i = 0; i < generations; i++){
		orchestrator->nextGeneration();
		usleep(100000);
	}
}

} /* namespace GameOfLife */
