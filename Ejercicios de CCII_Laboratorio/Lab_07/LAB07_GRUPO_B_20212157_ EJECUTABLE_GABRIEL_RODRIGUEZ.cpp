
//Laboratorio N�7
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Crear una clase Persona del cual tendr� m�todos asignar una edad y nombre. Una
segunda clase, alumno, tendr� que heredar este contenido y a trav�s de esta clase
poder asignar los datos de edad y nombre de los estudiantes.
*/
/*
#include <iostream>
#include <string>
#include "Persona.h"
#include "Alumno.h"
using namespace std;

int main (){
	Alumno x;
	x.dar_edad(20);
	x.dar_nombre("Pepe");
	x.mostrar_EdadNombre();

	return 0;
}
*/

/*
2. Crear una clase Color que mantenga 3 valores (RGB). Una segunda clase Material,
tendr� como informaci�n una variable de texto que describa alg�n material (Ejemplo:
madera, vidrio, platico, etc.) Una tercera clase, Objetos, deber� de heredar contenido
de ambas clases con la finalidad de describir diferentes objetos en cuanto a color y el
material. (Ejemplo: mesa de color caf� y material de pl�stico)
*/
/*
#include <iostream>
#include <string>
#include "Color.h"
#include "Material.h"
#include "Objeto.h"
using namespace std;

int main (){
	Objeto mesa;
	mesa.darnombre_Objeto("mesa");
	mesa.dar_Material("plastico");
	mesa.dar_RGB(255,0,0);
	mesa.describir();

	return 0;
}
*/

/*
4. Escribe una clase de nombre ClaseDisco, que herede de la clase ClaseMultimedia los
atributos y m�todos definidos por usted. La clase ClaseDisco tiene, aparte de los
elementos heredados, un atributo m�s tambi�n definido por usted. Al momento de
imprimir la informaci�n debe mostrase por pantalla toda la informaci�n.
*/
/*
#include <iostream>
#include <string>
#include "ClaseMultimedia.h"
#include "ClaseDisco.h"
using namespace std;

int main (){
    //Permite ingresar 3 valores (bool,string,string) que tienen el nombre de (interactiva,titulo,calidad)
	//interactiva y titulo pertenecen a "ClaseMultimedia"
    //calida pertenece a "ClaseDisco"
	ClaseDisco L(false,"Parque Jurasico 3","Buena");
	
	return 0;
}
*/

/*
5. Escribe un programa que implemente la siguiente jerarqu�a de clases
operacionBase->operacionFactorial
*/
/*
#include <iostream>
#include "operacionBase.h"
#include "operacionFactorial.h"
using namespace std;

int main (){
	int n = 10;
	operacionFactorial a;
	a.setOperador(n);
	cout<<"El factorial de "<<n<<" es: "<<a.devolverFactorial();
	
	return 0;
}
*/

/*
6. Escribe un programa que implemente la siguiente jerarqu�a de clases, Debe
implementar aquellos atributos y m�todos necesarios para que se pueda ejecutar el
siguiente programa:
Ave->Ganso
Ave->Pato
Ave->Gallina
*/

#include <iostream>
#include <string>
#include <clocale>//C�racteres Espa�ol
#include "Ave.h"
#include "Ganso.h"
#include "Pato.h"
#include "Gallina.h"
using namespace std;

int main (){
	setlocale(LC_CTYPE, "Spanish");//C�racteres Espa�ol
	
	cout<<"Ave A\n";
	Ave a(true,"Onk!","grande","marrones","largas");
	a.mostrar_Vals();
	cout<<"\n";
	
	
	Ganso b;
	cout<<"Ganso B\n";
	b.mostrar_Vals();
	cout<<"\n";
	
	Pato c;
	cout<<"Pato C\n";
	c.mostrar_Vals();
	cout<<"\n";
	
	Gallina d;
	cout<<"Gallina D\n";
	d.mostrar_Vals();
	cout<<"\n";
	
	return 0;
}

