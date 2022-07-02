
/*
• Your job is to write a program that reads integers from
the standard input, sorts them into ascending order, and
then prints the sorted numbers, one per line.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	//Memoria
	int n=0;
	int ntemp;
	vector<int> vectorx;
	
	//Ingreso del tamaño del vectorx
	while(n<=0 && n!=1){
		cout<<"Ingrese la cantidad de números que tendrá su secuencia: ";
		cin>>n;
	}
	cout<<endl;
	
	//Ingreaso de los números en el vectorx
	for(int i=0; i<n; i++){
		cout<<"Ingrese un número: ";
		cin>>ntemp;
		vectorx.push_back(ntemp);
	}
	cout<<endl;
	
	//Mostrar el vectorx
	cout<<"Vectorx (sin ordenar)"<<endl;
	for(int i=0; i<n; i++){
		cout<<vectorx.at(i)<<endl;
	}
	cout<<endl;
	
	//Ordenamiento de los datos
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(vectorx.at(j)>vectorx.at(j+1)){
				ntemp=vectorx.at(j);
				vectorx.at(j)=vectorx.at(j+1);
				vectorx.at(j+1)=ntemp;
			}
		}
	}
	
	//Mostrar el vectorx 2da vez
	cout<<"Vectorx (ordenado)"<<endl;
	for(int i=0; i<n; i++){
		cout<<vectorx.at(i)<<endl;
	}
	cout<<endl;
	
	return 0;
}

