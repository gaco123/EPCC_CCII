#include "mat3x3.h"

bool mat3x3::verifi_Random(int* vec, int n, int &it){
	for(int i=0; i<9; i++){
		if(n==vec[i]){
			return false;
		}
	}
	vec[it]=n;
	it++;
	return true;
}
mat3x3::mat3x3(){
	int* vec=new int[9];
	fill(vec,vec+9,0);
	int it=0;
	
	srand(time(NULL));
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int n = rand() % 9 + 1; 
			if(verifi_Random(vec,n,it)==true){
				mat[i][j]=n;
			}
			else{
				j--;
			}
		}
	}
	delete[] vec;
}
mat3x3::~mat3x3(){
}
void mat3x3::show_Mat(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
void mat3x3::search_Val(int val){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(mat[i][j]==val){
				cout<<"Se encontro el valor de \""<<val<<"\" en la fila \""<<i<<"\" y columna \""<<j<<"\".";
			}
		}
	}
}
