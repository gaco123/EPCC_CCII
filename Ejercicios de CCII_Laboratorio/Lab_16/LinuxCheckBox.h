#ifndef LINUXCHECKBOX_H
#define LINUXCHECKBOX_H
#include "LinuxFactory.h"

class LinuxCheckBox : public LinuxFactory{
public:
	string Draw() const override{
		return "Drawing Linux CheckBox";
	}
};

#endif

