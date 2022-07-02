
/*
6. sumarango.cpp. Escriba una funci�n template que tome un �nico
par�metro de tipo T y que acepte cuatro argumentos: un array de tipo T,
un �ndice de inicio, un �ndice de finalizaci�n (inclusivo) y un valor inicial
opcional. La funci�n debe devolver la suma de todos los elementos del
array en el rango especificado y el valor inicial.
*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T sumarango(vector<T> x, int ini, int fin, T val=0){
	T cont = 0;
	cont += val;
	fin++;
	for(auto i=x.begin()+ini; i<x.begin()+fin; i++){
		cont += *i;
	}
	return cont;
}

int main(int argc, char *argv[]) {
	vector<int> lista = {1,2,3,4,5,6,7,8,9};//Va de la posici�n 0 a 8
	cout<<"La suma de todos los elementos de la lista es: "<<sumarango(lista,0,8);
	
	return 0;
}

