#include "ClaseDisco.h"

ClaseDisco::ClaseDisco(bool _interactiva, string _titulo, string _calidad):ClaseMultimedia(_interactiva,_titulo){
	calidad=_calidad;
	cout<<"Se introdujo el valor de ("<<calidad<<") en la ClaseDisco\n";
}
ClaseDisco::~ClaseDisco(){
}
