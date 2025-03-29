#ifndef  TECNOLOGIA
#define TECNOLOGIA

#include <iostream>
#include <string>
#include<sstream>
#include "Producto.h"
using namespace std;

class Tecnologia :public Producto {
private:
	bool IA;
public:
	Tecnologia();
	Tecnologia(string nombre, int precio,Proveedor* proveedor, bool IA);
	void setIA(bool IA);
	int getIA();
	string toString();
	void guardar(ostream& salida);
	static Tecnologia* cargar(istream& entrada);
	~Tecnologia();
};

#endif
