#ifndef FORMA_H
#define FORMA_H
#define _USE_MATH_DEFINES
#include <string>
#include <cmath>
#include "Punto.h"

class Forma: public Punto{
public:
	Forma();
	Forma(Forma const&);
	Forma(string,double,double,char[]);
	~Forma();
	virtual void imprimir();
	virtual double Area();
	string obt_color();
	void camb_color(string);
protected:
	string color;
	char* nombre;
};

#endif

