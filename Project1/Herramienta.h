#ifndef HERRAMIENTA
#define HERRAMIENTA

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"
using namespace std;

class Herramienta:public Producto {
private:
	int nivelSeguridad;
	int categoria;
public:
	Herramienta();
	Herramienta(string nombre, int precio, Proveedor* proveedor,  int nivelSeguridad, int categoria);
	void setNivelSeguridad(int);
	int getNivelSeguridad();
	void setCategoria(int);
	int getCategoria();
	string toString();
	void guardar(ostream& salida);
	~Herramienta();
};
#endif