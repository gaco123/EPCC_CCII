#ifndef CUADRADO_H
#define CUADRADO_H
#include "Rectangulo.h"

class Cuadrado : public Rectangulo{
public:
	Cuadrado();
	Cuadrado(Cuadrado const&);
	Cuadrado(string, double, double, char[], double);
	~Cuadrado();
	void imprimir();
};

#endif

