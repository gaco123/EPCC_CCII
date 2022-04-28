
//Laboratorio N�1
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Escriba un c�digo que solicite al usuario ingresar dos n�meros enteros y que muestre
el producto de ambos.
*/
/*
#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	
	cout <<"Ingrese dos n�meros enteros, el resultado ser� el producto de ambos"<<endl;
	cout <<"Ingrese el primer n�mero"<<endl;
	cin >>a;
	cout <<"Ingrese el segundo n�mero"<<endl;
	cin >>b;
	c=a*b;
	cout <<"El producto de ambos es: "<<c;
	
	return 0;
}
*/

/*
2. Escriba un c�digo que solicite el primer nombre de una persona, el apellido paterno
y el apellido materno. Retornar su correo UNSA generado, el cual consiste de la
primera letra del nombre, el apellido paterno completo, y la primera letra del apellido
materno. (se agrega el dominio de la universidad al final).
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	//Memoria
	string nombre1;
	string apellidopa;
	string apellidoma;
	string correoUNSA;
	
	//Ingreso de datos
	cout <<"Ingrese su nombre:"<<endl;
	getline(cin,nombre1);
	cout <<"Ingrese su apellido paterno:"<<endl;
	getline(cin,apellidopa);
	cout <<"Ingrese su apellido materno:"<<endl;
	getline(cin,apellidoma);
	
	//Generaci�n del correo UNSA
	correoUNSA=nombre1[0];
	correoUNSA+=apellidopa;
	correoUNSA+=apellidoma[0];
	correoUNSA+="@unsa.edu.pe";
	
	//Final
	cout <<"Su correo UNSA es: "<<correoUNSA;
	
	return 0;
}
*/

/*
3. Elabore un programa que solicite ingresar una hora del d�a (HH:MM en formato de
cadena), solicite un tiempo en minutos a agregar, y retorne la hora de finalizaci�n (el
formato de salida debe de estar en AM o PM seg�n corresponda).
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	//Memoria
	string tiempo1;
	string hora1;
	string min1;
	
	int h1;
	int m1;
	int htemp;
	int agmin;
	
	//Conversi�n primaria del tiempo de string a int
	cout <<"Ingrese un hora del d�a (formato [HH:MM], 24 horas):"<<endl;
	getline(cin,tiempo1);
	hora1=tiempo1.substr(0,2);
	min1=tiempo1.substr(3,2);
	h1=stoi(hora1,nullptr,10);
	m1=stoi(min1,nullptr,10);
	
	//Tiempo a agregar
	cout <<"Indique el n�mero de tiempo (en minutos) que quiere agregar a esa hora del d�a:"<<endl;
	cin >>agmin;
	
	m1+=agmin;
	if(m1>=60){
		htemp=m1/60;
		m1=m1%60;
		h1+=htemp;
		if(h1>=24){
			h1=h1%24;
		}
	}

	//Conversi�n a formato de 24 horas a formato AM/PM
	if(h1>=13){
		h1=h1-12;
		if(h1<10 && m1<10){
			cout<<"La nuevo hora del d�a ser�a: 0"<<h1<<":0"<<m1<<"PM";
		}
		else if(h1<10){
			cout<<"La nuevo hora del d�a ser�a: 0"<<h1<<":"<<m1<<"PM";
		}
		else if(m1<10){
			cout<<"La nuevo hora del d�a ser�a: "<<h1<<":0"<<m1<<"PM";
		}
	}
	else{
		if(h1<10 && m1<10){
			cout<<"La nuevo hora del d�a ser�a: 0"<<h1<<":0"<<m1<<"AM";
		}
		else if(h1<10){
			cout<<"La nuevo hora del d�a ser�a: 0"<<h1<<":"<<m1<<"AM";
		}
		else if(m1<10){
			cout<<"La nuevo hora del d�a ser�a: "<<h1<<":0"<<m1<<"AM";
		}
	}
	
	return 0;
}
*/

/*
4. Escriba un c�digo que solicite una cantidad de minutos espec�fica y muestre como
resultado la hora y fecha resultante tomando como referencia la hora y fecha actual y
restarle el tiempo indicado.(incompleto...)
*/
/*
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(){
	int min;
	
	cout <<"Ingrese la cantidad de minutos a restarle a la hora actual:"<<endl;
	cin >>min;
	
    //Tiempo actual y estructura para manipular ese tiempo
	time_t ahora = time(0);
	tm *ltm = localtime(&ahora);
	
	//Restar el tiempo a la hora actual
	for(int i=0; i<min; i++){
		ltm->tm_min--;
		if(ltm->tm_min==-1){
			ltm->tm_min=59;
			ltm->tm_hour--;
			if(ltm->tm_hour==-1){
				ltm->tm_hour=23;
			}
		}
	}
	
	//Salida de datos en 24horas
	cout<<"La nuevo hora del d�a ser�a: "<<ltm->tm_hour<<":"<<ltm->tm_min;

	return 0;
}
*/

/*
5. Elabore un c�digo que reciba como entrada una secuencia de caracteres que contiene
un numero flotante y retorne el n�mero redondeado.
*/
/*
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(){
	//Memoria
	string nums;
	float num;
	int numi;
	
	//Ingreso del n�mero en formato string
	cout<<"Ingrese un dato de tipo float: ";
	getline(cin,nums);
	
	//Conversion de string a float y posterio redondeo a int
	num=stof(nums);
	numi=round(num);
	cout<<"El n�mero redondeado es: "<<numi;
	
	return 0;
}
*/

/*
6. Elabore un c�digo que solicite un numero entre 100 < x < 999 y muestre el resultado
en binario.
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	//Memoria
	int num;
	int tnum;
	string ts;
	string rbin;
	string bin;
	
	//Ingreso del n�mero decimal
	do{
		cout<<"Ingrese un n�mero entre 100 y 999 (que no sea 100 y 999): ";
		cin>>num;
	} while(num<=100||num>=999);
	
	//Conversi�n de decimal a binario
	while(2<=num/2){
		tnum=num%2;
		num=num/2;
		ts=to_string(tnum);
		rbin.append(ts);
	}
	tnum=num%2;
	ts=to_string(tnum);
	rbin.append(ts);
	ts=to_string(num/2);
	rbin.append(ts);
	
	//Resultado final
	for(int i=rbin.size()-1; i>=0; i--){
		ts=rbin[i];
		bin.append(ts);
	}
	cout<<"El n�mero en binario es: "<<bin;
	
	return 0;
}
*/

/*
7. Elabore un algoritmo que lea por teclado dos n�meros enteros y determine si uno es
divisor del otro.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int x;
	int y;
	
	//Ingreso de datos
	cout<<"Ingrese el n�mero X: ";
	cin>>x;
	cout<<"Ingrese el n�mero Y: ";
	cin>>y;
	cout<<endl;
	
	//Respuesta
	if(x%y!=0){
		cout<<"Y no es divisor de X"<<endl;
	}
	else{
	   cout<<"Y si es divisor de X"<<endl;
	}
	if(y%x!=0){
		cout<<"X no es divisor de Y"<<endl;
	}
	else{
		cout<<"X si es divisor de Y"<<endl;
	}
	
	return 0;
}
*/

/*
8. Escribir un programa que calcule la media de x cantidad n�meros introducidos por el
teclado.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int x;
	float med;
	int* arrayx;
	
	//Ingreso de datos
	cout<<"Ingrese la cantidad de n�meros que va a introducir: ";
	cin>>x;
	cout<<endl;
	arrayx= new int[x];
	for(int i=0; i<x; i++){
		cout<<"Ingrese un n�mero: ";
		cin>>arrayx[i];
	}
	cout<<endl;
	
	//Media de los datos
	for(int i=0; i<x; i++){
		med+=arrayx[i];
	}
	med=med/x;
	cout<<"La media de todos los n�meros en el vector es: "<<med;
	
	delete[] arrayx;
	
	return 0;
}
*/

/*
9. Escribir un programa que lea 10 datos desde el teclado y sume s�lo aquellos que sean
negativos.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	const int n = 10;
	int sum=0;
	int arrayx[n];
	
	//Ingreso de datos
	for(int i=0; i<n; i++){
		cout<<"Ingrese un n�mero: ";
		cin>>arrayx[i];
		if(arrayx[i]<0){
			sum+=arrayx[i];
		}
	}
	cout<<endl;
	
	//Suma
	cout<<"La suma de todos los n�meros negativos ingresado anteriormente es: "<<sum;
	
	return 0;
}
*/

/*
10. Escribir un programa que almacene la cadena de caracteres contrase�a en una
variable, pregunte al usuario por la contrase�a hasta que introduzca la contrase�a
correcta.
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	string cont="UNSA_CCII";
	string a;
	
	do{
		cout<<"Escriba la contrase�a guardada en este programa: ";
		getline(cin,a);
	} while(cont!=a);
	
	return 0;
}
*/
