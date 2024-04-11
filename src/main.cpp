#include <iostream>
#include <fstream>
#include <sstream>
#include "./modelo/model.h"

using namespace std;

    ClientController controlcliente;
    AutoController controlauto;
	Estadisticacontroller controlEstadistica;

	void Menuprincipal();
	void MenuAutos();
	void MenuVentas();
	void MenuCliente();

void MenuPrincipal(){
int opcion;
	cout << "_____________________________________________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||     |||| P R I N C I P A L ||||     ||||" << endl;
	cout << "_____________________________________________ \n" << endl;
	cout << " 1- Clientes" << endl;
	cout << " 2- Autos" << endl;
	cout << " 3- Ventas" << endl;
	cout << " 4- salir del sistema" << endl;
	cout << " Opcion: "; cin >> opcion;
	switch (opcion){
    case 1: MenuCliente(); MenuPrincipal(); break;
	case 2: MenuAutos(); MenuPrincipal(); break;
	case 3: MenuVentas(); MenuPrincipal(); break;
	case 4: cout << "Saliendo del sistema . . ." << endl; break;
	case 0: break;
	default: cout << "Opcion incorrecta" << endl << endl;
	}
}
void MenuCliente(){
	int opcion1;
	cout << "_____________________________________________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||      |||| C L I E N T E S ||||      ||||" << endl;
	cout << "_____________________________________________ \n" << endl;
	cout << " 1- Agregar" << endl;
	cout << " 2- Eliminar" << endl;
	cout << " 3- Mostrar" << endl;
	cout << " 4- Modificar" << endl;
	cout << " 5- Volver al menu principal" << endl;
	cout << " Opcion: "; cin >> opcion1;
	switch (opcion1)
	{
	case 1:{ 
		string nombre, apellido, correo;
		int edad;
		cout << " Ingrese el nombre y apellido del cliente: " ; cin>>nombre >> apellido;
		cout << " Ingrese el correo del cliente: " ; cin >> correo;
		cout << " Ingrese la edad del cliente: "; cin >> edad;
		controlcliente.AgregarCliente(nombre, apellido, correo, edad);
	}
	break;
		MenuCliente();
	//ELIMINAR CLIENTE
	case 2:{
		string id;
		cout << " Ingrese el id del cliente: "; cin >> id; 
		controlcliente.EliminarCliente(id);
	}
		break;
		MenuCliente();
	//MOSTRAR CLIENTE
	case 3:{
	int opcion2;
	cout << "_____________________________________________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||       |||| M O S T R A R ||||       ||||" << endl;
	cout << "_____________________________________________ \n" << endl;
	cout << " 1- Listado completo" << endl;
	cout << " 2- Busqueda detallada por id" << endl;
    cout << " 3- Volver al menu clientes" << endl;
	cout << " opcion: " ;cin >> opcion2;

	switch (opcion2)
	{
	case 1:{
		controlcliente.MostrarClientes();
	}
		MenuCliente();break;

	case 2:{
		string id;
		cout << " Ingrese el id del cliente: "; cin >> id; 
		controlcliente.MostrarCLientexID(id);
	}
	MenuCliente();break;

	default:
		MenuCliente();break;
	}

	}
		break;
		MenuCliente();
	//MODIFICAR CLIENTE
	case 4:{
		string id;
		cout << " Ingrese el id del cliente: "; cin >> id; 
		controlcliente.ModificarCliente(id);
	}
	break;
	MenuCliente();
	case 5: break;MenuPrincipal();
	}

}

void MenuAutos(){
	int opcion3;
	cout << "_______________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||    |||| I N V E N T A R I O ||||   ||||" << endl;
	cout << "_______________ \n" << endl;
	cout << " 1- Articulos" << endl;
	cout << " 2- Stock(cantidades) " << endl;
	cout << " 3- Busqueda de articulos" << endl;
	cout << " 4- Listado de Stock sin vender" << endl;
	cout << " 5- Listado de Stock vendido" << endl;
	cout << " 6- volver al menu principal" << endl;
	cout << " Opcion: "; cin >> opcion3;

	switch (opcion3)
	{
	//AGREGAR ARTICULOS
	case 1: {
	int opcion4;
	cout << "_______________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||      |||| A R T I C U L O S||||     ||||" << endl;
	cout << "_______________ \n" << endl;
	cout << " 1- agregar" << endl;
	cout << " 2- eliminar" << endl;
	cout << " 3- volver al menu principal" << endl;
	cout << " Opcion: "; cin >> opcion4;

	switch (opcion4)
	{
	//AGREGAR AUTO
	case 1:{
		string marca, modelo, año, comprado;
		cout << "ingrese la marca del auto y modelo: " ; cin>>marca >> modelo;
		cout << "ingrese de que año es el auto: " ; cin >> año;
		cout << "ingrese el precio de compra "; cin >> comprado;
		controlauto.AgregarAuto(marca, modelo, año, comprado);
	}
	MenuAutos(); break;
	//ELIMINAR AUTO
	case 2:{
		string id;
		cout << "ingrese el id del cliente "; cin >> id; 
		controlauto.EliminarAuto(id);
	}
		MenuAutos(); break;
	case 3:MenuAutos();break;
	default:MenuAutos();break;
		
	}
	
	}
	break;MenuAutos(); 
	//STOCK
	case 2:{
		controlauto.Stockautos();
	}
	break;MenuAutos();
	//MOSTRAR AUTO
	case 3:{
	int opcion4;
	cout << "_______________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||      |||| B U S Q U E D A ||||      ||||" << endl;
	cout << "_______________ \n" << endl;
	cout << " 1- Listado completo" << endl;
	cout << " 2- Busqueda detallada por id" << endl;
    cout << " 3- Volver al menu autos" << endl;
	cout << " opcion: " ;cin >> opcion4;

	switch (opcion4){
	case 1:{
		controlauto.MostrarAuto();
	}
		MenuAutos(); break;
	case 2:{
		string id;
		cout << "ingrese el id del cliente "; cin >> id; 
		controlauto.MostrarAutoxID(id);
	}
	MenuAutos(); break;
	case 3:MenuAutos(); break;
	default:MenuAutos(); break;
	}
	
	 }
	 break;MenuAutos();
	 //STOCK SIN VENDER
	 case 4:{
		controlauto.stocksinvender();

	 } break;MenuAutos();

	 //STOCK VENDIDO
	 case 5:{
		controlauto.stockvendido();

	 } break;MenuAutos();

	 //VOLVER AL MENU
	 case 6:break; MenuPrincipal();
     default:break; MenuAutos();
	 }
	}
void MenuVentas(){
int opcion5;
	cout << "_______________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||        |||| V E N T A S ||||        ||||" << endl;
	cout << "_______________ \n" << endl;
	cout << " 1- Caja" << endl;
	cout << " 2- Registro de Compra y venta" << endl;
	cout << " 3- Volver al menu principal" << endl;
	cout << " Opcion: "; cin >> opcion5;

	switch (opcion5)
	{
	case 1:{
		string id;
		cout << "ingrese el id del auto "; cin >> id;
		controlauto.ModificarAuto(id);
	}
		break;MenuVentas();

	case 2:{
int opcion6;
	cout << "_______________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||  |||| C O M P R A / V E N T A ||||  ||||" << endl;
	cout << "_______________ \n" << endl;
	cout << " 1- Regsitros por ID del cliente" << endl;
	cout << " 2- Regsitros por ID del auto" << endl;
	cout << " 3- Volver al menu principal" << endl;
	cout << " Opcion: "; cin >> opcion6;

	switch(opcion6){

		case 1: {
			controlEstadistica.compraventacliente();
		}
		MenuVentas();break;
		case 2:{
			controlEstadistica.compraventaauto();
		}
		MenuVentas();break;
		case 3:MenuVentas();break;
		default:MenuVentas();break;
	}
	}
	break;MenuVentas();

	case 3:	break;MenuPrincipal();
	
	default:break;MenuVentas();
	}

}
int main() {
MenuPrincipal();
}