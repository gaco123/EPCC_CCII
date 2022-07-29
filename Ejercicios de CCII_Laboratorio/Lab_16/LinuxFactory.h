#ifndef LINUXFACTORY_H
#define LINUXFACTORY_H
#include <string>
using namespace std;

class LinuxFactory{
public:
	virtual ~LinuxFactory() {};
	virtual string Draw() const = 0;
};

#endif

