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