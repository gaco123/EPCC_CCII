#ifndef MAX_MIN_H
#define MAX_MIN_H

template <class M>
class Max_min{
public:
	Max_min(M x=0, M y=0, M z=0);
	M getMax(){
		M a[3]={x,y,z};
		M temp=a[0];
		for(int i=0; i<3; i++){
			if(temp<a[i]){
				temp=a[i];
			}
		}
		return temp;
	};
	M getMin(){
		M a[3]={x,y,z};
		M temp=a[0];
		for(int i=0; i<3; i++){
			if(temp>a[i]){
				temp=a[i];
			}
		}
		return temp;
	};
private:
	M x;
	M y;
	M z;
};

template <class M>
Max_min<M>::Max_min(M x, M y, M z){
	this->x = x;
	this->y = y;
	this->z = z;
}

#endif

