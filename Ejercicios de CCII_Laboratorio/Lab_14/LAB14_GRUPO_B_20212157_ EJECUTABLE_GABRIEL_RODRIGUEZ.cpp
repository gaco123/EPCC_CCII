
//Laboratorio N°14
//Alumno: Gabriel Fernando Rodriguez Cutimbo
/*
1. Ejercicios
	Resolver los siguientes ejercicios planteados:
	Implemente un programa utilizando puntero a punteros que gestione los datos de
	stock de una tienda de ropa, la información a recoger será: código, nombre y
	precio del producto, asimismo la cantidad en stock. La tienda dispone de 10
	productos distintos. El programa debe ser capaz de:
	1. Dar de alta un producto nuevo.(Agregar la columna de estados)
	2. Dar de baja a un producto. (No hay stock).
	3. Buscar un producto por su nombre o código.
	4. Modificar el nombre, precio o cantidad de un producto dado.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void busqueda_Activo(vector<int**>& codigos, vector<string**>& nombres, vector<string**>& estado){
	string temp1;
	int it=0;
	cout<<"1. Buscar por nombre\n";
	cout<<"2. Buscar por código\n";
	do{
		cout<<"Ingrese el número de la opción:\n";
		getline(cin,temp1);
		if(temp1=="1"||temp1=="2"){
			break;
		}
		else{
			cout<<"Error, ingrese nuevamente el número de opción...\n\n";
		}
	}while(true);
	if(temp1=="1"){
		string op1;
		cout<<"Ingrese el nombre del producto:\n";
		getline(cin,op1);
		cout<<endl;
		it=0;
		for(auto i=estado.begin(); i<estado.end(); i++){
			if(**nombres.at(it)==op1){
				delete **i;
				**i=new string("Activo");
			}
			it++;
		}
	}
	else if(temp1=="2"){
		int op2;
		cout<<"Ingrese el código del producto:\n";
		cin>>op2;
		cout<<endl;
		it=0;
		for(auto i=estado.begin(); i<estado.end(); i++){
			if(**codigos.at(it)==op2){
				delete **i;
				**i=new string("Activo");
			}
			it++;
		}
	}
}
void busqueda_Inactivo(vector<int**>& codigos, vector<string**>& nombres, vector<string**>& estado){
	string temp1;
	int it=0;
	cout<<"1. Buscar por nombre\n";
	cout<<"2. Buscar por código\n";
	do{
		cout<<"Ingrese el número de la opción:\n";
		getline(cin,temp1);
		if(temp1=="1"||temp1=="2"){
			break;
		}
		else{
			cout<<"Error, ingrese nuevamente el número de opción...\n\n";
		}
	}while(true);
	if(temp1=="1"){
		string op1;
		cout<<"Ingrese el nombre del producto:\n";
		getline(cin,op1);
		cout<<endl;
		it=0;
		for(auto i=estado.begin(); i<estado.end(); i++){
			if(**nombres.at(it)==op1){
				delete **i;
				**i=new string("Inactivo");
			}
			it++;
		}
	}
	else if(temp1=="2"){
		int op2;
		cout<<"Ingrese el código del producto:\n";
		cin>>op2;
		cout<<endl;
		it=0;
		for(auto i=estado.begin(); i<estado.end(); i++){
			if(**codigos.at(it)==op2){
				delete **i;
				**i=new string("Inactivo");
			}
			it++;
		}
	}
}
void busqueda_Modificar(vector<int**>& codigos, vector<string**>& nombres, vector<double**>& precios, vector<int**>& stock, vector<string**>& estado){
	string temp1;
	int it=0;
	cout<<"1. Buscar por nombre\n";
	cout<<"2. Buscar por código\n";
	do{
		cout<<"Ingrese el número de la opción:\n";
		getline(cin,temp1);
		if(temp1=="1"||temp1=="2"){
			break;
		}
		else{
			cout<<"Error, ingrese nuevamente el número de opción...\n\n";
		}
	}while(true);
	if(temp1=="1"){
		string op1;
		cout<<"Ingrese el nombre del producto:\n";
		getline(cin,op1);
		cout<<endl;
		it=0;
		for(auto i=nombres.begin(); i<nombres.end(); i++){
			if(***i==op1){
				string n1;
				double p1;
				int s1;
				cout<<"Ingrese el nuevo nombre:\n";
				getline(cin,n1);
				cout<<"Ingrese el nuevo precio:\n";
				cin>>p1;
				cout<<"Ingrese el nuevo stock:\n";
				cin>>s1;
				delete *nombres.at(it);
				delete *precios.at(it);
				delete *stock.at(it);
				*nombres.at(it) = new string(n1);
				*precios.at(it) = new double(p1);
				*stock.at(it) = new int(s1);
				if(s1==0){
					delete *estado.at(it);
					*estado.at(it)= new string("Inactivo");
				}
			}
			it++;
		}
	}
	else if(temp1=="2"){
		int op2;
		cout<<"Ingrese el código del producto:\n";
		cin>>op2;
		cout<<endl;
		it=0;
		for(auto i=codigos.begin(); i<codigos.end(); i++){
			if(***i==op2){
				string n1;
				double p1;
				int s1;
				cout<<"Ingrese el nuevo nombre:\n";
				getline(cin,n1);
				cout<<"Ingrese el nuevo precio:\n";
				cin>>p1;
				cout<<"Ingrese el nuevo stock:\n";
				cin>>s1;
				delete *nombres.at(it);
				delete *precios.at(it);
				delete *stock.at(it);
				*nombres.at(it) = new string(n1);
				*precios.at(it) = new double(p1);
				*stock.at(it) = new int(s1);
				if(s1==0){
					delete *estado.at(it);
					*estado.at(it)= new string("Inactivo");
				}
			}
			it++;
		}
	}
	cout<<endl;
}	

int main(int argc, char *argv[]) {

	//Top
	vector<string**> top;
	top.push_back(new string*(new string("Código")));
	top.push_back(new string*(new string("Nombre")));
	top.push_back(new string*(new string("Precio")));
	top.push_back(new string*(new string("Stock")));
	top.push_back(new string*(new string("Estado")));
	
	//Middle
	vector<int**> codigos;
	vector<string**> nombres;
	vector<double**> precios;
	vector<int**> stock;
	vector<string**> estado;
	
	//Productos
	//1er
	codigos.push_back(new int*(new int(1)));
	nombres.push_back(new string*(new string("Polo-A")));
	precios.push_back(new double*(new double(45.5)));
	stock.push_back(new int*(new int(20)));
	estado.push_back(new string*(new string("Activo")));
	
	//2do
	codigos.push_back(new int*(new int(2)));
	nombres.push_back(new string*(new string("Crop")));
	precios.push_back(new double*(new double(40.5)));
	stock.push_back(new int*(new int(30)));
	estado.push_back(new string*(new string("Activo")));
	
	//3er
	codigos.push_back(new int*(new int(3)));
	nombres.push_back(new string*(new string("Jean")));
	precios.push_back(new double*(new double(45)));
	stock.push_back(new int*(new int(40)));
	estado.push_back(new string*(new string("Activo")));
	
	//4to
	codigos.push_back(new int*(new int(4)));
	nombres.push_back(new string*(new string("Casaca")));
	precios.push_back(new double*(new double(75)));
	stock.push_back(new int*(new int(20)));
	estado.push_back(new string*(new string("Activo")));
	
	//5to
	codigos.push_back(new int*(new int(5)));
	nombres.push_back(new string*(new string("Blusa")));
	precios.push_back(new double*(new double(30)));
	stock.push_back(new int*(new int(35)));
	estado.push_back(new string*(new string("Activo")));
	
	//6to
	codigos.push_back(new int*(new int(6)));
	nombres.push_back(new string*(new string("Polo-B")));
	precios.push_back(new double*(new double(55)));
	stock.push_back(new int*(new int(60)));
	estado.push_back(new string*(new string("Activo")));
	
	//7to
	codigos.push_back(new int*(new int(7)));
	nombres.push_back(new string*(new string("Guantes")));
	precios.push_back(new double*(new double(14.5)));
	stock.push_back(new int*(new int(100)));
	estado.push_back(new string*(new string("Activo")));
	
	//8vo
	codigos.push_back(new int*(new int(8)));
	nombres.push_back(new string*(new string("Gorro")));
	precios.push_back(new double*(new double(9.5)));
	stock.push_back(new int*(new int(80)));
	estado.push_back(new string*(new string("Activo")));
	
	//9no
	codigos.push_back(new int*(new int(9)));
	nombres.push_back(new string*(new string("Botas")));
	precios.push_back(new double*(new double(50)));
	stock.push_back(new int*(new int(30)));
	estado.push_back(new string*(new string("Activo")));
	
	//10mo
	codigos.push_back(new int*(new int(10)));
	nombres.push_back(new string*(new string("Camisa")));
	precios.push_back(new double*(new double(45.5)));
	stock.push_back(new int*(new int(40)));
	estado.push_back(new string*(new string("Activo")));
	
	//Programa en sí
	int it=0;
	string temp;
	while(true){
		cout<<"TIENDA DE ROPA \"AMONGUS\"\n";
		cout<<"1. Ver lista de productos\n";
		cout<<"2. Dar de alta un producto\n";
		cout<<"3. Dar de baja un producto\n";
		cout<<"4. Buscar un producto\n";
		cout<<"5. Modificar un producto\n";
		cout<<"6. Salir\n";
		do{
			cout<<"Ingrese el número de la opción:\n";
			getline(cin,temp);
			if(temp=="1"||temp=="2"||temp=="3"||temp=="4"||temp=="5"||temp=="6"){
				break;
			}
			else{
				cout<<"Error, ingrese nuevamente el número de opción...\n\n";
			}
		} while(true);
		cout<<endl;
		if(temp=="1"){
			for(auto i=top.begin(); i<top.end(); i++){
				cout<<***i<<"\t\t";
			}
			cout<<endl;
			it=0;
			for(auto i=codigos.begin(); i<codigos.end(); i++){
				cout<<**codigos.at(it)<<"\t\t";
				cout<<**nombres.at(it)<<"\t\t";
				cout<<**precios.at(it)<<"\t\t";
				cout<<**stock.at(it)<<"\t\t";
				cout<<**estado.at(it)<<"\t\t\n";
				it++;
			}
			cout<<endl;
		}
		else if(temp=="2"){
			busqueda_Activo(codigos,nombres,estado);
		}
		else if(temp=="3"){
			busqueda_Inactivo(codigos,nombres,estado);
		}
		else if(temp=="4"){
			string temp1;
			cout<<"1. Buscar por nombre\n";
			cout<<"2. Buscar por código\n";
			do{
				cout<<"Ingrese el número de la opción:\n";
				getline(cin,temp1);
				if(temp1=="1"||temp1=="2"){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el número de opción...\n\n";
				}
			}while(true);
			cout<<endl;
			if(temp1=="1"){
				string op1;
				cout<<"Ingrese el nombre del producto:\n";
				getline(cin,op1);
				cout<<endl;
				it=0;
				for(auto i=nombres.begin(); i<nombres.end(); i++){
					if(**nombres.at(it)==op1){
						cout<<"El producto buscado es el siguiente\n";
						for(auto i=top.begin(); i<top.end(); i++){
							cout<<***i<<"\t\t";
						}
						cout<<"\n";
						cout<<**codigos.at(it)<<"\t\t";
						cout<<**nombres.at(it)<<"\t\t";
						cout<<**precios.at(it)<<"\t\t";
						cout<<**stock.at(it)<<"\t\t";
						cout<<**estado.at(it)<<"\t\t\n\n";
						break;
					}
					it++;
				}
			}
			else if(temp1=="2"){
				int op2;
				cout<<"Ingrese el código del producto:\n";
				cin>>op2;
				cout<<endl;
				it=0;
				for(auto i=codigos.begin(); i<codigos.end(); i++){
					if(**codigos.at(it)==op2){
						cout<<"El producto buscado es el siguiente\n";
						for(auto i=top.begin(); i<top.end(); i++){
							cout<<***i<<"\t\t";
						}
						cout<<"\n";
						cout<<**codigos.at(it)<<"\t\t";
						cout<<**nombres.at(it)<<"\t\t";
						cout<<**precios.at(it)<<"\t\t";
						cout<<**stock.at(it)<<"\t\t";
						cout<<**estado.at(it)<<"\t\t\n\n";
						break;
					}
					it++;
				}
			}
		}
		else if(temp=="5"){
			busqueda_Modificar(codigos,nombres,precios,stock,estado);
		}
		else if(temp=="6"){
			break;
		}
	}
	
	
	//Eliminar punteros dobles
	for(auto i=top.begin(); i<top.end(); i++){
		delete **i;
		delete *i;
	}
	for(auto i=codigos.begin(); i<codigos.end(); i++){
		delete **i;
		delete *i;
	}
	for(auto i=nombres.begin(); i<nombres.end(); i++){
		delete **i;
		delete *i;
	}
	for(auto i=precios.begin(); i<precios.end(); i++){
		delete **i;
		delete *i;
	}
	for(auto i=stock.begin(); i<stock.end(); i++){
		delete **i;
		delete *i;
	}
	for(auto i=estado.begin(); i<estado.end(); i++){
		delete **i;
		delete *i;
	}
	
	return 0;
}

