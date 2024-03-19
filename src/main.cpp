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

int main() {
    MenuPrincipal();
}