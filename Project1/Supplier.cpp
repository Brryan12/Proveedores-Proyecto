#include "Supplier.h"

Supplier::Supplier() {
    supplierName = "Undefined";
    supplierID = "Undefined";
    category = -1;
    national = true;
}

Supplier::Supplier(string id, string supplierName, int category, bool national) {
    this->supplierID = id;
    this->supplierName = supplierName;
    this->category = category;
    this->national = national;
}

void Supplier::setSupplierName(string supplierName) {
    this->supplierName = supplierName;
}

string Supplier::getSupplierName() {
    return supplierName;
}

void Supplier::setSupplierID(string supplierID) {
    this->supplierID = supplierID;
}

string Supplier::getSupplierID() {
    return supplierID;
}

void Supplier::setCategory(int category) {
    this->category = category;
}

int Supplier::getCategory() {
    return category;
}

void Supplier::setNational(bool national) {
    this->national = national;
}

bool Supplier::getNational() {
    return national;
}

string Supplier::toString() {
    stringstream s;
    s << "\tSupplier Name: " << this->supplierName << endl;
    s << "\tSupplier ID: " << this->supplierID << endl;
    s << "\tCategory: " << this->category << endl;
    s << "\tNational: " << this->national << endl;
    return s.str();
}

void Supplier::save(ostream& output) {
    output << this->supplierID << "\t";
    output << this->supplierName << "\t";
    output << this->category << "\t";
    output << this->national << "\n";
}

Supplier::~Supplier() {}
