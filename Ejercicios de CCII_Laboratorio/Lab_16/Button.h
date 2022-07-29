#ifndef BUTTON_H
#define BUTTON_H
#include "GUIFactory.h"
#include "WinButton.h"
#include "MacButton.h"
#include "LinuxButton.h"

class Button : public GUIFactory{
public:
	~Button(){};
	WinFactory* CreateControlWin() const override{
		return new WinButton();
	}
	MacFactory* CreateControlMac() const override{
		return new MacButton();
	}
	LinuxFactory* CreateControlLinux() const override{
		return new LinuxButton();
	}
};

#endif

