#include "rectangle.h"

rectangle::rectangle(double _height, double _wide){
	height=abs(_height);
	wide=abs(_wide);
}
rectangle::~rectangle(){
}
void rectangle::height_Value(double _height){
	height=abs(_height);
}
void rectangle::wide_Value(double _wide){
	wide=abs(_wide);
}
void rectangle::Area(){
	double area = height * wide;
	cout<<"El area del rectangulo es: "<<area<<"\n";
}
void rectangle::Perimeter(){
	double perimeter = (2*height) + (2*wide);
	cout<<"El perimetro del rectangulo es: "<<perimeter<<"\n";
}
