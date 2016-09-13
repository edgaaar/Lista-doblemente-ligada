#include <iostream>

class Nodo
{
private:
	int Dato;
	Nodo* Sig;
	Nodo* Ant;
public:
	Nodo(int Dato, Nodo* Sig, Nodo* Ant);
	Nodo(int Dato);
	void setDato(int Dato);
	void setSig(Nodo* Sig);
	void setAnt(Nodo* Ant);
	int getDato();
	Nodo* getSig();
	Nodo* getAnt();
	//~Nodo();
};