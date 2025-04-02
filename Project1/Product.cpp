#include "Product.h"

Product::Product() {
    name = "undefined";
    price = 0;
    supplier = nullptr;
}

Product::Product(string name, int price, Supplier* supplier) : name(name), price(price), supplier(supplier) {}

void Product::setName(string name) {
    this->name = name;
}

string Product::getName() {
    return name;
}

void Product::setPrice(int price) {
    this->price = price;
}

int Product::getPrice() {
    return price;
}

void Product::setSupplier(Supplier* supplier) {
    this->supplier = supplier;
}

Supplier* Product::getSupplier() {
    return this->supplier;
}

string Product::toString() {
    stringstream s;
    s << "Name: " << name << endl;
    s << "Price: " << price << endl;
    return s.str();
}

Product::~Product() {}
