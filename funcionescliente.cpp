#include "funcionescliente.h"
using namespace std;

//FUNCION PARA AGREGAR CLIENTES
void agregarCliente(Cliente clientes[20], int &cantidadActualClientes) {
	cantidadActualClientes++;
	cout << "// AGREGAR CLIENTE //" << endl;
	cout << "Nombre del cliente: ";
	cin.ignore(); //LIMPIAR EL BUFFER POR EL SALTO DE LINEA
	getline(cin, clientes[cantidadActualClientes].nombre);
	cout << "Numero del cliente: ";
	cin >> clientes[cantidadActualClientes].telefono;
	
	cout << "// Direccion del cliente // " << endl;
	cout << "Distrito: ";
	cin.ignore(); //LIMPIAR EL BUFFER POR EL SALTO DE LINEA
	getline(cin, clientes[cantidadActualClientes].direccionCliente.distrito);
	cout << "Calle: ";
	getline(cin, clientes[cantidadActualClientes].direccionCliente.calle);
	cout << "Manzana: ";
	getline(cin, clientes[cantidadActualClientes].direccionCliente.manzana);
	cout << "Lote: ";
	getline(cin, clientes[cantidadActualClientes].direccionCliente.lote);
	cout << "// USUARIO AGREGADO CORRECTAMENTE //" << endl;
}

//FUNCION PARA EDITAR DATOS DEL CLIENTES
void editarDatosCliente(Cliente clientes[20], int &cantidadActualClientes) {
	int clienteEditar; //POSICION DE MEMORIA QUE LUEGO SERA EL CLIENTE QUE SE VA A EDITAR
	cout << "// EDITAR CLIENTE //" << endl;
	
	do { //DO WHILE PARA REPETIR EN TAL CASO EL USUARIO INGRESE NUMEROS QUE NO ESTEN ENTRE 1 Y 20
		cout << "Ingrese la posicion del usuario que desea editar (1 - " << cantidadActualClientes + 1 << "): ";
		cin >> clienteEditar;
		if ( clienteEditar >= 1 && clienteEditar <= cantidadActualClientes + 1 ) {
			cout << "// POSICION VALIDA //" << endl;
		} else {
			cout << "// ERROR: VALOR INCORRECTO //" << endl;
		}
	} while ( clienteEditar < 1 || clienteEditar > cantidadActualClientes + 1);
	
	clienteEditar--; //SE REDUCE EN 1 PARA QUE SEA LA POSICION CORRECTA, YA QUE SE CUENTA LA POSICION 0
	
	cout << "// DATOS DEL CLIENTE A EDITAR //" << endl;
	cout << "Nombre del cliente: ";
	cin.ignore(); //LIMPIAR EL BUFFER POR EL SALTO DE LINEA
	getline(cin, clientes[clienteEditar].nombre);
	cout << "Numero del cliente: ";
	cin >> clientes[clienteEditar].telefono;
	
	cout << "// Direccion del cliente // " << endl;
	cout << "Distrito: ";
	cin.ignore(); //LIMPIAR EL BUFFER POR EL SALTO DE LINEA
	getline(cin, clientes[clienteEditar].direccionCliente.distrito);
	cout << "Calle: ";
	getline(cin, clientes[clienteEditar].direccionCliente.calle);
	cout << "Manzana: ";
	getline(cin, clientes[clienteEditar].direccionCliente.manzana);
	cout << "Lote: ";
	getline(cin, clientes[clienteEditar].direccionCliente.lote);
	cout << "// USUARIO AGREGADO CORRECTAMENTE //" << endl;
}
