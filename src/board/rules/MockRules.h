#ifndef MOCKRULES_H_
#define MOCKRULES_H_

#include "Rules.h"
#include <gmock/gmock.h>

namespace GameOfLife {

	class MockRules : public Rules {
	 public:
	  MOCK_CONST_METHOD1(Apply,
		  bool(const unsigned short neighbors));
	};

}  // namespace GameOfLife

#endif // MOCKRULES_H_
