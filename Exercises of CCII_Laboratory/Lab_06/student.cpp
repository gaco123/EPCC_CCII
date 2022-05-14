#include "student.h"

student::student(int _CUI, string _full_name, float _score1, float _score2, float _score3) {
	CUI=_CUI;
	full_name=_full_name;
	score1=abs(_score1);
	score2=abs(_score2);
	score3=abs(_score3);
}
student::~student(){
}
void student::p_CUI(){
	cout<<"El CUI del estudiante es: "<<CUI<<"\n";
}
void student::pf_name(){
	cout<<"El nombre del estudiante es: "<<full_name<<"\n";
}
void student::p_average_score(){
	float temp=(score1+score2+score3)/3;
	cout<<"La nota promedio del estudiante es: "<<temp<<"\n";
	if(temp>=10.5){
		cout<<"El estudiante SI ha aprobado Ciencias de la Computacion II\n";
	}
	else{
		cout<<"El estudiante NO ha aprobado Ciencias de la Computacion II\n";
	}
}
