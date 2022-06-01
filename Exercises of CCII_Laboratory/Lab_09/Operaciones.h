#ifndef OPERACIONES_H
#define OPERACIONES_H

template <class O>
class Operaciones{
public:
	Operaciones(O num1=0, O num2=0);
	O Suma(){
		return num1+num2;
	};
	O Resta(){
		return num1-num2;
	};
	O Mult(){
		return num1*num2;
	};
	O Div(){
		return num1/num2;
	};
private:
	O num1;
	O num2;
};

template <class O>
Operaciones<O>::Operaciones(O num1, O num2){
	this->num1 = num1;
	this->num2 = num2;
}

#endif

