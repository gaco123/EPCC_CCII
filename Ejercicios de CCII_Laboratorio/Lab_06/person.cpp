#include "person.h"

person::person(string _name, string _bird, string _now){
	name=_name;
	bird=_bird;
	now=_now;
}
person::~person(){
}
void person::let_dateOB(string _bird){
	bird=_bird;
}
void person::let_dateON(string _now){
	now=_now;
}
void person::show_Name(){
	cout<<"El nombre de la persona es: "<<name;
}
void person::actual_Age(){
	string temp;
	string actual;
	//Fecha de Nacimiento
	int yx;
	int mx;
	int dx;
	
	//Fecha Actual
	int yy;
	int my;
	int dy;
	
	//Edad Actual
	int yz=0;
	int mz=1;
	int dz=1;
	
	//Separación Nacimiento
	temp=bird.substr(0, 4);
	yx=stoi(temp);
	temp=bird.substr(5, 2);
	mx=stoi(temp);
	temp=bird.substr(8, 2);
	dx=stoi(temp);
	
	//Separación Fecha Actual
	temp=now.substr(0, 4);
	yy=stoi(temp);
	temp=now.substr(5, 2);
	my=stoi(temp);
	temp=now.substr(8, 2);
	dy=stoi(temp);
	
	//Calculo de Edad Actual en años, meses y días
	while((yx<yy)||(mx<my)||(dx<dy)){
		dx++;
		if(mx==1&&dx==32){
			mx++;
			dx=1;
		}
		if(mx==2&&dx==30){
			mx++;
			dx=1;
		}
		if(mx==2&&dx==29){
			mx++;
			dx=1;
			if(yx%4==0){
				mx--;
				dx=29;
			}
		}
		if(mx==3&&dx==32){
			mx++;
			dx=1;
		}
		if(mx==4&&dx==31){
			mx++;
			dx=1;
		}
		if(mx==5&&dx==32){
			mx++;
			dx=1;
		}
		if(mx==6&&dx==31){
			mx++;
			dx=1;
		}
		if(mx==7&&dx==32){
			mx++;
			dx=1;
		}
		if(mx==8&&dx==32){
			mx++;
			dx=1;
		}
		if(mx==9&&dx==31){
			mx++;
			dx=1;
		}
		if(mx==10&&dx==32){
			mx++;
			dx=1;
		}
		if(mx==11&&dx==31){
			mx++;
			dx=1;
		}
		if(mx==12&&dx==32){
			mx=1;
			dx=1;
			yx++;
		}
		dz++;
		if(mz==1&&dz==32){
			mz++;
			dz=1;
		}
		if(mz==2&&dz==30){
			mz++;
			dz=1;
		}
		if(mz==2&&dz==29){
			mz++;
			dz=1;
			if(yz%4==0){
				mz--;
				dz=29;
			}
		}
		if(mz==3&&dz==32){
			mz++;
			dz=1;
		}
		if(mz==4&&dz==31){
			mz++;
			dz=1;
		}
		if(mz==5&&dz==32){
			mz++;
			dz=1;
		}
		if(mz==6&&dz==31){
			mz++;
			dz=1;
		}
		if(mz==7&&dz==32){
			mz++;
			dz=1;
		}
		if(mz==8&&dz==32){
			mz++;
			dz=1;
		}
		if(mz==9&&dz==31){
			mz++;
			dz=1;
		}
		if(mz==10&&dz==32){
			mz++;
			dz=1;
		}
		if(mz==11&&dz==31){
			mz++;
			dz=1;
		}
		if(mz==12&&dz==32){
			mz=1;
			dz=1;
			yz++;
		}
	}
	
	//Transforma ints a string
	temp=to_string(yz);
	actual=temp;
	temp=to_string(mz);
	actual+="-";
	actual+=temp;
	temp=to_string(dz);
	actual+="-";
	actual+=temp;
	
	//Edad actual
	cout<<"Su edad actual seria (formato Y-M-D): "<<actual;
}
