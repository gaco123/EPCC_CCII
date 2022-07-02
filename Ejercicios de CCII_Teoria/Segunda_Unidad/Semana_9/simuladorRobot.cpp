
/*
4. simuladorRobot.cpp
	Escribir un simulador de robot.
	Una fábrica de robots necesita un programa para verificar los movimientos
	de sus robots.
	Los robots tienen tres posibles movimientos:
	* (D) Girar a la derecha
	* (I) Girar a la izquierda
	* (A) Avanzar una posición
	Los robots se colocan en un plano cartesiano infinito (hipotético), mirando en
	una dirección particular (norte, este, sur u oeste) en un punto {x, y}.
	Luego, el robot recibe una serie de instrucciones
	La cadena de letras "DAAIAI" significa:
		* Gire a la derecha
		* Avanzar dos veces
		* Gire a la izquierda
		* Avanzar una vez
		* Gire a la izquierda una vez más
	Digamos que un robot comienza en {7, 3} mirando hacia el norte. Luego de
	ejecutar este flujo de instrucciones debería dejarlo en {9, 4} mirando al oeste.
	Cree una clase robot con los atributos y métodos adecuados.
*/
#include <iostream>
#include <string>
using namespace std;

class Robot{
public:
	Robot(int,int,string);
	void D();
	void I();
	void A();
	void Instrucciones(string);
	void Imprimir();
private:
	int x;
	int y;
	string mirando;
};
Robot::Robot(int x, int y, string mirando){
	this->x=x;
	this->y=y;
	this->mirando=mirando;
}
void Robot::D(){
	if(mirando=="norte"){
		mirando="este";
	}
	else if(mirando=="este"){
		mirando="sur";
	}
	else if(mirando=="sur"){
		mirando="oeste";
	}
	else if(mirando=="oeste"){
		mirando="norte";
	}
}
void Robot::I(){
	if(mirando=="norte"){
		mirando="oeste";
	}
	else if(mirando=="oeste"){
		mirando="sur";
	}
	else if(mirando=="sur"){
		mirando="este";
	}
	else if(mirando=="este"){
		mirando="norte";
	}
}
void Robot::A(){
	if(mirando=="norte"){
		y++;
	}
	else if(mirando=="oeste"){
		x--;
	}
	else if(mirando=="sur"){
		y--;
	}
	else if(mirando=="este"){
		x++;
	}
}
void Robot::Instrucciones(string inst){
	string temp;
	for(int i=0; i<inst.length(); i++){
		temp=inst[i];
		if(temp=="D"){
			D();
		}
		else if(temp=="I"){
			I();
		}
		else if(temp=="A"){
			A();
		}
	}
}
void Robot::Imprimir(){
	cout<<"Posición x: "<<x<<endl;
	cout<<"Posición y: "<<y<<endl;
	cout<<"Mirando hacia: "<<mirando<<endl;
}

int main(int argc, char *argv[]) {
	//Digamos que un robot comienza en {7, 3} mirando hacia el norte.
	cout<<"ROBOT ORION (posición inicial)\n";
	Robot Orion(7,3,"norte");
	Orion.Imprimir();
	//Luego de ejecutar este flujo de instrucciones debería dejarlo en {9, 4} mirando al oeste.
	cout<<"ROBOT ORION (posición déspues de las instrucciones)\n";
	Orion.Instrucciones("DAAIAI");
	Orion.Imprimir();
	
	return 0;
}

