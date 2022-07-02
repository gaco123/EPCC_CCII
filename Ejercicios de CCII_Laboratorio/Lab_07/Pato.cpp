#include "Pato.h"

Pato::Pato(){
	sonido="Cuack!";
	es_volador=true;
	tam_pico="grande";
	color_plumas="verdes y marrones";
	tam_patas="medianas";
}
Pato::Pato(bool _es_volador, string _sonido, string _tam_pico, string _color_plumas, string _tam_patas)
:Ave(_es_volador, _sonido, _tam_pico, _color_plumas, _tam_patas){
}
Pato::~Pato(){
}

