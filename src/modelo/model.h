#include <iostream>
#include <fstream>
#include <sstream>
#include "../controlador/controller.cpp"
#include "../vista/view.cpp"

class ClientController {
private:
	ClientModel model;
	ClienteView view;
public:
	void AgregarCliente(string nombre, string apellido, string correo, int edad) {
		model.agregar_a_csv("../assets/clients.csv", nombre, apellido, correo, edad);
	}
	void EliminarCliente(string id) {
		model.eliminar_de_csv("../assets/clients.csv", id);
	}
	void ModificarCliente(string id_modificar) {
		model.modificar_csv("../assets/clients.csv", id_modificar);
	}
	void MostrarClientes() {
		view.mostrar_registros_csv("../assets/clients.csv");
	}
    void MostrarCLientexID(string id){
        view.mostrar_x_id_csv("../assets/clients.csv", id);
    }
};

class Estadisticacontroller {
private:
	EstadisticaView view;
public:

void compraventacliente(){
		view.compraventa_x_cliente("../assets/clients.csv", "../assets/cars_data.csv");
	}
void compraventaauto(){
		view.cliente_vendedor_Xauto("../assets/clients.csv", "../assets/cars_data.csv");
	}

};