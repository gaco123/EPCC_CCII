#include "Cuadrado.h"

Cuadrado::Cuadrado()=default;
Cuadrado::Cuadrado(const Cuadrado &x)=default;
Cuadrado::Cuadrado(string _color, double _x, double _y, char _nombre[], double _lado)
:Rectangulo(_color,_x,_y,_nombre,_lado,_lado){
}
Cuadrado::~Cuadrado(){
}
void Cuadrado::imprimir(){
	Forma::imprimir();
	cout<<"El lado es: "<< lmenor <<endl;
}



