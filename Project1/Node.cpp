#include "Node.h"

Node::Node(Product* product, Node* next) : product(product), next(next) {}

Node::~Node() {
    delete product;
    cout << "A Node has been destroyed" << endl;
}

void Node::setProduct(Product* product) {
    this->product = product;
}

Product* Node::getProduct() {
    return this->product;
}

void Node::setNext(Node* next) {
    this->next = next;
}

Node* Node::getNext() {
    return next;
}

string Node::toStringNode() {
    return product->toString();
}