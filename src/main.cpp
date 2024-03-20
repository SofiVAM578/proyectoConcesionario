#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#pragma region Estructuras

string Clientes = "id; firt_name; last_name; email; age";
string Autos= "id; maker; model; year; sold_to; bought_to; sold_for; bought_for ";
struct Client {
	int id;
	string first_name;
	string last_name;
	string email;
	int age;
};
struct Seller {
	int id;
	string first_name;
	string last_name;
	string email;
	int age;
};
struct Car {
	int id;
	string maker;
	string model;
	int year;
	int sold_to;
	int bought_to;
	int sold_for;
	int bought_for;
};

#pragma region Prototipos
void ContadorCliente();
void ContadorAutos();
void MenuPrincipal();

void MenuAgregar();
void Agregar_Cliente();
void Agregar_Auto();

void MenuEliminar();
void Eliminar_Cliente();
void Eliminar_Auto();

void MenuMostrar();
void Mostrar_Clientes();
void Mostrar_Autos();
void Mostrar_Cliente_x_id();
void Mostrar_Auto_x_id();

void MenuModificar();
void Modificar_Auto();
void Modificar_Cliente();

void MenuEstadistica();
void Estadistica_General();
void Autos_Comprados();
void Autos_Vendidos();
void Autos_sin_vender();
#pragma endregion

#pragma region Funciones

void MenuPrincipal() {
	int opcion;
	cout << "_____________________________________________ \n" << endl;
	cout << "||||          |||| M E N U ||||          ||||" << endl;
	cout << "||||     |||| P R I N C I P A L ||||     ||||" << endl;
	cout << "_____________________________________________ \n" << endl;
	cout << " 1- Agregar" << endl;
	cout << " 2- Eliminar" << endl;
	cout << " 3- Mostrar" << endl;
	cout << " 4- Modificar" << endl;
	cout << " 5- Estadisticas" << endl;
	cout << " 6- salir del sistema" << endl;
	cout << " Opcion: "; cin >> opcion;
	switch (opcion) {
	case 1: MenuAgregar(); break;
	case 2: MenuEliminar(); break;
	case 3: MenuMostrar(); break;
	case 4: MenuModificar(); break;
	case 5: MenuEstadistica(); break;
	case 6: cout << "Saliendo del sistema . . ." << endl; break;
	case 0: break;
	default: cout << "Opcion incorrecta" << endl << endl;
	}
}

#pragma region Agregar
void MenuAgregar() {
	int opcion1;
	cout << "_____________________________________________ \n " << endl;
	cout << "||||     |||| O P C I O N   D E ||||     ||||" << endl;
	cout << "||||     ||||  R E G I S T R O  ||||     ||||" << endl;
	cout << "_____________________________________________ \n" << endl;

	cout << " 1- Agregar Cliente" << endl;
	cout << " 2- Agregar Vendedor" << endl;
	cout << " 3- Agregar Vehiculo" << endl;
	cout << " 4- Menu Principal" << endl;
	cout << " Opcion: "; cin >> opcion1;

	switch (opcion1) {
	case 1: Agregar_Cliente(); MenuAgregar(); break;
	case 2: Agregar_Cliente(); MenuAgregar(); break;
	case 3: Agregar_Auto(); MenuAgregar(); break;
	case 4: MenuPrincipal(); break;
	case 0: break;
	default: cout << "Opcion incorrecta" << endl << endl;
	}
}

void Agregar_Cliente() {
	ifstream clients_read("..\\assets\\clients.csv");
	ofstream clients_write("..\\assets\\clients.csv", ios::app);
	int UltimoID = 0;
	string line;
	Client Clients;
	getline(clients_read, line);
	while (getline(clients_read, line)) {
		istringstream ss(line);
		Client Clients;
		string id_str;
		getline(ss, id_str, ';');
		Clients.id = stoi(id_str);

		UltimoID = Clients.id;
	}

	clients_read.close();

	int SiguienteID = UltimoID + 1;
	cout << "Nombre: ", cin >> Clients.first_name;
	cout << "Apellido: "; cin >> Clients.last_name;
	cout << "Correo electronico: "; cin >> Clients.email;
	cout << "Edad: "; cin >> Clients.age;

	clients_write << SiguienteID << ';' << Clients.first_name << ';' << Clients.last_name << ';' << Clients.email << ';' << Clients.age << endl;
	cout << "Cliente " << Clients.first_name << " " << Clients.last_name << " agregado exitosamente" << endl;

	clients_write.close();
}
void Agregar_Auto() {
	ifstream cars_read("..\\assets\\cars_data.csv");
	ofstream cars_write("..\\assets\\cars_data.csv", ios::app);
	int UltimoID = 0;
	string line;
	Car Cars;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		string id_str;

		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		UltimoID = Cars.id;
	}

	cars_read.close();

	int SiguienteID = UltimoID + 1;
	cout << "Marca: "; cin >> Cars.maker;
	cout << "Modelo: "; cin >> Cars.model;
	cout << "Año: "; cin >> Cars.year;
	cout << "Vendedor: "; cin >> Cars.bought_to;
	cout << "Precio - Compra: "; cin >> Cars.bought_for;

	cars_write << SiguienteID << ';' << Cars.maker << ';' << Cars.model << ';' << Cars.year << ';' << 0 << ';' << Cars.bought_to << ";" << 0 << ';' << Cars.bought_for << endl;
	cout << "Automovil agregado exitosamente" << endl;


	cars_write.close();
}
#pragma endregion

#pragma region Eliminar
void MenuEliminar() {
	int opcion1;
	cout << "_______________ \n " << endl;
	cout << "||||     |||| O P C I O N   D E ||||     ||||" << endl;
	cout << "||||   |||| E L I M I N A C I O N ||||   ||||" << endl;
	cout << "_______________ \n" << endl;

	cout << " 1- Eliminar Cliente" << endl; 
	cout << " 2- Eliminar Vendedor" << endl; 
	cout << " 3- Eliminar Vehiculo" << endl; 
	cout << " 4- Menu Principal" << endl; 
	cout << " Opcion: "; cin >> opcion1;

	switch (opcion1) {
	case 1: Eliminar_Cliente(); MenuEliminar(); break;
	case 2: Eliminar_Cliente(); MenuEliminar(); break;
	case 3: Eliminar_Auto(); MenuEliminar(); break;
	case 4: MenuPrincipal(); break;
	case 0: break;
	default: cout << "Opcion incorrecta" << endl << endl;
	}
}
void Eliminar_Cliente() {
	ifstream clients_read("..\\assets\\clients.csv");
	ofstream clients_write("..\\assets\\clients.csv", ios::app);
	ofstream clients_Temp("..\\assets\\clients_temp.csv", ios::in);
	string line, id_eliminar;
	bool existe = false;
	cout << "Ingrese el id del cliente que desea eliminar: "; cin >> id_eliminar;
	clients_Temp << Clientes << endl;
	getline(clients_read, line);
	while (getline(clients_read, line)) {
		istringstream ss(line);
		Client Clients;
		string id_str, age_str;
		getline(ss, id_str, ';');
		Clients.id = stoi(id_str);
		getline(ss, Clients.first_name, ';');
		getline(ss, Clients.last_name, ';');
		getline(ss, Clients.email, ';');
		getline(ss, age_str, ';');
		Clients.age = stoi(age_str);

		if (id_eliminar.compare(id_str) == 0) existe = true;
		else clients_Temp << Clients.id << ";" << Clients.first_name << ";" << Clients.last_name << ";" << Clients.email << ";" << Clients.age << endl;
	}

	clients_read.close();
	clients_Temp.close();
	clients_write.close();

	if (existe) {
		remove("..\\assets\\clients.csv");
		cout << "El cliente fue eliminado correctamente" << endl;
		int NowClient = rename("..\\assets\\clients_temp.csv", "..\\assets\\clients.csv");
		if (NowClient == 0) {
			ofstream Nuevo("..\\assets\\clients_temp.csv");
		}
		else {
			cout << "Hubo un fallo en la insercion de los registros" << endl;
		}

	}
	else {
		cout << "Cliente con el ID: " << id_eliminar << " no existe en los registros" << endl;
	}
}
void Eliminar_Auto() {

	ifstream cars_read("..\\assets\\cars_data.csv");
	ofstream cars_write("..\\assets\\cars_data.csv", ios::app);
	ofstream cars_Temp("..\\assets\\cars_data_temp.csv", ios::in);
	string line, id_eliminar;
	bool existe = false;
	cout << "Ingrese el id del automovil que desea eliminar: "; cin >> id_eliminar;
	cars_Temp << Autos << endl;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		string id_str, year_str, sold_to_str, sold_for_str, bought_to_str, bought_for_str;

		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		getline(ss, Cars.maker, ';');
		getline(ss, Cars.model, ';');
		getline(ss, year_str, ';');
		Cars.year = stoi(year_str);
		getline(ss, sold_to_str, ';');
		Cars.sold_to = stoi(sold_to_str);
		getline(ss, bought_to_str, ';');
		Cars.bought_to = stoi(bought_to_str);
		getline(ss, sold_for_str, ';');
		Cars.sold_for = stoi(sold_for_str);
		getline(ss, bought_for_str, ';');
		Cars.bought_for = stoi(bought_for_str);

		if (id_eliminar.compare(id_str) == 0) existe = true;
		else cars_Temp << Cars.id << ";" << Cars.maker << ";" << Cars.model << ";" << Cars.year << ";" << Cars.sold_to << ";" << Cars.bought_to << ";" << Cars.sold_for << ";" << Cars.bought_for << endl;
	}

	cars_read.close();
	cars_Temp.close();
	cars_write.close();

	if (existe) {
		remove("..\\assets\\cars_data.csv");
		cout << "El automovil fue eliminado correctamente" << endl;
		int NowCar = rename("..\\assets\\cars_data_temp.csv", "..\\assets\\cars_data.csv");
		if (NowCar == 0) {
			ofstream Nuevo("..\\assets\\cars_data_temp.csv");
		}
		else {
			cout << "Hubo un fallo en la insercion de los registros" << endl;
		}

	}
	else {
		cout << "Auto con el ID: " << id_eliminar << " no existe en los registros" << endl;
	}
}
#pragma endregion

#pragma region Mostrar
void MenuMostrar() {
	int opcion1;
	cout << "_____________________________________________ \n " << endl;
	cout << "||||     |||| O P C I O N   D E ||||     ||||" << endl;
	cout << "||||       |||| M O S T R A R ||||       ||||" << endl;
	cout << "_____________________________________________ \n" << endl;

	cout << " 1- Listado de Clientes" << endl;
	cout << " 2- Listado de Autos" << endl;
	cout << " 3- Busqueda de cliente por ID" << endl;
	cout << " 4- Busqueda de auto por ID" << endl;
	cout << " 5- Menu Principal" << endl;
	cout << " Opcion: "; cin >> opcion1;

	switch (opcion1) {
	case 1: Mostrar_Clientes(); MenuMostrar(); break;
	case 2: Mostrar_Autos(); MenuMostrar(); break;
	case 3: Mostrar_Cliente_x_id(); MenuMostrar(); break;
	case 4: Mostrar_Auto_x_id(); MenuMostrar(); break;
	case 5: MenuPrincipal(); break;
	case 0: break;
	default: cout << "Opcion incorrecta" << endl << endl;
	}
}
void Mostrar_Clientes() {
	string FileName = "..\\assets\\clients.csv";
	ifstream clients_read(FileName);
	string line;
	getline(clients_read, line);
	while (getline(clients_read, line)) {
		istringstream ss(line);
		Client Clients;
		string id_str, age_str;
		getline(ss, id_str, ';');
		Clients.id = stoi(id_str);
		getline(ss, Clients.first_name, ';');
		getline(ss, Clients.last_name, ';');
		getline(ss, Clients.email, ';');
		getline(ss, age_str, ';');
		Clients.age = stoi(age_str);

		cout << " ID________ " << Clients.id << endl;
		cout << " NOMBRES / APELLIDOS___ " << Clients.first_name << " " << Clients.last_name << endl;
		cout << " EMAIL_______ " << Clients.email << endl;
		cout << " AGE_______ " << Clients.age << endl;
		cout << " _________________________________________________________________________ \n" << endl;
	}

	clients_read.close();
	clients_read.open("..\\assets\\clients.csv");
}
void Mostrar_Autos() {
	ifstream cars_read("..\\assets\\cars_data.csv");
	string line;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		string id_str, year_str, sold_to_str, sold_for_str, bought_to_str, bought_for_str;
		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		getline(ss, Cars.maker, ';');
		getline(ss, Cars.model, ';');
		getline(ss, year_str, ';');
		Cars.year = stoi(year_str);
		getline(ss, sold_to_str, ';');
		Cars.sold_to = stoi(sold_to_str);
		getline(ss, bought_to_str, ';');
		Cars.bought_to = stoi(bought_to_str);
		getline(ss, sold_for_str, ';');
		Cars.sold_for = stoi(sold_for_str);
		getline(ss, bought_for_str, ';');
		Cars.bought_for = stoi(bought_for_str);


		cout << " ID: " << Cars.id << " MARCA: " << Cars.maker << " MODELO: " << Cars.model << " AÑO: " << Cars.year << endl;
		cout << " VENDEDOR: " << Cars.sold_to << " COMPRADOR: " << Cars.bought_to << endl;
		cout << " VENDIDO POR: " << Cars.sold_for << " COMPRADO POR: " << Cars.bought_for;
		int vendido = Cars.sold_for;
		int comprado = Cars.bought_for;
		int Dif = vendido - comprado;
		if (vendido < comprado) {
			cout << " PERDIDA: " << Dif << endl;
		}
		else {
			cout << " GANANCIA: " << Dif << endl;
		}
		cout << " ______________________________________________________________ \n" << endl;
	}
	cars_read.close();
	cars_read.open("..\\assets\\cars_data.csv");
}
void Mostrar_Cliente_x_id() {
	ifstream clients_read("..\\assets\\clients.csv");
	string line, id_client, id_str, age_str;
	bool existe = false;
	cout << " Ingrese el ID del cliente que desea consultar: "; cin >> id_client;
	getline(clients_read, line);
	while (getline(clients_read, line)) {
		istringstream ss(line);
		Client Clients;
		getline(ss, id_str, ';');
		Clients.id = stoi(id_str);
		getline(ss, Clients.first_name, ';');
		getline(ss, Clients.last_name, ';');
		getline(ss, Clients.email, ';');
		getline(ss, age_str, ';');
		Clients.age = stoi(age_str);

		if (id_client.compare(id_str) == 0) {
			existe = true;
			cout << " \n |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " ID________ " << Clients.id << endl;
			cout << " NOMBRES / APELLIDOS___ " << Clients.first_name << " " << Clients.last_name << endl;
			cout << " EMAIL_______ " << Clients.email << endl;
			cout << " AGE_______ " << Clients.age << endl;
			cout << " |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		}
	}
	clients_read.close();
	clients_read.open("..\\assets\\clients.csv");
	if (!existe) {
		cout << "ID:" << id_client << " no encontrado";
	}
}
void Mostrar_Auto_x_id() {
	ifstream cars_read("..\\assets\\cars_data.csv");
	string line, id_auto, registro, id_str, year_str, sold_to_str, sold_for_str, bought_to_str, bought_for_str;
	bool existe = false;
	cout << " Ingrese el ID del auto que desea consultar: "; cin >> id_auto;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		getline(ss, Cars.maker, ';');
		getline(ss, Cars.model, ';');
		getline(ss, year_str, ';');
		Cars.year = stoi(year_str);
		getline(ss, sold_to_str, ';');
		Cars.sold_to = stoi(sold_to_str);
		getline(ss, bought_to_str, ';');
		Cars.bought_to = stoi(bought_to_str);
		getline(ss, sold_for_str, ';');
		Cars.sold_for = stoi(sold_for_str);
		getline(ss, bought_for_str, ';');
		Cars.bought_for = stoi(bought_for_str);

		if (id_auto.compare(id_str) == 0) {
			existe = true;
			cout << " \n |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " ID: " << Cars.id << " MARCA: " << Cars.maker << " MODELO: " << Cars.model << " AÑO: " << Cars.year << endl;
			cout << " VENDEDOR: " << Cars.sold_to << " COMPRADOR: " << Cars.bought_to << endl;
			cout << " VENDIDO POR: " << Cars.sold_for << " COMPRADO POR: " << Cars.bought_for;
			int vendido = Cars.sold_for;
			int comprado = Cars.bought_for;
			int Dif = vendido - comprado;
			if (vendido < comprado) {
				cout << " PERDIDA: " << Dif << endl;
			}
			else {
				cout << " GANANCIA: " << Dif << endl;
			}
			cout << " ||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n" << endl;
		}

	}
	cars_read.close();
	cars_read.open("..\\assets\\cars_data.csv");
	if (!existe) {
		cout << "ID: " << id_auto << " no encontrado" << endl;
	}
}
#pragma endregion

#pragma region Modificar
void MenuModificar() {
	int opcion1;
	cout << "_____________________________________________ \n " << endl;
	cout << "||||     |||| O P C I O N   D E ||||     ||||" << endl;
	cout << "||||     |||| M O D I F I C A R ||||     ||||" << endl;
	cout << "_____________________________________________ \n" << endl;

	cout << " 1- Informacion - Auto" << endl;
	cout << " 2- Informacion - Cliente" << endl;
	cout << " 3- Menu Principal" << endl;
	cout << " Opcion: "; cin >> opcion1;

	switch (opcion1) {
	case 1: Modificar_Auto(); MenuModificar(); break;
	case 2: Modificar_Cliente(); MenuModificar(); break;
	case 3: MenuPrincipal(); break;
	case 0: break;
	default: cout << "Opcion incorrecta" << endl << endl;
	}
}
void Modificar_Auto() {
	ifstream cars_read("..\\assets\\cars_data.csv");
	ofstream cars_write("..\\assets\\cars_data.csv", ios::app);
	ofstream cars_Temp("..\\assets\\cars_data_temp.csv", ios::in);
	string line, id_modif;
	bool existe = false;
	cout << "Ingrese el id del automovil que desea modificar: "; cin >> id_modif;
	cars_Temp << Autos << endl;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		string id_str, year_str, sold_to_str, sold_for_str, bought_to_str, bought_for_str;

		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		getline(ss, Cars.maker, ';');
		getline(ss, Cars.model, ';');
		getline(ss, year_str, ';');
		Cars.year = stoi(year_str);
		getline(ss, sold_to_str, ';');
		Cars.sold_to = stoi(sold_to_str);
		getline(ss, bought_to_str, ';');
		Cars.bought_to = stoi(bought_to_str);
		getline(ss, sold_for_str, ';');
		Cars.sold_for = stoi(sold_for_str);
		getline(ss, bought_for_str, ';');
		Cars.bought_for = stoi(bought_for_str);

		if (id_modif.compare(id_str) == 0) {
			existe = true;

			cout << " |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " ID: " << Cars.id << " MARCA: " << Cars.maker << " MODELO: " << Cars.model << " AO: " << Cars.year << endl;
			cout << " COMPRADOR: " << Cars.bought_to << endl;
			cout << " COMPRADO POR: " << Cars.bought_for << endl;
			cout << " ||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n" << endl;
			cout << "Ingrese en cuanto fue vendido: " << endl; cin >> Cars.sold_for;
			cout << "Ingrese el codigo del cliente: " << endl; cin >> Cars.sold_to;

			cars_Temp << Cars.id << ";" << Cars.maker << ";" << Cars.model << ";" << Cars.year << ";" << Cars.sold_to << ";" << Cars.bought_to << ";" << Cars.sold_for << ";" << Cars.bought_for << endl;
		}

		else {
			cars_Temp << Cars.id << ";" << Cars.maker << ";" << Cars.model << ";" << Cars.year << ";" << Cars.sold_to << ";" << Cars.bought_to << ";" << Cars.sold_for << ";" << Cars.bought_for << endl;
		}

	}
	cars_read.close();
	cars_Temp.close();
	cars_write.close();

	if (existe) {
		remove("..\\assets\\cars_data.csv");
		cout << "El automovil fue modificado correctamente" << endl;
		int NowCar = rename("..\\assets\\cars_data_temp.csv", "..\\assets\\cars_data.csv");
		if (NowCar == 0) {
			ofstream Nuevo("..\\assets\\cars_data_temp.csv");
		}
		else {
			cout << "Hubo un fallo en la insercion de los registros" << endl;
		}
	}
	else {
		cout << "Auto con el ID: " << id_modif << " no existe en los registros" << endl;
	}
}
void Modificar_Cliente() {

	ifstream clients_read("..\\assets\\clients.csv");
	ofstream clients_write("..\\assets\\clients.csv", ios::app);
	ofstream clients_Temp("..\\assets\\clients_temp.csv", ios::in);
	string line, id_modif;
	bool existe = false;

	cout << "Ingrese el id del cliente que desea modificar: "; cin >> id_modif;
	clients_Temp << Clientes << endl;
	getline(clients_read, line);
	while (getline(clients_read, line)) {
		istringstream ss(line);
		Client Clients;
		string id_str, age_str;
		getline(ss, id_str, ';');
		Clients.id = stoi(id_str);
		getline(ss, Clients.first_name, ';');
		getline(ss, Clients.last_name, ';');
		getline(ss, Clients.email, ';');
		getline(ss, age_str, ';');
		Clients.age = stoi(age_str);

		if (id_modif.compare(id_str) == 0) {
			existe = true;

			cout << " |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " ID: " << Clients.id << " EDAD: " << Clients.age << endl;
			cout << " ||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n" << endl;

			cout << "Ingrese el nombre: " << endl; cin >> Clients.first_name;
			cout << "Ingrese el apellido: " << endl; cin >> Clients.last_name;
			cout << "Ingrese el correo: " << endl; cin >> Clients.email;

			clients_Temp << Clients.id << ";" << Clients.first_name << ";" << Clients.last_name << ";" << Clients.email << ";" << Clients.age << endl;
		}

		else {
			clients_Temp << Clients.id << ";" << Clients.first_name << ";" << Clients.last_name << ";" << Clients.email << ";" << Clients.age << endl;
		}
	}

	clients_read.close();
	clients_Temp.close();
	clients_write.close();

	if (existe) {
		remove("..\\assets\\clients.csv");
		cout << "El cliente fue modificado correctamente" << endl;
		int NowCar = rename("..\\assets\\clients_temp.csv", "..\\assets\\clients.csv");
		if (NowCar == 0) {
			ofstream Nuevo("..\\assets\\clients_temp.csv");
		}
		else {
			cout << "Hubo un fallo en la insercion de los registros" << endl;
		}
	}
	else {
		cout << "El cliente con el ID: " << id_modif << " no existe en los registros" << endl;
	}

}
#pragma endregion

void MenuEstadistica() {
	int opcion1;
	cout << "_____________________________________________ \n " << endl;
	cout << "||||     |||| O P C I O N   D E ||||     ||||" << endl;
	cout << "||||   |||| E S T A D I S T I C A ||||   ||||" << endl;
	cout << "_____________________________________________ \n" << endl;

	cout << " 1- Estadistica General" << endl;
	cout << " 2- Autos Comprados" << endl;
	cout << " 3- Autos Vendidos" << endl;
	cout << " 4- Autos Sin vender" << endl;
	cout << " 5- Menu Principal" << endl;
	cout << " Opcion: "; cin >> opcion1;

	switch (opcion1) {
	case 1: Estadistica_General(); MenuEstadistica(); break;
	case 2: Autos_Comprados(); MenuEstadistica(); break;
	case 3: Autos_Vendidos(); MenuEstadistica(); break;
	case 4: Autos_sin_vender(); MenuEstadistica(); break;
	case 5: MenuPrincipal(); break;
	case 0: break;
	default: cout << "Opcion incorrecta" << endl << endl;
	}
}
void Estadistica_General() {
	int autos_Vendidos = 0;
	int autos_Perdida = 0;
	ifstream cars_read("..\\assets\\cars_data.csv");
	string line, id_auto, registro, id_str, year_str, sold_to_str, sold_for_str, bought_to_str, bought_for_str;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		getline(ss, Cars.maker, ';');
		getline(ss, Cars.model, ';');
		getline(ss, year_str, ';');
		Cars.year = stoi(year_str);
		getline(ss, sold_to_str, ';');
		Cars.sold_to = stoi(sold_to_str);
		getline(ss, bought_to_str, ';');
		Cars.bought_to = stoi(bought_to_str);
		getline(ss, sold_for_str, ';');
		Cars.sold_for = stoi(sold_for_str);
		getline(ss, bought_for_str, ';');
		Cars.bought_for = stoi(bought_for_str);

		if (sold_for_str.compare("0") == 0) {
			autos_Perdida++;
		}
		else {
			autos_Vendidos++;
		}
	}
	cout << " ____________________________________________\n" << endl;
	cout << " | Stock Autos - Comprados ________> " << autos_Perdida + autos_Vendidos << endl;
	cout << " | Autos con registro de venta ____> " << autos_Vendidos << endl;
	cout << " | Autos sin registro de venta ____> " << autos_Perdida << endl;
	cout << " ____________________________________________" << endl;
	cars_read.close();
	cars_read.open("..\\assets\\cars_data.csv");
}
void Autos_Comprados() {
	ifstream cars_read("..\\assets\\cars_data.csv");
	string line;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		string id_str, year_str, sold_to_str, sold_for_str, bought_to_str, bought_for_str;
		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		getline(ss, Cars.maker, ';');
		getline(ss, Cars.model, ';');
		getline(ss, year_str, ';');
		Cars.year = stoi(year_str);
		getline(ss, sold_to_str, ';');
		Cars.sold_to = stoi(sold_to_str);
		getline(ss, bought_to_str, ';');
		Cars.bought_to = stoi(bought_to_str);
		getline(ss, sold_for_str, ';');
		Cars.sold_for = stoi(sold_for_str);
		getline(ss, bought_for_str, ';');
		Cars.bought_for = stoi(bought_for_str);

		cout << " |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << " ID: " << Cars.id << " MARCA: " << Cars.maker << " MODELO: " << Cars.model << " AÑO: " << Cars.year << endl;
		cout << " VENDEDOR: " << Cars.sold_to << " COMPRADOR: " << Cars.bought_to << endl;
		cout << " VENDIDO POR: " << Cars.sold_for << " COMPRADO POR: " << Cars.bought_for;
		int vendido = Cars.sold_for;
		int comprado = Cars.bought_for;
		int Dif = comprado - vendido;
		if (vendido < comprado) {
			cout << " GANANCIA: " << Dif << endl;
		}
		else {
			cout << " PERDIDA: " << Dif << endl;
		}
		cout << " ||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n" << endl;
	}
	cars_read.close();
	cars_read.open("..\\assets\\cars_data.csv");
}
void Autos_Vendidos() {
	ifstream cars_read("..\\assets\\cars_data.csv");
	string line;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		string id_str, year_str, sold_to_str, sold_for_str, bought_to_str, bought_for_str;
		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		getline(ss, Cars.maker, ';');
		getline(ss, Cars.model, ';');
		getline(ss, year_str, ';');
		Cars.year = stoi(year_str);
		getline(ss, sold_to_str, ';');
		Cars.sold_to = stoi(sold_to_str);
		getline(ss, bought_to_str, ';');
		Cars.bought_to = stoi(bought_to_str);
		getline(ss, sold_for_str, ';');
		Cars.sold_for = stoi(sold_for_str);
		getline(ss, bought_for_str, ';');
		Cars.bought_for = stoi(bought_for_str);


		if (sold_for_str.compare("0") != 0)
		{
			cout << " |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " ID: " << Cars.id << " MARCA: " << Cars.maker << " MODELO: " << Cars.model << " A�O: " << Cars.year << endl;
			cout << " VENDEDOR: " << Cars.sold_to << " COMPRADOR: " << Cars.bought_to << endl;
			cout << " VENDIDO POR: " << Cars.sold_for << " COMPRADO POR: " << Cars.bought_for;
			int vendido = Cars.sold_for;
			int comprado = Cars.bought_for;
			int Dif = comprado - vendido;
			if (vendido < comprado) {
				cout << " GANANCIA: " << Dif << endl;
			}
			else {
				cout << " PERDIDA: " << Dif << endl;
			}
			cout << " |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		}
	}

	cars_read.close();
	cars_read.open("..\\assets\\cars_data.csv");
}
void Autos_sin_vender() {
	ifstream cars_read("..\\assets\\cars_data.csv");
	string line;
	getline(cars_read, line);
	while (getline(cars_read, line)) {
		istringstream ss(line);
		Car Cars;
		string id_str, year_str, sold_to_str, sold_for_str, bought_to_str, bought_for_str;
		getline(ss, id_str, ';');
		Cars.id = stoi(id_str);
		getline(ss, Cars.maker, ';');
		getline(ss, Cars.model, ';');
		getline(ss, year_str, ';');
		Cars.year = stoi(year_str);
		getline(ss, sold_to_str, ';');
		Cars.sold_to = stoi(sold_to_str);
		getline(ss, bought_to_str, ';');
		Cars.bought_to = stoi(bought_to_str);
		getline(ss, sold_for_str, ';');
		Cars.sold_for = stoi(sold_for_str);
		getline(ss, bought_for_str, ';');
		Cars.bought_for = stoi(bought_for_str);


		if (sold_for_str.compare("0") == 0)
		{
			cout << " |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " ID: " << Cars.id << " MARCA: " << Cars.maker << " MODELO: " << Cars.model << " AñO: " << Cars.year << endl;
			cout << " VENDEDOR: " << Cars.sold_to << " COMPRADOR: " << Cars.bought_to << endl;
			cout << " VENDIDO POR: " << Cars.sold_for << " COMPRADO POR: " << Cars.bought_for;
			int vendido = Cars.sold_for;
			int comprado = Cars.bought_for;
			int Dif = comprado - vendido;
			if (vendido < comprado) {
				cout << " GANANCIA: " << Dif << endl;
			}
			else {
				cout << " PERDIDA: " << Dif << endl;
			}
			cout << " ||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n" << endl;
		}
	}

	cars_read.close();
	cars_read.open("..\\assets\\cars_data.csv");
}
#pragma endregion

int main() {
    MenuPrincipal();
}