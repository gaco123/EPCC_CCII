#include "Objeto.h"

Objeto::Objeto(){
}
Objeto::~Objeto(){
}
void Objeto::darnombre_Objeto(string _objeto){
	objeto=_objeto;
}
void Objeto::describir(){
	string temp;
	if(R==0 && G==0 && B==0){
		temp="negro";
	}
	else if(R==255 && G==255 && B==255){
		temp="blanco";
	}
	else if(R==255 && G==0 && B==0){
		temp="rojo";
	}
	else if(R==0 && G==255 && B==0){
		temp="verde";
	}
	else if(R==0 && G==0 && B==255){
		temp="azul";
	}
	else{
		temp="error";
	}
	cout<<objeto<<" de color "<<temp<<" y material de "<<material;
}
