#include "Rectangulo.h"

Rectangulo::Rectangulo()=default;
Rectangulo::Rectangulo(const Rectangulo &x)=default;
Rectangulo::Rectangulo(string _color, double _x, double _y, char _nombre[], double _lmenor, double _lmayor)
:Forma(_color,_x,_y,_nombre){
	lmenor=_lmenor;
	lmayor=_lmayor;
}
Rectangulo::~Rectangulo(){
}
void Rectangulo::imprimir(){
	Forma::imprimir();
	cout<<"El lado menor es: "<< lmenor <<endl;
	cout<<"El lado mayor es: "<< lmayor <<endl;
}
double Rectangulo::Area(){
	return lmenor*lmayor;
}
double Rectangulo::Perimetro(){
	return (2*lmenor)+(2*lmayor);
}
void Rectangulo::Escalar(double es){
	lmenor=lmenor*es;
	lmayor=lmayor*es;
	cout<<"Los lados han sido escalados por "<<es<<endl;
}

