#include "List.h"
#include <fstream>

List::List() {
    first = nullptr;
    current = nullptr;
}

List::~List() {
    while (first != nullptr) {
        current = first;
        first = first->getNext();
        delete current;
    }
}

void List::insertEnd(Product* product) {
    Node* auxNode = new Node(product, nullptr);
    if (first == nullptr) {
        first = auxNode;
    } else {
        current = first;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(auxNode);
    }
}

string List::toString() {
    stringstream s;
    current = first;
    while (current != nullptr) {
        s << current->getProduct()->toString() << endl;
        current = current->getNext();
    }
    return s.str();
}

string List::toStringSpecific(string product) {
    stringstream s;
    current = first;
    while (current != nullptr) {
        if (product == "technology") {
            if (dynamic_cast<Technology*>(current->getProduct()) != nullptr)
                s << current->getProduct()->toString() << endl;
        } else if (product == "tool") {
            if (dynamic_cast<Tool*>(current->getProduct()) != nullptr)
                s << current->getProduct()->toString() << endl;
        } else if (product == "equipment") {
            if (dynamic_cast<Equipment*>(current->getProduct()) != nullptr)
                s << current->getProduct()->toString() << endl;
        }
        current = current->getNext();
    }
    return s.str();
}

List* List::returnSupplierList(string supplierID) {
    List* auxList = new List();
    current = first;
    while (current != nullptr) {
        if (current->getProduct()->getSupplier()->getSupplierID() == supplierID) {
            auxList->insertEnd(current->getProduct());
        }
        current = current->getNext();
    }
    return auxList;
}

void List::saveList() {
    ofstream output;
    output.open("../Files/products.txt");
    if (output.good()) {
        current = first;
        while (current != nullptr) {
            current->getProduct()->save(output);
            current = current->getNext();
        }
    } else {
        cerr << "Error opening the file" << endl;
    }
    output.close();

    output.open("../Files/suppliers.txt");
    if (output.good()) {
        current = first;
        while (current != nullptr) {
            bool alreadySaved = false;
            string currentSupplierID = current->getProduct()->getSupplier()->getSupplierID();

            Node* aux = first;
            while (aux != current) {
                string auxSupplierID = aux->getProduct()->getSupplier()->getSupplierID();
                if (auxSupplierID == currentSupplierID) {
                    alreadySaved = true;
                    break;
                }
                aux = aux->getNext();
            }

            if (!alreadySaved) {
                current->getProduct()->getSupplier()->save(output);
            }

            current = current->getNext();
        }
    } else {
        cerr << "Error opening the file" << endl;
    }
    output.close();
}

void List::loadList() {
    ifstream input;
    input.open("../Files/products.txt");
    if (input.good()) {
        while (!input.eof()) {
            string type, name, price, supplierID;
            getline(input, type, '\t');

            if (type == "Technology") {
                string AI;
                getline(input, name, '\t');
                getline(input, price, '\t');
                getline(input, supplierID, '\t');
                getline(input, AI, '\n');

                if (!name.empty() && !price.empty() && !supplierID.empty() && !AI.empty()) {
                    Supplier* supplier = nullptr;

                    ifstream inputSuppliers("../Files/suppliers.txt");
                    if (inputSuppliers.good()) {
                        string id, supplierName, category, national;
                        while (getline(inputSuppliers, id, '\t')) {
                            getline(inputSuppliers, supplierName, '\t');
                            getline(inputSuppliers, category, '\t');
                            getline(inputSuppliers, national, '\n');

                            if (id == supplierID) {
                                supplier = new Supplier(id, supplierName, stoi(category), stoi(national));
                                break;
                            }
                        }
                        inputSuppliers.close();
                    } else {
                        cerr << "Error opening the file suppliers.txt" << endl;
                    }

                    if (supplier != nullptr) {
                        Technology* techAux = new Technology(name, stoi(price), supplier, stoi(AI));
                        this->insertEnd(techAux);
                    }
                }
            } else if (type == "Tool") {
                string safetyLevel, category;
                getline(input, name, '\t');
                getline(input, price, '\t');
                getline(input, supplierID, '\t');
                getline(input, safetyLevel, '\t');
                getline(input, category, '\n');

                if (!name.empty() && !price.empty() && !supplierID.empty() && !safetyLevel.empty() && !category.empty()) {
                    Supplier* supplier = nullptr;

                    ifstream inputSuppliers("../Files/suppliers.txt");
                    if (inputSuppliers.good()) {
                        string id, supplierName, supplierCategory, national;
                        while (getline(inputSuppliers, id, '\t')) {
                            getline(inputSuppliers, supplierName, '\t');
                            getline(inputSuppliers, supplierCategory, '\t');
                            getline(inputSuppliers, national, '\n');

                            if (id == supplierID) {
                                supplier = new Supplier(id, supplierName, stoi(supplierCategory), stoi(national));
                                break;
                            }
                        }
                        inputSuppliers.close();
                    } else {
                        cerr << "Error opening the file suppliers.txt" << endl;
                    }
                    if (supplier != nullptr) {
                        Tool* toolAux = new Tool(name, stoi(price), supplier, stoi(safetyLevel), stoi(category));
                        this->insertEnd(toolAux);
                    }
                }
            } else if (type == "Equipment") {
                string outdoor, material, weight;
                getline(input, name, '\t');
                getline(input, price, '\t');
                getline(input, supplierID, '\t');
                getline(input, outdoor, '\t');
                getline(input, material, '\t');
                getline(input, weight, '\n');

                if (!name.empty() && !price.empty() && !supplierID.empty() && !outdoor.empty() && !material.empty() && !weight.empty()) {
                    Supplier* supplier = nullptr;

                    ifstream inputSuppliers("../Files/suppliers.txt");
                    if (inputSuppliers.good()) {
                        string id, supplierName, category, national;
                        while (getline(inputSuppliers, id, '\t')) {
                            getline(inputSuppliers, supplierName, '\t');
                            getline(inputSuppliers, category, '\t');
                            getline(inputSuppliers, national, '\n');

                            if (id == supplierID) {
                                supplier = new Supplier(id, supplierName, stoi(category), stoi(national));
                                break;
                            }
                        }
                        inputSuppliers.close();
                    } else {
                        cerr << "Error opening the file suppliers.txt" << endl;
                    }
                    if (supplier != nullptr) {
                        Equipment* equipAux = new Equipment(name, stoi(price), supplier, stoi(outdoor), material, stoi(weight));
                        this->insertEnd(equipAux);
                    }
                }
            }
        }
    } else {
        cerr << "Error opening the file products.txt" << endl;
    }

    input.close();
}
