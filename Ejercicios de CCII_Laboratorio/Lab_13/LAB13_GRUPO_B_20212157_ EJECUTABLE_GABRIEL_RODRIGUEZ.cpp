
//Laboratorio N°13
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Implementar un programa que maneje un arreglo de estructuras para almacenar
los nombres y las fechas de cumpleaños de sus n compañeros. Y debe mostrarse
por pantalla quienes cumplen años en este mes.
*/
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Estructura esencial
struct amigo{
	string nombres;
	string fecha;
};

//Función para comprobar si cumple este mes un amigo
void esteMes(amigo a, string actual){
	string m1 = a.fecha.substr(3,2);
	string m2 = actual.substr(3,2);
	if(m1==m2){
		cout<<a.nombres<<" tiene su cumpleaños este mes\n";
	}
}

int main(int argc, char *argv[]){
	//Memoria
	string actual;
	vector<amigo> lista;
	int n;
	string tempn;
	string tempf;
	
	//Datos Iniciales
	cout<<"Ingrese cuantos n amigos tiene: ";
	cin>>n;
	cout<<"Ingrese la fecha actual (formato DD/MM/AAAA): ";
	getline(cin,actual);
	getline(cin,actual);
	cout<<endl;
	
	//Datos de cada amigo
	for(int i=0; i<n; i++){
		cout<<"Ingrese el nombre completo de su amigo: ";
		getline(cin,tempn);
		cout<<"Ingrese la fecha de cumpleaños de su amigo (formato DD/MM/AAAA): ";
		getline(cin,tempf);
		amigo a={tempn,tempf};
		lista.push_back(a);
	}
	cout<<endl;
	
	//Comprobación de cada amigo con la función
	for(auto i=lista.begin(); i!=lista.end(); i++){
		esteMes(*i,actual);
	}
	
	
	return 0;
}
*/

/*
2. Implementar un programa que maneje un arreglo de estructuras que calcule la
nota final del Ciencia de la Computación. El programa debe permitir el ingreso
de cualquier cantidad de alumnos y para cada alumno, se podrá ingresar nombre,
grupo, nota de la primera fase, segunda fase, tercera fase y proyecto final. El
porcentaje de cada ítem es 15%, 20%, 25% y 40% respectivamente.
*/
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Estructura esencial
struct alumno{
	string nombre;
	string grupo;
	double nota1;
	double nota2;
	double nota3;
	double notapf;
	double total;
};

int main(int argc, char *argv[]){
	//Memoria
	vector<alumno> lista;
	string si;
	
	//Lista de infinitos alumnos
	do{
		alumno a;
		cout<<"Ingrese el nombre del alumno: ";
		getline(cin,a.nombre);
		cout<<"Ingrese el grupo del alumno: ";
		getline(cin,a.grupo);
		cout<<"Ingrese la nota de la primera fase: ";
		cin>>a.nota1;
		cout<<"Ingrese la nota de la segunda fase: ";
		cin>>a.nota2;
		cout<<"Ingrese la nota de la tercera fase: ";
		cin>>a.nota3;
		cout<<"Ingrese la nota del proyecto final: ";
		cin>>a.notapf;
		a.total=((a.nota1*15)+(a.nota2*20)+(a.nota3*25)+(a.notapf*40))/100;
		cout<<"Desea continuar? (escriba si), caso contrario escriba cualquier cosa: ";
		getline(cin,si);
		getline(cin,si);//Por alguna razón no agarra al primer getline
		lista.push_back(a);
		cout<<endl;
	} while(si=="si");
	
	//Mostrar nota final de cada alumno
	for(auto i=lista.begin(); i!=lista.end(); i++){
		cout<<"El alumno "<<(*i).nombre<<" del grupo "<<(*i).grupo<<" tiene una nota final de "<<(*i).total<<"\n";
	}
	
	return 0;
}
*/

/*
3. Implemente un programa que maneje un arreglo de estructuras que solicite el
nombre, edad y talla de 10 jugadores, debe mostrar por pantalla los que son
menores de 20 años y tienen una talla mayor a 1,70 mts de altura.
*/
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Estructura esencial
struct jugador{
	string nombre;
	int edad;
	double talla;
};

int main(int argc, char *argv[]){
	//Memoria
	vector<jugador> lista;
	string si;
	
	//Lista de 10 jugadores
	for(int i=0; i<10; i++){
		jugador a;
		cout<<"Ingrese el nombre del jugador: ";
		getline(cin,a.nombre);
		if(i>=1){
			getline(cin,a.nombre);
		}
		cout<<"Ingrese la edad del jugador: ";
		cin>>a.edad;
		cout<<"Ingrese la talla del jugador: ";
		cin>>a.talla;
		lista.push_back(a);
		cout<<endl;
	}
	
	//Mostrar a jugadores menores de 20 años y con una talla mayor a 1.70mts
	for(auto i=lista.begin(); i!=lista.end(); i++){
		if((*i).edad<20&&(*i).talla>1.70){
			cout<<"El jugador "<<(*i).nombre<<" es menor de 20 años y tiene una talla mayor a 1.70mts\n";
		}
	}
	
	return 0;
}
*/

/*
4. Implemente un programa que maneje un arreglo de estructuras que solicite
nombre, sexo y sueldo de los empleados de una empresa y debe mostrar por
pantalla el menor y mayor sueldo.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Estructura esencial
struct empleado{
	string nombre;
	string sexo;
	double sueldo;
};

int main(int argc, char *argv[]){
	//Memoria
	vector<empleado> lista;
	string si;
	
	//Lista de empleados
	do{
		empleado a;
		cout<<"Ingrese el nombre del empleado(a): ";
		getline(cin,a.nombre);
		cout<<"Ingrese el sexo del empleado (Hombre o Mujer): ";
		getline(cin,a.sexo);
		cout<<"Ingrese el sueldo del empleado: ";
		cin>>a.sueldo;
		cout<<"Desea continuar? (escriba si), caso contrario escriba cualquier cosa: ";
		getline(cin,si);
		getline(cin,si);//Por alguna razón no agarra al primer getline
		lista.push_back(a);
		cout<<endl;
	} while(si=="si");
	
	//Encontrar el amyor y menor sueldo entre los empleados
	empleado mayor=lista.at(0);
	empleado menor=lista.at(0);
	for(auto i=lista.begin(); i!=lista.end(); i++){
		if((*i).sueldo>mayor.sueldo){
			mayor=*i;
		}
		if((*i).sueldo<menor.sueldo){
			menor=*i;
		}
	}
	
	//Mostrar
	if(mayor.sexo=="Hombre"){
		cout<<"El empleado "<<mayor.nombre<<" tiene el mayor sueldo, el cual es "<<mayor.sueldo<<"\n";
	}
	else if(mayor.sexo=="Mujer"){
		cout<<"La empleada "<<mayor.nombre<<" tiene el mayor sueldo, el cual es "<<mayor.sueldo<<"\n";
	}
	if(menor.sexo=="Hombre"){
		cout<<"El empleado "<<menor.nombre<<" tiene el menor sueldo, el cual es "<<menor.sueldo<<"\n";
	}
	else if(menor.sexo=="Mujer"){
		cout<<"La empleada "<<menor.nombre<<" tiene el menor sueldo, el cual es "<<menor.sueldo<<"\n";
	}
	
	return 0;
}

