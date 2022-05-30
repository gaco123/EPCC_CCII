
/*
Generar una tabla de multiplicación hasta un n número.
*/

#include <iostream>
using namespace std;

int main(){
	//Memoria
	int n=0;
	
	//Ingreso de datos
	while(n<=0){
		cout<<"Ingrese el número hasta donde se mostrara la tabla de multiplicar: ";
		cin>>n;
		if(n<=0){
			cout<<"Error vuelva a intentarlo"<<endl;
		}
	}
	cout<<endl;
	
	//Reservación de memoria para la matriz m1
	int** m1 = new int* [n];
	for(int i=0; i<n; i++){
		m1[i] = new int [n];
	}
	
	//Genera los numeros de la tabla para la matriz m1
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			m1[i][j]=(i+1)*(j+1);
		}
	}
	
	//Mostrar la interfaz horizontal superior
	cout<<"Tabla de multiplicación del 1 hasta el "<<n<<endl;
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
	
	//Liberación de memoria para la matriz m1
	for(int i=0; i<n; i++){
		delete[] m1[i];
	}
	delete[] m1;
	
	return 0;
}

