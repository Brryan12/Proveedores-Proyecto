#ifndef NODO
#define NODO

#include "Producto.h"
using namespace std;

class Nodo {
private:
    Producto* producto;
    Nodo* next;
public:
    Nodo(Producto* producto, Nodo* next);
    ~Nodo();
    void setProducto(Producto* producto);
    Producto* getProducto();
    void setNext(Nodo* next);
    Nodo* getNext();
    string toStringNodo();
};
#endif