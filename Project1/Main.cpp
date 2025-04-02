#include "Product.h"
#include "Tool.h"
#include "Equipment.h"
#include "Technology.h"
#include "Supplier.h"
#include "List.h"

int main() {
    Supplier* supplier1 = new Supplier("111", "Nubank", 1, 0);
    Supplier* supplier2 = new Supplier("222", "Maersk", 1, 0);
    Supplier* supplier3 = new Supplier("333", "Home_Depot", 2, 0);
    Supplier* supplier4 = new Supplier("444", "Johnson_&_Johnson", 1, 0);
    Supplier* supplier5 = new Supplier("555", "The_Lego_Group", 2, 0);
    Supplier* supplier6 = new Supplier("666", "Gro_Intelligence", 3, 0);

    Tool* tool1 = new Tool("Polisher", 6200, supplier1, 1, 1);
    Tool* tool2 = new Tool("Jigsaw", 200, supplier1, 2, 1);
    Tool* tool3 = new Tool("Rotary_Hammer", 340, supplier2, 2, 1);

    Equipment* equip1 = new Equipment("Bridge_Crane", 462700, supplier1, 1, "Steel", 234);
    Equipment* equip2 = new Equipment("Air_Extractor", 45200, supplier4, 1, "Steel", 222);
    Equipment* equip3 = new Equipment("Bucket_Elevator", 34000, supplier5, 1, "Steel", 356);
    Equipment* equip4 = new Equipment("Hydraulic_Press", 56000, supplier6, 1, "Steel", 444);

    Technology* tech1 = new Technology("Servers", 46270, supplier5, 1);
    Technology* tech2 = new Technology("Routers", 5270, supplier3, 1);
    Technology* tech3 = new Technology("Switches", 5390, supplier2, 0);
    Technology* tech4 = new Technology("Firewalls", 6380, supplier1, 0);

    cout << endl << "----------------Item #1 and #2----------------------" << endl;
    cout << "Show complete list..." << endl << endl;
    List* list1 = new List();
    list1->insertEnd(tech2);
    list1->insertEnd(equip3);
    list1->insertEnd(tool1);
    list1->insertEnd(equip2);
    list1->insertEnd(tool2);
    list1->insertEnd(equip1);
    list1->insertEnd(tech3);
    list1->insertEnd(equip4);
    list1->insertEnd(tech1);
    list1->insertEnd(tool3);
    list1->insertEnd(tech4);

    cout << list1->toString() << endl;

    cout << "<Press Enter>" << endl;
    cin.get();
    system("cls");

    cout << endl << "----------------Item #3----------------------" << endl;
    cout << "Show only specific products..." << endl << endl;

    cout << list1->toStringSpecific("technology") << endl;
    cout << "...................................................................." << endl;
    cout << list1->toStringSpecific("tool") << endl;
    cout << "...................................................................." << endl;
    cout << list1->toStringSpecific("equipment") << endl;

    cout << "<Press Enter>" << endl;
    cin.get();
    system("cls");

    cout << endl << "----------------Item #4----------------------" << endl;
    cout << "Show sublist by supplier..." << endl << endl;
    List* auxList;

    auxList = list1->returnSupplierList(supplier1->getSupplierID());
    cout << auxList->toString() << endl;
    cout << "...................................................................." << endl;
    auxList = list1->returnSupplierList(supplier2->getSupplierID());
    cout << auxList->toString() << endl;
    cout << "...................................................................." << endl;

    auxList = list1->returnSupplierList(supplier3->getSupplierID());
    cout << auxList->toString() << endl;
    cout << "...................................................................." << endl;

    auxList = list1->returnSupplierList(supplier4->getSupplierID());
    cout << auxList->toString() << endl;
    cout << "...................................................................." << endl;

    auxList = list1->returnSupplierList(supplier5->getSupplierID());
    cout << auxList->toString() << endl;
    cout << "...................................................................." << endl;

    auxList = list1->returnSupplierList(supplier6->getSupplierID());
    cout << auxList->toString() << endl;
    cout << "...................................................................." << endl;

    cout << "<Press Enter>" << endl;
    cin.get();
    system("cls");

    cout << endl << "----------------Item #5----------------------" << endl;
    cout << "Saving current list..." << endl << endl;

    list1->saveList();

    cout << "<Press Enter>" << endl;
    cin.get();
    system("cls");

    cout << endl << "----------------Item #6----------------------" << endl;
    cout << "Loading files into new list..." << endl << endl;

    List* newList = new List();
    newList->loadList();
    cout << newList->toString();

    cout << "<Press Enter>" << endl;
    cin.get();
    system("cls");

    cin.get();
    return 0;
}