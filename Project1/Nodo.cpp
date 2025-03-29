#include "Nodo.h"

Nodo::Nodo(Producto* producto, Nodo* next) : producto(producto), next(next){}

Nodo:: ~Nodo() { 
	delete producto;
	cout << "Se ha destruido un Nodo" << endl;
}

void Nodo::setProducto(Producto *producto) { this->producto=producto; }
Producto*   Nodo::getProducto() { return this->producto; }
void Nodo::setNext(Nodo* next) { this->next=next; }
Nodo* Nodo::getNext() { return next; }

string Nodo::toStringNodo() {
	return  producto->toString();
}