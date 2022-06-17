
//Laboratorio N°12
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Defina una Cola que permita insertar elementos utilizando clases.
2. Sobre el ejercicio anterior, adecue el programa para eliminar elementos de una
Cola.
3. Implemente un algoritmo para buscar elementos de la Cola.
4. Escribir un programa que permita comparar las edades de diferentes elementos.
Debe utilizar el formato de colas en clases. Se debe definir· inicialmente el
número de elementos y valores de cada cola (pudiendo ser de diferentes tamaños
ej. 2-3). Se evaluará el resultado de la comparación de los primeros elementos de
las colas, realizada en un número de iteraciones 'n', en cada iteración se debe
realizar el procedimiento de inserción y eliminación de elementos (rotando los
elementos definidos inicialmente)
*/

#include<iostream>
#include <clocale>//Cáracteres Español
#include <string>
#include <ctime>
#include <random>
#include "Nodo.h"
using namespace std;

mt19937 gen(time(0));
uniform_int_distribution<> rand_digits(1,75);

void push(Nodo*& prim, Nodo*& ult, int val){
	Nodo* temp = new Nodo;
	temp->val=val;
	if(prim==NULL){
		prim=temp;
		ult=prim;
	}
	else{
		ult->sig=temp;
		ult=temp;
	}
}
Nodo* pop(Nodo*& prim){
	Nodo* temp = prim;
	prim=prim->sig;
	temp->sig=NULL;
	
	return temp;
}
Nodo* searchl(Nodo*& prim, int val){
	Nodo* temp=prim;
	int n=0;
	while(temp!=NULL&&temp->val!=val){
		temp=temp->sig;
		n++;
	}
	if(temp!=NULL){
		cout<<"SI se encontro el valor "<<val<<" en la posición "<<n<<" cola seleccionada\n";
	}
	else{
		cout<<"NO se encontro el valor "<<val<<" en la cola seleccionada\n";
	}
	return temp;
}
void comp(Nodo*& prim1, Nodo*& ult1, Nodo*& prim2, Nodo*& ult2, int it){
	Nodo* temp = NULL;
	string msj;
	for(int i=0; i<it; i++){
		if(prim1->val==prim2->val){
			msj="HOMBRE=MUJER\n";
		}
		else if(prim1->val>prim2->val){
			msj="HOMBRE\n";
		}
		else{
			msj="MUJER\n";
		}
		//Cola de los hombres
		temp=pop(prim1);
		push(prim1,ult1,temp->val);
		delete temp;
		temp=NULL;
		//Cola de las mujeres
		temp=pop(prim2);
		push(prim2,ult2,temp->val);
		delete temp;
		temp=NULL;
	}
	cout<<"¿Quién es mayor en la iteración "<<it<<"?\n";
	cout<<msj;
}
void print(Nodo*& prim){
	Nodo* temp = prim;
	if(temp!=NULL){
		cout<<"[";
		while(temp->sig!=NULL){
			cout<<temp->val<<", ";
			temp=temp->sig;
		}
		cout<<temp->val<<"]\n";
	}
	if(temp==NULL){
		cout<<"NULL\n";
	}
}

int main (int argc, char *argv[]) {
	setlocale(LC_CTYPE, "Spanish");//Cáracteres Español
	
	//Hombres
	Nodo* primh = NULL;
	Nodo* ulth = NULL;
	push(primh,ulth,20);
	push(primh,ulth,15);
	cout<<"Cola de Edades de Hombres\n";
	print(primh);
	
	//Mujeres
	Nodo* primm = NULL;
	Nodo* ultm = NULL;
	push(primm,ultm,13);
	push(primm,ultm,18);
	push(primm,ultm,23);
	cout<<"Cola de Edades de Mujeres\n";
	print(primm);
	cout<<endl;
	
	//Comparación mediante iteración
	comp(primh,ulth,primm,ultm,3);
	comp(primh,ulth,primm,ultm,10);
	comp(primh,ulth,primm,ultm,100);
	
	return 0;
}
