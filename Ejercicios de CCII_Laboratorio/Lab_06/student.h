#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class student {
public:
	student(int,string,float,float,float);
	~student();
	void p_CUI();
	void pf_name();
	void p_average_score();
	
private:
	int CUI;
	string full_name;
	float score1;
	float score2;
	float score3;
};

#endif

