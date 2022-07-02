#include "Punto.h"

Punto::Punto()=default;
Punto::Punto(const Punto &x)=default;
Punto::Punto(double _x, double _y){
	x=_x;
	y=_y;
}
Punto::~Punto(){
}
void Punto::camb_punto(double _x, double _y){
	x=_x;
	y=_y;
	cout<<"La coordenada X ha cambiado a: "<< x <<endl;
	cout<<"La coordenada Y ha cambiado a: "<< y <<endl;
}
void Punto::imprimir(){
	cout<<"La coordenada X es: "<< x <<endl;
	cout<<"La coordenada Y es: "<< y <<endl;
}
