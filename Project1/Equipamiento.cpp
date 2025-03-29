
#include "Equipamiento.h"

Equipamiento::Equipamiento() {
	this->exteriores = 0;
	this->material = "sin def";
	this->peso = -1;

}

Equipamiento::Equipamiento(string nombre, int precio, Proveedor* proveedor, bool exteriores, string material, int peso ) :Producto(nombre, precio, proveedor) {
	this->exteriores= exteriores;
	this->material= material;
	this->peso= peso;
}
void Equipamiento::setExteriores(bool exteriores) { 
	this->exteriores = exteriores;
}

bool Equipamiento::getExteriores() { return exteriores;  }


void Equipamiento::setMaterial(string material) {
	this->material = material;
}

string Equipamiento::getMaterial() { return material;  }



void Equipamiento::setPeso(int peso) { this->peso=peso; }

int Equipamiento::getPeso() { return peso; }

string Equipamiento::toString() {
	stringstream s;
	s << "--Equipamiento--" << endl;
	s << Producto::toString();
	s << "Exteriores:  " << this->exteriores << endl;
	s << "Material:  " << this->material << endl;
	s << "Peso:" << this->peso << endl;
	if (proveedor != nullptr) {
		s << proveedor->toString() << endl;
	}
	else {
		s << "Proveedor: sin asignar" << endl;
	}
	s << endl;
	return s.str();
}

void Equipamiento::guardar(ostream& salida)
{
	salida << "Equipamiento" << "\t";
	salida << this->nombre << "\t";
	salida << this->precio << "\t";
	if (proveedor != nullptr) {
		salida << proveedor->getIDProve() << "\t";
	}
	else {
		salida << "0" << "\t";
	}
	salida << this->exteriores << "\t";
	salida << this->material << "\t";
	salida << this->peso << "\n";

}

Equipamiento::~Equipamiento() {}