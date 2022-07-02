
/*
Producto m�ximo de dos n�meros en una secuencia
� Dada una secuencia de n n�meros no negativos y mayores que cero. 
� El objetivo es encontrar el mayor n�mero que se pueda obtener multiplicando dos n�meros de esta secuencia. 
� Usando un bucle for para esto.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	//Memoria
	int n=0;
	int ntemp;
	int maxp;
	vector<int> vectorx;
	
	//Ingreso del tama�o del vectorx
	while(n<=0 || n==1){
		cout<<"Ingrese la cantidad de n�meros que tendr� su secuencia: ";
		cin>>n;
		if(n<=0 || n==1){
			cout<<"Error vuelva a intentarlo"<<endl;
		}
	}
	cout<<endl;
	
	//Ingreso de los n�meros en el vectorx
	for(int i=0; i<n; i++){
		cout<<"Ingrese un n�mero positivo y mayor que cero: ";
		cin>>ntemp;
		if(ntemp<=0){
			cout<<"Error vuelva a intentarlo"<<endl;
			i--;
		}
		else{
			vectorx.push_back(ntemp);
		}
	}
	cout<<endl;
	
	//Mostrar vectorx(secuencia)
	for(int i=0; i<n; i++){
		cout<<vectorx.at(i)<<" ";
	}
	cout<<endl;
	
	//M�ximo producto
	int mpa=vectorx.at(0);
	int mpb=vectorx.at(1);
	int temp;
	for(int i=0; i<n; i++){
		if(vectorx.at(i)>mpa){
			temp=mpa;
			mpa=vectorx.at(i);
		}
		if(i<n-1&&vectorx.at(i+1)>mpb){
			mpb=vectorx.at(i+1);
		}
		if(mpa==mpb){
			mpa=vectorx.at(i);
			if(mpa==mpb){
				mpa=temp;
			}
		}
	}

	maxp = mpa*mpb;
	cout<<"El m�ximo producto de la anterior secuencia es: "<<maxp;
	
	return 0;
}

