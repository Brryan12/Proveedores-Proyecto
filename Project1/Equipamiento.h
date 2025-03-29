#ifndef EQUIPAMIENTO
#define EQUIPAMIENTO

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"
using namespace std;

class Equipamiento :public Producto {
private:
	bool exteriores;
	string material;
	int peso;
public:
	Equipamiento();
	Equipamiento(string nombre, int precio, Proveedor* proveedor, bool exteriores, string material, int peso);
	void setExteriores(bool exteriores);
	bool getExteriores();
	void setMaterial(string material);
	string getMaterial();
	string toString();
	void setPeso(int peso);
	int getPeso();
	void guardar(ostream& salida);
	~Equipamiento();
};
#endif