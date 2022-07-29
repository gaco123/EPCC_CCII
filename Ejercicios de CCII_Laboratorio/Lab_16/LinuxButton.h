#ifndef LINUXBUTTON_H
#define LINUXBUTTON_H
#include "LinuxFactory.h"

class LinuxButton : public LinuxFactory{
public:
	string Draw() const override{
		return "Drawing Linux Button";
	}
};

#endif

