
/*
• Escriba un programa para convertir un número decimal a
binario.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> binary(int a){
	static vector<int> vectorx{};
	vectorx.push_back(a%2);
	if(a/2==1){
		static vector<int> vectory;
		vectory.push_back(1);
		for(auto i=vectorx.end()-1; i!=vectorx.begin()-1; i--){
			vectory.push_back(*i);
		}
		return vectory;
	}
	else if(a/2==0){
		static vector<int> vectory;
		vectory.push_back(0);
		for(auto i=vectorx.end()-1; i!=vectorx.begin()-1; i--){
			vectory.push_back(*i);
		}
		return vectory;
	}

	return binary(a/2);
}

int main(){
	int num1;
	cout<<"Ingrese un número en base decimal: ";
	cin>>num1;
	
	vector<int> bi = binary(num1);
	cout<<"El número ingresado en binario es: ";
	for(auto i=bi.begin(); i!=bi.end(); i++){
		cout<<*i;
	}
	
	return 0;
}

