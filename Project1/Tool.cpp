#include "Tool.h"

Tool::Tool() {
    safetyLevel = 0;
    category = 0;
}

Tool::Tool(string name, int price, Supplier* supplier, int safetyLevel, int category) : Product(name, price, supplier) {
    this->safetyLevel = safetyLevel;
    this->category = category;
}

void Tool::setSafetyLevel(int safetyLevel) {
    this->safetyLevel = safetyLevel;
}

int Tool::getSafetyLevel() {
    return safetyLevel;
}

void Tool::setCategory(int category) {
    this->category = category;
}

int Tool::getCategory() {
    return category;
}

string Tool::toString() {
    stringstream s;
    s << "--Tool--" << endl;
    s << Product::toString();
    s << "Safety Level: " << this->safetyLevel << endl;
    s << "Category: " << this->category << endl;
    if (supplier != nullptr) {
        s << supplier->toString() << endl;
    } else {
        s << "Supplier: not assigned" << endl;
    }
    s << endl;
    return s.str();
}

void Tool::save(ostream& output) {
    output << "Tool" << "\t";
    output << this->name << "\t";
    output << this->price << "\t";
    if (supplier != nullptr) {
        output << supplier->getSupplierID() << "\t";
    } else {
        output << "0" << "\t";
    }
    output << this->safetyLevel << "\t";
    output << this->category << "\n";
}

Tool::~Tool() {}
