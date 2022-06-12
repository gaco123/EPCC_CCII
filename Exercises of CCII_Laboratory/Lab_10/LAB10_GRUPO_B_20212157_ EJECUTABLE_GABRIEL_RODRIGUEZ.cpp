
//Laboratorio N�10
//Alumno: Gabriel Fernando Rodriguez Cutimbo

#include <iostream>
#include <clocale>//C�racteres Espa�ol
#include "Nodo.h"
using namespace std;

/*
1. Defina una lista enlazada que permita insertar elementos al final de todos los
elementos que ya se hayan ingresado. Por el momento no es necesario preservar un
orden, simplemente los elementos nuevos deben de ingresar como el �ltimo elemento.
*/
void adirUltNodo(Nodo* a, int val){
	//B�squeda del �ltimo elemento
	Nodo* b = a;
	while(b->sig!=NULL){
		b=b->sig;
	}
	//Creaci�n de un nuevo nodo
	Nodo* c = new Nodo;
	c->val=val;
	//Asignaci�n del nuevo nodo al ultimo elemento de la lista
	b->sig=c;
}
/*
2. Con la implementaci�n de la lista enlazada anterior, desarrolle una funci�n que
permita ingresar los elementos al inicio de todos los dem�s elementos. Tendr� que
modificar el comportamiento del puntero que tiene referencia al primer elemento para
que sea redireccionado al nuevo elemento por ingresar.
*/
Nodo* adirPrimNodo(Nodo* a, int val){
	//Asignar el sig del nuevo nodo al nodo a
	Nodo* c = new Nodo;
	c->val=val;
	c->sig=a;
	//Poner al nuevo nodo como la cabeza de la lista
	return c;
}
/*
3. Desarrolle una funci�n que permita ingresar elementos en el medio de dos elementos
de la lista enlazada, como se muestra en la siguiente imagen. Solicite que se ingrese
una posici�n v�lida dentro de la lista y permita que el valor ingresado se pueda anexar
en esa posici�n.
*/
Nodo* adirPosNodo(Nodo* a, int val, int pos){
	//Tama�o valido del vector
	Nodo* b = a;
	int n=1;
	while(b->sig!=NULL){
		b=b->sig;
		n++;
	}
	if(pos<n&&pos>=0){
		//B�squeda del elemento en la posici�n indicada
		b=a;//Reinicio de la posicion del puntero b
		if(pos==0){
			Nodo* c = new Nodo;
			c->val=val;
			c->sig=a;
			cout<<"Se agrego un nodo de la posici�n "<<pos<<"\n\n";
			return c;
		}
		for(int i=0; i<pos-1; i++){
			b=b->sig;
		}
		Nodo* c = new Nodo;
		c->val=val;
		c->sig=b->sig;
		b->sig=c;
		cout<<"Se agrego un nodo de la posici�n "<<pos<<"\n\n";
		return a;
	}
	else{
		cout<<"Error al insertar el nodo en la posici�n indicada...\n\n";
		return a;
	}
}
/*
4. Elabore una funci�n que permita eliminar el �ltimo elemento de una lista enlazada.
(Evite copiar los elementos en una nueva lista para completar la eliminaci�n del
elemento)
*/
void borrarUltNodo(Nodo* a){
	Nodo* b = a;
	//Bucle para apuntar al pen�ltimo elemento
	while(b->sig->sig!=NULL){
		b=b->sig;
	}
	//Desde el pen�ltimo elemento se borra el �ltimo elemento y se hace que pen�ltimo elemento apunte a NULL
	delete b->sig;
	b->sig=NULL;
}
/*
5. Desarrolle una funci�n que permita eliminar el primer elemento de una lista sin perder
referencia de los dem�s elementos que ya se encuentran almacenados en la estructura
.(Evite copiar los elementos en una nueva lista para completar la eliminaci�n de los
elementos)
*/
Nodo* borrarPrimNodo(Nodo* a){
	Nodo* b = a;
	//Asigna al apuntador de la cabeza que seleccione el siguiente nodo
	a=a->sig;
	//Elimina la referencia del nodo en la cabeza al siguiente nodo
	b->sig=NULL;
	//Se elimina el primer nodo
	delete b;
	return a;
}
/*
6. Dado una posici�n v�lida dentro de la lista, permita al usuario eliminar un elemento
de cualquier posici�n sin perder referencia de los dem�s elementos.
*/
Nodo* borrarPosNodo(Nodo* a, int pos){
	//Tama�o valido del vector
	Nodo* b = a;
	int n=1;
	while(b->sig!=NULL){
		b=b->sig;
		n++;
	}
	if(pos<n&&pos>=0){
		//B�squeda del elemento en la posici�n indicada
		b=a;//Reinicio de la posicion del puntero b
		if(pos==0){
			Nodo* c = a;
			a=a->sig;
			c->sig=NULL;
			delete c;
			cout<<"Se borro el nodo de la posici�n "<<pos<<"\n\n";
			return a;
		}
		for(int i=0; i<pos-1; i++){
			b=b->sig;
		}
		Nodo* c = b;
		b=b->sig;
		c->sig=b->sig;
		b->sig=NULL;
		delete b;
		cout<<"Se borro el nodo de la posici�n "<<pos<<"\n\n";
		return a;
	}
	else{
		cout<<"Error al borrar el nodo en la posici�n indicada...\n\n";
		return a;
	}
}
//Imprime la lista enlazada
void impLista(Nodo* a){
	Nodo* b = a;
	cout<<"[";
	//Recorre toda la lista enlazada hasta que el "nodo* sig" sea null
	while(b->sig!=NULL){
		cout<<b->val<< ", ";
		b=b->sig;
	}
	//Imprime el ultimo elemento
	cout<<b->val<< "]\n\n";
}
/*
7. Desarrolle un algoritmo de ordenamiento que permita ordenar los elementos de forma
ascendente y descendente de acuerdo a la elecci�n del usuario. Se debe poder simular
el ingreso de 10 mil elementos de forma aleatoria y ordenarlos en el menor tiempo
posible ( < 2 seg).
*/
void descendNodo(Nodo* a){
	//Buscar tama�o del nodo
	Nodo* b = a;
	int n=1;
	while(b->sig!=NULL){
		b=b->sig;
		n++;
	}
		
	//Ordenamiento Descendente
	int it = 0;
	Nodo* temp = a;
	int tempval = temp->val;
	int temppos = 0;
	bool comp=false;
	for(int i=it; i<n; i++){
		//Evita que el c�digo se ejecute cuando llegue al final
		if(it!=n-1){
			//Hallar el valor b en cada posici�n indicada
			b = a;
			for(int j=0; j<i; j++){
				b=b->sig;
			}
			//Comparar el valor de cada posici�n del vector con la posicion con mayor valor actual
			if(tempval<b->val){
				temppos=i;
				tempval=b->val;
				comp=true;
			}
			if(i==n-1&&it<n){
				//Hallar la posicion del mayor valor
				b = a;
				for(int e=0; e<temppos; e++){
					b=b->sig;
				}
				//Cuando se ha encontrado un numero mayor que el numero seleccionado por temp
				if(comp==true){
					//Intercambiar ambos valores
					swap(temp->val,b->val);
					//Ajustar el temporal a la nueva posici�n
					it++;
					i=it-1;
					temp = a;
					for(int d=0; d<it; d++){
						temp=temp->sig;
					}
					tempval=temp->val;
					comp=false;
				}
				//Solo si el n�mero seleccionado por temp ya es mayor que todos los n�meros
				else{
					it++;
					i=it-1;
					if(b->sig!=NULL){
						temp = a;
						for(int d=0; d<it; d++){
							temp=temp->sig;
						}
						tempval=temp->val;
					}
				}
			}
		}
	}
}
/*
7. Desarrolle un algoritmo de ordenamiento que permita ordenar los elementos de forma
ascendente y descendente de acuerdo a la elecci�n del usuario. Se debe poder simular
el ingreso de 10 mil elementos de forma aleatoria y ordenarlos en el menor tiempo
posible ( < 2 seg).
*/
void ascendNodo(Nodo* a){
	//Buscar tama�o del nodo
	Nodo* b = a;
	int n=1;
	while(b->sig!=NULL){
		b=b->sig;
		n++;
	}
		
	//Ordenamiento Ascendente
	int it = 0;
	Nodo* temp = a;
	int tempval = temp->val;
	int temppos = 0;
	bool comp=false;
	for(int i=it; i<n; i++){
		//Evita que el c�digo se ejecute cuando llegue al final
		if(it!=n-1){
			//Hallar el valor b en cada posici�n indicada
			b = a;
			for(int j=0; j<i; j++){
				b=b->sig;
			}
			//Comparar el valor de cada posici�n del vector con la posicion con menor valor actual
			if(tempval>b->val){
				temppos=i;
				tempval=b->val;
				comp=true;
			}
			if(i==n-1&&it<n){
				//Hallar la posicion del mayor valor
				b = a;
				for(int e=0; e<temppos; e++){
					b=b->sig;
				}
				//Cuando se ha encontrado un numero menor que el numero seleccionado por temp
				if(comp==true){
					//Intercambiar ambos valores
					swap(temp->val,b->val);
					//Ajustar el temporal a la nueva posici�n
					it++;
					i=it-1;
					temp = a;
					for(int d=0; d<it; d++){
						temp=temp->sig;
					}
					tempval=temp->val;
					comp=false;
				}
				//Solo si el n�mero seleccionado por temp ya es menor que todos los n�meros
				else{
					it++;
					i=it-1;
					if(b->sig!=NULL){
						temp = a;
						for(int d=0; d<it; d++){
							temp=temp->sig;
						}
						tempval=temp->val;
					}
				}
			}
		}
	}
}
	
int main(int argc, char* argv[]){
	setlocale(LC_CTYPE, "Spanish");//C�racteres Espa�ol
	
	bool comp=true;
	bool comporg=false;
	int op;
	
	Nodo* a;
	while(comp==true){
		cout<<"MEN� PRINCIPAL DE LA LISTA ENLAZADA\n";
		cout<<"1. Crear el Primer Nodo\n";
		cout<<"2. A�adir Nodo al Final\n"; 
		cout<<"3. A�adir Nodo al Principio\n"; 
		cout<<"4. A�adir Nodo en la Posici�n Seleccionada\n";
		cout<<"5. Eliminar Nodo al Final\n";
		cout<<"6. Eliminar Nodo al Principio\n";
		cout<<"7. Eliminar Nodo en la Posici�n Seleccionada\n";
		cout<<"8. Ordenar Nodos de Manera Descendente\n";
		cout<<"9. Ordenar Nodos de Manera Ascendente\n";
		cout<<"10. Imprimir Nodos\n";
		cout<<"11. Salir del Programa\n\n";
		cout<<"Ingrese una opci�n: ";
		cin>>op;
		if(op==11){
			return 0;
		}
		if(op==1&&comporg==false){
			a=new Nodo;
			cout<<"Ingrese un valor para el nodo: ";
			cin>>a->val;
			cout<<endl;
			comporg=true;
		}
		else if(op==1&&comporg==true){
			cout<<"Error, ya se cre� el Primer Nodo...\n\n";
		}
		if(comporg==true){
			if(op==2){
				int temp;
				cout<<"Ingrese un valor para el nuevo nodo: ";
				cin>>temp;
				cout<<"Se agrego un ultimo nodo a la lista\n\n";
				adirUltNodo(a,temp);
			}
			else if(op==3){
				int temp;
				cout<<"Ingrese un valor para el nuevo nodo: ";
				cin>>temp;
				cout<<"Se agrego un primer nodo a la lista\n\n";
				a=adirPrimNodo(a,temp);
			}
			else if(op==4){
				int temp1;
				cout<<"Ingrese un valor para el nuevo nodo: ";
				cin>>temp1;
				int temp2;
				cout<<"Ingrese la posici�n donde se agregara al nuevo nodo: ";
				cin>>temp2;
				a=adirPosNodo(a,temp1,temp2);
			}
			else if(op==5){
				borrarUltNodo(a);
				cout<<"Se borro el ultimo nodo de la lista\n\n";
			}
			else if(op==6){
				a=borrarPrimNodo(a);
				cout<<"Se borro el primer nodo de la lista\n\n";
			}
			else if(op==7){
				int temp;
				cout<<"Ingrese la posici�n donde se borrara un nodo: ";
				cin>>temp;
				a=borrarPosNodo(a,temp);
			}
			else if(op==8){
				descendNodo(a);
				cout<<"Se ordeno de manera descendente la lista\n\n";
			}
			else if(op==9){
				ascendNodo(a);
				cout<<"Se ordeno de manera ascendente la lista\n\n";
			}
			else if(op==10){
				cout<<"\nLISTA ENLAZADA\n";
				impLista(a);
			}
			else if (op<1||op>10){
				cout<<"Error, escriba un n�mero de opci�n valida...\n\n";
			}
		}
		else{
			cout<<"Error, necesita crear el Primer Nodo...\n\n";
		}
	}
}
