
//Laboratorio N°11
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
	1. Defina una Pila que permita insertar elementos utilizando clases.
	2. Sobre el ejercicio anterior, adecue el programa para eliminar elementos de una
	Pila.
	3. Implemente un algoritmo para buscar elementos de la Pila.
	4. Escribir un programa que dé la solución al problema de las Torres de Hanoi para
	N discos, utilizando pilas, las cuales representen cada uno de los postes:
*/
#include<iostream>
#include <clocale>//Cáracteres Español
#include "Nodo.h"
using namespace std;

//Añadir elemento al inicio de la pila
void push(Nodo*& Pila, int val){
	Nodo* temp = new Nodo;
	temp->val = val;
	temp->sig = Pila;
	Pila = temp;
}
//Sacar elemente del final de la pila
Nodo* pop(Nodo*& Pila){
	Nodo* temp = Pila;
	Pila=Pila->sig;
	temp->sig=NULL;
	
	return temp;
}
Nodo* searchl(Nodo*& Pila, int val){
	Nodo* temp = Pila;
	while(temp->val!=val){
		temp=temp->sig;
	}
	return temp;
}
void print(Nodo*& Pila){
	Nodo* temp = Pila;
	if(temp!=NULL){
		cout<<"[";
		while(temp->sig!=NULL){
			cout<<temp->val<<", ";
			temp=temp->sig;
		}
		cout<<temp->val<<"]\n";
	}
	else{
		cout<<"NULL\n";
	}
	
}
void T_Hanoi(int discos, Nodo*& Torre1, Nodo*& Torre2, Nodo*& Torre3, char id1, char id2, char id3, Nodo*& TPorre1, Nodo*& TPorre2, Nodo*& TPorre3){
	Nodo* temp = NULL;
	if(discos==1){
		temp=pop(Torre1);
		cout<<"Mover disco con valor "<<temp->val<<" de la torre "<<id1<<" hacia la torre "<<id3<<endl;
		push(Torre3,temp->val);
		print(TPorre1);
		print(TPorre2);
		print(TPorre3);
		cout<<endl;
		delete temp;
		temp=NULL;
	}
	else{
		T_Hanoi(discos-1, Torre1, Torre3, Torre2, id1, id3, id2, TPorre1, TPorre2, TPorre3);
		temp=pop(Torre1);
		cout<<"Mover disco con valor "<<temp->val<<" de la torre "<<id1<<" hacia la torre "<<id3<<endl;
		push(Torre3,temp->val);
		print(TPorre1);
		print(TPorre2);
		print(TPorre3);
		cout<<endl;
		T_Hanoi(discos-1, Torre2, Torre1, Torre3, id2, id1, id3, TPorre1, TPorre2, TPorre3);
		delete temp;
		temp=NULL;
	}
}
	
int main (int argc, char *argv[]) {
	setlocale(LC_CTYPE, "Spanish");//Cáracteres Español
	
	int discos;
	char id1='1';
	Nodo* Torre1 = NULL;
	char id2='2';
	Nodo* Torre2 = NULL;
	char id3='3';
	Nodo* Torre3 = NULL;
	
	cout<<"¿Con cuantos discos va a jugar?: ";
	cin>>discos;
	cout<<endl;
	for(int i=discos; i>=1; i--){
		push(Torre1,i);
	}
	cout<<"TORRE 1: ";
	print(Torre1);
	cout<<endl;
	T_Hanoi(discos,Torre1,Torre2,Torre3,id1,id2,id3,Torre1,Torre2,Torre3);
	cout<<"TORRE 3: ";
	print(Torre3);
	
	return 0;
}

