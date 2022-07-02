/*
4. pila.cpp. Escriba una implementación de pila para un tipo genérico. Se
	debe definir el tamaño máximo de la pila. Proporcione las siguientes
	funciones:
	a) Constructor
	b) Destructor si es necesario
	c) top: muestra el último elemento
	d) pop: retorna el último elemento y lo elimina de la pila
	e) push: inserta un nuevo elemento
	f) clear: borra todos los elementos
	g) size: número de elementos
	h) full: comprueba si la pila está llena, y
	i) empty: comprueba si la pila está vacía.
	
	Se debe generar una excepción cuando la pila esté llena y se quiera
	colocar un nuevo elemento, y también cuando la pila esté vacía y se
	quiera obtener un elemento.
*/
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

//Clase para definir una pila y sus nodos
template <class n>
class Nodo {
public:
	//Crea un nodo
	Nodo(Nodo* sig = NULL, n val = {}, int max_size = 1){
		this->sig=sig;
		this->val=val;
		this->max_size=max_size;
	}
	Nodo* sig;
	n val;
	int max_size;
	int csize;
};

//Muestra el último elemento de la pila
template <typename n>
void top(Nodo<n>*& Pila){
	cout<<Pila->val<<endl;
}
//Añadir elemento al inicio de la pila
template <typename n>
void push(Nodo<n>*& Pila, n val){
	int cont=0;
	Nodo<n>* contp=Pila;
	while(contp!=NULL){
		cont++;
		contp=contp->sig;
	}
	try{
		if(cont<Pila->max_size){
			Nodo<n>* temp = new Nodo<n>(Pila,val,Pila->max_size);
			Pila = temp;
		}
		else{
			throw "No se puede insertar un nuevo elemento, debido a que la pila alcanzo su máximo tamaño";
		}
	}
	catch(const char* error){
		cout<<error<<endl;
	}
}
//Sacar elemente del final de la pila
template <typename n>
Nodo<n>* pop(Nodo<n>*& Pila){
	try{
		if(Pila!=NULL){
			Nodo<n>* temp = Pila;
			Pila=Pila->sig;
			temp->sig=NULL;
			
			return temp;
		}
		else{
			throw "No se puede retornar el ultimo elemento, debido a que la pila esta vacia";
		}
	}
	catch(const char* error){
		cout<<error<<endl;
	}
	return NULL;
}
//Practicamente funciona como un destructor para la pila
template <typename n>
void clear(Nodo<n>*& Pila){
	Nodo<n>* basura;
	if(Pila!=NULL){
		while(Pila->sig!=NULL){
			basura=pop(Pila);
			delete basura;
		}
		basura=pop(Pila);
		delete basura;
	}
}
//Tamaño actual de la pila
template <typename n>
int size(Nodo<n>*& Pila){
	int cont=0;
	Nodo<n>* contp=Pila;
	while(contp!=NULL){
		cont++;
		contp=contp->sig;
	}
	return cont;
}
//Comprueba si la pila esta llena
template <typename n>
bool full(Nodo<n>*& Pila){
	if(size(Pila)==Pila->max_size){
		return true;
	}
	else{
		return false;
	}
}
//Comprueba si la pila esta vacía
template <typename n>
bool empty(Nodo<n>*& Pila){
	if(size(Pila)==0){
		return true;
	}
	else{
		return false;
	}
}
//Imprimir nodos vinculados
template <typename n>
void print(Nodo<n>*& Pila){
	Nodo<n>* temp = Pila;
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

int main(int argc, char *argv[]) {
	//Puntero Inicial
	Nodo<int>* Pila = new Nodo<int>(NULL,15,5);
	
	//Pila de 5 elementos, se comprueban las funciones push, print, full y size
	cout<<"Primer Bloque\n";
	push(Pila,20);
	push(Pila,80);
	push(Pila,30);
	push(Pila,10);
	print(Pila);
	push(Pila,40);//Genera una excepción
	if(full(Pila)){
		cout<<"La pila esta llena"<<endl;
	}
	cout<<"Tamaño de la pila: "<<size(Pila)<<endl<<endl;
	
	//Pila de 0 elementos, se comprueban las funciones clear, empty y pop
	cout<<"Segundo Bloque\n";
	clear(Pila);
	print(Pila);
	if(empty(Pila)){
		cout<<"La pila esta vacía"<<endl;
	}
	cout<<"Tamaño de la pila: "<<size(Pila)<<endl;
	pop(Pila);//Genera una excepción
	
	return 0;
}

