#include "ListaDoble.h"

ListaDoble::ListaDoble()
{
	this->H=NULL;
	this->T=NULL;
}

ListaDoble::ListaDoble(int Dato)
{
	Nodo * aux= new Nodo(Dato);
	this->H=aux;
	this->T=aux;
}

bool ListaDoble::ListaDobleVacia()
{
	if (this->H == NULL && this->T == NULL)
		return true;
	return false;
}

void ListaDoble::AddInicio(int Dato)
{
	Nodo* aux = new Nodo(Dato,this->H, NULL);
	if (!ListaDobleVacia())
	{
		H->setAnt(aux);
		H = aux;
	}else{
		H = T = aux;
	}
}

void ListaDoble::Show()
{
	Nodo* aux = this->H;
	while(aux!=NULL)
	{
		std::cout<<aux->getDato()<<std::endl;
		if (aux->getAnt()!=NULL)
		{
			std::cout<<"El anterior de "<<aux->getDato()<<" es: "<< aux->getAnt()->getDato()<<std::endl;
		}
		aux=aux->getSig();
	}
}

void ListaDoble::AddFinal(int Dato)
{
	Nodo* aux = new Nodo(Dato, NULL, this->T);
	if(!ListaDobleVacia())
	{
		T->setSig(aux);
	}else{
		H = aux;
		T = aux;
	}
}

void ListaDoble::AddRef(int Dato, int Ref)
{
	if(ListaDobleVacia())
	{
		Nodo* aux = new Nodo(Dato);
		H = aux;
		T = H;
		std::cout<<"La lista estaba vacía, sin embargo se agregó el elemento"<<std::endl;
	}else{
		Nodo* aux = H;
		while(aux->getDato() != Ref || aux != NULL)
		{
			aux = aux->getSig();	
		}
		//Sale del while siendo aux el nodo donde se encuentra la ref. (o siendo nulo)
		if(aux != NULL)
		{
			Nodo* aux2 = new Nodo(Dato, aux->getSig(), aux);
			aux->getSig()->setAnt(aux2);
			aux->setSig(aux2);
		}else{
			std::cout<<"No existe la referencia en la lista"<<std::endl;
		}
	}
}

int ListaDoble::RemoveInicio(void)
{
	if(!ListaDobleVacia())
	{
		int Dato = H->getDato();
		H = H->getSig();
		H->setAnt(NULL);
		return Dato;
	}else{
		std::cout<<"La lista está vacía"<<std::endl;
		return (int)NULL;
	}	
}

int ListaDoble::RemoveFinal(void)
{
	if(!ListaDobleVacia())
	{
		int Dato = T->getDato();
		if(H!=T)
		{
			Nodo* aux = H;
			while(aux->getSig()!=T)
			{
				aux = aux->getSig();
			}
			aux->setSig(NULL);
			T = aux;

		}else{
				VaciarListaDoble();
		}
		return Dato;
	}else{
		std::cout<<"La lista está vacía"<<std::endl;
		return (int)NULL;
	}	
}

int ListaDoble::RemoveRef(int Ref)
{
	if(!ListaDobleVacia())
	{
	
		Nodo* aux = H;
		Nodo* aux2 = NULL; 
		while(aux->getDato()!= Ref || aux != NULL)
		{
			aux2 = aux;
			aux = aux->getSig();
		}
		aux2->setSig(aux->getSig());
		
		return Ref;

	}else{
		std::cout<<"La lista está vacía"<<std::endl;
		return (int)NULL;
	}
}

Nodo* ListaDoble::BuscarElemento(int Dato)
{
	if(!ListaDobleVacia())
	{
		Nodo* aux = H;
		while(aux->getDato()!=Dato && aux != NULL)
			aux = aux->getSig();
		return aux;
	}
}

void ListaDoble::VaciarListaDoble(void)
{
	H = NULL;
	T = H;
}