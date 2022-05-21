
//Laboratorio N°8
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Defina una clase Forma que tenga los siguientes miembros de datos:
	- Color
	- Coordenada del centro de la forma (objeto Punto)
	- Nombre de la forma (char *)
Y, al menos, las siguientes funciones miembro:
	- Imprimir
	- Obtener y cambiar el color
	- Mover la forma (o sea, su centro)
Defina una clase derivada Rectángulo que tenga los siguientes miembros como
datos:
	- Lado menor.
	- Lado mayor.
Y, al menos, las siguientes funciones miembro:
	- Imprimir. Debe imprimir qué se trata de un rectángulo mostrando su nombre,
	color, centro y lado. Debería usarse la función Imprimir de la clase base para
	realizar parte de este trabajo.
	- Calcular el área (lado menor * lado mayor).
	- Calcular el perímetro. (2 * lado menor + 2 * lado mayor).
	- Cambiar el tamaño del rectángulo. Recibe como parámetro un factor de escala.
Así, por ejemplo, si el factor vale 2, el rectángulo duplicará su tamaño y si es 0,5
se reducirá a la mitad.
Realice un programa que pruebe el funcionamiento de estas clases. Debe crear
objetos y comprobar el correcto funcionamiento de las funciones miembro.


2. Defina una clase Elipse derivada de forma. Recordatorio: una elipse queda
definida por su radio mayor (R) y su radio menor (r), tal que el área de una elipse
es igual a p*(R*r).

3. Defina una clase Cuadrado derivada de la clase Rectángulo.

4. Defina una clase Circulo derivada de la clase Elipse.

5. Realice un programa que defina varias formas diferentes, cree un vector de
punteros de la clase Forma que apunten a los objetos creados. El programa debe
realizar un bucle que recorra todas las formas, las ponga todas del mismo color y
las mueva a una determinada posición.

6. Analice qué ocurre en el ejercicio anterior si se intenta imprimir la información
de cada forma y qué sucede si se intenta obtener en ese bucle el área de todas las
formas del vector.

7. Utilice la técnica de las funciones virtuales para arreglar los comportamientos
anómalos detectados en el ejercicio anterior.

8. Desarrolle un programa que, dado un conjunto de formas, calcule cuál tiene el
área máxima e imprima la información de dicha forma.
*/

#include <iostream>
#include <string>
#include <clocale>//Cáracteres Español
#include "Punto.h"
#include "Forma.h"
#include "Rectangulo.h"
#include "Elipse.h"
#include "Cuadrado.h"
#include "Circulo.h"
using namespace std;

int main (){
	setlocale(LC_CTYPE, "Spanish");//Cáracteres Español
	
	cout<<"PROGRAMA PARA RESOLVER EJERCICIOS DEL 1 HASTA EL 4\n";
	//Forma
	char n1[]={"forma"};
	Forma a("negro",50,50,n1);
	cout<<"FORMA\n";
	a.imprimir();
	cout<<"\n";
	
	//Rectangulo 1er-Parte
	char n2[]={"rectangulo"};
	Rectangulo b("azul",1,0,n2,5,10);
	cout<<"RECTANGULO-1er\n";
	b.imprimir();
	cout<<"El área es: "<<b.Area()<<endl;
	cout<<"El perimetro es: "<<b.Perimetro()<<endl;
	cout<<"\n";
	
	//Rectangulo 2da-Parte
	cout<<"RECTANGULO-2do\n";
	b.camb_punto(0,1);
	b.Escalar(0.5);
	b.imprimir();
	cout<<"El área es: "<<b.Area()<<endl;
	cout<<"El perimetro es: "<<b.Perimetro()<<endl;
	cout<<"\n";
	
	//Elipse 1er-Parte
	char n3[]=("elipse");
	Elipse c("verde",-1,-1,n3,10,20);
	cout<<"ELIPSE-1er\n";
	c.imprimir();
	cout<<"El área es: "<<c.Area()<<endl;
	cout<<"\n";
	
	//Elipse 2da-Parte
	cout<<"ELIPSE-2do\n";
	c.camb_punto(0,0);
	c.Escalar(2);
	c.imprimir();
	cout<<"El área es: "<<c.Area()<<endl;
	cout<<"\n";
	
	//Cuadrado
	char n4[]=("cuadrado");
	Cuadrado d("rojo",5,5,n4,15);
	cout<<"CUADRADO\n";
	d.imprimir();
	cout<<"El área es: "<<d.Area()<<endl;
	cout<<"El perimetro es: "<<d.Perimetro()<<endl;
	cout<<"\n";
	
	//Circulo
	char n5[]="circulo";
	Circulo e("amarillo",-10,-10,n5,10);
	cout<<"CIRCULO\n";
	e.imprimir();
	cout<<"El área es: "<<e.Area()<<endl;
	cout<<"\n";
	
	cout<<"PROGRAMA PARA RESOLVER EJERCICIOS DEL 5 HASTA EL 8\n";
	//Vector de Formas
	int n = 4;
	Forma** vec = new Forma*[n]; 
	vec[0]=&b;//Rectangulo
	vec[1]=&c;//Elipse
	vec[2]=&d;//Cuadrado
	vec[3]=&e;//Circulo
	
	//Cambiar color a los objetos en el vector y moverlor
	cout<<"CAMBIO DE COLOR Y POSICION PARA LAS 4 FORMAS\n";
	for(int i=0; i<n; i++){
		vec[i]->camb_color("café");
		cout<<"vec["<<i<<"]="<<vec[i]->obt_color()<<"\n";
		vec[i]->camb_punto(100,100);
	}
	cout<<endl;
	
	//Verificar el imprimir()
	for(int i=0; i<n; i++){
		cout<<"FORMA EN V["<<i<<"]\n";
		vec[i]->imprimir();
		cout<<endl;
	}
	
	//Obtener áreas
	cout<<"ÁREAS DE LOS OBJETOS\n";
	double ab[]={0,0,0,0};
	for(int i=0; i<n; i++){
		ab[i]=vec[i]->Area();
		if(i!=3){
			cout<<ab[i]<<", ";
		}
		else{
			cout<<ab[i]<<endl;
		}
	}
	
	//Detecta el area mayor e imprime la informacion del objeto con mayor area
	int ptemp=0;
	double temp=ab[ptemp];
	for(int i=0; i<n; i++){
		if(temp<ab[i]){
			temp=ab[i];
			ptemp=i;
		}
	}
	cout<<endl;
	cout<<"FORMA CON EL ÁREA MAXIMA\n";
	vec[ptemp]->imprimir();
	cout<<endl;
	
	delete[] vec;
	
	return 0;
}

