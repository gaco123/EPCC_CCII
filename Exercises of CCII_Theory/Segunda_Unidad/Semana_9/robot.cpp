
/*
3. robot.cpp
Usted administra una fábrica de robots.
Cuando un robot sale de la fábrica, no tiene nombre.
La primera vez que enciende un robot, se genera un nombre aleatorio en
formato de dos letras mayúsculas seguidas de tres dígitos, como RZ123 o
CD731.

Cuando necesitamos resetear un robot a su configuración de fábrica, su
nombre se borra. De modo que la próxima vez que se le pregunte su nombre,
ese robot responderá con un nuevo nombre aleatorio.
Los nombres de los robot deben ser aleatorios: no deben seguir una
secuencia predecible. El uso de nombres aleatorios implica un riesgo de
colisiones. Su solución debe garantizar que cada robot existente tenga un
nombre único.

Use la cabecera <random>
Pruebe su solución generando 100 robots, luego en un ciclo resetee sus
nombres y asigne nuevos nombre, compruebe que sus nombres siguen
siendo únicos.
*/

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
//Motor Aleatorio
mt19937 gen(time(0));
uniform_int_distribution<char> rand_ascii('A','Z');
uniform_int_distribution<> rand_digits(100,999);
//Clase
class Robot{
public:
	Robot();
	void imprimir();
	void resetear();
	char prim;
	char seg;
	string snum;
};
Robot::Robot(){
	prim = rand_ascii(gen);
	seg = rand_ascii(gen);
	snum = to_string(rand_digits(gen));
}
void Robot::imprimir(){
	cout<<"El nombre del robot es: "<<prim<<seg<<snum<<endl;
}
void Robot::resetear(){
	char tprim, tseg;
	string tsnum;
	
	do{
		tprim = rand_ascii(gen);
		tseg = rand_ascii(gen);
		tsnum = to_string(rand_digits(gen));
	} while(tsnum==snum||tprim==prim||tseg==seg);
	
	prim=tprim;
	seg=tseg;
	snum=tsnum;
}
//Funciones
bool nose_repite(vector<Robot>& lista){
	//Este codigo garantiza que los nombres no se repitan
	for(auto i=lista.begin(); i!=lista.end(); i++){
		for(auto j=lista.begin(); j!=lista.end(); j++){
			if(i!=j&&i->prim==j->prim&&i->seg==j->seg&&i->snum==j->snum){
				cout<<"Se encontro que uno(varios) nombre(s) se repiten\n\n";
				system("pause");
				return false;
			}
		}
	}
	return true;
}
void resetear_todo(vector<Robot>& lista){
	//Este codigo resetea todos los nombres de los robots
	for(auto k=lista.begin(); k!=lista.end(); k++){
		k->resetear();
	}
}
//Main
int main(int argc, char *argv[]) {
	//Memoria
	vector<Robot> lista;	
	for(int i=0; i<100; i++){
		lista.push_back(Robot());
	}
	//Primera Lista de Nombres con su comprobación
	cout<<"NOMBRES ORIGINALES\n";
	for(auto i=lista.begin(); i!=lista.end(); i++){
		i->imprimir();
	}
	if(nose_repite(lista)==true){
		cout<<"No se repite ningún nombre\n\n";
		system("pause");
	}
	
	//Reseteo de todos los nombres
	resetear_todo(lista);
	
	//Segunda Lista de Nombres con su comprobación
	cout<<"NOMBRES DESPUES DEL BUCLE\n";
	for(auto i=lista.begin(); i!=lista.end(); i++){
		i->imprimir();
	}
	if(nose_repite(lista)==true){
		cout<<"No se repite ningún nombre\n\n";
		system("pause");
	}
	
	
	return 0;
}

