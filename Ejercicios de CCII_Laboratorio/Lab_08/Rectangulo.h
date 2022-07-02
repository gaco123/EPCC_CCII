#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "Forma.h"

class Rectangulo : public Forma{
public:
	Rectangulo();
	Rectangulo(Rectangulo const&);
	Rectangulo(string, double, double, char[], double, double);
	~Rectangulo();
	void imprimir();
	double Area();
	double Perimetro();
	void Escalar(double);
protected:
	double lmenor;
	double lmayor;
};

#endif

