#ifndef CHECKBOX_H
#define CHECKBOX_H
#include "GUIFactory.h"
#include "WinCheckBox.h"
#include "MacCheckBox.h"
#include "LinuxCheckBox.h"

class CheckBox : public GUIFactory{
public:
	~CheckBox(){};
	WinFactory* CreateControlWin() const override{
		return new WinCheckBox();
	}
	MacFactory* CreateControlMac() const override{
		return new MacCheckBox();
	}
	LinuxFactory* CreateControlLinux() const override{
		return new LinuxCheckBox();
	}
};

#endif

