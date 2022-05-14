
/*
� Escriba una funci�n arePrimeFactors que tome un n�mero
entero n y un vector de n�meros enteros, que devuelva true
si los n�meros en el vector son todos primos y su producto
es n.
*/
#include <iostream>
#include <vector>
using namespace std;

bool arePrimeFactors(vector<int> vectorx, int n){
	bool prueba = true;
	int temp=1;
	for(int i=0; i!=vectorx.size(); i++){
		//Casos especiales
		if (vectorx[i]==0||vectorx[i]==1||vectorx[i]==4){ 
			prueba=false;
		}
		for (int x=2; x<vectorx[i]/2; x++){
			if (vectorx[i]%x==0){ 
				prueba=false;
			}
		}
		//Si no se pudo dividir por ninguno de los de arriba, s� es primo
		if(prueba==false){
			cout<<"En el vector \"vectorx\" uno o varios n�meros NO son primos.\n";
			break;
		}
		prueba=true;
	}
	//Verificar si el producto de todos los numeros del vector es n
	if(prueba==true){
		cout<<"En el vector \"vectorx\" todos los n�meros SI son primos.\n";
		for(int x=0; x!=vectorx.size(); x++){
			temp=temp*vectorx[x];
		}
		if(temp==n){
			cout<<"El producto de todos los elementos del vector = \""<<temp<<"\" SI es igual a el n�mero n = \""<<n<<"\"\n";
		}
		else{
			cout<<"El producto de todos los elementos del vector = \""<<temp<<"\"  NO es igual a el n�mero n = \""<<n<<"\"\n";
		}
	}
	
	return prueba;
	
}

int main(){
	int n=42;
	vector<int> vectorx{2,3,7};
	arePrimeFactors(vectorx,n);
	
	return 0;
}

