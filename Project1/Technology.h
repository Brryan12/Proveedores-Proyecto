#ifndef TECHNOLOGY
#define TECHNOLOGY

#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
using namespace std;

/**
 * @class Technology
 * @brief Represents a technology product, derived from the Product class.
 */
class Technology : public Product {
private:
    bool AI;
public:
    /**
     * @brief Default constructor for Technology.
     */
    Technology();

    /**
     * @brief Parameterized constructor for Technology.
     * @param name The name of the technology product.
     * @param price The price of the technology product.
     * @param supplier Pointer to the supplier of the technology product.
     * @param AI Indicates if the technology product has AI capabilities.
     */
    Technology(string name, int price, Supplier* supplier, bool AI);

    /**
     * @brief Sets whether the technology product has AI capabilities.
     * @param AI Boolean indicating if the technology product has AI capabilities.
     */
    void setAI(bool AI);

    /**
     * @brief Gets whether the technology product has AI capabilities.
     * @return Boolean indicating if the technology product has AI capabilities.
     */
    bool getAI();

    /**
     * @brief Converts the technology product details to a string.
     * @return A string representation of the technology product.
     */
    string toString();

    /**
     * @brief Saves the technology product details to an output stream.
     * @param output The output stream to save the technology product details.
     */
    void save(ostream& output);

    /**
     * @brief Loads the technology product details from an input stream.
     * @param input The input stream to load the technology product details.
     * @return A pointer to the loaded Technology object.
     */
    static Technology* load(istream& input);

    /**
     * @brief Destructor for Technology.
     */
    ~Technology();
};

#endif
