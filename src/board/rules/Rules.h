#ifndef RULES_H_
#define RULES_H_

namespace GameOfLife {
	class Rules {
	public:
		Rules(){};
		virtual ~Rules(){};
		virtual const bool Apply(const unsigned short neighbors) const = 0;
	};
}
#endif /* RULES_H_ */
