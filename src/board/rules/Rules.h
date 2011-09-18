#ifndef RULES_H_
#define RULES_H_

namespace GameOfLife {
	class Rules {
	public:
		Rules(){};
		virtual ~Rules(){}
		virtual bool Apply(const unsigned short neighbors);
	};
}
#endif /* RULES_H_ */
