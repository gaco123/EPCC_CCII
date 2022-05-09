
/*
Exercise 2. convertSeconds.cpp

• Write a program that converts a total number of
seconds to hours, minutes, and seconds. 
• It should (1) prompt the user for input, 
(2) read an integer from the keyboard, 
(3) calculate the result, and
(4) use std::cout to display the output. 
Enter the number of seconds to convert: 5000
	5000 seconds = 1 hours, 23 minutes, and 20 seconds
*/
#include <iostream>
using namespace std;

int main() {
	//Memory
	int seconds;
	int th=0;
	int tm=0;
	int ts=0;
	
	//Get a value for seconds
	cout<<"Enter the number of seconds to convert: ";
	cin>>seconds;
	
	//Calculate the result
	for(int i=0; i<seconds; i++){
		ts++;
		if(ts==60){
			ts=0;
			tm++;
		}
		if(tm==60){
			tm=0;
			th++;
		}
	}
	
	//Print the result
	cout<<seconds<<" seconds = "<<th<<" hours, "<<tm<<" minutes, and "<<ts<<" seconds";
	
	return 0;
}

