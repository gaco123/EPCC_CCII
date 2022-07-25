
//Alumno: Gabriel Fernando Rodriguez Cutimbo
/*
2. e2funcion.cpp.
    *Escriba una función de tal forma que usted pueda invocar a cualquiera de
	las funciones siguientes:

	float sumafi(float a, int b) {
		return a + b;
	}
	double restalf(float a, double b) {
		return a - b;
	}
	long multiplicaid(int a, long b) {
		return a * b;
	}
	
   *Forma de llamar a la función:
	funcion(sumafi, 4.0f, 5);
	funcion(restalf, 4.0f, 5.0);
	funcion(multiplicaid, 4, 5L);
*/
#include <iostream>
using namespace std;

float sumar(float a, int b){
	return a+b;
}
double restar(float a, double b){
	return a-b;
}
long multiplicar(int a, long b){
	return a*b;
}
template<typename xtype, typename ytype, typename ztype>
xtype operaciones_basicas(xtype (*x)(ytype,ztype), ytype a, ztype b){
	return x(a,b);
}

int main() {
	cout.precision(6);
	cout<<"La suma de los dos números es: "<<fixed<<operaciones_basicas(&sumar,4.0f,5)<<endl;
	cout.precision(7);
	cout<<"La resta de los dos números es: "<<fixed<<operaciones_basicas(&restar,4.0f,5.0)<<endl;
	cout<<"La multiplicación de los dos números es: "<<operaciones_basicas(&multiplicar,4,5L)<<endl;
	
	return 0;
}

