
/*
2. racional.cpp. Implemente una clase genérica Racional que represente un
	número racional, es decir, un número de la forma x / y donde x e y son
	números enteros, con y distinto de cero. La clase debe cumplir los
	siguientes requisitos:
	a) Proporcione un constructor que tome dos argumentos
	correspondientes al numerador y denominador. El primer argumento
	
	debe ser cero por defecto, el segundo argumento debe ser uno por
	defecto.
	b) La clase debe proporcionar un constructor copia, operador de
	asignación.
	c) Proporcione los operadores de suma, resta, multiplicación y división.
	d) Proporcione los operadores +=, -=, *= y /=.
	e) Implemente una función double que devuelva la mejor aproximación
	del racional como un doble.
	f) Implemente el operador de inserción para leer un número racional en
	con el formato como “-15/23”.
	g) Mantenga el número racional es su forma reducida, es decir, el
	numerador y el denominador son coprimos.
*/
#include <iostream>
#include <vector>
using namespace std;

class racional{
public:
	//Constructor
	racional(int num = 0, int den = 1){
		this->num=num;
		this->den=den;
		coprimos(); 
	}
	//Operadores "= , += , -= , *= , /="
	racional& operator=(racional x){
		if (this == &x){
			return *this;
		}
		num = x.obtNum();
		den = x.obtDen();
		return *this;
	}
	void operator+=(racional x){
		if(den==x.obtDen()){
			num+=x.obtNum();
		}
		else{
			num=(num*x.obtDen())+(x.obtNum()*den);
			den=(den*x.obtDen());
		}
		coprimos(); 
	}
	void operator-=(racional x){
		if(den==x.obtDen()){
			num-=x.obtNum();
		}
		else{
			num=(num*x.obtDen())-(x.obtNum()*den);
			den=(den*x.obtDen());
		}
		coprimos(); 
	}
	void operator*=(racional x){
		num*=x.obtNum();
		den*=x.obtDen();
		coprimos(); 
	}
	void operator/=(racional x){
		num*=x.obtDen();
		den*=x.obtNum();
		coprimos(); 
	}
	void asignar(int num = 0, int den = 1){
		this->num=num;
		this->den=den;
		coprimos(); 
	}
	//Operadores "<< , >>"
	friend ostream& operator<<(ostream& out, racional x){
		out << x.obtNum() << "/" << x.obtDen();
		return out;
	}
	friend istream& operator>>(istream& in, racional& x){
		cout << "Ingrese un racional en el formato (numerador/denominador): ";
		double num{0}, den{0};
		char sep{'\0'};
		if (not (in >> num >> sep)){
			// Error al leer el numerador o el caracter de separacion
			in.setstate(ios::failbit);
		}
		else if (sep != '/') {
			// Se leyó el numeral, pero no le sigue una slash
			// Colocamos de vuelta sep en el stream
			in.unget();
			x.asignar(num);
		} 
		else if (in >> den){
			// Se leyó con éxito el numerador, el slash, y el denominador
			x.asignar(num, den);
		}
		else{
			// Error al leer el denominador
			in.setstate(ios::failbit);
		}
		return in;
	}
	//Rendondear a decimales el número racional
	double decim(){
		double temp = num;
		return temp/den;
	}
	//Hacer que el numerador y el denominador sean coprimos
	void coprimos(){
		int temp;
		if(num<=den){
			temp=num;
		}
		else{
			temp=den;
		}
		int res = 1;
		for(int i=1; i<=temp; i++){
			if((num%i==0)&&(den%i==0)){
				res=i;
			}
		}
		num/=res;
		den/=res;
	}
	//Funciones para obtener el numerador y el denominador respectivamente
	int obtNum(){
		return num;
	}
	int obtDen(){
		return den;
	}
private:
	int num;
	int den;
};
//Operadores "+ , - , * , /"
racional operator+(racional& a, racional& b){
	if(a.obtDen()==b.obtDen()){
		return racional(a.obtNum()+b.obtNum(), a.obtDen());;
	}
	else{
		return racional((a.obtNum()*b.obtDen()) + (b.obtNum()*a.obtDen()), a.obtDen()*b.obtDen());
	}
}
racional operator-(racional& a, racional& b){
	if(a.obtDen()==b.obtDen()){
		return racional(a.obtNum()-b.obtNum(), a.obtDen());
	}
	else{
		return racional((a.obtNum()*b.obtDen()) - (b.obtNum()*a.obtDen()), a.obtDen()*b.obtDen());
	}
}
racional operator*(racional& a, racional& b){
	return racional(a.obtNum()*b.obtNum(), a.obtDen()*b.obtDen());
}
racional operator/(racional& a, racional& b){
	return racional(a.obtNum()*b.obtDen(), a.obtDen()*b.obtNum());
}

int main(int argc, char *argv[]) {
	racional a(10,13);
	racional b(20,56);
	racional c;
	
	cout<<"Números Racionales Iniciales\n";
	cout<<"A: "<<a<<endl;
	cout<<"B: "<<b<<endl;
	cout<<"C: "<<c<<endl<<endl;
	
	cout<<"Asignación y Suma\n";
	c=a;
	a+=b;
	cout<<"A: "<<a<<endl;
	cout<<"C: "<<c<<endl<<endl;;
	
	cout<<"Multiplicación y llevada a decimales\n";
	c*=b;
	cout<<"C: "<<c<<endl;
	cout<<"C a decimales: "<<c.decim()<<endl<<endl;
	
	cout<<"Resta y División\n";
	b-=c;
	cout<<"B: "<<b<<endl;
	cout<<"A/B: "<<a/b<<endl<<endl;
	
	cout<<"Inserción en el racional a\n";
	cin>>a;
	cout<<"A: "<<a<<endl;
	
	return 0;
}

