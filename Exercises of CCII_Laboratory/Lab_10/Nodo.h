#ifndef NODO_H
#define NODO_H
#include <cstddef>

class Nodo{
public:
	Nodo();
	~Nodo();
	Nodo* sig;
	int val;
};

#endif

