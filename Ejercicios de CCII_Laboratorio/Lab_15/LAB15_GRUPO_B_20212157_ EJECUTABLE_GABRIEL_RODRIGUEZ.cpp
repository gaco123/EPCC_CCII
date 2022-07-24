

//Laboratorio N�15
//Alumno: Gabriel Fernando Rodriguez Cutimbo
/*
Ejercicio:
	1. El alumno deber� de implementar un conjunto de clases que permita seleccionar
	las piezas de un autom�vil, es decir, se podr�n tener componentes a disposici�n
	del cliente (puertas, llantas, tim�n, asientos, motor, espejos, vidrios, etc.). Del cual
	el cliente puede indicar que caracter�sticas de color puede tener cada pieza. Al
	final mostrar opciones al Cliente o permitirle que �l pueda escoger las piezas e
	indicar el color. Utilizar el patr�n Builder.
	*Pista, en lugar de trabajar el producto con una lista de componentes, se puede
	alojar una estructura o clase.
*/

#include <iostream>
#include <vector>
using namespace std;

//Este es el producto realizado por la clase "BuilderEspecifico"
class Automovil{
public:
	vector<string> componentes;
	void ListaComp()const {
		cout << "Componentes: ";
		for (size_t i = 0; i < componentes.size(); i++) {
			if (componentes[i] == componentes.back()) {
				cout << componentes[i];
			}
			else {
				cout << componentes[i] << ", ";
			}
		}
		cout << "\n\n";
	}
};

/*Nombres de las funciones que tendr�n que describir cada 
clase "BuilderEspecifico"*/
class IBuilder{
public:
	virtual ~IBuilder() {}
	virtual void ProducirPuerta(string) const = 0;
	virtual void ProducirLlanta(string) const = 0;
	virtual void ProducirTimon(string) const = 0;
	virtual void ProducirAsiento(string) const = 0;
	virtual void ProducirMotor(string) const = 0;
	virtual void ProducirEspejo(string) const = 0;
	virtual void ProducirGuantera(string) const = 0;
	virtual void ProducirCajaCambios(string) const = 0;
	virtual void ProducirVentana(string) const = 0;
	virtual void ProducirBateria(string) const = 0;
};

/*Descripci�n de cada funci�n de "IBuilder" (en este caso solo 
hay una clase "BuilderEspecifico", pero, pueden a ver m�s con otras 
instrucciones para las funciones nombradas por "IBuilder"*/
class BuilderEspecifico : public IBuilder{
private:
	Automovil* product;
public:
	BuilderEspecifico() {
		this->Reset();
	}
	~BuilderEspecifico() {
		delete product;
	}
	void Reset() {
		this->product = new Automovil();
	}
	
	void ProducirPuerta(string color)const override{
		string temp = "Puerta["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirLlanta(string color)const override{
		string temp = "Llanta["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirTimon(string color)const override{
		string temp = "Timon["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirAsiento(string color)const override{
		string temp = "Asiento["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirMotor(string color)const override{
		string temp = "Motor["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirEspejo(string color)const override{
		string temp = "Espejo["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirGuantera(string color)const override{
		string temp = "Guantera["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirCajaCambios(string color)const override{
		string temp = "Caja_de_Cambios["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirVentana(string color)const override{
		string temp = "Ventana["+color+"]";
		this->product->componentes.push_back(temp);
	}
	void ProducirBateria(string color)const override{
		string temp = "Bater�a["+color+"]";
		this->product->componentes.push_back(temp);
	}
	
	Automovil* GetProducto(){
		Automovil* resultado = this->product;
		this->Reset();
		return resultado;
	}
};

/*No existe la clase "Director", ya que, en este caso no se necesita un producto
prefabricado*/

//Programa en s�
int main(){
	//Memoria Basica
	BuilderEspecifico* builder = new BuilderEspecifico(); //IBuilder => BuilderEspecifico
	Automovil* p; //Producto
	int op_p;//Se encarga de las opciones del men� principal
	
	//Se encargan de las opciones de los diferentes submen�s de colores
	int op_ps1;
	int op_ps2;
	int op_ps3;
	int op_ps4;
	int op_ps5;
	int op_ps6;
	int op_ps7;
	int op_ps8;
	int op_ps9;
	int op_ps10;
	
	bool comp_ps11 = true; //Para comprobar que al menos una vez se ha construido el vehiculo
	
	//Esta va a ser el "Cliente" ya que con este men� se va a armar un auto desde cero
	while(true){
		cout<<"MENU PARA FABRICAR UN AUTOMOVIL\n";
		cout<<"1. Agregar puerta\n";
		cout<<"2. Agregar llanta\n";
		cout<<"3. Agregar tim�n\n";
		cout<<"4. Agregar asiento\n";
		cout<<"5. Agregar motor\n";
		cout<<"6. Agregar espejo\n";
		cout<<"7. Agregar guantera\n";
		cout<<"8. Agregar caja de cambios\n";
		cout<<"9. Agregar ventana\n";
		cout<<"10. Agregar bater�a\n";
		cout<<"11. Construir vehiculo(Solo usar una vez terminado de agregar todo)\n";
		cout<<"12. Mostrar componentes actuales(Us� primero la opci�n 11)\n";
		cout<<"13. Salir\n";
		do{
			cout<<"Ingrese el n�mero de la opci�n: ";
			cin>>op_p;
			if(op_p==1||op_p==2||op_p==3||op_p==4||op_p==5||op_p==6||op_p==7||op_p==8||op_p==9||op_p==10||op_p==11||op_p==12||op_p==13){
				break;
			}
			else{
				cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
			}
		}while(true);
		cout<<endl;
		//Puerta
		if(op_p==1){
			cout<<"MENU PARA ELEGIR EL COLOR DE LA PUERTA\n";
			cout<<"1. Azul Metalico\n";
			cout<<"2. Rojo Metalico\n";
			cout<<"3. Blanco\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps1;
				if(op_ps1==1||op_ps1==2||op_ps1==3){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps1==1){
				builder->ProducirPuerta("Azul Metalico");
				cout<<"Se agrego una puerta color \"Azul Metalico\"\n\n";
			}
			else if(op_ps1==2){
				builder->ProducirPuerta("Rojo Metalico");
				cout<<"Se agrego una puerta color \"Rojo Metalico\"\n\n";
			}
			else if(op_ps1==3){
				builder->ProducirPuerta("Blanco");
				cout<<"Se agrego una puerta color \"Blanco\"\n\n";
			}
		}
		//Llanta
		if(op_p==2){
			cout<<"MENU PARA ELEGIR EL COLOR DE LA LLANTA\n";
			cout<<"1. Negro\n";
			cout<<"2. Gris\n";
			cout<<"3. Amarillo\n";
			cout<<"4. Blanco\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps2;
				if(op_ps2==1||op_ps2==2||op_ps2==3||op_ps2==4){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps2==1){
				builder->ProducirLlanta("Negro");
				cout<<"Se agrego una llanta color \"Negro\"\n\n";
			}
			else if(op_ps2==2){
				builder->ProducirLlanta("Gris");
				cout<<"Se agrego una llanta color \"Gris\"\n\n";
			}
			else if(op_ps2==3){
				builder->ProducirLlanta("Amarillo");
				cout<<"Se agrego una llanta color \"Amarillo\"\n\n";
			}
			else if(op_ps2==4){
				builder->ProducirLlanta("Blanco");
				cout<<"Se agrego una llanta color \"Blanco\"\n\n";
			}
		}
		//Timon
		if(op_p==3){
			cout<<"MENU PARA ELEGIR EL COLOR DEL TIMON\n";
			cout<<"1. Caf�\n";
			cout<<"2. Negro\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps3;
				if(op_ps3==1||op_ps3==2){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps3==1){
				builder->ProducirTimon("Caf�");
				cout<<"Se agrego un tim�n color \"Caf�\"\n\n";
			}
			else if(op_ps3==2){
				builder->ProducirTimon("Negro");
				cout<<"Se agrego un tim�n color \"Negro\"\n\n";
			}
		}
		//Asiento
		if(op_p==4){
			cout<<"MENU PARA ELEGIR EL COLOR DEL ASIENTO\n";
			cout<<"1. Caf�\n";
			cout<<"2. Negro\n";
			cout<<"3. Blanco\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps4;
				if(op_ps4==1||op_ps4==2||op_ps4==3){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps4==1){
				builder->ProducirAsiento("Caf�");
				cout<<"Se agrego un asiento color \"Caf�\"\n\n";
			}
			else if(op_ps4==2){
				builder->ProducirAsiento("Negro");
				cout<<"Se agrego un asiento color \"Negro\"\n\n";
			}
			else if(op_ps4==2){
				builder->ProducirAsiento("Blanco");
				cout<<"Se agrego un asiento color \"Blanco\"\n\n";
			}
		}
		//Motor
		if(op_p==5){
			cout<<"MENU PARA ELEGIR EL COLOR DEL MOTOR\n";
			cout<<"1. Negro\n";
			cout<<"2. Blanco\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps5;
				if(op_ps5==1||op_ps5==2){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps5==1){
				builder->ProducirMotor("Negro");
				cout<<"Se agrego un motor color \"Negro\"\n\n";
			}
			else if(op_ps5==2){
				builder->ProducirMotor("Blanco");
				cout<<"Se agrego un motor color \"Blanco\"\n\n";
			}
		}
		//Espejo
		if(op_p==6){
			cout<<"MENU PARA ELEGIR EL COLOR DEL ESPEJO\n";
			cout<<"1. Azul Metalico\n";
			cout<<"2. Rojo Metalico\n";
			cout<<"3. Blanco\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps6;
				if(op_ps6==1||op_ps6==2||op_ps6==3){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps6==1){
				builder->ProducirEspejo("Azul Metalico");
				cout<<"Se agrego un espejo color \"Azul Metalico\"\n\n";
			}
			else if(op_ps6==2){
				builder->ProducirEspejo("Rojo Metalico");
				cout<<"Se agrego un espejo color \"Rojo Metalico\"\n\n";
			}
			else if(op_ps6==3){
				builder->ProducirEspejo("Blanco");
				cout<<"Se agrego un espejo color \"Blanco\"\n\n";
			}
		}
		//Guantera
		if(op_p==7){
			cout<<"MENU PARA ELEGIR EL COLOR DE LA GUANTERA\n";
			cout<<"1. Negro\n";
			cout<<"2. Gris\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps7;
				if(op_ps7==1||op_ps7==2){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps7==1){
				builder->ProducirGuantera("Negro");
				cout<<"Se agrego una guantera color \"Negro\"\n\n";
			}
			else if(op_ps7==2){
				builder->ProducirGuantera("Gris");
				cout<<"Se agrego una guantera color \"Gris\"\n\n";
			}
		}
		//Caja de Cambios
		if(op_p==8){
			cout<<"MENU PARA ELEGIR EL COLOR DE LA CAJA DE CAMBIOS\n";
			cout<<"1. Caf�\n";
			cout<<"2. Negro\n";
			cout<<"3. Blanco\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps8;
				if(op_ps8==1||op_ps8==2||op_ps8==3){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps8==1){
				builder->ProducirCajaCambios("Caf�");
				cout<<"Se agrego una caja de cambios color \"Caf�\"\n\n";
			}
			else if(op_ps8==2){
				builder->ProducirCajaCambios("Negro");
				cout<<"Se agrego una caja de cambios color \"Negro\"\n\n";
			}
			else if(op_ps8==3){
				builder->ProducirCajaCambios("Blanco");
				cout<<"Se agrego una caja de cambios color \"Blanco\"\n\n";
			}
		}
		//Ventana
		if(op_p==9){
			cout<<"MENU PARA ELEGIR EL COLOR DE LA VENTANA\n";
			cout<<"1. Transparente\n";
			cout<<"2. Opaco\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps9;
				if(op_ps9==1||op_ps9==2){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps9==1){
				builder->ProducirVentana("Transparente");
				cout<<"Se agrego una ventana color \"Transparente\"\n\n";
			}
			else if(op_ps9==2){
				builder->ProducirVentana("Opaco");
				cout<<"Se agrego una ventana color \"Opaco\"\n\n";
			}
		}
		//Bater�a
		if(op_p==10){
			cout<<"MENU PARA ELEGIR EL COLOR DE LA BATERIA\n";
			cout<<"1. Gris\n";
			cout<<"2. Blanco\n";
			do{
				cout<<"Ingrese el n�mero de la opci�n: ";
				cin>>op_ps10;
				if(op_ps10==1||op_ps10==2){
					break;
				}
				else{
					cout<<"Error, ingrese nuevamente el n�mero de opci�n...\n\n";
				}
			}while(true);
			cout<<endl;
			if(op_ps10==1){
				builder->ProducirBateria("Gris");
				cout<<"Se agrego una bater�a color \"Gris\"\n\n";
			}
			else if(op_ps10==2){
				builder->ProducirBateria("Blanco");
				cout<<"Se agrego una bater�a color \"Blanco\"\n\n";
			}
		}
		//Construir Vehiculo
		else if(op_p==11){
			if(comp_ps11==false){
				delete p;
				p = builder->GetProducto();
			}
			else{
				p = builder->GetProducto();
				comp_ps11=false;
			}
			cout<<"Vehiculo Construido\n\n";
		}
		//Ver componentes del auto construido
		else if(op_p==12){
			p->ListaComp();
		}
		//Salir del programa
		else if(op_p==13){
			if(comp_ps11==false){
				delete p;
			}
			delete builder;
			break;
		}
	}
	
	return 0;
}
