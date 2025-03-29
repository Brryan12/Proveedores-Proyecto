#ifndef PRODUCTO
#define PRODUCTO

#include <iostream>
#include "Proveedor.h"
#include <string>
#include <sstream>
using namespace std;

class Producto{
protected:
	string nombre;
	int precio;
	Proveedor* proveedor;
public:
	Producto();
	Producto(string nombre, int precio, Proveedor* provproveedoredor);
	virtual void setNombre(string nombre);
	virtual string getNombre();
	virtual void setPrecio(int precio);
	virtual int getPrecio();
	virtual void setProve(Proveedor* proveedor);
	virtual Proveedor* getProve();
	virtual string toString();
	virtual void guardar(ostream& salida)=0;
	virtual ~Producto();
};

#endif


