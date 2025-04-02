#ifndef TOOL
#define TOOL

#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
using namespace std;

/**
 * @class Tool
 * @brief Represents a tool item, derived from the Product class.
 */
class Tool : public Product {
private:
    int safetyLevel;
    int category;
public:
    /**
     * @brief Default constructor for Tool.
     */
    Tool();

    /**
     * @brief Parameterized constructor for Tool.
     * @param name The name of the tool.
     * @param price The price of the tool.
     * @param supplier Pointer to the supplier of the tool.
     * @param safetyLevel The safety level of the tool.
     * @param category The category of the tool.
     */
    Tool(string name, int price, Supplier* supplier, int safetyLevel, int category);

    /**
     * @brief Sets the safety level of the tool.
     * @param safetyLevel The safety level of the tool.
     */
    void setSafetyLevel(int safetyLevel);

    /**
     * @brief Gets the safety level of the tool.
     * @return The safety level of the tool.
     */
    int getSafetyLevel();

    /**
     * @brief Sets the category of the tool.
     * @param category The category of the tool.
     */
    void setCategory(int category);

    /**
     * @brief Gets the category of the tool.
     * @return The category of the tool.
     */
    int getCategory();

    /**
     * @brief Converts the tool details to a string.
     * @return A string representation of the tool.
     */
    string toString();

    /**
     * @brief Saves the tool details to an output stream.
     * @param output The output stream to save the tool details.
     */
    void save(ostream& output);

    /**
     * @brief Destructor for Tool.
     */
    ~Tool();
};

#endif