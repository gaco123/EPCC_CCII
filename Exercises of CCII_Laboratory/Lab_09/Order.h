#ifndef ORDER_H
#define ORDER_H

template <class O, class P, class U>
class Order{
public:
	Order(O,P,U);
	void Ascend(){
		auto temp = arrayx[prim];
		int pos = prim;
		int prit = prim;
		int ultt = ult;
		
		for(int i=prit; i<=ultt; i++){
			if(temp<arrayx[i]){
				temp=arrayx[i];
				pos=i;
			}
			if(i==ultt&&prit!=ultt){
				arrayx[pos] = arrayx[prit];
				arrayx[prit] = temp;
				prit=prit+1;
				i=prit;
				temp=arrayx[prit];
				pos=prit;
			}
		}
	};
	void Descend(){
		auto temp = arrayx[prim];
		int pos = prim;
		int prit = prim;
		int ultt = ult;
		
		for(int i=prit; i<=ultt; i++){
			if(temp>arrayx[i]){
				temp=arrayx[i];
				pos=i;
			}
			if(i==ultt&&prit!=ultt){
				arrayx[pos] = arrayx[prit];
				arrayx[prit] = temp;
				prit=prit+1;
				i=prit;
				temp=arrayx[prit];
				pos=prit;
			}
		}
	};
private:
	O arrayx;
	P prim;
	U ult;
};

template <class O, class P, class U>
Order<O,P,U>::Order(O arrayx, P prim, U ult){
	this->arrayx = arrayx;
	this->prim = prim;
	this->ult = ult;
}

#endif

