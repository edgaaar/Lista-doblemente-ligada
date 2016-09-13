#include "ListaDoble.h"



int main()
{
	ListaDoble ld = ListaDoble();
	ld.RemoveInicio();
	ld.RemoveFinal();
	ld.AddInicio(4);
	ld.AddInicio(5);
	ld.AddFinal(20);
	ld.AddInicio(6);
	//ld.RemoveInicio();
	
	//ld.AddRef(50,5);
	ld.AddInicio(7);
	ld.RemoveFinal();
	ld.Show();

	std::cout<<"Hello World"<<std::endl;
	return 0;
}