#ifndef ARRAY5V_H
#define ARRAY5V_H
#include <iostream>
using namespace std;

class array5v {
public:
	array5v();
	~array5v();
	bool if_Space();
	bool somethingTo_Remove();
	void new_Element(int);
	void remove_Element(int);
	void show_Array();
private:
	int** arr5;
	int p_it=0;
};

#endif

