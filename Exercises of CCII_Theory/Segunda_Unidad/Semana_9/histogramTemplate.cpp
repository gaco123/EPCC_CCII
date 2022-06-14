
/*1. histogramaTemplate.cpp
	Escriba una clase usando templates que tome una colección de elementos
	como parámetro. La clase debe tener un método que devuelva el histograma
	de los elementos de la colección. El método histograma debe aceptar un
	parámetro que indique en cuantos intervalos agrupar a los elementos de la
	colección. La clase debe tener además un método para imprimir el
	histograma. Ejemplo: Dada la colección de enteros {10, 2, 9, 7, 5, 6, 1, 8, 8, 4}
y con el número de intervalos igual a 5, el histograma debe retornar 2 1 2 2 3
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <class element>
class Histogram{
public:
	Histogram(vector<element>, int);
	vector<int> return_Frequency();
	void print_Map();
private:
	map<element, int> counts{};
	vector<int> vecfreq;
	int in{};
};

template <class element>
Histogram<element>::Histogram(vector<element> vecx, int in){
	//Value for the map
	for(auto i=vecx.begin(); i!=vecx.end(); i++){
		++counts[*i];
	}
	//Size of each intervale
	int n=1;
	for(auto i=counts.begin(); i!=counts.end(); i++){
		n++;
	}
	this->in=n/in;
}
template <class element>
vector<int> Histogram<element>::return_Frequency(){
	auto apuntini=counts.begin();
	auto apuntend=counts.end();
	apuntend--;
	int minin=apuntini->first;
	int maxin=apuntini->first+in;
	int frequency=0;
	int staend=apuntend->first;
	
	for(auto i=counts.begin(); i!=counts.end(); i++){
		if(i->first>=maxin){
			vecfreq.push_back(frequency);
			frequency=0;
			minin+=in;
			maxin+=in;
		}
		if(i->first>=minin&&i->first<maxin){
			frequency+=i->second;
		}
		if(i->first==staend){
			vecfreq.push_back(frequency);
		}

	}
	return vecfreq;
}
template <class element>
void Histogram<element>::print_Map(){
	cout<<"TABLE OF FREQUENCY OF THE COLLECTION\n";
	for(auto i=counts.begin(); i!=counts.end(); i++){
		cout<<i->first<<" => ";
		for(int j=0; j<i->second; j++){
			cout<<"*";
		}
		cout<<"\n";
	}
}

int main() {
	//Memory/Input
	int in = 5;//Intervals
	vector<int> vec = {10, 2, 9, 7, 5, 6, 1, 8, 8, 4};//Inicial Vector 
	vector<int> freq{};//Vector with the frequency of each interval
	
	//Output
	cout<<"PROGRAM TO CALCULATE THE HISTOGRAM OF A COLLECTION OF ELEMENTS\n";
	Histogram<int> ints(vec, in);
	freq=ints.return_Frequency();
	cout<<"FREQUENCY IN EACH INTERVAL\n";
	cout<<"[";
	for(auto i=freq.begin(); i!=freq.end(); i++){
		if(i!=freq.end()-1){
			cout<<*i<<", ";
		}
		else{
			cout<<*i<<"]\n";
		}
	}
	ints.print_Map();
	
	return 0;
}


