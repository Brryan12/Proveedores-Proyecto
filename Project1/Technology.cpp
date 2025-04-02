#include "Technology.h"

Technology::Technology() {
    this->AI = false;
}

Technology::Technology(string name, int price, Supplier* supplier, bool AI) : Product(name, price, supplier) {
    this->AI = AI;
}

void Technology::setAI(bool AI) {
    this->AI = AI;
}

bool Technology::getAI() {
    return AI;
}

string Technology::toString() {
    stringstream s;
    s << "--Technology--" << endl;
    s << Product::toString();
    s << "AI: " << this->AI << endl;
    if (supplier != nullptr) {
        s << supplier->toString() << endl;
    } else {
        s << "Supplier: not assigned" << endl;
    }
    s << endl;
    return s.str();
}

void Technology::save(ostream& output) {
    output << "Technology" << "\t";
    output << this->name << "\t";
    output << this->price << "\t";
    if (supplier != nullptr) {
        output << supplier->getSupplierID() << "\t";
    } else {
        output << "0" << "\t";
    }
    output << this->AI << "\n";
}

Technology::~Technology() {}
