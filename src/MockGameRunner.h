#ifndef MOCKGAMERUNNER_H_
#define MOCKGAMERUNNER_H_

#include "GameRunner.h"

namespace GameOfLife {

class MockGameRunner : public GameRunner {
 public:
  MOCK_CONST_METHOD2(run,
      void(const OrchestratorPtr orchestrator, const int generations));
};

}  // namespace GameOfLife

#endif // MOCKGAMERUNNER_H_
