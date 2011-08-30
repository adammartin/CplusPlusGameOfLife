#include "gmock/gmock.h"
#include "rules.h"

class MockRules : public Rules {
 public:
	MOCK_METHOD1(Apply, bool(const unsigned short neighbors));
};
