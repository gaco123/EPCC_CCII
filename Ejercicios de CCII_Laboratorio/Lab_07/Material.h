#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
using namespace std;

class Material{
public:
	Material();
	~Material();
	void dar_Material(string);
protected:
	string material;
};

#endif

