#ifndef LINERENDERER_H_
#define LINERENDERER_H_

#include <string>
#include <iostream.h>

using namespace std;

class LineRenderer {
public:
	LineRenderer(){};
	LineRenderer(ostream &otherstream) :stream(otherstream){};
	virtual ~LineRenderer(){}
	virtual void Render(const string &line){
		stream << line << endl;
	};
private:
	ostream &stream;
};

#endif /* LINERENDERER_H_ */
