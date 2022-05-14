
/*
• La criba (sieve) de Eratóstenes es un algoritmo para
encontrar todos los números primos hasta cualquier límite
dado. 
• Escriba una función sieve que tome un parámetro entero, n,
y devuelva un vector de bools que indique, para cada
número de 0 a n - 1, si el número es primo.
*/

#include <iostream>
using namespace std;

bool* bus_Sieve(int n){
	//Vector principal donde se guardan todos los numero de 2 hasta n
	int* v1 = new int[n-1];
	for(int i=0; i<n-1; i++){
		v1[i]=i+2;
	}
	cout<<"TODOS LOS NUMEROS DESDE EL 2 HASTA EL "<<n<<"\n";
	for(int i=0; i<n-1; i++){
		cout<<v1[i]<<" ";
	}
	cout<<"\n";
	//Vector temporal para agregar los primos encontrados
	int* v2 = new int[(n-1)/2];
	int j = 1;
	v2[0]=v1[0];
	//Vector booleano para saber si un numero de v1 es primo o no
	bool* v3 = new bool[n-1];
	
	//Sieva de Erastosthenes
	bool prueba{};
	for(int i=1; i<n-1; i++){
		//Encontrar si v1[i] es divisible entre algún numero primo de v2
		prueba=true;
		for(int i1=0; i1<j; i1++){
			if(v1[i]%v2[i1]==0){
				prueba=false;
				break;
			}
		}
		//Realizar la operación de agregar v1[i] a v2[j] si es primo
		if(prueba==true){
			v2[j]=v1[i];
			j++;
		}
		//Agregar el valor de true o false a v3 para cada número de v1
		v3[i]=prueba;//Si es false el número no es primo y si es true el número es primo (esto es para el vector bool)
	}
	
	//Eliminar todos los vectores dinamicos creados
	delete[] v1;
	delete[] v2;
	
	return v3;
}

int main(){
	int n; 
	cout<<"Ingrese hasta que número se evaluara si hay primos (a partir del 2): ";
	cin>>n;

	bool* v3=bus_Sieve(n);
	
	cout<<"TODOS LOS NUMEROS PRIMOS DESDE EL 2 HASTA EL "<<n<<"\n";
	for(int i=0; i<n-1; i++){
		if(v3[i]==true){
			cout<<i+2<<" ";
		}
	}
	cout<<"\n";
	
	return 0;
}

