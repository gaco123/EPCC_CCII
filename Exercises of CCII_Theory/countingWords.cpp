
/*
Exercise 4. countingWords.cpp

• Your task is to write a program that reads words and
counts the frequency of each unique word. 
• A word is a string of nonspace characters separated by
white space.
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	//Memory
	
	map<string, int> counts{};
	string word{};
	
	//Input
	cout<<"PROGRAM TO CALCULATE THE FREQUENCY OF EACH WORD ON THE \"MAP\"\n";
	cout<<"(To end the entry of words, press CTRL+Z and then ENTER)\n";
	do{
		cout<<"Enter any word: ";
		++counts[word];
	}while(cin>>word);
	cout<<"\n";
	
	//Frequency
	cout<<"TABLE OF FREQUENCY OF EACH WORD\n";
	for(auto i=counts.begin(); i!=counts.end(); i++){
		if(i->first!=""){
			cout<<i->first<<" => "<<i->second<<"\n";
		}
	}
	
	return 0;
}

