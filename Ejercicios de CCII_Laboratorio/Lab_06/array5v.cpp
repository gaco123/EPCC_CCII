#include "array5v.h"

array5v::array5v(){
	arr5=new int* [5];
	for(int i=0; i<5; i++){
		arr5[i]=NULL;
	}
}
array5v::~array5v(){
	for(int i=0; i<5; i++){
		delete arr5[i];
	}
	delete[] arr5;
}
bool array5v::if_Space(){
	if(p_it==5){
		return false;
	}
	return true;
}
bool array5v::somethingTo_Remove(){
	bool* barr5=new bool [5];
	for(int i=0; i<5; i++){
		if(arr5[i]==NULL){
			barr5[i]=false;
		}
		else{
			barr5[i]=true;
		}
	}
	for(int i=0; i<5; i++){
		if(barr5[i]==true){
			delete[] barr5;
			return true;
		}
	}
	delete[] barr5;
	return false;
}
void array5v::new_Element(int a){
	if(if_Space()==true){
		arr5[p_it]=new int(a);
		cout<<"Se agrego exitosamente el valor \""<<a<<"\" en la posicion \""<<p_it<<"\" del array\n";
		p_it++;
	}
	else{
		cout<<"El array esta completamente lleno\n";
	}
}
void array5v::remove_Element(int a){
	if(somethingTo_Remove()==true){
		for(int i=0; i<5; i++){
			if(*arr5[i]==a){
				delete arr5[i];
				arr5[i]=NULL;
				if(arr5[i+1]!=NULL){
					for(int j=i; j<4; j++){
						arr5[j]=arr5[j+1];
						arr5[j+1]=NULL;
					}
					p_it--;
				}
				cout<<"Se elimino exitosamente el valor \""<<a<<"\" en la posicion \""<<i<<"\" del array\n";
				break;
			}
		}
	}
	else{
		cout<<"No hay ningun elemento para eliminar\n";
	}
}
void array5v::show_Array(){
	cout<<"[";
	for(int i=0; i<5; i++){
		if(i<=3&&arr5[i]!=NULL){
			cout<<*arr5[i]<<", ";
		}
		else if(i<=3&&arr5[i]==NULL){
			cout<<"NULL, ";
		}
		else if(i>3&&arr5[i]!=NULL){
			cout<<*arr5[i]<<"]";
		}
		else if(i>3&&arr5[i]==NULL){
			cout<<"NULLL]";
		}
	}
	cout<<"\n";
}
