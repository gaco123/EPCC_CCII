#ifndef WINBUTTON_H
#define WINBUTTON_H
#include "WinFactory.h"

class WinButton : public WinFactory{
public:
	string Draw() const override{
		return "Drawing Windows Button";
	}
};

#endif

