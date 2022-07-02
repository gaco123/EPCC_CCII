#include "Circulo.h"

Circulo::Circulo()=default;
Circulo::Circulo(const Circulo &x)=default;
Circulo::Circulo(string _color, double _x, double _y, char _nombre[], double _radio)
:Elipse(_color,_x,_y,_nombre,_radio,_radio){
}
Circulo::~Circulo(){
}
void Circulo::imprimir(){
	Forma::imprimir();
	cout<<"El radio es: "<< rmenor <<endl;
}

