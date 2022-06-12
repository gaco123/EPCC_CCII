#include "Nodo.h"

Nodo::Nodo(){
	sig=NULL;
	val={};
}
Nodo::~Nodo(){
	delete sig;
}
