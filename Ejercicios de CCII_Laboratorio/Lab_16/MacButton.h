#ifndef MACBUTTON_H
#define MACBUTTON_H
#include "MacFactory.h"

class MacButton : public MacFactory{
public:
	string Draw() const override{
		return "Drawing Mac Button";
	}
	string draw(const WinFactory& colaborator) const override{
		const string result = colaborator.Draw();
		return "Mac Button with help of " + result;
	}
};

#endif

