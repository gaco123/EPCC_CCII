
//Alumno: Gabriel Fernando Rodriguez Cutimbo
/*
3. e3asignacion.cpp.
	Considerando el c�digo de LinkedList
	
	https://drive.google.com/drive/folders/1ow9DIEuGdD8yM48RGyFGx-
	GU4GWCXeNo?usp=sharing
	
	Implemente el operador de asignaci�n.
	Escriba c�digo de ejemplo para probar su implementaci�n.
*/
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main(){
	LinkedList x(20);
	x.insert(45);
	x.insert(15);
	x.insert(14);
	x.insert(9);
	cout<<"LISTA ENLAZADA \"X\" INICIAL\n";
	cout<<x<<endl;
	
	LinkedList y;
	y = x;
	cout<<"LISTA ENLAZADA \"Y\" INICIAL\n";
	cout<<y<<endl;
	y.insert(23);
	cout<<"LISTA ENLAZADA \"Y\"\n";
	cout<<y<<endl;
	x = y;
	cout<<"LISTA ENLAZADA \"X\"\n";
	cout<<x<<endl;
	
	return 0;
}

