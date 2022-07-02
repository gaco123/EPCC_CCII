#ifndef CORREO_H
#define CORREO_H
#include <string>

template <class C, class S>
class Correo{
public:
	Correo(C ini='x', S ape="abcdefghi");
	S gen_email(){
		S temp = ini + ape + "@unsa.edu.pe";
		return temp;
	};
private:
	C ini;
	S ape;
};

template <class C, class S>
Correo<C,S>::Correo(C ini, S ape){
	this->ini = ini;
	this->ape = ape;
}

#endif

