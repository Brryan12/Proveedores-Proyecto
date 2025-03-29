#ifndef PROVEEDOR
#define PROVEEDOR

#include <iostream>
#include <string>
#include<sstream>
using namespace std;

class Proveedor {
private:
	string nombreProveedor;
	string IDproveedor;
	int categoria;
	bool nacional;
public:
	Proveedor();
	Proveedor(string nombreProveedor, string IDproveedor, int categoria, bool nacional);
	void setNombreProve(string nombreProveedor);
	string getNomProve();
	void setIDProveedor(string IDProveedor);
	string getIDProve();
	void setCategoria(int categoria);
	int getCategoria();
	void setNacional(bool nacional);
	bool getNacional();
	string toString();
	void guardar(ostream& salida);
	~Proveedor();
}; 
#endif

