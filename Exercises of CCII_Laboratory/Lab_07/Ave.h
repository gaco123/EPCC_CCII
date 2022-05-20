#ifndef AVE_H
#define AVE_H
#include <string>
#include <iostream>
using namespace std;

class Ave{
public:
	Ave();
	Ave(bool,string,string,string,string);
	~Ave();
	void mostrar_Vals();
protected:
	bool es_volador;
	string sonido;
	string tam_pico;
	string color_plumas;
	string tam_patas;
};

#endif

