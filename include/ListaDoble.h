#include "Nodo.h"

class ListaDoble
{
public:
	Nodo* H;
	Nodo* T;	
	ListaDoble();
	ListaDoble(int Dato);
	bool ListaDobleVacia();
	void AddInicio(int Dato);
	void AddFinal(int Dato);
	void AddRef(int Dato, int Ref);
	int RemoveInicio();
	int RemoveFinal();
	int RemoveRef(int Ref);
	void VaciarListaDoble();
	Nodo* BuscarElemento(int Dato);
	void Show();
};