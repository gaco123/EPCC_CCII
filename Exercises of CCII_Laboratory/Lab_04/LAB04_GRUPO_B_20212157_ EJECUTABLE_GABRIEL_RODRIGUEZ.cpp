
//Laboratorio N°4
//Alumno: Gabriel Fernando Rodriguez Cutimbo

/*
1. Escribir un programa donde se pueda ingresar los datos de tres personas, como el
nombre, apellido, edad y DNI y luego lo muestre por pantalla.
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	//Memoria
	string datos[4];

	//Asiganación de valores
	cout<<"PROGRAMA PARA INTRODUCIR DATOS DENTRO DE UN ARRAY DE TIPO STRING\n";
	for(int i=0; i<4; i++){
		if(i==0){
			cout<<"Ingrese su nombre: ";
			getline(cin,datos[i]);
		}
		else if(i==1){
			cout<<"Ingrese su apellido: ";
			getline(cin,datos[i]);
		}
		else if(i==2){
			cout<<"Ingrese su edad: ";
			getline(cin,datos[i]);
		}
		else if(i==3){
			cout<<"Ingrese su DNI: ";
			getline(cin,datos[i]);
		}
	}
	
	//Salida
	cout<<"\n";
	cout<<"Nombre-"<<datos[0]<<"; Apellido-"<<datos[1]<<"; Edad-"<<datos[2]<<"; DNI-"<<datos[3];
	
	return 0;
}
*/

/*
2. Hacer un array unidimensional que acepte ocho números enteros. Luego le
pregunte al usuario que ingrese un número a buscar, implementar una función que
busque ese número, si lo encuentra, debe retornar un valor de verdaderos, en caso
contrario, retornar falso.
*/
/*
#include <iostream>
using namespace std;

//Función buscar
bool buscar(int a, int b[8]){
	for(int i=0; i<8; i++){
		if(a==b[i]){
			return true;
		}
	}
	return false;
}

int main(){
	//Memoria
	int vector[8];
	int n;
	
	//Asignación de valores al vector
	cout<<"PROGRAMA PARA BUSCAR UN NUMERO DENTRO DE UN ARRAY QUE CONTIENE 8 NUMEROS\n";
	for(int i=0; i<8; i++){
		cout<<"Ingrese un número: ";
		cin>>vector[i];
	}
	cout<<"\n";
	
	//Búsqueda de un número en el vector
	cout<<"Ingrese el número a buscar dentro del vector: ";
	cin>>n;
	
	//Función buscar
	if(buscar(n,vector)==false){
		cout<<"NO se encontro el número dentro del array";
	}
	else{
		cout<<"SI se encontro el número dentro del array";
	}
	
	return 0;
}
*/

/*
3. Hacer un array 5x3 que acepte números enteros ingresados por el usuario. Al final,
debe mostrar la suma de todos los números que estén en una fila par.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int matriz[5][3];
	int sum;
	int summ=0;
	
	//Ingreso de datos
	cout<<"PROGRAMA PARA EL INGRESO DE DATOS DE UNA MATRIZ 5X3 Y CALCULO DE LA SUMA DE LAS FILAS PARES\n";
	for(int i=0; i<5; i++){
		for(int j=0; j<3; j++){
			cout<<"Ingrese un número: ";
			cin>>matriz[i][j];
		}
	}
	cout<<"\n";
		
	//Mostrar matriz
	cout<<"MATRIZ 5X3\n";
	for(int i=0; i<5; i++){
		for(int j=0; j<3; j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n";
	
	//Suma de cada fila param_type
	for(int i=0; i<5; i++){
		sum=0;
		for(int j=0; j<3; j++){
			if(i%2==0){
				sum+=matriz[i][j];
				summ+=matriz[i][j];
			}
		}
		if(i%2==0){
			cout<<"La suma de la fila "<<i<<" es: "<<sum<<"\n";
		}
	}
	cout<<"La suma total de todas las filas pares es: "<<summ;
	
	return 0;
}
*/

/*
4. Implementar un programa que rellene un array con los números primos
comprendidos entre 1 y 100 y los muestre en pantalla en orden descendente.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	bool prueba=true;
	int prim[50];
	int it=0;
	
	//Rellenar el array con ceros
	for(int i=0; i<50; i++){
		prim[i]=0;
	}
	
	//Relleno del array con primero entre 1 y 100
	for(int i=100; i>=1; i--){
		//Casos especiales
		if (i==0||i==1||i==4){ 
			prueba=false;
		}
		for (int x=2; x<i/2; x++){
			if (i%x==0){ 
				prueba=false;
			}
		}
		
		//Si no se pudo dividir por ninguno de los de arriba, sí es primo
		if(prueba==true){
			prim[it]=i;
			it++;
		}
		prueba=true;
	}
	
	//Mostrar el array prim
	cout<<"ARRAY PRIM\n";
	for(int i=0; i<50; i++){
		if(prim[i]!=0){
			cout<<prim[i]<<" ";
		}
	}
	
	return 0;
}
*/

/*
5. Implemente un programa que gestione los datos de stock de una tienda de abarrotes,
la información a recoger será: nombre del producto, precio, cantidad en stock. La
tienda dispone de 10 productos distintos. El programa debe ser capaz de:
	a. Dar de alta un producto nuevo.
	b. Buscar un producto por su nombre.
	c. Modificar el stock y precio de un producto dado.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria 1
	string prod[10][3];
	int op;
	int opsub2;
	int it=0;
	
	//Memoria 2
	bool prodnp;
	string prodn;
	
	//Programa en sí
	while(true){
		cout<<"PROGRAMA DE GESTION DE PRODUCTOS\n";
		cout<<"1. Dar de alta un producto nuevo[limite max 10 productos]\n";
		cout<<"2. Buscar un producto por su nombre\n";
		cout<<"3. Modificar el stock y precio de un producto dado\n";
		cout<<"4. Salir del programa\n";
		do{
			cout<<"Ingrese el numero de la opción a elegir: ";
			cin>>op;
			if(op!=1&&op!=2&&op!=3){
				cout<<"Error, ingrese de nuevo el número de opción\n\n";
			}
		} while(op!=1&&op!=2&&op!=3);
		cout<<"\n";
		
		//Condición a.
		if(op==1){
			if(it==10){
				cout<<"!!!ALERTA¡¡¡, esta reemplazando el primer producto de la lista\n";
				it=0;
			}
			cout<<"Ingrese los siguientes datos del producto\n";
			cout<<"Nombre del producto: ";
			cin>>prod[it][0];
			cout<<"Precio: ";
			cin>>prod[it][1];
			cout<<"Cantidad en stock: ";
			cin>>prod[it][2];
			cout<<"\n";
			it++;
		}
		//Condición b.
		else if(op==2){
			prodnp=false;
			cout<<"Ingrese el nombre del producto a buscar: ";
			getline(cin,prodn);
			getline(cin,prodn);
			for(int i=0; i<10; i++){
				if(prodn==prod[i][0]){
					prodnp=true;
					cout<<"SI se encontro el producto llamado \""<<prod[i][0]<<"\" su precio es \""<<prod[i][1]<<"\" su stock es \""<<prod[i][2]<<"\"\n\n";
					break;
				}
			}
			if(prodnp==false){
				cout<<"NO se encontro ningún producto llamado: "<<prodn<<"\n\n";
			}
		}
		//Condición c.
		else if(op==3){
			do{
				prodnp=false;
				cout<<"Ingrese el nombre del producto a modificar: ";
				getline(cin,prodn);
				getline(cin,prodn);
				cout<<"\n";
				for(int i=0; i<10; i++){
					if(prodn==prod[i][0]){
						prodnp=true;
						cout<<"SUBMENU PARA LA MODIFICACION DE UN PRODUCTO\n";
						cout<<"1. Precio del producto\n";
						cout<<"2. Stock del producto\n";
						do{
							cout<<"Ingrese el número de opción: ";
							cin>>opsub2;
							if(opsub2!=1&&opsub2!=2){
								cout<<"Error, ingrese de nuevo el número de opción\n\n";
							}
						} while(opsub2!=1&&opsub2!=2);
						cout<<"\n";
						if(opsub2==1){
							cout<<"Escriba el nuevo precio del producto: ";
							getline(cin,prod[i][1]);
							getline(cin,prod[i][1]);
							cout<<"\n";
						}
						else if(opsub2==2){
							cout<<"Escriba el nuevo stock del producto: ";
							getline(cin,prod[i][2]);
							getline(cin,prod[i][2]);
							cout<<"\n";
						}
						break;
					}
				}
			} while(prodnp==false);
		}
		//Salir del programa
		else if(op==4){
			break;
		}
	}
	
	return 0;
}
*/

/*
6. Escribe un programa que pida nueve números enteros y los almacene en una matriz
3x3. Calcula la suma de los números de cada fila y mostrar por pantalla el número de
fila con mayor suma.
*/
/*
#include <iostream>
using namespace std;

int main(){
	//Memoria
	int matriz[3][3];
	int sum[3];
	int temp;
	int tempi;
	
	//Asignacion de valores 0 para el vector sum[]
	for(int i=0; i<3; i++){
		sum[i]=0;
	}
	
	//Asignacion de valores para la matriz 3x3
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<"Ingrese un número: ";
			cin>>matriz[i][j];
			sum[i]+=matriz[i][j];
		}
	}
	cout<<"\n";
	
	//Mostrar matriz
	cout<<"MATRIZ 3X3\n";
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n";
	
	//Calculo de la fila con mayor suma
	temp=sum[0];
	tempi=0;
	for(int i=0; i<3; i++){
		if(temp<sum[i]){
			temp=sum[i];
			tempi=i;
		}
	}
	cout<<"La fila con la mayor suma de números es la: "<<tempi;
	
	return 0;
}
*/

/*
7. Escribe un programa, que trabajando mediante funciones, presente un menú al
usuario, mueva las columnas a la derecha o izquierda, asimismo mueva las filas para
arriba o para abajo.
*/
/*
#include <iostream>
using namespace std;

void mover_derecha(int** mat){
	
}

int main(){
	//Memoria
	int op;
	const int n=3;
	int** mat= new int* [n];
	for(int i=0; i<n; i++){
		mat[i]= new int [n];
	}
	
	//Ingreso de valores
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"Ingrese un número: ";
			cin>>mat[i][j];
		}
	}
	
	//Mostrar matriz
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	while(true){
		cout<<"MENU PARA FILAS Y COLUMNAS DE UNA MATRIZ\n";
		cout<<"1. Mover a la derecha\n";
		cout<<"2. Mover a la izquierda\n";
		cout<<"3. Mover hacia arriba\n";
		cout<<"4. Mover hacia abajo\n";
		break;
	}
	
	//Eliminar memorio de la matriz mat
	for(int i=0; i<3; i++){
		delete[] mat[i];
	}
	delete[] mat;
	
	return 0;
}
*/
