#ifndef CLASEMULTIMEDIA_H
#define CLASEMULTIMEDIA_H
#include <string>
#include <iostream>
using namespace std;

class ClaseMultimedia{
public:
	ClaseMultimedia(bool, string);
	~ClaseMultimedia();
private:
	bool interactiva;
	string titulo;
};

#endif

