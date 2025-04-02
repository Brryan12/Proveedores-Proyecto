#ifndef SUPPLIER
#define SUPPLIER

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * @class Supplier
 * @brief Represents a supplier with a name, ID, category, and nationality.
 */
class Supplier {
private:
    string supplierName;
    string supplierID;
    int category;
    bool national;
public:
    /**
     * @brief Default constructor for Supplier.
     */
    Supplier();

    /**
     * @brief Parameterized constructor for Supplier.
     * @param supplierName The name of the supplier.
     * @param supplierID The ID of the supplier.
     * @param category The category of the supplier.
     * @param national Indicates if the supplier is national.
     */
    Supplier(string supplierName, string supplierID, int category, bool national);

    /**
     * @brief Sets the name of the supplier.
     * @param supplierName The name of the supplier.
     */
    void setSupplierName(string supplierName);

    /**
     * @brief Gets the name of the supplier.
     * @return The name of the supplier.
     */
    string getSupplierName();

    /**
     * @brief Sets the ID of the supplier.
     * @param supplierID The ID of the supplier.
     */
    void setSupplierID(string supplierID);

    /**
     * @brief Gets the ID of the supplier.
     * @return The ID of the supplier.
     */
    string getSupplierID();

    /**
     * @brief Sets the category of the supplier.
     * @param category The category of the supplier.
     */
    void setCategory(int category);

    /**
     * @brief Gets the category of the supplier.
     * @return The category of the supplier.
     */
    int getCategory();

    /**
     * @brief Sets whether the supplier is national.
     * @param national Boolean indicating if the supplier is national.
     */
    void setNational(bool national);

    /**
     * @brief Gets whether the supplier is national.
     * @return Boolean indicating if the supplier is national.
     */
    bool getNational();

    /**
     * @brief Converts the supplier details to a string.
     * @return A string representation of the supplier.
     */
    string toString();

    /**
     * @brief Saves the supplier details to an output stream.
     * @param output The output stream to save the supplier details.
     */
    void save(ostream& output);

    /**
     * @brief Destructor for Supplier.
     */
    ~Supplier();
};

#endif
