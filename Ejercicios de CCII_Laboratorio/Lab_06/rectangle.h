#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <cmath>
using namespace std;

class rectangle{
public:
	rectangle(double,double);
	~rectangle();
	void height_Value(double);
	void wide_Value(double);
	void Area();
	void Perimeter();
private:
	double height;
	double wide;
};

#endif

