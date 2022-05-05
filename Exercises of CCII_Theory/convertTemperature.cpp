
/*
Exercise 1. convertTemperature.cpp

• Write a program that converts a temperature from Celsius
to Fahrenheit. 

• It should (1) prompt the user for input, 
(2) read a double value from the keyboard, 
(3) calculate the result, 
and (4) format the output to one decimal place. When it’s finished,
it should work like this:
	Enter a temperature in Celsius: 24
	24.0 C = 75.2 F

• Formula to do the conversion:
	F = C × 9 / 5 + 32
*/
#include <iostream>
using namespace std;

int main() {
	//Memory
	double celsius;
	double farenheit;
	
	//Get a value for celsius
	cout<<"Enter a temperature in Celsius: ";
	cin>>celsius;
	
	//Convert celsius to farenheit
	farenheit=celsius*9/5+32;
	
	//Print farenheit in the console (only one decimal)
	cout.precision(1);
	cout<<fixed<<celsius<<" C = "<<fixed<<farenheit<<" F";
	
	return 0;
}

