#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class ClienteView {
public:
 void mostrar_registros_csv(string filename) {
  try {
   ifstream file(filename);
   string line;
   cout << " LISTADO DE AUTOS:" << endl;
   getline(file, line);
   while (getline(file, line)) {
    stringstream ss(line);
    string id, nombre, apellido, correo, edad;

    getline(ss, id, ';');
    int current_id = stoi(id);
    getline(ss, nombre, ';');
    getline(ss, apellido, ';');
    getline(ss, correo, ';');
    getline(ss, edad, ';');
    int current_edad = stoi(edad);

    cout << " \n __________________________________________________ \n" << endl;
    cout << " ID____________________ " << current_id << endl;
    cout << " NOMBRES / APELLIDOS___ " << nombre << " " << apellido << endl;
    cout << " CORREO________________ " << correo << endl;
    cout << " EDAD__________________ " << edad << endl;
    cout << " __________________________________________________ \n" << endl;

   }
   file.close();
  }
  catch (const exception& e) {
   cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
  }
 }

 void mostrar_x_id_csv(string filename, string id_client) {
  try {
   ifstream file(filename);
   string line;
   string id, nombre, apellido, correo, edad;
   bool existe = false;
   getline(file, line);
   while (getline(file, line)) {
    stringstream ss(line);

   getline(ss, id, ';');
    int current_id = stoi(id);
    getline(ss, nombre, ';');
    getline(ss, apellido, ';');
    getline(ss, correo, ';');
    getline(ss, edad, ';');
    int current_edad = stoi(edad);

    if (id_client.compare(id) == 0) {
    existe = true;
    cout << " \n __________________________________________________ \n" << endl;
    cout << " ID____________________ " << current_id << endl;
    cout << " NOMBRES / APELLIDOS___ " << nombre << " " << apellido << endl;
    cout << " CORREO________________ " << correo << endl;
    cout << " EDAD__________________ " << current_edad << endl;
    cout << " __________________________________________________ \n" << endl;
}
    
   }
   file.close();
  }
  catch (const exception& e) {
   cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
  }
  
 }
};

class AutoView {
public:
void mostrar_registros_csv(string filename) {
		try {
			ifstream file(filename);
			string line;
			cout << " LISTADO DE AUTOS:" << endl;
			getline(file, line);
			while (getline(file, line)) {
				stringstream ss(line);
				string id, marca, modelo, año, vendedor, comprador, vendido, comprado;

				getline(ss, id, ';');
				int current_id = stoi(id);
				getline(ss, marca, ';');
				getline(ss, modelo, ';');
				getline(ss, año, ';');
				int current_año = stoi(año);
				getline(ss, vendedor, ';');
				int current_vendedor = stoi(vendedor);
				getline(ss, comprador, ';');
				int current_comprador = stoi(comprador);
				getline(ss, vendido, ';');
				int current_vendido = stoi(vendido);
				getline(ss, comprado, ';');
				int current_comprado = stoi(comprado);

				cout << " \n |||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << " ID: " << current_id << " MARCA: " << marca << " MODELO: " << modelo << " AÑO: " << current_año << endl;
				cout << " VENDEDOR: " << current_vendedor << " COMPRADOR: " << current_comprador << endl;
				cout << " VENDIDO POR: " << current_vendido << " COMPRADO POR: " << current_comprado;
				int Dif = current_vendido - current_comprado;
				if (current_vendido < current_comprado) {
					cout << " PERDIDA: " << Dif << endl;
				}
				else {
					cout << " GANANCIA: " << Dif << endl;
				}
				cout << " ||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n" << endl;
			}
			file.close();
		}
		catch (const exception& e) {
			cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
		}
	}

void mostrar_x_id_csv(string filename, string id_auto) {
		try {
			ifstream file(filename);
			string line;
			string id, marca, modelo, año, vendedor, comprador, vendido, comprado;
			bool existe = false;
			getline(file, line);
			while (getline(file, line)) {
				stringstream ss(line);
				
				getline(ss, id, ';');
				int current_id = stoi(id);
				getline(ss, marca, ';');
				getline(ss, modelo, ';');
				getline(ss, año, ';');
				int current_año = stoi(año);
				getline(ss, vendedor, ';');
				int current_vendedor = stoi(vendedor);
				getline(ss, comprador, ';');
				int current_comprador = stoi(comprador);
				getline(ss, vendido, ';');
				int current_vendido = stoi(vendido);
				getline(ss, comprado, ';');
				int current_comprado = stoi(comprado);

				if (id_auto.compare(id) == 0) {
				existe = true;
				cout << " \n ______________________________________________________ \n" << endl;
				cout << " ID____________________ " << current_id << endl;
				cout << " MARCA / MODELO________ " << marca << " " << modelo << endl;
				cout << " AÑO___________________ " << año << endl;
				cout << " VENDENDOR_____________ " << current_vendedor << endl;
				cout << " COMPRADOR_____________ " << current_comprador << endl;
				cout << " VENDIDO EN____________ " << current_vendido << endl;
				cout << " COMPRADO POR__________ " << current_comprado << endl;
				int Dif= current_vendido-current_comprado;
				if (vendido < comprado){
					cout << " PERDIDA: " << Dif << endl;
				}
				else{
					cout << " GANANCIA: " << Dif << endl;
				}
				
				cout << " ______________________________________________________ \n" << endl;
}
				
			}
			file.close();
		}
		catch (const exception& e) {
			cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
		}
		
	}
	
void stock(string filename){
		try {
			ifstream file(filename);
			string line;
			string id, marca, modelo, año, vendedor, comprador, vendido, comprado;
			bool existe = false;
			int autos_Vendidos = 0;
			int autos_Perdida = 0;
			getline(file, line);
			while (getline(file, line)) {
				stringstream ss(line);
				
				getline(ss, id, ';');
				int current_id = stoi(id);
				getline(ss, marca, ';');
				getline(ss, modelo, ';');
				getline(ss, año, ';');
				int current_año = stoi(año);
				getline(ss, vendedor, ';');
				int current_vendedor = stoi(vendedor);
				getline(ss, comprador, ';');
				int current_comprador = stoi(comprador);
				getline(ss, vendido, ';');
				int current_vendido = stoi(vendido);
				getline(ss, comprado, ';');
				int current_comprado = stoi(comprado);

				if (current_vendido != 0) {
					autos_Vendidos++;
				}
				
				else{
					autos_Perdida++;
				}
				
				}
				cout << " ____________________________________________\n" << endl;
				cout << " | Stock Autos - Comprados ________> " << autos_Perdida + autos_Vendidos << endl;
				cout << " | Autos con registro de venta ____> " << autos_Vendidos << endl;
				cout << " | Autos sin registro de venta ____> " << autos_Perdida << endl;
				cout << " ____________________________________________" << endl;
				file.close();

			}
			catch (const exception& e) {
			cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
		}

		}

void sinverder(string filename){
		try {
			ifstream file(filename);
			string line;
			string id, marca, modelo, año, vendedor, comprador, vendido, comprado;
			bool existe = false;
			int autos_sinvender = 0;
			getline(file, line);
			while (getline(file, line)) {
				stringstream ss(line);
				
				getline(ss, id, ';');
				int current_id = stoi(id);
				getline(ss, marca, ';');
				getline(ss, modelo, ';');
				getline(ss, año, ';');
				int current_año = stoi(año);
				getline(ss, vendedor, ';');
				int current_vendedor = stoi(vendedor);
				getline(ss, comprador, ';');
				int current_comprador = stoi(comprador);
				getline(ss, vendido, ';');
				int current_vendido = stoi(vendido);
				getline(ss, comprado, ';');
				int current_comprado = stoi(comprado);

				if (current_vendido == 0) {
				autos_sinvender++;
				cout << " \n ______________________________________________________ \n" << endl;
				cout << " ID____________________ " << current_id << endl;
				cout << " MARCA / MODELO________ " << marca << " " << modelo << endl;
				cout << " AÑO___________________ " << año << endl;
				cout << " VENDENDOR_____________ " << current_vendedor << endl;
				cout << " COMPRADOR_____________ " << current_comprador << endl;
				cout << " VENDIDO EN____________ " << current_vendido << endl;
				cout << " COMPRADO POR__________ " << current_comprado << endl;
				int Dif= current_vendido-current_comprado;
				if (vendido < comprado){
					cout << " PERDIDA: " << Dif << endl;
				}
				else{
					cout << " GANANCIA: " << Dif << endl;
				}
				
				cout << " ______________________________________________________ \n" << endl;
				}
				
				
				}
				cout << " CANTIDAD TOTAL DE AUTOS SIN VENDER " <<autos_sinvender <<endl;
				
				file.close();

			}
			catch (const exception& e) {
			cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
		}

	}

void vendido(string filename){
		try {
			ifstream file(filename);
			string line;
			string id, marca, modelo, año, vendedor, comprador, vendido, comprado;
			bool existe = false;
			int autos_vendidos = 0;
			getline(file, line);
			while (getline(file, line)) {
				stringstream ss(line);
				
				getline(ss, id, ';');
				int current_id = stoi(id);
				getline(ss, marca, ';');
				getline(ss, modelo, ';');
				getline(ss, año, ';');
				int current_año = stoi(año);
				getline(ss, vendedor, ';');
				int current_vendedor = stoi(vendedor);
				getline(ss, comprador, ';');
				int current_comprador = stoi(comprador);
				getline(ss, vendido, ';');
				int current_vendido = stoi(vendido);
				getline(ss, comprado, ';');
				int current_comprado = stoi(comprado);

				if (current_vendido != 0) {
				autos_vendidos++;
				cout << " \n ______________________________________________________ \n" << endl;
				cout << " ID____________________ " << current_id << endl;
				cout << " MARCA / MODELO________ " << marca << " " << modelo << endl;
				cout << " AÑO___________________ " << año << endl;
				cout << " VENDENDOR_____________ " << current_vendedor << endl;
				cout << " COMPRADOR_____________ " << current_comprador << endl;
				cout << " VENDIDO EN____________ " << current_vendido << endl;
				cout << " COMPRADO POR__________ " << current_comprado << endl;
				int Dif= current_vendido-current_comprado;
				if (vendido < comprado){
					cout << " PERDIDA: " << Dif << endl;
				}
				else{
					cout << " GANANCIA: " << Dif << endl;
				}
				
				cout << " ______________________________________________________ \n" << endl;
				}
				
				}
				cout << " CANTIDAD TOTAL DE AUTOS VENDIDOS " <<autos_vendidos <<endl;
				
				file.close();

			}
			catch (const exception& e) {
			cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
		}

	}

};

class EstadisticaView{
 public:
void compraventa_x_cliente(string filename_Cliente, string filename_Auto){

  try {
   ifstream file_cliente(filename_Cliente);
   string line1, line2, line3;
   string id, nombre, apellido, correo, edad, id_client; 
   string id1, marca, modelo, año, vendedor, comprador, vendido, comprado;
   int Autos_comprados = 0, Autos_vendidos = 0;
   bool existe = false;
   getline(file_cliente, line1);
   cout << " Ingrese el ID del cliente: "; cin >>id_client;
   while (getline(file_cliente, line1)) {
    stringstream ss(line1);

   getline(ss, id, ';');
    int current_id = stoi(id);
    getline(ss, nombre, ';');
    getline(ss, apellido, ';');
    getline(ss, correo, ';');
    getline(ss, edad, ';');
    int current_edad = stoi(edad);

    if (id_client.compare(id) == 0) {
    existe = true;
    cout << " \n __________________________________________________ \n" << endl;
    cout << " ID____________________ " << current_id << endl;
    cout << " NOMBRES / APELLIDOS___ " << nombre << " " << apellido << endl;
    cout << " CORREO________________ " << correo << endl;
    cout << " EDAD__________________ " << current_edad << endl;
    cout << " __________________________________________________ \n" << endl;
      
            ifstream file_auto1(filename_Auto);
   getline(file_auto1, line2);
   cout << "LISTADO DE AUTOS COMPRADOS " <<endl;
   while (getline(file_auto1, line2)) {
    stringstream ss(line2);
    
    getline(ss, id1, ';');
    int current_id = stoi(id1);
    getline(ss, marca, ';');
    getline(ss, modelo, ';');
    getline(ss, año, ';');
    int current_año = stoi(año);
    getline(ss, vendedor, ';');
    int current_vendedor = stoi(vendedor);
    getline(ss, comprador, ';');
    int current_comprador = stoi(comprador);
    getline(ss, vendido, ';');
    int current_vendido = stoi(vendido);
    getline(ss, comprado, ';');
    int current_comprado = stoi(comprado);

    if (id_client.compare(comprador) == 0) {
    Autos_vendidos++;
    cout << " \n __________________________________________________ \n" << endl;
    cout << " ID____________________ " << current_id << endl;
    cout << " MARCA / MODELO________ " << marca << " " << modelo << endl;
    cout << " AÑO___________________ " << año << endl;
    cout << " VENDENDOR_____________ " << current_vendedor << endl;
    cout << " COMPRADOR_____________ " << current_comprador << endl;
    cout << " VENDIDO EN____________ " << current_vendido << endl;
    cout << " COMPRADO POR__________ " << current_comprado << endl;
    int Dif= current_vendido-current_comprado;
    if (vendido < comprado){
     cout << " PERDIDA: " << Dif << endl;
    }
    else{
     cout << " GANANCIA: " << Dif << endl;
    }
    
    cout << " __________________________________________________ \n" << endl;
}
    
   }
   file_auto1.close();

   ifstream file_auto2(filename_Auto);
   getline(file_auto2, line3);
   cout << "LISTADO DE AUTOS VENDIDOS " <<endl;
   while (getline(file_auto2, line3)) {
    stringstream ss(line3);
    
    getline(ss, id, ';');
    int current_id = stoi(id);
    getline(ss, marca, ';');
    getline(ss, modelo, ';');
    getline(ss, año, ';');
    int current_año = stoi(año);
    getline(ss, vendedor, ';');
    int current_vendedor = stoi(vendedor);
    getline(ss, comprador, ';');
    int current_comprador = stoi(comprador);
    getline(ss, vendido, ';');
    int current_vendido = stoi(vendido);
    getline(ss, comprado, ';');
    int current_comprado = stoi(comprado);

    if (id_client.compare(vendedor) == 0) {
    Autos_comprados++;
    cout << " \n __________________________________________________ \n" << endl;
    cout << " ID____________________ " << current_id << endl;
    cout << " MARCA / MODELO________ " << marca << " " << modelo << endl;
    cout << " AÑO___________________ " << año << endl;
    cout << " VENDENDOR_____________ " << current_vendedor << endl;
    cout << " COMPRADOR_____________ " << current_comprador << endl;
    cout << " VENDIDO EN____________ " << current_vendido << endl;
    cout << " COMPRADO POR__________ " << current_comprado << endl;
    int Dif= current_vendido-current_comprado;
    if (vendido < comprado){
     cout << " PERDIDA: " << Dif << endl;
    }
    else{
     cout << " GANANCIA: " << Dif << endl;
    }
    
    cout << " __________________________________________________ \n" << endl;
}
    
   }
   file_auto2.close();
    }
    
   }
   file_cliente.close();

   cout << "AUTOS COMPRADOS AL CLIENTE " << Autos_comprados <<endl;
   cout << "AUTOS VENDIDOS AL CLIENTE " << Autos_vendidos <<endl;

  }
  catch (const exception& e) {
   cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
  }

 }

void cliente_vendedor_Xauto(string filename_Cliente, string filename_Auto){
 try {
   ifstream file_auto(filename_Auto);
   string line1, line2, line3;
   string id, nombre, apellido, correo, edad; 
   string id1, marca, modelo, año, vendedor, comprador, vendido, comprado;
   string id_auto;
   bool existe = false;
   cout << " Ingrese el ID del auto a buscar "; cin >> id_auto;
   getline(file_auto, line1);
   while (getline(file_auto, line1)) {
    stringstream ss(line1);
    
    getline(ss, id1, ';');
    int current_id = stoi(id1);
    getline(ss, marca, ';');
    getline(ss, modelo, ';');
    getline(ss, año, ';');
    int current_año = stoi(año);
    getline(ss, vendedor, ';');
    int current_vendedor = stoi(vendedor);
    getline(ss, comprador, ';');
    int current_comprador = stoi(comprador);
    getline(ss, vendido, ';');
    int current_vendido = stoi(vendido);
    getline(ss, comprado, ';');
    int current_comprado = stoi(comprado);

    if (id_auto.compare(id1) == 0) {
    existe = true;
    cout << " \n __________________________________________________ \n" << endl;
    cout << " ID____________________ " << current_id << endl;
    cout << " MARCA / MODELO________ " << marca << " " << modelo << endl;
    cout << " AÑO___________________ " << año << endl;
    cout << " VENDENDOR_____________ " << current_vendedor << endl;
    cout << " COMPRADOR_____________ " << current_comprador << endl;
    cout << " VENDIDO EN____________ " << current_vendido << endl;
    cout << " COMPRADO POR__________ " << current_comprado << endl;
    int Dif= current_vendido-current_comprado;
    if (vendido < comprado){
     cout << " PERDIDA: " << Dif << endl;
    }
    else{
     cout << " GANANCIA: " << Dif << endl;
    }
    
    cout << " __________________________________________________ \n" << endl;

            ifstream file_cliente(filename_Cliente);
   getline(file_cliente, line2);
   cout << " VENDEDOR DEL AUTO " <<endl;
   while (getline(file_cliente, line2)) {
    stringstream ss(line2);
   getline(ss, id, ';');
   int current_id = stoi(id);
    getline(ss, nombre, ';');
    getline(ss, apellido, ';');
    getline(ss, correo, ';');
    getline(ss, edad, ';');
    int current_edad = stoi(edad);

    if (vendedor.compare(id) == 0) {
    cout << " \n __________________________________________________ \n" << endl;
    cout << " ID____________________ " << current_id << endl;
    cout << " NOMBRES / APELLIDOS___ " << nombre << " " << apellido << endl;
    cout << " CORREO________________ " << correo << endl;
    cout << " EDAD__________________ " << current_edad << endl;
    cout << " __________________________________________________ \n" << endl;
    
   }
   }
   file_cliente.close();

   ifstream file_cliente1(filename_Cliente);
   getline(file_cliente1, line3);
   cout << " COMPRADOR DEL AUTO " <<endl;
   while (getline(file_cliente1, line3)) {
    stringstream ss(line3);

   getline(ss, id, ';');
   int current_id = stoi(id);
    getline(ss, nombre, ';');
    getline(ss, apellido, ';');
    getline(ss, correo, ';');
    getline(ss, edad, ';');
    int current_edad = stoi(edad);

    if (comprador.compare(id) == 0) {
    cout << " \n __________________________________________________ \n" << endl;
    cout << " ID____________________ " << current_id << endl;
    cout << " NOMBRES / APELLIDOS___ " << nombre << " " << apellido << endl;
    cout << " CORREO________________ " << correo << endl;
    cout << " EDAD__________________ " << current_edad << endl;
    cout << " __________________________________________________ \n" << endl;
    
   }
   }
   file_cliente1.close();

    }
    
   }
   file_auto.close();


  }
  catch (const exception& e) {
   cout << " Error al mostrar los registros del archivo CSV: " << e.what() << endl;
  }

}

};