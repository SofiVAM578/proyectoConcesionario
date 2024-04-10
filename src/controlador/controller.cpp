#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Cliente {
    string id;
    string nombre;
    string apellido;
    string correo;
    string edad;
};

struct Car {
	string id;
	string marca;
	string modelo;
	string año;
	string vendedor;
	string comprador;
	string vendido;
	string comprado;
};

class ClientModel {
public:
    void agregar_a_csv(string filename, string nombre, string apellido, string correo, int edad) {
		try {
			ofstream file_write(filename, ios::app);
			ifstream file_read(filename);
			int UltimoID = 0;
			string line;
			getline(file_read, line);

			while (getline(file_read, line)) {
				stringstream ss(line);
				string id;
				getline(ss, id, ',');
				int current_id = stoi(id);
				UltimoID = current_id;
			}

			int siguienteID = UltimoID + 1;

			file_write << siguienteID << ";" << nombre << ";" << apellido << ";" << correo << ";" << edad << endl;
			cout << " Cliente agregado . . ." << endl;
			file_write.close();
			file_read.close();
		}
		catch (const exception& e) {
			cerr << "Error al agregar al archivo CSV: " << e.what() << endl;
		}
	}

    void eliminar_de_csv(string filename, string id_to_remove) {
	ifstream file(filename);
    ofstream temp("../assets/clients_temp.csv", ios::app);
    string line, columnas = "id;nombre;apellido;correo;edad";
    bool existe = false;
    getline(file, line);
   
    // Leer datos del archivo y almacenarlos en un arreglo dinámico
    Cliente* clientes = nullptr;
    int numClientes = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, nombre, apellido, correo, edad;
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, apellido, ';');
        getline(ss, correo, ';');
        getline(ss, edad);

        // Agregar cliente al arreglo dinámico
        Cliente cliente = {id, nombre, apellido, correo, edad};
        Cliente* tempArray = new Cliente[numClientes + 1];
        for (int i = 0; i < numClientes; ++i) {
            tempArray[i] = clientes[i];
        }
        tempArray[numClientes++] = cliente;
        delete[] clientes;
        clientes = tempArray;
    }
    file.close();

    // Ordenar el arreglo dinámico por id
    sort(clientes, clientes + numClientes, [](const Cliente& a, const Cliente& b) {
        return a.id < b.id;
    });

    // Búsqueda binaria
    int left = 0, right = numClientes - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (clientes[mid].id == id_to_remove) {
            existe = true;
            // Eliminar el cliente del arreglo dinámico
            Cliente* tempArray = new Cliente[numClientes - 1];
            int idx = 0;
            for (int i = 0; i < numClientes; ++i) {
                if (i != mid) {
                    tempArray[idx++] = clientes[i];
                }
            }
            delete[] clientes;
            clientes = tempArray;
            numClientes--;
            break;
        } else if (clientes[mid].id < id_to_remove) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Escribir los clientes restantes en el archivo temporal
    temp << columnas << endl;
    for (int i = 0; i < numClientes; ++i) {
        temp << clientes[i].id << ';' << clientes[i].nombre << ';' << clientes[i].apellido << ';' << clientes[i].correo << ';' << clientes[i].edad << endl;
    }
    temp.close();

    if (existe) {
        remove(filename.c_str());
        int cars = rename("../assets/clients_temp.csv", "../assets/clients.csv");
        if (cars == 0) {
            cout << " Cliente eliminado . . . " << endl;
            ofstream nuevo("../assets/clients_temp.csv");
        } else {
            cout << " Hubo un fallo en la insercion de los registros" << endl;
        }
    } else {
        cout << " El id ingresado, no existe en los registros" << endl;
    }

    // Liberar memoria del arreglo dinámico
    delete[] clientes;
	}

	void modificar_csv(string filename, string id_modificar) {
	ifstream file(filename);
    ofstream temp("../assets/clients_temp.csv", ios::app);
    string line, columnas = "id;nombre;apellido;correo;edad";
    bool existe = false;
    getline(file, line);
   
    // Leer datos del archivo y almacenarlos en un arreglo dinámico
    Cliente* clientes = nullptr;
    int numClientes = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, nombre, apellido, correo, edad;
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, apellido, ';');
        getline(ss, correo, ';');
        getline(ss, edad);

        // Agregar cliente al arreglo dinámico
        Cliente cliente = {id, nombre, apellido, correo, edad};
        Cliente* tempArray = new Cliente[numClientes + 1];
        for (int i = 0; i < numClientes; ++i) {
            tempArray[i] = clientes[i];
        }
        tempArray[numClientes++] = cliente;
        delete[] clientes;
        clientes = tempArray;
    }
    // Fin del while
    file.close();

    // Ordenar el arreglo dinámico por id
    sort(clientes, clientes + numClientes, [](const Cliente& a, const Cliente& b) {
        return a.id < b.id;
    });

    // Búsqueda binaria
    int left = 0, right = numClientes - 1;
    while (left <= right) {
    int mid = left + (right - left) / 2;
    if (clientes[mid].id == id_modificar) {
        existe = true;
        // Imprecion en patalla de la informacion solicitada 
                cout << " __________________ \n" << endl;
				cout << " NOMBRES / APELLIDOS___ " << clientes[mid].nombre << " " << clientes[mid].apellido << endl;
				cout << " CORREO______ " << clientes[mid].correo << endl;
				cout << " EDAD________ " << clientes[mid].edad<< endl;
				cout << " __________________ \n" << endl;

        // Modificar la información del cliente
        cout << " Ingrese el nuevo nombre: ";
        cin >> clientes[mid].nombre;
        cout << " Ingrese el nuevo apellido: ";
        cin >> clientes[mid].apellido;
        cout << " Ingrese el nuevo correo: ";
        cin >> clientes[mid].correo;
        cout << " Ingrese la nueva edad: ";
        cin >> clientes[mid].edad;
        break;
    } else if (clientes[mid].id < id_modificar) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}

    // Escribir los clientes restantes en el archivo temporal
    temp << columnas << endl;
    for (int i = 0; i < numClientes; ++i) {
        temp << clientes[i].id << ';' << clientes[i].nombre << ';' << clientes[i].apellido << ';' << clientes[i].correo << ';' << clientes[i].edad << endl;
    }
    temp.close();

    if (existe) {
        remove(filename.c_str());
        int cars = rename("../assets/clients_temp.csv", "../assets/clients.csv");
        if (cars == 0) {
            cout << "\nInformacion del cliente actualizada . . . " << endl;
            ofstream nuevo("../assets/clients_temp.csv");
        } else {
            cout << " Hubo un fallo en la insercion de los registros" << endl;
        }
    } else {
        cout << " El id ingresado, no existe en los registros" << endl;
    }

    // Liberar memoria del arreglo dinámico
    delete[] clientes;
	}

};

class AutoModel {
public:
    void agregar_a_csv(string filename, string marca, string modelo, string año, string comprado) {
			try
		{
			ofstream file_write(filename, ios::app);
			ifstream file_read(filename);
			int UltimoID = 0;
			string line;
			getline(file_read, line);

			while (getline(file_read, line)) {
				stringstream ss(line);
				string token;
				getline(ss, token, ',');
				int current_id = stoi(token);
				UltimoID = current_id;
			}

			int siguienteID = UltimoID + 1;

			file_write << siguienteID << ";" << marca << ";" << modelo << ";" << año << ";" << 0 << ";" << 0 << ";" << 0 << ";" << comprado << endl;
			cout << " Auto agregado . . ." << endl;
			file_write.close();
			file_read.close();
		}
		catch (const exception& e)
		{
			cout << " Error al Eliminar el registro del archivo CSV: " << e.what() << endl;
		}

	}

    void eliminar_de_csv(const string& filename, const string& id_to_remove) {
	
			ifstream file(filename);
			ofstream temp("../assets/cars_data_temp.csv", ios::app);
			string line, columnas = "id;marca;modelo;año;vendedor;comprador;vendido;comprado";
			bool existe = false;
			getline(file, line);

			 Car* cars = nullptr;
			 int numautos = 0;

			while (getline(file, line)) {
				stringstream ss(line);
				string id, marca, modelo, año, vendedor,comprador, vendido, comprado;
				getline(ss, id, ';');
				getline(ss, marca, ';');
				getline(ss, modelo, ';');
				getline(ss, año, ';');
				getline(ss, vendedor, ';');
				getline(ss, comprador, ';');
				getline(ss, vendido, ';');
				getline(ss, comprado, ';');

				Car car = {id, marca, modelo, año, vendedor,comprador, vendido, comprado};
				Car* tempArray = new Car[numautos + 1];
				for (int i = 0; i < numautos; ++i) {
				tempArray[i] = cars[i];
				}
				tempArray[numautos++] = car;
				delete[] cars;
				cars = tempArray;
			}
			file.close();

			// Ordenar el arreglo dinámico por id
		sort(cars, cars + numautos, [](const Car& a, const Car& b) {
        return a.id < b.id;
		});

		int left = 0, right = numautos - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].id == id_to_remove) {
            existe = true;
            // Eliminar el cliente del arreglo dinámico
            Car* tempArray = new Car[numautos - 1];
            int idx = 0;
            for (int i = 0; i < numautos; ++i) {
                if (i != mid) {
                    tempArray[idx++] = cars[i];
                }
            }
            delete[] cars;
            cars = tempArray;
            numautos--;
            break;
        } else if (cars[mid].id < id_to_remove) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

	 // Escribir los clientes restantes en el archivo temporal
    temp << columnas << endl;
    for (int i = 0; i < numautos; ++i) {
        temp << cars[i].id << ';' << cars[i].marca << ';' << cars[i].modelo << ';' << cars[i].año << ';' << cars[i].vendedor << ';' << cars[i].comprador << ';' << cars[i].vendido << ';' << cars[i].comprado << endl;
    }

	temp.close();

			if (existe) {
				remove(filename.c_str());
				int cars = rename("../assets/cars_data_temp.csv", "../assets/cars_data.csv");
				if (cars == 0) {
					ofstream nuevo("../assets/cars_data_temp.csv");
					cout << "Auto eliminado . . . " << endl;
				}
				else {
					cout << "Hubo un fallo en la insercion de los registros" << endl;
				}
			}
			else {
				cout << "El id ingresado, no existe en los registros" << endl;
			}

			delete[] cars;

	}

	void modificar_csv(string filename, string id_modificar) {
		ifstream file(filename);
			ofstream temp("../assets/cars_data_temp.csv", ios::app);
			string line, columnas = "id;marca;modelo;año;vendedor;comprador;vendido;comprado";
			bool existe = false;
			getline(file, line);

			 Car* cars = nullptr;
			 int numautos = 0;

			while (getline(file, line)) {
				stringstream ss(line);
				string id, marca, modelo, año, vendedor,comprador, vendido, comprado;
				getline(ss, id, ';');
				getline(ss, marca, ';');
				getline(ss, modelo, ';');
				getline(ss, año, ';');
				getline(ss, vendedor, ';');
				getline(ss, comprador, ';');
				getline(ss, vendido, ';');
				getline(ss, comprado, ';');

				Car car = {id, marca, modelo, año, vendedor,comprador, vendido, comprado};
				Car* tempArray = new Car[numautos + 1];
				for (int i = 0; i < numautos; ++i) {
				tempArray[i] = cars[i];
				}
				tempArray[numautos++] = car;
				delete[] cars;
				cars = tempArray;
			}
			file.close();

			// Ordenar el arreglo dinámico por id
		sort(cars, cars + numautos, [](const Car& a, const Car& b) {
        return a.id < b.id;
		});

		int left = 0, right = numautos - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].id == id_modificar) {
            existe = true;
            cout << " \n ______________________________________________________ \n" << endl;
				cout << " ID____________________ " << cars[mid].id << endl;
				cout << " MARCA / MODELO________ " << cars[mid].marca << " " << cars[mid].modelo << endl;
				cout << " AÑO___________________ " << cars[mid].año << endl;
				cout << " VENDENDOR_____________ " << cars[mid].vendedor << endl;
				cout << " COMPRADOR_____________ " << cars[mid].comprador << endl;
				cout << " VENDIDO EN____________ " << cars[mid].vendido << endl;
				cout << " COMPRADO POR__________ " << cars[mid].comprado << endl;
				int ven= stoi(cars[mid].vendido);
				int com= stoi(cars[mid].comprado);
				int Dif= ven - com;
				if (ven < com){
					cout << " PERDIDA: " << Dif << endl;
				}
				else{
					cout << " GANANCIA: " << Dif << endl;
				}
				
				cout << " ______________________________________________________ \n" << endl;

		
        cout << " Ingrese el ID del vendedor: ";
        cin >> cars[mid].vendedor;
		 cout << " Ingrese el ID del comprador: ";
        cin >> cars[mid].comprador ;
		 cout << " Ingrese el monto de la venta: ";
        cin >> cars[mid].vendido;


            break;
        } else if (cars[mid].id < id_modificar) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

	 // Escribir los clientes restantes en el archivo temporal
    temp << columnas << endl;
    for (int i = 0; i < numautos; ++i) {
        temp << cars[i].id << ';' << cars[i].marca << ';' << cars[i].modelo << ';' << cars[i].año << ';' << cars[i].vendedor << ';' << cars[i].comprador << ';' << cars[i].vendido << ';' << cars[i].comprado << endl;
    }

	temp.close();

			if (existe) {
				remove(filename.c_str());
				int cars = rename("../assets/cars_data_temp.csv", "../assets/cars_data.csv");
				if (cars == 0) {
					ofstream nuevo("../assets/cars_data_temp.csv");
					cout << "Auto vendido . . . " << endl;
				}
				else {
					cout << "Hubo un fallo en la insercion de los registros" << endl;
				}
			}
			else {
				cout << "El id ingresado, no existe en los registros" << endl;
			}

			delete[] cars;
	
	}
};