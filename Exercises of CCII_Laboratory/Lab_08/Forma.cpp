#include "Forma.h"

Forma::Forma()=default;
Forma::Forma(const Forma &x)=default;
Forma::Forma(string _color, double _x, double _y, char _nombre[])
:Punto(_x,_y){
	color=_color;
	nombre=_nombre;
}
Forma::~Forma(){
	delete[] nombre;
}
void Forma::imprimir(){
	cout<<"El nombre es: "<< nombre <<endl;
	cout<<"El color es: "<< color <<endl;
	Punto::imprimir();
}
double Forma::Area(){
}
string Forma::obt_color(){
	return color;
}
void Forma::camb_color(string _color){
	color=_color;
}
