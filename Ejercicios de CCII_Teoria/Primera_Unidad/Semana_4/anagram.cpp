
/*
Ejercicio
• Dos palabras son anagramas si contienen las mismas
letras y el mismo número de cada letra. 
• Por ejemplo, stop es un anagrama de pots, Alan Smithee
es un anagrama de The alias men
• Escriba una función anagram que tome dos strings y
verifique si son anagramas entre sí.
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
void anagram(map<string,int> &counts1, map<string,int> &counts2, string word1, string word2){
	string temp;
	for(int i=0; i<word1.length(); i++){
		word1[i]=tolower(word1[i]);
		temp=word1[i];
		if(temp!=" "){
			++counts1[temp];
		}
	}
	for(int i=0; i<word2.length(); i++){
		word2[i]=tolower(word2[i]);
		temp=word2[i];
		if(temp!=" "){
			++counts2[temp];
		}
	}
	cout<<"\n";
	cout<<"*****  "<<word1<<"  *****"<<"\n";
	cout<<"*****  "<<word2<<"  *****"<<"\n";
	if(counts1==counts2){
		cout<<"Ambas palabras SI son anagramas entre sí\n\n";
	}
	else{
		cout<<"Ambas palabras NO son anagramas entre sí\n\n";
	}
}
	
int main(){
	//Memory
	map<string, int> counts1{};
	map<string, int> counts2{};
	string word1;
	string word2;
		
	//Input
	cout<<"PROGRAM TO CALCULATE THE FREQUENCY OF EACH LETTER ON A WORD\n";
	cout<<"Enter word1: ";
	getline(cin,word1);
	cout<<"Enter word2: ";
	getline(cin,word2);
		
	anagram(counts1,counts2,word1,word2);
		
	//Frequency-1
	cout<<"TABLE OF FREQUENCY OF EACH LETTER ON A WORD1\n";
	for(auto i=counts1.begin(); i!=counts1.end(); i++){
		if(i->first!=""){
			cout<<i->first<<" => ";
			for(int j=0; j<i->second; j++){
				cout<<"*";
			}
			cout<<"\n";
		}
	}
	//Frequency-2
	cout<<"TABLE OF FREQUENCY OF EACH LETTER ON A WORD2\n";
	for(auto i=counts2.begin(); i!=counts2.end(); i++){
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

