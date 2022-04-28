
//Laboratorio N�2
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Sumar todos los enteros pares desde 2 hasta 100
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int sum=0;
	
	//Proceso de suma
	for(int i=2; i<=100; i+=2){
		sum+=i;
	}
	cout<<"La suma de los enteros pares desde 2 hasta 100 es: "<<sum;
	
	return 0;
}
*/

/*
2. Calcule los primeros 50 n�meros primos y muestre el resultado en pantalla.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	const int n=50;
	int it=0;
	int prim[n];
	int tempn=0;
	bool prueba = true;
	
	//Proceso de busqueda de primos
	while(it<n){
		// Casos especiales
		if (tempn==0||tempn==1||tempn==4){ 
			prueba = false;
		}
		for (int x=2; x<tempn/2; x++){
			if (tempn%x==0){ 
				prueba = false;
			}
		}
		if(prueba==false){
			tempn++;
		}
		// Si no se pudo dividir por ninguno de los de arriba, s� es primo
		if(prueba==true){
			prim[it]=tempn;
			tempn++;
			it++;
		}
		prueba=true;
	}
	
	//Mostrar vector
	for(int i=0; i<n; i++){
		cout<<prim[i]<<" ";
	}
	
	return 0;
}
*/

/*
3. Escribir un programa que visualice en pantalla los n�meros m�ltiplos de 5
comprendidos entre 1 y 100.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Proceso
	for(int i=0; i<=100; i+=5){
		cout<<i<<" ";
	}
	
	return 0;
}
*/

/*
4. Escriba un c�digo que solicite ingresar dos n�meros ?? y ??, tal que ?? < ??. Muestre
todos los n�meros primos que se encuentren entre el rango de valores, de no
encontrarse, mostrar el primo m�s cercano a ?? o ??.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria 1
	int it=0;
	int tempn;
	bool prueba = true;
	
	//Memoria 2
	int a, b;
	do{
		cout<<"Ingrese el primer n�mero (este debe ser menor que el siguiente n�mero): ";
		cin>>a;
		if(a<0){
			cout<<"Error, intentelo de nuevo";
		}
	} while(a<0);
	do{
		cout<<"Ingrese el segundo n�mero: ";
		cin>>b;
		if(a>=b||b<0){
			cout<<"Error, intentelo de nuevo";
		}
	} while(a>=b||b<0);
	int n=b-a;
	int* prim = new int[n];
	//Todos los elementos del vector seran 0
	for(int i=0; i<n; i++){
		prim[i]=0;
	}
	
	//Proceso de busqueda de primos
	tempn=a;
	for(int i=0; i<n; i++){
		// Casos especiales
		if (tempn==0||tempn==1||tempn==4){ 
			prueba=false;
		}
		for (int x=2; x<tempn/2; x++){
			if (tempn%x==0){ 
				prueba=false;
			}
		}
		if(prueba==false){
			tempn++;
		}
		// Si no se pudo dividir por ninguno de los de arriba, s� es primo
		if(prueba==true&&tempn>=a&&tempn<=b){
			prim[it]=tempn;
			tempn++;
			it++;
		}
		prueba=true;
	}
	
	//Mostrar vector
	for(int i=0; i<n; i++){
		if(prim[i]!=0){
			cout<<prim[i]<<" ";
		}
	}
	
	delete[] prim;
	
	return 0;
}
*/

/*
5. Elabore un programa que lea n n�meros y determine cu�l es el mayor, el menor y la
media de los n�meros le�dos.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria 1
	int n;
	cout<<"Ingrese la cantidad de n�meros que aceptar� este programa: ";
	cin>>n;
	int* vec = new int[n];
	for(int i=0; i<n; i++){
		cout<<"Ingrese un n�mero: ";
		cin>>vec[i];
	}
	
	//Memoria 2
	int max=vec[0];
	int min=vec[0];
	int med=0;
	
	//N�mero mayor
	for(int i=0; i<n; i++){
		if(max<vec[i]){
			max=vec[i];
		}
	}
	
	//N�mero menor
	for(int i=0; i<n; i++){
		if(min>vec[i]){
			min=vec[i];
		}
	}
	
	//La media de todos los n�meros
	for(int i=0; i<n; i++){
		med+=vec[i];
	}
	med=med/n;
	
	//Salida
	cout<<"El mayor n�mero de todos los n�meros es: "<<max<<endl;
	cout<<"El menor n�mero de todos los n�meros es: "<<min<<endl;
	cout<<"La media de todos los n�meros es: "<<med<<endl;
	
	delete[] vec;
	return 0;
}
*/

/*
6. Elabore un programa que calcule la serie de Fibonacci. La serie de Fibonacci es la
sucesi�n de n�meros: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... Cada n�mero se calcula sumando
los dos anteriores a �l.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int nveces,ant,sig,sum;
	ant=0;
	sig=1;
	
	//Fibonacci
	cout<<"Este programa genera la sucesi�n de Fibonacci." <<endl;
	cout<<"Cuantas nveces se generara la sucesi�n de Fibonacci: ";
	cin>>nveces;
	if(nveces==1){
		cout<<ant;
	}
	if(nveces>=2){
		cout<<ant<<", "<<sig;
	}
	for(int n=3;n<=nveces;n++){
		sum=ant+sig;
		cout<<", "<<sum;
		ant=sig;
		sig=sum;
	}
		
	cout<<endl;
	
	return 0;
}
*/

/*
7. Calcula el promedio de 3 notas para n estudiantes.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int a[3];
	int prom=0;
	
	//Promedio
	cout<<"Este programa calcula el promedio de 3 notas"<<endl;
	for(int i=0; i<3; i++){
		cout<<"Ingrese la nota: ";
		cin>>a[i];
		prom+=a[i];
	}
	prom=prom/3;
	
	//Salida
	cout<<"El promedio de las 3 notas es: "<<prom; 
	
	return 0;
}
*/

/*
8. Escribir un programa que genere la tabla de multiplicar de un n�mero introducido por
el teclado
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int n=0;
	
	//Ingreso de datos
	while(n<=0){
		cout<<"Ingrese el n�mero hasta donde se mostrara la tabla de multiplicar: ";
		cin>>n;
		if(n<=0){
			cout<<"Error vuelva a intentarlo"<<endl;
		}
	}
	cout<<endl;
	
	//Reservaci�n de memoria para la matriz m1
	int** m1 = new int* [n];
	for(int i=0; i<n; i++){
		m1[i] = new int [n];
	}
	
	//Lector de datos de la matriz m1
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			m1[i][j]=(i+1)*(j+1);
		}
	}
	cout<<endl;
	
	//Mostrar la interfaz horizontal superior
	cout<<"Tabla de multiplicaci�n del 1 hasta el "<<n<<endl;
	for(int i=0; i<=n; i++){
		if (i==0){
			cout<<"*\t|\t";
		}
		else{
			cout<<i<<"\t";
		}
	}
	cout<<endl;
	for(int i=0; i<=n+1; i++){
		cout<<"--------";
	}
	cout<<endl;
	
	//Mostrador de datos de la matriz m1 // Mostrar la interfaz vertical izquierda
	for(int i=0; i<n; i++){
		cout<<m1[i][0]<<"\t|\t";
		for(int j=0; j<n; j++){
			cout<<m1[i][j] << "\t";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//Liberaci�n de memoria para la matriz m1
	for(int i=0; i<n; i++){
		delete[] m1[i];
	}
	delete[] m1;
	
	return 0;
}
*/

/*
9. Escribir un programa que pida al usuario un n�mero entero y muestre por pantalla un
tri�ngulo rect�ngulo como el de m�s abajo, de altura el n�mero introducido.
*
**
***
****
*****
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int temp=1;
	int n;
	cout<<"Ingrese un n�mero entero: ";
	cin>>n;
	cout<<endl;
	if(n<0){
		n=n*-1;
	}
	
	//Tri�ngulo Rect�ngulo
	for(int i=0; i<n; i++){
		for(int j=0; j<temp; j++){
			cout<<"*";
		}
		temp++;
		cout<<endl;
	}
	
	return 0;
}
*/

/*
10. Escribir un programa que pida al usuario una palabra y luego muestre por pantalla
una a una las letras de la palabra introducida empezando por la �ltima.
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	//Memoria
	string palabra;
	cout<<"Ingrese una palabra: ";
	getline(cin,palabra);
	
	//Reverso
	cout<<"Esta seria la palabra invertida: ";
	for(int i=(palabra.size()-1); i>=0; i--){
		cout<<palabra[i];
	}
	
	return 0;
}
*/
