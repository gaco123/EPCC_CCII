
/*
1. contador.cpp. Implemente una clase Contador que represente un
	contador de enteros simple. La clase debe satisfacer los siguientes
	requisitos:
	a) Proporcione un constructor que tome un solo argumento int que se
	use para inicializar el valor del contador. El argumento debe ser cero
	por defecto.
	b) Sobrecarge los operadores de incremento prefijo y de incremento
	posfijo para proporcionar un medio por el cual incrementar el valor
	del contador.
	c) Proporcione una funci�n miembro valor() que devuelva el valor actual
	del contador.
	d) Adem�s, la clase debe saber cu�ntos objetos Contador existen
	actualmente. Proporcione una interfaz para consultar este valor. El
	c�digo no debe utilizar ninguna variable global. Use miembros
	est�ticos.
*/
#include <iostream>
using namespace std;

class contador{
public:
	static int nobjt;
	contador(int val = 0){
		this->val=val;
		++nobjt;
	}
	//Incremento Prefijo (devuelve el valor despues de incrementarse)
	contador& operator++(){
		++val;
		return *this;//*this hace referencia la objeto actual que estamos modificando
	}
	//Incremento Postfijo (devuelve el valor antes de incrementarse)
	contador operator++(int){//El int es un marcador
		contador temp{*this};
		++(*this);
		return temp;
	}
	int valor(){
		return val;
	}
	int nobjetos(){
		return nobjt;
	}
private:
	int val;
};
int contador::nobjt=0;

int main(int argc, char *argv[]) {
	contador a(1);
	++a;
	cout<<"Valor de a: "<<a.valor()<<endl;
	cout<<"N�mero de objetos contador: "<<a.nobjetos()<<endl;
	contador b(5);
	b++;
	cout<<"Valor de b: "<<b.valor()<<endl;
	cout<<"N�mero de objetos contador: "<<b.nobjetos()<<endl;
	
	return 0;
}

