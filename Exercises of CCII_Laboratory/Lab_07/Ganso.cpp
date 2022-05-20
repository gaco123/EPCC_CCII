#include "Ganso.h"

Ganso::Ganso(){
	sonido="On!, On!";
	es_volador=true;
	tam_pico="mediano";
	color_plumas="blancas";
	tam_patas="grandes";
}
Ganso::Ganso(bool _es_volador, string _sonido, string _tam_pico, string _color_plumas, string _tam_patas)
:Ave(_es_volador, _sonido, _tam_pico, _color_plumas, _tam_patas){
}
Ganso::~Ganso(){
}

