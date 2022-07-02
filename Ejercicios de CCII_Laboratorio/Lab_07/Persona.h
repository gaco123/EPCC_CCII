#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>
using namespace std;

class Persona{
public:
	Persona();
	~Persona();
	void dar_edad(int);
	void dar_nombre(string);
	int obtener_edad();
	string obtener_nombre();
private:
	int edad;
	string nombre;
};

#endif

