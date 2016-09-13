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
		aux=aux->getSig();
	}
}

void ListaDoble::AddFinal(int Dato)
{
	Nodo* aux = new Nodo(Dato, NULL, this->T);
	if(!ListaDobleVacia())
	{
		T->setSig(aux);
		T = aux;
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
		Nodo* aux = BuscarElemento(Ref);

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
			Nodo* aux = NULL;
			aux = T->getAnt();
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

void ListaDoble::RemoveRef(int Ref)
{
	if(!ListaDobleVacia())
	{
		Nodo* aux = BuscarElemento(Ref);
		if(aux != NULL){
			if (aux != H && aux != T)
			{
				aux->getAnt()->setSig(aux->getSig());
				aux->getSig()->setAnt(aux->getAnt());
			}else{
				(aux==H)?RemoveInicio():RemoveFinal();
			}
		}else{
			std::cout<<"No se encontró la referencia a eliminar"<<std::endl;
		}
		
	}else{
		std::cout<<"La lista está vacía"<<std::endl;
	}
}

Nodo* ListaDoble::BuscarElemento(int Dato)
{
	if(!ListaDobleVacia())
	{
		Nodo* aux = H;

			while(aux != NULL && aux->getDato()!=Dato)
					aux = aux->getSig();

		return aux;
	}else{
		return NULL;
	}
}

void ListaDoble::VaciarListaDoble(void)
{
	H = NULL;
	T = H;
}