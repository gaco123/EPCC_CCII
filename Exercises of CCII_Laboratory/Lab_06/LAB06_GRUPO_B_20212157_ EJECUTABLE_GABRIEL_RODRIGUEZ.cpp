
//Laboratorio N°6
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Implemente un programa con clases que calcule el área de un rectángulo y perímetro.
*/

#include <iostream>
#include "rectangle.h"
using namespace std;

int main(){
	//Clase Rectangulo
	rectangle one(10,20);
	//Primer Area y Perimetro del rectangulo
	cout<<"Primer Rectangulo\n";
	one.Area();
	one.Perimeter();
	//Cambiar valores del rectangulo
	one.height_Value(15);
	one.wide_Value(35);
	//Segunda Area y Perimetro del rectangulo
	cout<<"Segundo Rectangulo\n";
	one.Area();
	one.Perimeter();
	
	return 0;
}


/*
2. Se conoce de un alumno de la Universidad Nacional de San Agustín: CUI, nombre
completo y tres notas parciales (nota1, nota2, nota3). El programa con clases debe
imprimir: CUI, el primer nombre, el promedio de las tres notas e indique con un
mensaje si el alumno aprobó (nota final >= 10.5) o no aprobó (nota final < 10.5) la
asignatura de Ciencias de la Computación II.
*/
/*
#include <iostream>
#include "student.h"
using namespace std;

int main(){
	
	student marcos(20221213,"Marcos Perez",10.5,10.5,10.5);
	marcos.pf_name();
	marcos.p_CUI();
	marcos.p_average_score();
	
	return 0;
}
*/

/*
3. Implemente un programa con clases que lea la fecha de nacimiento y la fecha de hoy
y muestre por pantalla el nombre y la edad de la persona.
*/
/*
#include <iostream>
#include "person.h"
using namespace std;

int main(){
	//Ingresar las fechas en formato YYYY-MM-DD
	person pepe("Pepe","2002-01-23","2022-05-12");
	pepe.show_Name();
	cout<<"\n";
	pepe.actual_Age();
	cout<<"\n";
	
	pepe.let_dateOB("2003-05-26");
	pepe.let_dateON("2022-05-26");
	pepe.show_Name();
	cout<<"\n";
	pepe.actual_Age();
	cout<<"\n";
	
	return 0;
}
*/

/*
4. Implemente una aplicación con clases donde una clase contiene un arreglo en el que
se pueden almacenar como máximo 5 datos. Debe tener un nuevo dato para
almacenarlo, debe existir un método que verifique que el arreglo tenga espacio
disponible para guardar el dato. En caso contrario se debe mostrar un mensaje
indicando que el arreglo está lleno. Asimismo, debe tener un método para retirar un
dato del arreglo, este método debe verificar que, si haya algo para sacar del arreglo,
es decir que el arreglo no vaya a estar vacío, en cuyo caso debe desplegar un mensaje
diciendo que no hay nada para sacar de arreglo.
*/
/*
#include <iostream>
#include "array5v.h"
using namespace std;

int main(){
	array5v arrx;
	cout<<"PRIMER ARRAY\n";
	arrx.new_Element(10);
	arrx.new_Element(5);
	arrx.new_Element(2);
	arrx.new_Element(3);
	arrx.new_Element(2);
	arrx.show_Array();
	arrx.new_Element(12);
	cout<<"\n";
	
	cout<<"PRIMER ARRAY (PRIMERAS MODIFICACIONES)\n";
	arrx.remove_Element(2);
	arrx.show_Array();
	arrx.remove_Element(5);
	arrx.show_Array();
	arrx.new_Element(11);
	arrx.show_Array();
	cout<<"\n";
	
	cout<<"PRIMER ARRAY (SEGUNDAS MODIFICACIONES)\n";
	arrx.remove_Element(11);
	arrx.remove_Element(2);
	arrx.remove_Element(3);
	arrx.remove_Element(10);
	arrx.show_Array();
	arrx.remove_Element(5);
	
	return 0;
}
*/

/*
5. Implementar un programa con clases que haga la búsqueda de un dato almacenado en
una matriz de 3x3 que tiene los números de 1 al 9 ingresados aleatoriamente y debe
indicar la posición donde se encuentra el dato.
*/
/*
#include <iostream>
#include "mat3x3.h"
using namespace std;

int main(){
	mat3x3 x;
	cout<<"MATRIZ X\n";
	x.show_Mat();
	x.search_Val(1);
	
	return 0;
}
*/
