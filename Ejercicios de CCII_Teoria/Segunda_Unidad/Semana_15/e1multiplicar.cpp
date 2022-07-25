
//Alumno: Gabriel Fernando Rodriguez Cutimbo
/*
1. e1multiplicar.cpp.
   *Implemente una función que reciba dos parámetros, una matriz "x" y un
	valor, que multiplique los elementos de dicha matriz por ese valor.
	
	int x[3][4][2] = {{{1, 2}, {4, 5}, {7, 8}, {1, 2}},
					  {{10, 11}, {13, 14}, {16, 17}, {1, 2}},
					  {{19, 20}, {22, 23}, {25, 26}, {1, 2}}};

   *La implementación debe funcionar para cualquier tamaño de matriz
	tridimensional.

   *La implementación debe deducir el tamaño para cada dimensión.
	
   *Forma de llamar a la función multiplicar(x, 4); significa que cada
	elemento de la matriz se multiplicará por 4.

   *Implemente además una función para imprimir la matriz tridimensional.
*/

#include <iostream>
#include <vector>
using namespace std;

void mat_Multi(vector<vector<vector<int>>>& x, int*& ptr){
	for(int i=0; i<x.size(); i++){
		for(int j=0; j<x[0].size(); j++){
			for(int k=0; k<x[0][0].size(); k++){
				x[i][j][k]=x[i][j][k]*(*ptr);
			}
		}
	}
}
void print_Mat(vector<vector<vector<int>>>& x){
	cout<<"{";
	for(int i=0; i<x.size(); i++){
		cout<<"{";
		for(int j=0; j<x[0].size(); j++){
			cout<<"{";
			for(int k=0; k<x[0][0].size(); k++){
				cout<<x[i][j][k];
				if(k!=x[0][0].size()-1){
					cout<<",";
				}
			}
			if(j==x[0].size()-1){
				cout<<"}";
			}
			else{
				cout<<"},";
			}
		}
		if(i==x.size()-1){
			cout<<"}";
		}
		else{
			cout<<"},";
			if(i!=x.size()-1){
				cout<<endl;
			}
		}
	}
	cout<<"}"<<endl<<endl;
}
	
int main() {
	vector<vector<vector<int>>> x =	{{{1,2},{3,4},{5,6}},
									 {{7,8},{9,10},{11,12}},
									 {{13,14},{15,16},{17,18}},
									 {{19,20},{21,22},{23,24}}};
	cout<<"MATRIZ ORIGINAL\n";
	print_Mat(x);
	int* ptr = new int;
	*ptr = 3;
	mat_Multi(x,ptr);
	cout<<"MATRIZ TRIPLICADA\n";
	print_Mat(x);
	delete ptr;
	
	return 0;
}

