#ifndef GUIFACTORY_H
#define GUIFACTORY_H
#include "WinFactory.h"
#include "MacFactory.h"
#include "LinuxFactory.h"

class GUIFactory{
public:
	virtual WinFactory* CreateControlWin() const = 0;
	virtual MacFactory* CreateControlMac() const = 0;
	virtual LinuxFactory* CreateControlLinux() const = 0;
};

#endif

