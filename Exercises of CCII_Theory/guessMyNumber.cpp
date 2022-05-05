
/*
Exercise 3. guessMyNumber.cpp

• The goal of this exercise is to program a Guess My Number game. When it’s finished, it should work like this:

	I'm thinking of a number between 1 and 100 (including both). Can you guess what it is?
	Type a number: 45
	Your guess is: 45
	The number I was thinking of is: 14
	You were off by: 31

• To choose a random number, use the random library of C++
<random> https://en.cppreference.com/w/cpp/numeric/random
*/
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

int main (){
	
	//Memory
	int num;
	int entry;
	int diff;
	
	//Seed(it use the actual time of system) and random engine
	unsigned seed =	chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	
	//Determine range of random engine between 1 and 100
	uniform_int_distribution<int> range(1, 100);
	
	//Finally, get a pseudo aleatory number
	num= range(generator);
	
	//Text
	cout<<"I\'m thinking of a number between 1 and 100 (including both). Can you guess what it is?\n";
	cout<<"Type a number: ";
	cin>>entry;
	cout<<"Your guess is: "<<entry<<"\n";
	cout<<"The number I was thinking of is: "<<num<<"\n";
	cout<<"You were off by: ";
	
	//You were off by (calculate)
	if(entry<=num){
		diff=num-entry;
	}
	else if(entry>num){
		diff=entry-num;
	}
	
	//You were off by
	cout<<diff;
	
	return 0;
}
