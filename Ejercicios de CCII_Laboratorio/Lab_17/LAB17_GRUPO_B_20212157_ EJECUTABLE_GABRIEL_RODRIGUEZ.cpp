
//Laboratorio N�17
//Alumno: Gabriel Fernando Rodriguez Cutimbo
/*
1. Desarrolle un programa simple de calculadora (operaciones basicas) que utilice
	clases utilizando plantillas
*/
/*
#include <iostream>
using namespace std;

template <class X, class Y> 
class op_basica{
public:
	op_basica(int op, X a, Y b){
		if(op==1){
			cout<<"La suma de los n�meros ingresados es: "<<a+b;
		}
		else if(op==2){
			cout<<"La resta de los n�meros ingresados es: "<<a-b;
		}
		else if(op==3){
			cout<<"La multiplicaci�n de los n�meros ingresados es: "<<a*b;
		}
		else if(op==4){
			cout<<"La divisi�n de los n�meros ingresados es: "<<a/b;
		}
	}
};

int main() {
	int op;
	
	do{
		system("CLS");
		cout<<"CALCULADORA DE OPERACIONES BASICAS\n";
		cout<<"1. Suma\n";
		cout<<"2. Resta\n";
		cout<<"3. Multiplicaci�n\n";
		cout<<"4. Divisi�n\n";
		cout<<"Ingrese el n�mero de la opci�n: ";
		cin>>op;
		if(op==1||op==2||op==3||op==4){
			break;
		}
		else{
			cout<<"Error ingrese de nuevo la opci�n...\n\n";
			system("PAUSE");
		}
	}while(true);
	cout<<endl;
	
	if(op==1){
		int a, b;
		cout<<"Ingrese el primer n�mero: ";
		cin>>a;
		cout<<"Ingrese el segundo n�mero: ";
		cin>>b;
		op_basica<int,int> x(1,a,b);
	}
	else if(op==2){
		float a, b;
		cout<<"Ingrese el primer n�mero: ";
		cin>>a;
		cout<<"Ingrese el segundo n�mero: ";
		cin>>b;
		op_basica<float,float> x(2,a,b);
	}
	else if(op==3){
		long a, b;
		cout<<"Ingrese el primer n�mero: ";
		cin>>a;
		cout<<"Ingrese el segundo n�mero: ";
		cin>>b;
		op_basica<long,long> x(3,a,b);
	}
	else if(op==4){
		double a, b;
		cout<<"Ingrese el primer n�mero: ";
		cin>>a;
		cout<<"Ingrese el segundo n�mero: ";
		cin>>b;
		op_basica<double,double> x(4,a,b);
	}
	
	return 0;
}
*/

/*
2. Definir una clase utilizando plantillas que permita almacenar datos en un arbol
binario. Por el momento solo se insertaran elementos en la estructura. Simule el
proceso de almacenar 100 datos y verifique que la estructura no tenga problemas.
*/
/*
#include <iostream>
using namespace std;

template <class X>
class nodo{
public:
	nodo(X val){
		this->val = val;
		this->sig = nullptr;
	}
	X val;
	nodo<X>* sig;
};

template <class X>
class l_enlazada{
private:
	nodo<X>* head;
public:
	l_enlazada(X val){
		head = new nodo<X>(val);
	}
	~l_enlazada(){
		nodo<X>* temp = head;
		while(temp->sig!=nullptr){
			head=head->sig;
			delete temp;
			temp=head;
		}
		delete head;
	}
	void push_back(X val){
		nodo<X>* new1 = new nodo<X>(val);
		nodo<X>* temp = head;
		while(temp->sig!=nullptr){
			temp=temp->sig;
		}
		temp->sig = new1;
	}
	void print(){
		nodo<X>* temp = head;
		cout<<"[";
		while(temp!=nullptr){
			if(temp->sig!=nullptr){
				cout<<temp->val;
				cout<<", ";
			}
			else{
				cout<<temp->val;
			}
			temp=temp->sig;
		}
		cout<<"]";
	}
};

int main(){
	//Lista enlazada que almacena floats
	float a = 0.5;
	l_enlazada<float> x(a);
	
	for(int i=1; i<100; i++){
		x.push_back(a+i);
	}
	cout<<"LISTA ENLAZADA [FLOAT]\n";
	x.print();
	cout<<endl<<endl;
	
	//Lista enlazada que almacena ints
	l_enlazada<int> y(0);
	
	for(int i=1; i<100; i++){
		y.push_back(i);
	}
	cout<<"LISTA ENLAZADA [INT]\n";
	y.print();
	
	return 0;
}
*/

/*
3. Analice y describa el siguiente comportamiento
*/

#include <iostream>
using namespace std;

//Clase gen�rica Contenedor
template<class T>
class Contenedor{
	T elemento;
public:
	//Constructor gen�rico de la clase "Contenedor"
	Contenedor(T arg){
		elemento = arg;
	}
	//Suma 1 al "elemento" que esta en la clase "Contenedor"
	T add(){
		return ++elemento;
	}
};

/*
	Descripci�n espec�fica para la clase "Contenedor" cuando el tipo de valor
	tomado por el template es <char>
*/
template <>
class Contenedor<char>{
	char elemento;
public:
	//Constructor de la clase "Contenedor<char>"
	Contenedor(char arg){
		elemento = arg;
	}
	//Esta funci�n se encarga de volver una letra minuscula en may�scula
	char uppercase(){
		if((elemento >= 'a') && (elemento <= 'z')){
			//'A' = 65 y 'a' = 97 entonces 'A'-'a' = -32
			/*
				Al restar este n�mero a una letra minuscula hara que est� retroceda 32 espacios
				quedando exactamente en su misma letra pero en may�scula
			*/
			elemento += 'A'-'a';
		}
		return elemento;
	}
};

int main(){
	//Crea una clase "Contenedor" gen�rica que acepta elementos de tipo <int>
	Contenedor<int> cint(5);
	//Crea un "Contenedor<char>" que tiene su propia descripci�n
	Contenedor<char> cchar('t');
	//Utiliza la funci�n add de la clase "Contenedor" gen�rica
	cout<<cint.add()<<endl;
	//Utiliza la funci�n uppercase que es propia de la clase "Contenedor<char>"
	cout<<cchar.uppercase()<<endl;
	
	return 0;
}
