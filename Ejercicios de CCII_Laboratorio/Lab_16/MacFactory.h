#ifndef MACFACTORY_H
#define MACFACTORY_H
#include "WinFactory.h"
#include <string>
using namespace std;

class MacFactory{
public:
	virtual ~MacFactory() {};
	virtual string Draw() const = 0;
	virtual string draw(const WinFactory& colaborator) const = 0; 
};

#endif

