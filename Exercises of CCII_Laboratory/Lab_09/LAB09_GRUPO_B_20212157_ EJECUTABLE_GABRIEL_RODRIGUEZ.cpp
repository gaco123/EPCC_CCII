
//Laboratorio N°9
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Se pide escribir una función utilizando plantillas que tome tres argumentos
genéricos y devuelva el menor y el máximo de ellos como valor de retorno. La
función debe ser capaz de dar este tipo de resultados.
*/
/*
#include <iostream>
#include <clocale>//Cáracteres Español
#include "Max_min.h"
using namespace std;

int main (){
	
	setlocale(LC_CTYPE, "Spanish");//Cáracteres Español
	
	Max_min<int> MM1(2, 1, 5); 
	Max_min<float> MM2(1.400023, 1.400012, 1.400000);
	Max_min<double> MM3(0.4000237, 0.4000238, 0.4000239);
	cout << "Máximo valor de MM1: " << MM1.getMax() << endl;
	cout << "Mínimo valor de MM1: " << MM1.getMin() << endl;
	cout.precision(6);
	cout << "Máximo valor de MM2: " <<fixed<< MM2.getMax() << endl;
	cout << "Mínimo valor de MM2: " <<fixed<< MM2.getMin() << endl;
	cout.precision(7);
	cout << "Máximo valor de MM3: " <<fixed<< MM3.getMax() << endl;
	cout << "Mínimo valor de MM3: " <<fixed<< MM3.getMin() << endl;
	
	return 0;
}
*/

/*
2. Se pide escribir una función utilizando plantillas que tome dos argumentos
genéricos de tipo entero y flotante que devuelva las cuatro operaciones básicas.
*/
/*
#include <iostream>
#include <clocale>//Cáracteres Español
#include "Operaciones.h"
using namespace std;

int main (){
	
	setlocale(LC_CTYPE, "Spanish");//Cáracteres Español
	
	Operaciones<int> op1(11, 2); 
	Operaciones<float> op2(11, 2);
	
	//op1
	cout << "Suma de op1: " << op1.Suma() << endl;
	cout << "Resta de op1: " << op1.Resta() << endl;
	cout << "Multiplicación de op1: " << op1.Mult() << endl;
	cout << "División de op1: " << op1.Div() << endl;
	cout<<endl;
	
	//op2
	cout.precision(6);
	cout << "Suma de op2: " << op2.Suma() << endl;
	cout << "Resta de op2: " << op2.Resta() << endl;
	cout << "Multiplicación de op2: " << op2.Mult() << endl;
	cout << "División de op2: " << op2.Div() << endl;
	
	return 0;
}
*/

/*
3. Se pide escribir una función utilizando plantillas que tome dos valores genéricos
de tipo char y string (5 veces); char corresponde a una letra y string corresponde
al apellido. El programa debe mostrar por pantalla el siguiente formato de correo
electrónico: char/string@unsa.edu.pe.
*/
/*
#include <iostream>
#include <clocale>//Cáracteres Español
#include <string>
#include "Correo.h"
using namespace std;

int main (){
	
	setlocale(LC_CTYPE, "Spanish");//Cáracteres Español
	
	Correo<char,string> pe1('g', "rodriguez"); 
	Correo<char,string> pe2('f', "cutimbo"); 
	Correo<char,string> pe3('m', "casas"); 
	Correo<char,string> pe4('j', "quispe"); 
	Correo<char,string> pe5('p', "mamani"); 
	
	cout<<"Email generado automáticamente de pe1: "<<pe1.gen_email()<<endl;
	cout<<"Email generado automáticamente de pe2: "<<pe2.gen_email()<<endl;
	cout<<"Email generado automáticamente de pe3: "<<pe3.gen_email()<<endl;
	cout<<"Email generado automáticamente de pe4: "<<pe4.gen_email()<<endl;
	cout<<"Email generado automáticamente de pe5: "<<pe5.gen_email()<<endl;
	
	return 0;
}
*/

/*
4. Implemente un programa que haga uso de plantillas para determinar el mínimo y
máximo valor de un arreglo de elementos dado. Debe de existir dos funciones, la
primera que retorne el mayor de los valores y la segunda que retorne el menor de
los valores. Asimismo, en la función main, se hace una prueba de estas funciones,
con arreglos de enteros y flotantes.
	int ArrayEntero [5] = {10,7,2, 8, 6};
	float ArrayFloat [5] = {12.1, 8.7, 5.6, 8.4, 1.2};
*/
/*
#include <iostream>
#include <clocale>//Cáracteres Español
#include "Maxmin_array.h"
using namespace std;

int main (){
	
	setlocale(LC_CTYPE, "Spanish");//Cáracteres Español
	const int n=5;
	
	int a[n]={10,7,2,8,6};
	Maxmin_array<int*,int,int> b(a,n); 
	
	float c[n]={12.1, 8.7, 5.6, 8.4, 1.2};
	Maxmin_array<float*,float,int> d(c,n); 
	
	cout<<"Máximo valor del array a: "<<b.Max()<<endl;
	cout<<"Mínimo valor del array a: "<<b.Min()<<endl;
	cout<<endl;
	
	cout<<"Máximo valor del array c: "<<d.Max()<<endl;
	cout<<"Mínimo valor del array c: "<<d.Min()<<endl;
	
	return 0;
}
*/

/*
5. Realizar la implementación de un programa que haga uso de plantillas, para
elaborar una función que permita ordenar ascendentemente y descendentemente
los elementos de un arreglo de valores enteros y otro arreglo de valores flotantes.
Las funciones deben recibir como parámetros, un puntero al tipo de elemento
dado, y dos enteros que indican los índices del primero y último elemento.
	int ArrayEntero [5] = {5,7,2,8,6,1,3,4,9};
	float ArrayFloat [5] = {10.1, 8.4, 3.6, 4.4, 11.2};
*/
/*
#include <iostream>
#include <clocale>//Cáracteres Español
#include "Order.h"
using namespace std;

int main (){
	
	setlocale(LC_CTYPE, "Spanish");//Cáracteres Español
	
	int a[]={10,7,2,8,6};
	cout<<"a antes \n";
	for(int i=0; i<5; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n a despues \n";
	Order<int*,int,int,int> b(a,0,5); 
	b.Ascend();
	for(int i=0; i<5; i++){
		cout<<a[i]<<" ";
	}
	
	float c[]={12.1, 8.7, 5.6, 8.4, 1.2};
	Order<float*,float,int,int> d(c,0,5); 
	
	return 0;
}
*/
