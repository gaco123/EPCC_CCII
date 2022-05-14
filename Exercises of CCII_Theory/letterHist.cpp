
/*
Ejercicio
• Escriba una función letterHist que tome un string como
parámetro y devuelva un histograma de las letras del string. 
• El elemento cero del histograma debe contener el número
de aes (plural de a) en el string (mayúsculas y minúsculas)
• El elemento 25 debe contener el número de zetas.
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
void listHist(map<string,int> &counts, string word){
	string temp;
	for(int i=0; i<word.length(); i++){
		word[i]=tolower(word[i]);
		temp=word[i];
		if(temp!=" "){
			++counts[temp];
		}
	}
	cout<<"\n";
	cout<<"*****  "<<word<<"  *****"<<"\n\n";
}

int main() {
	//Memory
	map<string, int> counts{};
	string word;
	
	//Input
	cout<<"PROGRAM TO CALCULATE THE FREQUENCY OF EACH LETTER ON A WORD\n";
	cout<<"Enter any word: ";
	getline(cin,word);
	
	listHist(counts,word);
	
	//Frequency
	cout<<"TABLE OF FREQUENCY OF EACH LETTER\n";
	for(auto i=counts.begin(); i!=counts.end(); i++){
		if(i->first!=""){
			cout<<i->first<<" => ";
			for(int j=0; j<i->second; j++){
				cout<<"*";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}

