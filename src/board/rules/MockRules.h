#include "Rules.h"
#include <gmock/gmock.h>

namespace GameOfLife {

class MockRules : public Rules {
 public:
  MOCK_CONST_METHOD1(Apply,
      bool(const unsigned short neighbors));
};

}  // namespace GameOfLife


