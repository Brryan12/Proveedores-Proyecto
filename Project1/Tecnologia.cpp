#include "Tecnologia.h"

Tecnologia::Tecnologia() {
	this->IA = 0;

}
Tecnologia::Tecnologia(string nombre, int precio, Proveedor* prove, bool IA) :Producto(nombre, precio, prove) {
	this->IA = IA;
}
void Tecnologia::setIA(bool IA) { this->IA = IA; }
int Tecnologia::getIA() { return IA; }

string Tecnologia::toString() {
	stringstream s;
	s << "--Tecnologia--" << endl;
	s << Producto::toString();
	s << "IA:" << this->IA  << endl;
	if (proveedor != nullptr) {
		s << proveedor->toString() << endl;
	}
	else {
		s << "Proveedor: sin asignar" << endl;
	}
	s << endl;
	return s.str();
}

void Tecnologia::guardar(ostream& salida)
{
	salida << "Tecnologia" << "\t";
	salida << this->nombre << "\t";
	salida << this->precio << "\t";
	if (proveedor != nullptr) {
		salida << proveedor->getIDProve() << "\t";
	}
	else {
		salida << "0" << "\t";
	}
	salida << this->IA << "\n";

}

Tecnologia::~Tecnologia() {}