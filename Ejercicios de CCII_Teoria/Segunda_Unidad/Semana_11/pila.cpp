/*
4. pila.cpp. Escriba una implementaci�n de pila para un tipo gen�rico. Se
	debe definir el tama�o m�ximo de la pila. Proporcione las siguientes
	funciones:
	a) Constructor
	b) Destructor si es necesario
	c) top: muestra el �ltimo elemento
	d) pop: retorna el �ltimo elemento y lo elimina de la pila
	e) push: inserta un nuevo elemento
	f) clear: borra todos los elementos
	g) size: n�mero de elementos
	h) full: comprueba si la pila est� llena, y
	i) empty: comprueba si la pila est� vac�a.
	
	Se debe generar una excepci�n cuando la pila est� llena y se quiera
	colocar un nuevo elemento, y tambi�n cuando la pila est� vac�a y se
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

//Muestra el �ltimo elemento de la pila
template <typename n>
void top(Nodo<n>*& Pila){
	cout<<Pila->val<<endl;
}
//A�adir elemento al inicio de la pila
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
			throw "No se puede insertar un nuevo elemento, debido a que la pila alcanzo su m�ximo tama�o";
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
//Tama�o actual de la pila
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
//Comprueba si la pila esta vac�a
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
	push(Pila,40);//Genera una excepci�n
	if(full(Pila)){
		cout<<"La pila esta llena"<<endl;
	}
	cout<<"Tama�o de la pila: "<<size(Pila)<<endl<<endl;
	
	//Pila de 0 elementos, se comprueban las funciones clear, empty y pop
	cout<<"Segundo Bloque\n";
	clear(Pila);
	print(Pila);
	if(empty(Pila)){
		cout<<"La pila esta vac�a"<<endl;
	}
	cout<<"Tama�o de la pila: "<<size(Pila)<<endl;
	pop(Pila);//Genera una excepci�n
	
	return 0;
}

