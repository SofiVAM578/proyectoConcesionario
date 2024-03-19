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

#pragma region Agregar
void MenuAgregar() {
	int opcion1;
	cout << "_______________ \n " << endl;
	cout << "||||     |||| O P C I O N   D E ||||     ||||" << endl;
	cout << "||||     ||||  R E G I S T R O  ||||     ||||" << endl;
	cout << "_______________ \n" << endl;

	cout << " 1- Agregar Cliente" << endl;
	cout << " 2- Agregar Vendedor" << endl;
	cout << " 3- Agregar Vehiculo" << endl;
	cout << " 4- Menu Principal" << endl;
	cout << " Opcion: "; cin >> opcion1;

	switch (opcion1) {
	case 1: Agregar_Cliente(); MenuAgregar();
	case 2: Agregar_Cliente(); MenuAgregar();
	case 3: Agregar_Auto(); MenuAgregar();
	case 4: MenuPrincipal(); break;
	case 0: break;
	default: cout << "Opcion incorrecta" << endl << endl;
	}
}
void Agregar_Cliente() {
	ifstream clients_read("clients.csv");
	ofstream clients_write("clients.csv", ios::app);
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
	ifstream cars_read("cars_data.csv");
	ofstream cars_write("cars_data.csv", ios::app);
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