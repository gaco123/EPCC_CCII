#ifndef WINCHECKBOX_H
#define WINCHECKBOX_H
#include "WinFactory.h"

class WinCheckBox : public WinFactory{
public:
	string Draw() const override{
		return "Drawing Windows CheckBox";
	}
};

#endif

