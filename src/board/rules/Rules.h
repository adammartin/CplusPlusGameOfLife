#ifndef RULES_H_
#define RULES_H_

namespace GameOfLife {
	class Rules {
	public:
		Rules(){};
		virtual ~Rules(){};
		virtual const bool Apply(const unsigned short neighbors) const { return false; };
	};
}
#endif /* RULES_H_ */
