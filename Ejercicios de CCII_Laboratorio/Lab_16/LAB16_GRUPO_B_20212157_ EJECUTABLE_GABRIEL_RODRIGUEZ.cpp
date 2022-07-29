
//Laboratorio N°16
//Alumno: Gabriel Fernando Rodriguez Cutimbo
/*
1. Dado el siguiente modelo de la siguiente imagen, realizar la implementación del
modelo. De ser posible, incluir una interfaz para Linux que también sea utilizado
por los productos Button y CheckBox. (Las funciones Draw() solo imprimen el
tipo de Producto y el sistema en que se encuentra)
*/

#include <iostream>

#include "GUIFactory.h"
#include "WinFactory.h"
#include "MacFactory.h"
#include "LinuxFactory.h"

#include "Button.h"
#include "WinButton.h"
#include "MacButton.h"
#include "LinuxButton.h"

#include "CheckBox.h"
#include "WinCheckBox.h"
#include "MacCheckBox.h"
#include "LinuxCheckBox.h"

using namespace std;

void Application(const GUIFactory& f, int os) {
	if(os==1){
		const WinFactory* pa = f.CreateControlWin();
		cout << pa->Draw();
		delete pa;
	}
	else if(os==2){
		const MacFactory* pb = f.CreateControlMac();
		cout << pb->Draw();
		delete pb;
	}
	else if(os==3){
		const LinuxFactory* pc = f.CreateControlLinux();
		cout << pc->Draw();
		delete pc;
	}
	else{
		cout<<"Error SO no soportado";
	}
}

int main () {
	//Win
	cout << "Cliente => Windows\n"; // 1 - Windows
	//WinButton
	Button* f1a = new Button();
	Application(*f1a,1); 
	delete f1a;
	cout << endl;
	//WinCheckBox
	CheckBox* f1b = new CheckBox();
	Application(*f1b,1);
	delete f1b;
	cout << endl << endl;
	
	//Mac
	cout << "Cliente => Mac\n"; // 2 - Mac
	//MacButton
	Button* f2a = new Button();
	Application(*f2a,2); 
	delete f2a;
	cout << endl;
	//MacCheckBox
	CheckBox* f2b = new CheckBox();
	Application(*f2b,2);
	delete f2b;
	cout << endl << endl;
	
	//Linux
	cout << "Cliente => Linux\n"; // 3 - Linux
	//LinuxButton
	Button* f3a = new Button();
	Application(*f3a,3); 
	delete f3a;
	cout << endl;
	//LinuxCheckBox
	CheckBox* f3b = new CheckBox();
	Application(*f3b,3);
	delete f3b;
	
	return 0;
}

