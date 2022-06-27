
/*
5. cuadrático.cpp. Desarrolle una clase Cuadrática que represente una
función de la forma f(x) = ax^2 + bx + c, donde x es un variable real
y a, b, c son constantes reales. La clase debe cumplir con los siguientes
requisitos:
	a) Proporcione un constructor que tome los valores de a, b y c como
	argumentos. Estos argumentos deben ser cero por defecto.
	b) La clase debe proporcionar constructor copia y operador de
	asignación
	c) Proporcione el operador de llamada a función que tome un solo
	argumento x y devuelva el valor f(x).
*/
#include <iostream>
#include <cmath>
using namespace std;

class cuadratica{
public:
	cuadratica(double a = 0, double b = 0, double c = 0){
		this->a=a;
		this->b=b;
		this->c=c;
	}
	cuadratica(const cuadratica& x) = default;
	cuadratica& operator=(cuadratica x){
		if (this == &x){
			return *this;
		}
		a = x.obtA();
		b = x.obtB();
		b = x.obtC();
		return *this;
	}
	double operator()(double x){
		cout<<"La función "<<a<<"*("<<x<<"^"<<2<<") + "<<b<<"*"<<x<<" + "<<c<<" = ";
		return (a*pow(x,2))+(b*x)+c;
	}
	
	double obtA(){
		return a;
	}
	double obtB(){
		return b;
	}
	double obtC(){
		return c;
	}
private:
	double a;
	double b;
	double c;
};

int main(int argc, char *argv[]) {
	cuadratica a(5,3,8);
	cout<<a(3);
	
	return 0;
}

