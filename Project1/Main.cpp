#include "Producto.h"
#include "Herramienta.h"
#include "Equipamiento.h"
#include "Tecnologia.h"
#include "Proveedor.h"
#include "Lista.h"

int main(){
	Proveedor* prove1 = new Proveedor( "111", "Nubank", 1, 0);
	Proveedor* prove2 = new Proveedor( "222","Maersk", 1, 0);
	Proveedor* prove3 = new Proveedor( "333", "Home_Depot", 2, 0);
	Proveedor* prove4 = new Proveedor( "444", "Johnson_&_Johnson", 1, 0);
	Proveedor* prove5 = new Proveedor( "555", "The_Lego_Group", 2, 0);
	Proveedor* prove6 = new Proveedor( "666", "Gro_Intelligence", 3, 0);

	Herramienta* herra1 = new Herramienta("Pulidora",  6200, prove1, 1, 1);
	Herramienta* herra2 = new Herramienta("Sierra_calar", 200, prove1, 2, 1);
	Herramienta* herra3 = new Herramienta("Rotomartillo", 340, prove2, 2, 1);
	
	Equipamiento* equi1 = new Equipamiento("Grua_puente", 462700, prove1, 1,"Acero", 234);
	Equipamiento * equi2 = new Equipamiento("Extractor_de_aire",45200, prove4,1, "Acero", 222);
	Equipamiento * equi3 = new Equipamiento("Elevador_de_cangilones",34000, prove5,1, "Acero", 356);
	Equipamiento * equi4 = new Equipamiento("Prensa_hidraulica", 56000,prove6,1,  "Acero", 444);

	Tecnologia* tecno1 = new Tecnologia("Servidores ", 46270, prove5, 1);
	Tecnologia* tecno2 = new Tecnologia("Enrutadores ", 5270, prove3, 1);
	Tecnologia* tecno3 = new Tecnologia("Conmutadores ", 5390, prove2, 0);
	Tecnologia* tecno4 = new Tecnologia("Cortafuegos", 6380, prove1, 0);


	cout <<endl<< "----------------Item  #1 y #2----------------------" << endl;
	cout << "Mostrar Lista completa..." << endl << endl;
	Lista* l1 = new Lista();
	l1->insertarFinal(tecno2);
	l1->insertarFinal(equi3);
	l1->insertarFinal(herra1);
	l1->insertarFinal(equi2);
	l1->insertarFinal(herra2);
	l1->insertarFinal(equi1);
	l1->insertarFinal(tecno3);
	l1->insertarFinal(equi4);
	l1->insertarFinal(tecno1);
	l1->insertarFinal(herra3);
	l1->insertarFinal(tecno4);
	
	cout << l1->toString() << endl;
	
	cout << "<Digite Enter>" << endl;
	cin.get();
	system("cls");

	cout << endl << "----------------Item #3----------------------" << endl;
	cout << "Mostrar solo productos especificos..." << endl << endl;
	
	cout << l1->toStringEspecifico ("tecnologia") << endl;
	cout << "...................................................................." << endl;
	cout << l1->toStringEspecifico("herramienta") << endl;
	cout << "...................................................................." << endl;
	cout << l1->toStringEspecifico("equipamiento") << endl;
	
	cout << "<Digite Enter>" << endl;
	cin.get();
	system("cls");
	
	cout << endl << "----------------Item #4----------------------" << endl;
	cout << "Mostrar subLista segun proveedor..." << endl << endl;
	Lista* auxLista;

	auxLista=l1->retornaListaProveedor(prove1->getIDProve()); 
	cout << auxLista->toString() << endl;
	cout << "...................................................................." << endl;
	auxLista = l1->retornaListaProveedor(prove2->getIDProve()); 
	cout << auxLista->toString() << endl;
	cout << "...................................................................." << endl;

	auxLista = l1->retornaListaProveedor(prove3->getIDProve()); 
	cout << auxLista->toString() << endl;
	cout << "...................................................................." << endl;

	auxLista = l1->retornaListaProveedor(prove4->getIDProve()); 
	cout << auxLista->toString() << endl;
	cout << "...................................................................." << endl;

	auxLista = l1->retornaListaProveedor(prove5->getIDProve());
	cout << auxLista->toString() << endl;
	cout << "...................................................................." << endl;


	auxLista = l1->retornaListaProveedor(prove6->getIDProve());
	cout << auxLista->toString() << endl;
	cout << "...................................................................." << endl;
	
	cout  << "<Digite Enter>" << endl;
	cin.get();
	system("cls");
	
	cout << endl << "----------------Item #5----------------------" << endl;
	cout << "Guardando Lista Actual..." << endl << endl;
	
	l1->guardarLista();
	
	cout << "<Digite Enter>" << endl;
	cin.get();
	system("cls");

	cout << endl << "----------------Item #6----------------------" << endl;
	cout << "Levantando archivos en Lista Nueva..." << endl << endl;
	
	Lista* nuevaLista = new Lista();
	nuevaLista->cargarLista();
	cout << nuevaLista->toString();
	
	cout << "<Digite Enter>" << endl;
	cin.get();
	system("cls");
	
	cin.get();
	return 0;
}