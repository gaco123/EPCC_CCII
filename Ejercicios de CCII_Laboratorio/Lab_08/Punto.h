#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
using namespace std;

class Punto{
public:
	Punto();
	Punto(Punto const&);
	Punto(double,double);
	~Punto();
	void camb_punto(double,double);
	void imprimir();
protected:
	double x;
	double y;
};

#endif

