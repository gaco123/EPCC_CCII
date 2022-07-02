
/*
6. diamante.cpp
	El programa diamante toma como entrada una letra y la muestra en forma
	de diamante. Dada una letra, imprime un diamante que comienza con 'A',
	con la letra proporcionada en el punto más ancho.
	Requisitos
	* La primera fila contiene una 'A'.
	* La última fila contiene una 'A'.
	* Todas las filas, excepto la primera y la última, tienen exactamente dos
	letras idénticas.
	* Todas las filas tienen tantos espacios finales como espacios iniciales. (Esto podría ser 0).
	* El diamante es simétrico horizontalmente.
	* El diamante es verticalmente simétrico.
	* El diamante tiene una forma cuadrada (el ancho es igual a la altura).
	* Las letras forman una forma de diamante.
	* La mitad superior tiene las letras en orden ascendente.
	* La mitad inferior tiene las letras en orden descendente.
	* Las cuatro esquinas (que contienen los espacios) son triángulos.
	En los ejemplos, los espacios se indican mediante ·.
	Diamante para la letra 'A':
		A
	Diamante para la letra 'C':
		··A··
		·B·B·
		C···C
		·B·B·
		··A··
	Diamante para la letra 'E':
		····A····
		···B·B···
		··C···C··
		·D·····D·
		E·······E
		·D·····D·
		··C···C··
		···B·B···
		····A····
	Utilice la cabecera <sstream> para crear el diamante, luego utilice una
	función adicional para mostrar el diamante.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

stringstream diamante(string letra, vector<string>& abc){
	stringstream diamante;
	int n=0;
	//Buscamos la posición donde está
	for(auto i=abc.begin(); i!=abc.end(); i++){
		if(letra!=*i){
			n++;
		}
		else{
			break;
		}
	}
	//Primera Fila del Diamante
	string afuera;
	auto it=abc.begin();
	for(int i=0; i<n; i++){
		afuera+="·";
	}
	diamante<<afuera<<*it<<afuera<<"\n";
	it++;
	//Parte de Arriba del diamante
	string dentro="·";
	for(int i=1; i<=n; i++){
		afuera.clear();
		for(int j=0; j<n-i; j++){
			afuera+="·";
		}
		diamante<<afuera<<*it<<dentro<<*it<<afuera<<"\n";
		it++;
		dentro+="··";
	}
	//Resetear valores antes usados
	dentro.pop_back();
	dentro.pop_back();
	it--;
	it--;
	//Parte de Abajo del diamante
	for(int i=1; i<n; i++){
		afuera.clear();
		dentro.pop_back();
		dentro.pop_back();
		for(int j=0; j<i; j++){
			afuera+="·";
		}
		diamante<<afuera<<*it<<dentro<<*it<<afuera<<"\n";
		it--;
	}
	//Ultima fila del diamante
	afuera.clear();
	for(int i=0; i<n; i++){
		afuera+="·";
	}
	diamante<<afuera<<*it<<afuera<<"\n";
	
	return diamante;

}
void imp(stringstream& temp){
	//Imprimir Diamante
	string imp=temp.str();
	for(int i=0; i<imp.length(); i++){
		cout<<imp[i];
	}
}

int main(int argc, char *argv[]) {
	//Memoria
	vector<string> abc;
	stringstream ss;
	//Abecedario
	for(char i='A'; i<='Z'; i++){
		ss<<i;
		abc.push_back(ss.str());
		ss.str("");
		ss.clear();
	}
	//Diamante
	cout<<"DIAMANTE\n";
	stringstream temp;
	temp=diamante("E",abc);
	imp(temp);
	
	return 0;
}

