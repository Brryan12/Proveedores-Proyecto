#ifndef PRODUCT
#define PRODUCT

#include <iostream>
#include "Supplier.h"
#include <string>
#include <sstream>
using namespace std;

/**
 * @class Product
 * @brief Represents a product with a name, price, and supplier.
 */
class Product {
protected:
    string name;
    int price;
    Supplier* supplier;
public:
    /**
     * @brief Default constructor for Product.
     */
    Product();

    /**
     * @brief Parameterized constructor for Product.
     * @param name The name of the product.
     * @param price The price of the product.
     * @param supplier Pointer to the supplier of the product.
     */
    Product(string name, int price, Supplier* supplier);

    /**
     * @brief Sets the name of the product.
     * @param name The name of the product.
     */
    virtual void setName(string name);

    /**
     * @brief Gets the name of the product.
     * @return The name of the product.
     */
    virtual string getName();

    /**
     * @brief Sets the price of the product.
     * @param price The price of the product.
     */
    virtual void setPrice(int price);

    /**
     * @brief Gets the price of the product.
     * @return The price of the product.
     */
    virtual int getPrice();

    /**
     * @brief Sets the supplier of the product.
     * @param supplier Pointer to the supplier of the product.
     */
    virtual void setSupplier(Supplier* supplier);

    /**
     * @brief Gets the supplier of the product.
     * @return Pointer to the supplier of the product.
     */
    virtual Supplier* getSupplier();

    /**
     * @brief Converts the product details to a string.
     * @return A string representation of the product.
     */
    virtual string toString();

    /**
     * @brief Saves the product details to an output stream.
     * @param output The output stream to save the product details.
     */
    virtual void save(ostream& output) = 0;

    /**
     * @brief Destructor for Product.
     */
    virtual ~Product();
};

#endif
