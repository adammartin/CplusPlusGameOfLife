/*
 * rules.h
 *
 *  Created on: Aug 24, 2011
 *      Author: adammartin
 */

#ifndef RULES_H_
#define RULES_H_

class Rules {
public:
	Rules();
	virtual ~Rules();
	virtual bool Apply(const unsigned short neighbors);
};

#endif /* RULES_H_ */
