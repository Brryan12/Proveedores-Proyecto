#include "Lista.h"
#include <fstream>

Lista::Lista(){
	primero = nullptr;
	actual = nullptr;
}
//---------------------------------------------//
Lista::~Lista() {
	while (primero != nullptr) { 
		actual = primero;
		primero = primero->getNext();
		delete actual;
	}
}

void Lista::insertarFinal(Producto* producto)
{
	Nodo* nodoAux = new Nodo(producto, nullptr);
	if (primero == nullptr) {
		primero = nodoAux;
	}
	else {
		actual = primero;
		while (actual->getNext() != nullptr) {
			actual = actual->getNext();
		}
		actual->setNext(nodoAux);
	}
}

string Lista::toString()
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getProducto()->toString() << endl;
		actual = actual->getNext();
	}
	return s.str();
}

string Lista::toStringEspecifico(string producto)
{
	stringstream s;
	actual = primero;
	while (actual != nullptr) {
		if (producto== "tecnologia") {
			if (dynamic_cast<Tecnologia*>(actual->getProducto()) != nullptr)
				s << actual->getProducto()->toString() << endl;
		}
		else if (producto == "herramienta") {
			if (dynamic_cast<Herramienta*>(actual->getProducto()) != nullptr)
				s << actual->getProducto()->toString() << endl;
		}
		else if (producto == "equipamiento") {
			if (dynamic_cast<Equipamiento*>(actual->getProducto()) != nullptr)
				s << actual->getProducto()->toString() << endl;
		}
		actual = actual->getNext();
	}
	return s.str();
}

Lista* Lista::retornaListaProveedor(string IDproveedor)
{
	Lista* auxLista = new Lista();
	actual = primero;
	while (actual != nullptr) {
		if (actual->getProducto()->getProve()->getIDProve() == IDproveedor) {
			auxLista->insertarFinal(actual->getProducto());
		}
		actual = actual->getNext();
	}
	return auxLista;
}

void Lista::guardarLista()
{
	ofstream salida;
	salida.open("../productos.txt");
	if (salida.good())
	{
		actual = primero;
		while (actual != nullptr) {
			actual->getProducto()->guardar(salida);
			actual = actual->getNext();
		}
	}
	else {
		cerr << "Error al abrir el archivo" << endl;
	}
	salida.close();

	salida.open("../proveedores.txt");
	if (salida.good()) {
		actual = primero;
		while (actual != nullptr) {
			bool yaGuardado = false;
			string idProveActual = actual->getProducto()->getProve()->getIDProve();

			Nodo* aux = primero;
			while (aux != actual) {
				string idProveAux = aux->getProducto()->getProve()->getIDProve();
				if (idProveAux == idProveActual) {
					yaGuardado = true;  
					break;
				}
				aux = aux->getNext();
			}

			if (!yaGuardado) {
				actual->getProducto()->getProve()->guardar(salida);
			}

			actual = actual->getNext();  
		}
	}
	else {
		cerr << "Error al abrir el archivo" << endl;
	}
	salida.close();
}

void Lista::cargarLista() {
    ifstream entrada;
    entrada.open("../productos.txt");
    if (entrada.good()) {
        while (!entrada.eof()) {
            string tipo, nombre, precio, idproveedor;
            getline(entrada, tipo, '\t');

            if (tipo == "Tecnologia") {
                string IA;
                getline(entrada, nombre, '\t');
                getline(entrada, precio, '\t');
                getline(entrada, idproveedor, '\t');
                getline(entrada, IA, '\n');

                if (!nombre.empty() && !precio.empty() && !idproveedor.empty() && !IA.empty()) {
                    Proveedor* proveedor = nullptr;

                    ifstream entradaProveedores("../proveedores.txt");
                    if (entradaProveedores.good()) {
                        string id, provNombre, categoria, nacional;
                        while (getline(entradaProveedores, id, '\t')) {
                            getline(entradaProveedores, provNombre, '\t');
                            getline(entradaProveedores, categoria, '\t');
                            getline(entradaProveedores, nacional, '\n');

                            if (id == idproveedor) {
                                proveedor = new Proveedor(id, provNombre, stoi(categoria), stoi(nacional));
                                break; 
                            }
                        }
                        entradaProveedores.close(); 
                    }
                    else {
                        cerr << "Error al abrir el archivo proveedores.txt" << endl;
                    }

                    if (proveedor != nullptr) {
                        Tecnologia* tecAux = new Tecnologia(nombre, stoi(precio), proveedor, stoi(IA));
                        this->insertarFinal(tecAux); 
                    }
                }
            }
            else if (tipo == "Herramienta") {
                string nivelSeguridad, categoria;
                getline(entrada, nombre, '\t');
                getline(entrada, precio, '\t');
                getline(entrada, idproveedor, '\t');
                getline(entrada, nivelSeguridad, '\t');
                getline(entrada, categoria, '\n');

                if (!nombre.empty() && !precio.empty() && !idproveedor.empty() && !nivelSeguridad.empty() && !categoria.empty()) {
                    Proveedor* proveedor = nullptr;

                    ifstream entradaProveedores("../proveedores.txt");
                    if (entradaProveedores.good()) {
                        string id, provNombre, categoriaProv, nacional;
                        while (getline(entradaProveedores, id, '\t')) {
                            getline(entradaProveedores, provNombre, '\t');
                            getline(entradaProveedores, categoriaProv, '\t');
                            getline(entradaProveedores, nacional, '\n');

                            if (id == idproveedor) {
                                proveedor = new Proveedor(id, provNombre, stoi(categoriaProv), stoi(nacional));
                                break;
                            }
                        }
                        entradaProveedores.close(); 
                    }
                    else {
                        cerr << "Error al abrir el archivo proveedores.txt" << endl;
                    }
                    if (proveedor != nullptr) {
                        Herramienta* herAux = new Herramienta(nombre, stoi(precio), proveedor, stoi(nivelSeguridad), stoi(categoria));
                        this->insertarFinal(herAux); 
                    }
                }
            }
            else if (tipo == "Equipamiento") {
                string exteriores, material, peso;
                getline(entrada, nombre, '\t');
                getline(entrada, precio, '\t');
                getline(entrada, idproveedor, '\t');
                getline(entrada, exteriores, '\t');
                getline(entrada, material, '\t');
                getline(entrada, peso, '\n');

                if (!nombre.empty() && !precio.empty() && !idproveedor.empty() && !exteriores.empty() && !material.empty() && !peso.empty()) {
                    Proveedor* proveedor = nullptr;

                    ifstream entradaProveedores("../proveedores.txt");
                    if (entradaProveedores.good()) {
                        string id, provNombre, categoria, nacional;
                        while (getline(entradaProveedores, id, '\t')) {
                            getline(entradaProveedores, provNombre, '\t');
                            getline(entradaProveedores, categoria, '\t');
                            getline(entradaProveedores, nacional, '\n');

                            if (id == idproveedor) {
                                proveedor = new Proveedor(id, provNombre, stoi(categoria), stoi(nacional));
                                break; 
                            }
                        }
                        entradaProveedores.close();
                    }
                    else {
                        cerr << "Error al abrir el archivo proveedores.txt" << endl;
                    }
                    if (proveedor != nullptr) {
                        Equipamiento* equiAux = new Equipamiento(nombre, stoi(precio), proveedor, stoi(exteriores), material, stoi(peso));
                        this->insertarFinal(equiAux);  
                    }
                }
            }
        }
    }
    else {
        cerr << "Error al abrir el archivo productos.txt" << endl;
    }

    entrada.close();
}



