#ifndef OPERACIONBASE_H
#define OPERACIONBASE_H

class operacionBase{
public:
	operacionBase();
	~operacionBase();
	void setOperador(int);
	int getOperador();
private:
	int operador;
};

#endif

