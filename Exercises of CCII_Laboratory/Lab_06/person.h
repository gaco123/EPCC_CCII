#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class person{
public:
	person(string,string,string);
	~person();
	void let_dateOB(string);
	void let_dateON(string);
	void show_Name();
	void actual_Age();
private:
	string name;
	string bird;
	string now;
};

#endif

