
/*
3. tiempo.cpp. Implemente una clase que maneje tiempos sin fechas, en
formato de 24 horas. Por ejemplo, Tiempo(6, 45, 30) representa 6 horas
con 45 minutos y 30 segundos.
	a) Sobrecargue los operadores + y - para sumar y restar tiempos. Por
	ejemplo si definimos Tiempo t1(12, 45, 30) y t2(0, 30, 35) la suma t1 +
	t2 debe resultar en Tiempo(13, 16, 5)
	b) Sobrecargue los operadores de igualdad ==, != y de comparación <, >,
	<=, >=
	c) Sobrecargue el operador de extracción para mostrar las horas.
	d) Implemente métodos adecuados para mostrar las horas en formato
	am / pm.
*/
#include <iostream>
#include <string>
using namespace std;

class tiempo{
public:
	tiempo(int h = 0, int m = 0, int s = 0){
		this->h=h;
		this->m=m;
		this->s=s;
		formato24();
	}
	void formato24(){
		h=h%24+m/60;
		m=m%60+s/60;
		s=s%60;
	}
	friend ostream& operator<<(ostream& out, tiempo x){
		out << x.obtH() << ":" << x.obtM() << ":" <<x.obtS();
		return out;
	}
	string am_pm(){
		int temph=h;
		string apm;
		if(temph>12){
			temph-=12;
			apm=to_string(temph)+":"+to_string(m)+":"+to_string(s)+" pm";
			return apm;
		}
		else{
			if(temph==12){
				apm=to_string(temph)+":"+to_string(m)+":"+to_string(s)+" pm";
				return apm;
			}
			else if(temph==0){
				apm="12:"+to_string(m)+":"+to_string(s)+" am";
				return apm;
			}
			else{
				apm=to_string(temph)+":"+to_string(m)+":"+to_string(s)+" am";
				return apm;
			}
		}
	}
	int obtH(){
		return h;
	}
	int obtM(){
		return m;
	}
	int obtS(){
		return s;
	}
private:
	int h;
	int m;
	int s;
};
//Operadores " + , - "
tiempo operator+(tiempo& a, tiempo& b){
	return tiempo(a.obtH()+b.obtH(), a.obtM()+b.obtM(), a.obtS()+b.obtS());
}
tiempo operator-(tiempo& a, tiempo& b){
	int temph = a.obtH();
	for(int i=1; i<=b.obtH(); i++){
		temph--;
		if(temph==-1){
			temph=23;
		}
	}
	int tempm = a.obtM();
	for(int i=1; i<=b.obtM(); i++){
		tempm--;
		if(tempm==-1){
			tempm=59;
			temph--;
			if(temph==-1){
				temph=23;
			}
		}
	}
	int temps = a.obtS();
	for(int i=1; i<=b.obtS(); i++){
		temps--;
		if(temps==-1){
			temps=59;
			tempm--;
			if(tempm==-1){
				tempm=59;
			}
		}
	}
	return tiempo(temph,tempm,temps);
}
bool operator==(tiempo x, tiempo y){
	if((x.obtH()==y.obtH())&&(x.obtM()==y.obtM())&&(x.obtS()==y.obtS())){
		return true;
	}
	else{
		return false;
	}
}
bool operator!=(tiempo x, tiempo y){
	if((x.obtH()!=y.obtH())||(x.obtM()!=y.obtM())||(x.obtS()!=y.obtS())){
		return true;
	}
	else{
		return false;
	}
}
bool operator<(tiempo x, tiempo y){
	if(x.obtH()<y.obtH()){
		return true;
	}
	else if (x.obtH()==y.obtH()){
		if(x.obtM()<y.obtM()){
			return true;			
		}
		else if(x.obtM()==y.obtM()){
			if(x.obtS()<y.obtS()){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}
bool operator>(tiempo x, tiempo y){
	if(x.obtH()>y.obtH()){
		return true;
	}
	else if (x.obtH()==y.obtH()){
		if(x.obtM()>y.obtM()){
			return true;			
		}
		else if(x.obtM()==y.obtM()){
			if(x.obtS()>y.obtS()){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}
bool operator<=(tiempo x, tiempo y){
	if(x.obtH()<y.obtH()){
		return true;
	}
	else if (x.obtH()==y.obtH()){
		if(x.obtM()<y.obtM()){
			return true;			
		}
		else if(x.obtM()==y.obtM()){
			if(x.obtS()<=y.obtS()){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}
bool operator>=(tiempo x, tiempo y){
	if(x.obtH()>y.obtH()){
		return true;
	}
	else if (x.obtH()==y.obtH()){
		if(x.obtM()>y.obtM()){
			return true;			
		}
		else if(x.obtM()==y.obtM()){
			if(x.obtS()>=y.obtS()){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

int main(int argc, char *argv[]) {
	tiempo a(23,50,40);
	tiempo b(23,50,41);
	tiempo c(13,50,30);
	tiempo d(12,46,12);
	tiempo e(01,16,13);
	tiempo f=a;
	
	cout<<"Tiempos en formato 24h\n";
	cout<<"A: "<<a<<endl;
	cout<<"B: "<<b<<endl;
	cout<<"C: "<<c<<endl;
	cout<<"D: "<<d<<endl;
	cout<<"E: "<<e<<endl;
	cout<<"F: "<<f<<endl<<endl;
	
	cout<<"Tiempo en formato am/pm\n";
	cout<<"A: "<<a.am_pm()<<endl;
	cout<<"B: "<<b.am_pm()<<endl;
	cout<<"C: "<<c.am_pm()<<endl;
	cout<<"D: "<<d.am_pm()<<endl;
	cout<<"E: "<<e.am_pm()<<endl;
	cout<<"F: "<<f.am_pm()<<endl<<endl;
	
	cout<<"Comparaciones\n";
	if(b>a){
		cout<<"El tiempo b es mayor que el tiempo a"<<endl;;
	}
	if(c!=e){
		cout<<"El tiempo c es diferente del tiempo e"<<endl;;
	}
	if(f==a){
		cout<<"El tiempo f es igual al tiempo a"<<endl;;
	}
	if(d>=e){
		cout<<"El tiempo d es mayor o igual al tiempo e"<<endl;
	}
	
	return 0;
}

