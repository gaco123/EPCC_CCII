#include "Ave.h"

Ave::Ave(){
	sonido={};
	es_volador={};
	tam_pico={};
	color_plumas={};
	tam_patas={};
}
Ave::Ave(bool _es_volador, string _sonido, string _tam_pico, string _color_plumas, string _tam_patas){
	sonido=_sonido;
	es_volador=_es_volador;
	tam_pico=_tam_pico;
	color_plumas=_color_plumas;
	tam_patas=_tam_patas;
}
Ave::~Ave(){
}
void Ave::mostrar_Vals(){
	string temp{};
	if(es_volador==true){
		temp="Si";
	}
	else{
		temp="No";
	}
	cout<<"Sonido?: "<<sonido<<"\n";
	cout<<"Vuela?: "<<temp<<"\n";
	cout<<"Tamaño del pico?: "<<tam_pico<<"\n";
	cout<<"Color de las plumas?: "<<color_plumas<<"\n";
	cout<<"Tamaño de las patas?: "<<tam_patas<<"\n";
}
