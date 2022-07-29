#ifndef WINFACTORY_H
#define WINFACTORY_H
#include <string>
using namespace std;

class WinFactory{
public:
	virtual ~WinFactory() {};
	virtual string Draw() const = 0;
};

#endif

