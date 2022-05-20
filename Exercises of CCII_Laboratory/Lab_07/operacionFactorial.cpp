#include "operacionFactorial.h"

operacionFactorial::operacionFactorial(){
}
operacionFactorial::~operacionFactorial(){
}
int operacionFactorial::devolverFactorial(){
	int temp=1;
	for(int i=getOperador(); i>1; i--){
		temp=temp*i;
	}
	return temp;
}


