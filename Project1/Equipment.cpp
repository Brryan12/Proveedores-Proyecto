#include "Equipment.h"

Equipment::Equipment() {
    this->outdoor = false;
    this->material = "undefined";
    this->weight = -1;
}

Equipment::Equipment(string name, int price, Supplier* supplier, bool outdoor, string material, int weight) : Product(name, price, supplier) {
    this->outdoor = outdoor;
    this->material = material;
    this->weight = weight;
}

void Equipment::setOutdoor(bool outdoor) {
    this->outdoor = outdoor;
}

bool Equipment::getOutdoor() {
    return outdoor;
}

void Equipment::setMaterial(string material) {
    this->material = material;
}

string Equipment::getMaterial() {
    return material;
}

void Equipment::setWeight(int weight) {
    this->weight = weight;
}

int Equipment::getWeight() {
    return weight;
}

string Equipment::toString() {
    stringstream s;
    s << "--Equipment--" << endl;
    s << Product::toString();
    s << "Outdoor: " << this->outdoor << endl;
    s << "Material: " << this->material << endl;
    s << "Weight: " << this->weight << endl;
    if (supplier != nullptr) {
        s << supplier->toString() << endl;
    } else {
        s << "Supplier: not assigned" << endl;
    }
    s << endl;
    return s.str();
}

void Equipment::save(ostream& output) {
    output << "Equipment" << "\t";
    output << this->name << "\t";
    output << this->price << "\t";
    if (supplier != nullptr) {
        output << supplier->getSupplierID() << "\t";
    } else {
        output << "0" << "\t";
    }
    output << this->outdoor << "\t";
    output << this->material << "\t";
    output << this->weight << "\n";
}

Equipment::~Equipment() {}