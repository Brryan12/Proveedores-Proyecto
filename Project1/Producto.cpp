#include "Producto.h"

Producto::Producto() {
	nombre = "sin definir";
	precio = 0;
	proveedor = nullptr;
}


Producto::Producto(string nombre, int precio, Proveedor* proveedor): nombre(nombre), precio(precio), proveedor(proveedor){}

void Producto::setNombre(string nombre) { this->nombre = nombre; }
string Producto::getNombre() { return nombre; }

void Producto::setPrecio(int precio) { this->precio = precio; }
int Producto::getPrecio() { return precio; }

void Producto::setProve(Proveedor* proveprove) { this->proveedor = proveedor; }
Proveedor* Producto::getProve() { return  this->proveedor; }

string Producto::toString() {
	stringstream s;
	s << "Nombre:  " << nombre << endl;
	s << "Precio:" << precio << endl;
	return s.str();
}

Producto::~Producto() {  }

