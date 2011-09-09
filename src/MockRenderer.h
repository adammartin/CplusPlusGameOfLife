#include "LineRenderer.h"
#include "gmock/gmock.h"

class MockLineRenderer : public LineRenderer {
 public:
  MOCK_METHOD1(Render,
      void(const string &line));
};


