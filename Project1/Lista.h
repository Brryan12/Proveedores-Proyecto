#ifndef LISTA
#define LISTA

#include "Nodo.h"
#include <fstream>
#include "Tecnologia.h"
#include "Herramienta.h"
#include "Equipamiento.h"
using namespace std;

class Lista{
private:
	Nodo *primero;
	Nodo *actual;
public:
	Lista();
	~Lista();
	void insertarFinal(Producto* producto);
	string toString();
	string toStringEspecifico(string producto);
	Lista* retornaListaProveedor(string IDproveedor);
	void guardarLista();
	void cargarLista();
}; 
#endif