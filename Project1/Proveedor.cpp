#include "Proveedor.h"

Proveedor::Proveedor() { 
	nombreProveedor = "Sin def";
	IDproveedor = "Sin def";
	categoria= -1;
	nacional = 1;
}


Proveedor::Proveedor( string id, string nombreProveedor, int categoria,bool nacional) {
	this->IDproveedor = id;
	this->nombreProveedor = nombreProveedor;
	this->categoria = categoria;
	this->nacional = nacional;
}


void Proveedor::setNombreProve(string nombreProveedor) { nombreProveedor = nombreProveedor; }
string Proveedor::getNomProve() { return nombreProveedor; }

void Proveedor::setIDProveedor(string IDproveedor) {
	this->IDproveedor= IDproveedor;
}

string Proveedor::getIDProve() {
	return IDproveedor;
}

void Proveedor::setCategoria(int categoria) {
	this->categoria = categoria;
}

int Proveedor::getCategoria() {
	return categoria;
}

void Proveedor::setNacional(bool nacional) { 
	this->nacional = nacional;
}

bool Proveedor::getNacional() { 
	return nacional;
}

string Proveedor::toString() { 
	stringstream s;
	s <<"\tNombre Proveedor: " << this->nombreProveedor << endl;
	s <<"\tID Provedor: " << this ->IDproveedor << endl;
	s <<"\tCategoria: " << this ->categoria << endl;
	s <<"\tNacional: " << this ->nacional << endl;
	return s.str();
}

void Proveedor::guardar(ostream& salida) {
	salida << this->IDproveedor << "\t";
	salida << this->nombreProveedor << "\t";
	salida << this->categoria << "\t";
	salida << this->nacional << "\n";
}
Proveedor::~Proveedor() { }