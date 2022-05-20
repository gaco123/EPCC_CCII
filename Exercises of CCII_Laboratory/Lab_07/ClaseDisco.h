#ifndef CLASEDISCO_H
#define CLASEDISCO_H
#include "ClaseMultimedia.h"

class ClaseDisco: public ClaseMultimedia{
public:
	ClaseDisco(bool,string,string);
	~ClaseDisco();
private:
	string calidad;
};

#endif

