
/*
Exercise 1
• Cual es la diferencia entre inicializar una variable con {} y
una variable con =
*/
/*
Para entenderlo veamos estas variable:
int a = 2.5; Incialización copiada -> NO hay error, aunque para el programa (int a = 2;)
int a{2.5};  Inicialización directa -> SI hay error, debido a que "{}", no permite la conversión restrictiva
*/
/*
La inicialización copiada permite la transformación de un tipo de dato a otro
implicitamente, incluso, aunque halla perdida de datos a esto se le llama
"conversión restrictiva", por otro lado, tenemos a la incialización directa
esta solo permite "conversiones no-restrictivas", en otras palabras, no permite
la perdida de datos.
*/

/*
Exercise 2
• Reescriba el ejercicio de la tabla de multiplicación usando
funciones.
*/
/*
#include <iostream>
using namespace std;

int** matReservation(int** m1, int n){
	m1 = new int* [n];
	for(int i=0; i<n; i++){
		m1[i] = new int [n];
	}
	
	return m1;
}
void tablefirst_Generation(int** m1, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			m1[i][j]=(i+1)*(j+1);
		}
	}
}
void tableshow_Top(int n){
	cout<<"Tabla de multiplicación del 1 hasta el "<<n<<endl;
	for(int i=0; i<=n; i++){
		if (i==0){
			cout<<"*\t|\t";
		}
		else{
			cout<<i<<"\t";
		}
	}
	cout<<endl;
	for(int i=0; i<=n+1; i++){
		cout<<"--------";
	}
	cout<<endl;
}
void tableshow_Bot(int **m1, int n){
	for(int i=0; i<n; i++){
		cout<<m1[i][0]<<"\t|\t";
		for(int j=0; j<n; j++){
			cout<<m1[i][j] << "\t";
		}
		cout<<endl;
	}
	cout<<endl;
}
void matDelete(int** m1, int n){
	for(int i=0; i<n; i++){
		delete[] m1[i];
	}
	delete[] m1;
}
	
int main(){
	//Memoria
	int n=0;
	
	//Ingreso de datos
	while(n<=0){
		cout<<"Ingrese el número hasta donde se mostrara la tabla de multiplicar: ";
		cin>>n;
		if(n<=0){
			cout<<"Error vuelva a intentarlo"<<endl;
		}
	}
	cout<<endl;
	
	//Reservación de memoria para la matriz m1
	int** m1{};
	m1=matReservation(m1,n);
	
	//Genera los numeros de la tabla para la matriz m1
	tablefirst_Generation(m1,n);
	
	//Mostrar la interfaz horizontal superior
	tableshow_Top(n);
	
	//Mostrador de datos de la matriz m1 // Mostrar la interfaz vertical izquierda
	tableshow_Bot(m1,n);
	
	//Liberación de memoria para la matriz m1
	matDelete(m1,n);
	
	return 0;
}
*/

/*
Exercise 3
• Reescriba el ejercicio del conteo de palabras. Imprima las
palabras en forma alineada.
	– Escriba una función que encuentre la palabra más grande. 
	– Una función para limpiar caracteres que no sean alfabéticos.
*/
/*
#include <iostream>
#include <map>
#include <string>
using namespace std;

void largeWord(map<string,int> counts){
	auto i1 = counts.begin();
	string lw = i1->first;
	
	for(auto i=counts.begin(); i!=counts.end(); i++){
		if(i->first.length()>lw.length()){
			lw=i->first;
		}
	}
	
	cout<<"La palabra mas grande del texto es: "<<lw<<"\n";
}
string removeNumbers(string word){
	for(int i = 0; i<word.length(); i++){
		if(isdigit(word[i])){
			word.erase(i, 1);
			i--;
		}
	}
		
	return word;
}

int main() {
	//Memory
	
	map<string, int> counts{};
	string word{};
	
	//Input
	cout<<"PROGRAM TO CALCULATE THE FREQUENCY OF EACH WORD ON THE \"MAP\"\n";
	cout<<"(To end the entry of words, press CTRL+Z and then ENTER)\n";
	do{
		cout<<"Enter any word: ";
		++counts[removeNumbers(word)];
	}while(cin>>word);
	cout<<"\n";
	
	//Frequency
	cout<<"TABLE OF FREQUENCY OF EACH WORD\n";
	for(auto i=counts.begin(); i!=counts.end(); i++){
		if(i->first!=""){
			cout<<i->first<<" => "<<i->second<<"\n";
		}
	}
	
	//Largest Word
	largeWord(counts);
	
	return 0;
}
*/
