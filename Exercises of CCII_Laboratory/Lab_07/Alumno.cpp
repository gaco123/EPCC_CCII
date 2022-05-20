#include "Alumno.h"

Alumno::Alumno(){
}
Alumno::~Alumno(){
}
void Alumno::mostrar_EdadNombre(){
	int e = obtener_edad();
	string n = obtener_nombre();
	cout<<"La edad de la persona es: "<<e<<" y su nombre es: "<<n;
}
