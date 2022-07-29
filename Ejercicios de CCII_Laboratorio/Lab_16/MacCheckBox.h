#ifndef MACCHECKBOX_H
#define MACCHECKBOX_H
#include "MacFactory.h"

class MacCheckBox : public MacFactory{
public:
	string Draw() const override{
		return "Drawing Mac CheckBox";
	}
	string draw(const WinFactory& colaborator) const override{
		const string result = colaborator.Draw();
		return "Mac CheckBox with help of " + result;
	}
};

#endif

