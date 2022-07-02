#ifndef COLOR_H
#define COLOR_H
#include <string>
using namespace std;

class Color{
public:
	Color();
	~Color();
	void dar_RGB(int,int,int);
protected:
	int R;
	int G;
	int B;
};

#endif

