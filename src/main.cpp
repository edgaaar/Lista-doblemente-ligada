#include "ListaDoble.h"



int main()
{
	ListaDoble ld = ListaDoble();
	//ld.RemoveInicio();
	//ld.RemoveFinal();
	ld.RemoveRef(99);
	ld.RemoveFinal();
	ld.RemoveInicio();
	ld.AddInicio(4);
	ld.AddInicio(5);
	ld.AddFinal(20);
	ld.AddFinal(19);
	ld.AddFinal(18);
	ld.AddInicio(6);
	//ld.RemoveInicio();
	
	ld.AddRef(50,5);
	ld.AddRef(25,99);
	ld.AddRef(21,6);
	ld.AddInicio(7);
	ld.RemoveFinal();
	ld.RemoveInicio();
	ld.RemoveRef(4);
	ld.RemoveRef(99);
	/*ld.RemoveFinal();
	ld.RemoveFinal();
	ld.RemoveFinal();
	*/ld.Show();

	std::cout<<"Hello World"<<std::endl;
	return 0;
}