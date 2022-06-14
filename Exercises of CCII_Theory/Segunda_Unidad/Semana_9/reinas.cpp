
/*
7. reinas.cpp
	Dada la posición de dos reinas en un tablero de ajedrez, indicar si están o no
	colocadas de modo que puedan atacarse entre sí.
	En el juego de ajedrez, una reina puede atacar piezas que están en la misma
	fila, columna o diagonal.
	Un tablero de ajedrez se puede representar mediante una matriz de 8 por 8.
	Utilice vector de vectores para implementar la matriz.
	Entonces, si le dicen que la reina blanca está en (2, 3) y la reina negra en (5,6), 
	entonces sabrá que tiene una configuración como esta:
	_ _ _ _ _ _ _ _
	_ _ _ _ _ _ _ _
	_ _ _ B _ _ _ _
	_ _ _ _ _ _ _ _
	_ _ _ _ _ _ _ _
	_ _ _ _ _ _ N _
	_ _ _ _ _ _ _ _
	_ _ _ _ _ _ _ _
	
	Debe responder si las reinas pueden atacarse entre sí. En este ejemplo, la
	respuesta es sí, porque ambas piezas comparten una diagonal.
*/

#include <iostream>
#include <vector>
using namespace std;

void imp_Tablero(vector<vector<string>>& tablero){
	for(auto i=tablero.begin(); i!=tablero.end(); i++){
		for(auto j=i->begin(); j!=i->end(); j++){
			cout<<*j<<" ";
		}
		cout<<endl;
	}
}
bool comp_Tablero(vector<vector<string>>& tablero){
	//Diagonal principal
	int itc;
	int itf;
	
	itf=0;
	for(auto i=tablero.begin(); i!=tablero.end(); i++){
		itc=0;//N-Columna dentro de la matriz
		for(auto j=i->begin(); j!=i->end(); j++){
			if(*j!="-"){
				//Comprabación en su misma fila
				for(auto k=i->begin(); k!=i->end(); k++){
					if(*k!="-"&&*j!=*k){
						cout<<"La reina "<<*j<<" puede atacar a la reina "<<*k<<endl;
						return false;
					}
				}
				//Comprobación en su misma columna
				for(auto k=tablero.begin(); k!=tablero.end(); k++){
					if(*(k->begin()+itc)!="-"&&*j!=*(k->begin()+itc)){
						cout<<"La reina "<<*j<<" puede atacar a la reina "<<*(k->begin()+itc)<<endl;
						return false;
					}
				}
				//Comprobación diagonal principal
				//Fila Inicial y Columna Inicial 
				int tempi=itf;
				int tempj=itc;
				while(tempi>0&&tempj>0){
					tempi--;
					tempj--;
				}
				//Verificar
				auto tempis=tablero.begin()+tempi;
				auto tempjs=tempis->begin()+tempj;
				int tempint=tempj;
				while(tempis!=tablero.end()&&tempjs!=tempis->end()){
					if(*tempjs!="-"&&*j!=*tempjs){
						cout<<"La reina "<<*j<<" puede atacar a la reina "<<*tempjs;
						return false;
					}
					tempis++;
					tempint++;
					tempjs=tempis->begin()+tempint;
				}
				//Comprobación diagonal secundaria
				//Fila Inicial y Columna Inicial 
				tempi=itf;
				tempj=itc;
				while(tempi>0&&tempj<i->size()){
					tempi--;
					tempj++;
				}
				//Verificar
				tempis=tablero.begin()+tempi;
				tempjs=tempis->begin()+tempj;
				tempint=tempj;
				while(tempis!=tablero.end()&&tempjs!=tempis->begin()-1){
					if(*tempjs!="-"&&*j!=*tempjs){
						cout<<"La reina "<<*j<<" puede atacar a la reina "<<*tempjs;
						return false;
					}
					tempis++;
					tempint--;
					tempjs=tempis->begin()+tempint;
				}
			}
			itc++;
		}
		itf++;
	}
	return true;
}
	
	
int main(int argc, char *argv[]) {
	vector<vector<string>> tablero;
	tablero = {{"-","-","-","-","-","-","-","-"},
			   {"-","-","-","-","-","-","-","-"},
			   {"-","-","-","B","-","-","-","-"},
			   {"-","-","-","-","-","-","-","-"},
			   {"-","-","-","-","-","-","-","-"},
			   {"-","-","-","-","-","-","N","-"},
			   {"-","-","-","-","-","-","-","-"},
			   {"-","-","-","-","-","-","-","-"}};
	
	imp_Tablero(tablero);
	comp_Tablero(tablero);
	
	return 0;
}
