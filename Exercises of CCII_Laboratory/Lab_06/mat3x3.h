#ifndef MAT3X3_H
#define MAT3X3_H
#include <iostream>
#include <ctime>
using namespace std;

class mat3x3 {
public:
	bool verifi_Random(int*,int,int&);
	mat3x3();
	~mat3x3();
	void show_Mat();
	void search_Val(int);
private:
	int mat[3][3];
};

#endif

