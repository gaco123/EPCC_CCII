#include "Persona.h"

Persona::Persona(){
}
Persona::~Persona(){	
}
void Persona::dar_edad(int _edad){
	edad=_edad;
}
void Persona::dar_nombre(string _nombre){
	nombre=_nombre;
}
int Persona::obtener_edad(){
	return edad;
}
string Persona::obtener_nombre(){
	return nombre;
}
