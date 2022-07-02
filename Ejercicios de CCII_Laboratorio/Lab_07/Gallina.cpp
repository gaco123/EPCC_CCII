#include "Gallina.h"

Gallina::Gallina(){
	sonido="Kikiri, ki!";
	es_volador=false;
	tam_pico="pequeño";
	color_plumas="marrones, blancas o negras";
	tam_patas="cortas";
}
Gallina::Gallina(bool _es_volador, string _sonido, string _tam_pico, string _color_plumas, string _tam_patas)
:Ave(_es_volador, _sonido, _tam_pico, _color_plumas, _tam_patas){
}
Gallina::~Gallina(){
}
