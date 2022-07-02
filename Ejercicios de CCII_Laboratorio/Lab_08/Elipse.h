#ifndef ELIPSE_H
#define ELIPSE_H
#include "Forma.h"

class Elipse : public Forma{
public:
	Elipse();
	Elipse(Elipse const&);
	Elipse(string, double, double, char[], double, double);
	~Elipse();
	void imprimir();
	double Area();
	void Escalar(double);
protected:
	double rmenor;
	double rmayor;
};

#endif

