
#include "Herramienta.h"

Herramienta::Herramienta() {
	nivelSeguridad = 0;
	categoria = 0;
}


Herramienta::Herramienta(string nombre, int precio, Proveedor* proveedor, int nivelSeguridad, int categoria):Producto(nombre, precio, proveedor) {
	this->nivelSeguridad = nivelSeguridad;
	this->categoria = categoria;
}

void Herramienta::setNivelSeguridad(int nivelSeguridad) { this->nivelSeguridad = nivelSeguridad; }
int  Herramienta::getNivelSeguridad(){ return nivelSeguridad; }

void Herramienta::setCategoria(int categoria) { this->categoria = categoria; }
int Herramienta::getCategoria() { return categoria; }


string Herramienta::toString() {
	stringstream s;
	s << "--Herramienta--" << endl;
	s << Producto::toString();
	s << "nivelSeguridad:  " << this->nivelSeguridad << endl;
	s << "Categoria:" << this->categoria << endl;
	if (proveedor != nullptr) {
		s << proveedor->toString() << endl;
	}
	else {
		s << "Proveedor: sin asignar" << endl;
	}
	s << endl;
	return s.str();
}

void Herramienta::guardar(ostream& salida)
{
	salida << "Herramienta" << "\t";
	salida << this->nombre << "\t";
	salida << this->precio << "\t";
	if (proveedor != nullptr) {
		salida << proveedor->getIDProve() << "\t";
	}
	else {
		salida << "0" << "\t";
	}
	salida << this->nivelSeguridad << "\t";
	salida << this->categoria << "\n";


}

Herramienta::~Herramienta() {  }

