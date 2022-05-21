#include "Elipse.h"

Elipse::Elipse()=default;
Elipse::Elipse(const Elipse &x)=default;
Elipse::Elipse(string _color, double _x, double _y, char _nombre[], double _rmenor, double _rmayor)
:Forma(_color,_x,_y,_nombre){
	rmenor=_rmenor;
	rmayor=_rmayor;
}
Elipse::~Elipse(){
}
void Elipse::imprimir(){
	Forma::imprimir();
	cout<<"El radio menor es: "<< rmenor <<endl;
	cout<<"El radio mayor es: "<< rmayor <<endl;
}
double Elipse::Area(){
	return rmenor*rmayor*M_PI;
}
void Elipse::Escalar(double es){
	rmenor=rmenor*es;
	rmayor=rmayor*es;
	cout<<"Los radios han sido escalados por "<<es<<endl;
}
