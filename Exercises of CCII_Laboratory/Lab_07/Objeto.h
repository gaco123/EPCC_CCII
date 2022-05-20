#ifndef OBJETO_H
#define OBJETO_H
#include "Color.h"
#include "Material.h"
#include <iostream>

class Objeto : public Color , public Material{
public:
	Objeto();
	~Objeto();
	void darnombre_Objeto(string);
	void describir();
private:
	string objeto;
};

#endif

