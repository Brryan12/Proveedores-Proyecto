#ifndef NODE
#define NODE

#include "Product.h"
using namespace std;

/**
 * @class Node
 * @brief Represents a node in a linked list containing a product.
 */
class Node {
private:
    Product* product;
    Node* next;
public:
    /**
     * @brief Parameterized constructor for Node.
     * @param product Pointer to the product.
     * @param next Pointer to the next node.
     */
    Node(Product* product, Node* next);

    /**
     * @brief Destructor for Node.
     */
    ~Node();

    /**
     * @brief Sets the product of the node.
     * @param product Pointer to the product.
     */
    void setProduct(Product* product);

    /**
     * @brief Gets the product of the node.
     * @return Pointer to the product.
     */
    Product* getProduct();

    /**
     * @brief Sets the next node.
     * @param next Pointer to the next node.
     */
    void setNext(Node* next);

    /**
     * @brief Gets the next node.
     * @return Pointer to the next node.
     */
    Node* getNext();

    /**
     * @brief Converts the node details to a string.
     * @return A string representation of the node.
     */
    string toStringNode();
};

#endif