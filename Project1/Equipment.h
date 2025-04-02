#ifndef EQUIPMENT
#define EQUIPMENT

#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
using namespace std;

/**
 * @class Equipment
 * @brief Represents an equipment item, derived from the Product class.
 */
class Equipment : public Product {
private:
    bool outdoor;
    string material;
    int weight;
public:
    /**
     * @brief Default constructor for Equipment.
     */
    Equipment();

    /**
     * @brief Parameterized constructor for Equipment.
     * @param name The name of the equipment.
     * @param price The price of the equipment.
     * @param supplier Pointer to the supplier of the equipment.
     * @param outdoor Indicates if the equipment is for outdoor use.
     * @param material The material of the equipment.
     * @param weight The weight of the equipment.
     */
    Equipment(string name, int price, Supplier* supplier, bool outdoor, string material, int weight);

    /**
     * @brief Sets whether the equipment is for outdoor use.
     * @param outdoor Boolean indicating if the equipment is for outdoor use.
     */
    void setOutdoor(bool outdoor);

    /**
     * @brief Gets whether the equipment is for outdoor use.
     * @return Boolean indicating if the equipment is for outdoor use.
     */
    bool getOutdoor();

    /**
     * @brief Sets the material of the equipment.
     * @param material The material of the equipment.
     */
    void setMaterial(string material);

    /**
     * @brief Gets the material of the equipment.
     * @return The material of the equipment.
     */
    string getMaterial();

    /**
     * @brief Sets the weight of the equipment.
     * @param weight The weight of the equipment.
     */
    void setWeight(int weight);

    /**
     * @brief Gets the weight of the equipment.
     * @return The weight of the equipment.
     */
    int getWeight();

    /**
     * @brief Converts the equipment details to a string.
     * @return A string representation of the equipment.
     */
    string toString();

    /**
     * @brief Saves the equipment details to an output stream.
     * @param output The output stream to save the equipment details.
     */
    void save(ostream& output);

    /**
     * @brief Destructor for Equipment.
     */
    ~Equipment();
};

#endif