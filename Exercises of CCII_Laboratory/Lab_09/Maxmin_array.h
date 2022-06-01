#ifndef MAXMIN_ARRAY_H
#define MAXMIN_ARRAY_H

template <class A, class T, class N>
class Maxmin_array{
public:
	Maxmin_array(A,N);
	T Max(){
		T temp = arrayx[0];
		for(int i=0; i<size; i++){
			if(temp<arrayx[i]){
				temp=arrayx[i];
			}
		}
		return temp;
	};
	T Min(){
		T temp = arrayx[0];
		for(int i=0; i<size; i++){
			if(temp>arrayx[i]){
				temp=arrayx[i];
			}
		}
		return temp;
	};
private:
	A arrayx;
	N size;
};

template <class A, class T, class N>
Maxmin_array<A,T,N>::Maxmin_array(A arrayx, N size){
	this->arrayx = arrayx;
	this->size = size;
}

#endif

