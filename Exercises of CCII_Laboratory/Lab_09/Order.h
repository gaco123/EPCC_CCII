#ifndef ORDER_H
#define ORDER_H
#include <iostream>
using namespace std;

template <class O, class OT, class P, class U>
class Order{
public:
	Order(O,P,U);
	void Ascend(){
		OT temp = arrayx[prim];
		int pos = prim;
		
		for(int i=prim; i<=ult; i++){
			if(temp<arrayx[i]){
				temp=arrayx[i];
				pos=i;
			}
			if(i==ult&&prim!=ult){
				arrayx[pos]=arrayx[prim];
				arrayx[prim]=temp;
				++prim;
				i=prim;
			}
			for(int i=0; i<5; i++){
				cout<<arrayx[i]<<" ";
			}
			cout<<endl;
		}
	};
private:
	O arrayx;
	P prim;
	U ult;
};

template <class O, class OT, class P, class U>
Order<O,OT,P,U>::Order(O arrayx, P prim, U ult){
	this->arrayx = arrayx;
	this->prim = prim;
	this->ult = ult;
}

#endif

