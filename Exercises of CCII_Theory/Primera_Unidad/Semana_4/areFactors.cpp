
/*
• Escriba una función areFactors que tome un entero n y un
vector de enteros, y devuelva true si los números en el
vector son todos factores de n (lo que significa que n es
divisible por todos ellos).
*/

#include <iostream>
using namespace std;

bool areFactors(int n, int ve[4]){
	bool prueba = true;
	for(int i=0; i<4; i++){
		if(n%ve[i]!=0){
			prueba=false;
			break;
		}
	}
	
	return prueba;
}

int main(){
	//numero a revisar
	int n=10;
	//vector de factores de n
	int ve[4]={1,2,5,10};
	areFactors(n,ve);
	//mensajes para saber si es true o false
	if(areFactors(n,ve)==true){
		cout<<"Todos los números del vector \"ve\" SI son factores de n.";
	}
	else{
		cout<<"Uno o varios de los números del vector \"ve\" NO son factores de n.";
	}
	
	return 0;
}

