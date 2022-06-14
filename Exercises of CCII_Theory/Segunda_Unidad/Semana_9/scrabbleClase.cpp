
/*
2. scrabbleClase.cpp
En el juego de Scrabble, cada ficha contiene una letra, que se usa para formar
palabras en filas y columnas, y una puntuación, que se usa para determinar el
valor de las palabras.
	1. Escriba una definición para una clase llamada Ficha que represente fichas
	de Scrabble. Los atributos de la clase Ficha deben incluir un caracter llamado
	letra y un entero llamado valor.
	2. Escriba un constructor que tome parámetros llamados letra y valor e
	inicialice las variables de los atributos.
	3. Escriba un método llamado imprimir que tome un objeto Ficha como
	parámetro y muestre los atributos en un formato fácil de leer.
	4. Escriba una definición para una clase llamada Scrabble que represente un
	jugador de scrabble. Los atributos de la clase deben incluir un nombre para
	identificar al jugador y una colección de 7 Fichas.
	5. Escriba un método en Scrabble que genere las 7 fichas necesarias en forma
	aleatoria.
	6. Pruebe su clase Scrabble creando jugadores de scrabble (de 2 a 4) y los
	muestre en pantalla
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
using namespace std;

mt19937 gen(time(0));
uniform_int_distribution<char> rand_ascii('A','Z');
uniform_int_distribution<> rand_digits(1,100);

class Ficha{
public:
	Ficha(char,int);
	void Imprimir();
private:
	char letra;
	int valor;
};
Ficha::Ficha(char letra, int valor){
	this->letra=letra;
	this->valor=valor;
}
void Ficha::Imprimir(){
	cout<<"Letra: "<<letra<<endl;
	cout<<"Valor: "<<valor<<endl;
}

class Scrabble{
public:
	Scrabble(string);
	void gen_Fichas();
	void Imprimir();
private:
	string nombre;
	vector<Ficha> coleccion;
	bool comp=true;
};
Scrabble::Scrabble(string nombre){
	this->nombre=nombre;
}
void Scrabble::gen_Fichas(){
	if(comp==true){
		comp=false;
		for(int i=0; i<7; i++){
			Ficha temp(rand_ascii(gen),rand_digits(gen));
			coleccion.push_back(temp);
		}
	}
	else{
		cout<<"Ya se generaron las fichas\n";
	}
}
void Scrabble::Imprimir(){
	int j=1;
	cout<<"Fichas de "<<nombre<<endl;
	for(auto i=coleccion.begin(); i!=coleccion.end(); i++){
		cout<<"Datos de la Ficha-"<<j<<endl;
		i->Imprimir();
		j++;
	}
	cout<<endl;
}

int main(int argc, char *argv[]){
	Scrabble a("Gabriel");
	a.gen_Fichas();
	a.Imprimir();
	
	Scrabble b("Pepe");
	b.gen_Fichas();
	b.Imprimir();
	
	return 0;
}

