#ifndef CIRCULO_H
#define CIRCULO_H
#include "Elipse.h"

class Circulo : public Elipse{
public:
	Circulo();
	Circulo(Circulo const&);
	Circulo(string, double, double, char[], double);
	~Circulo();
	void imprimir();
};

#endif

