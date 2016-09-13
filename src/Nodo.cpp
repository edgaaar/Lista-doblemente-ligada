#include "Nodo.h"

Nodo::Nodo(int Dato , Nodo* Sig, Nodo* Ant)
{
	this->Dato = Dato;
	this->Sig = Sig;
	this->Ant = Ant;

}

Nodo::Nodo(int Dato)
{
	this->Dato = Dato;
	this->Sig = NULL;
	this->Ant = NULL;
}

void Nodo::setDato(int Dato)
{
	this->Dato = Dato;
}

void Nodo::setSig(Nodo* Sig)
{
	this->Sig = Sig;
}

void Nodo::setAnt(Nodo* Ant)
{
	this->Ant = Ant;
}

int Nodo::getDato()
{
	return this->Dato;
}

Nodo* Nodo::getSig()
{
	return this->Sig;
}

Nodo* Nodo::getAnt()
{
	return this->Ant;
}