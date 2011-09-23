#ifndef MOCKLINERENDERER_H_
#define MOCKLINERENDERER_H_

#include "LineRenderer.h"
#include <gmock/gmock.h>
#include <string>

using namespace std;

class MockLineRenderer : public LineRenderer {
 public:
  MOCK_CONST_METHOD0(clearScreen,
      void());
  MOCK_CONST_METHOD0(refreshScreen,
      void());
  MOCK_CONST_METHOD1(Render,
      void(const std::string &line));
};

#endif /* MOCKLINERENDERER */
