#ifndef LIST
#define LIST

#include "Node.h"
#include <fstream>
#include "Technology.h"
#include "Tool.h"
#include "Equipment.h"
using namespace std;

/**
 * @class List
 * @brief Represents a list of products.
 */
class List {
private:
    Node* first;
    Node* current;
public:
    /**
     * @brief Default constructor for List.
     */
    List();

    /**
     * @brief Destructor for List.
     */
    ~List();

    /**
     * @brief Inserts a product at the end of the list.
     * @param product Pointer to the product to be inserted.
     */
    void insertEnd(Product* product);

    /**
     * @brief Converts the list details to a string.
     * @return A string representation of the list.
     */
    string toString();

    /**
     * @brief Converts specific product details in the list to a string.
     * @param product The name of the product to be converted to string.
     * @return A string representation of the specific product in the list.
     */
    string toStringSpecific(string product);

    /**
     * @brief Returns a list of products from a specific supplier.
     * @param supplierID The ID of the supplier.
     * @return A pointer to the list of products from the specific supplier.
     */
    List* returnSupplierList(string supplierID);

    /**
     * @brief Saves the list to a file.
     */
    void saveList();

    /**
     * @brief Loads the list from a file.
     */
    void loadList();
};

#endif