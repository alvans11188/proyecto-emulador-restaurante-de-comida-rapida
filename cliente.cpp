#include <iostream>
#include "cliente.h"
using namespace std;

//REGISTRO DE DIRECCION
struct Direccion {
	string distrito;
	string calle;
	string manzana;
	string lote;
};

//REGISTRO DE CLIENTE
struct Cliente {
	string nombre;
	string telefono;
	Direccion direccionCliente;
};

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

//FUNCION DEL MENU CLIENTE
void menuCliente() {
	int opcion;
	const int cantidadClientes = 20;
	int cantidadActualClientes = 9; //SON 10 PERO AL SER UN ARREGLO EMPIEZA POR "0"
	
	//SE AGREGAN 10 CLIENTES PREDEFINIDOS
	Cliente clientes[cantidadClientes] = {
		{"Carlos Flores", "827364958", {"Miraflores", "Av. Pardo", "Mz. B", "Lt. 12"}}, //POSICION 0
		{"Juan Perez", "817361123", {"San Isidro", "Calle Las Flores", "Mz. F", "Lt. 8"}}, //POSICION 1
		{"Maria Lopez", "917345991", {"Barranco", "Av. Grau", "Mz. C", "Lt. 5"}}, //POSICION 2
		{"Carlos Gomez", "611230194", {"Surco", "Calle Los Alamos", "Mz. D", "Lt. 3"}}, //POSICION 3
		{"Laura Fernandez", "471623090", {"La Molina", "Av. La Universidad", "Mz. A", "Lt. 1"}}, //POSICION 4
		{"Luis Martinez", "918453124", {"San Borja", "Calle Los Laureles", "Mz. J", "Lt. 9"}}, //POSICION 5
		{"Sofia Torres", "019434198", {"Vitacura", "Av. Bolivar", "Mz. E", "Lt. 6"}}, //POSICION 6
		{"Pedro Meza", "981450001", {"Magdalena", "Calle San Martin", "Mz. H", "Lt. 2"}}, //POSICION 7
		{"Elena Mamani", "934217501", {"Polanco", "Av. Arequipa", "Mz. G", "Lt. 7"}}, //POSICION 8
		{"Jorge Morales", "091245762", {"Palermo", "Calle Salaverry", "Mz. L", "Lt. 3"}} //POSICION 9
	};
	
	//DO WHILE QUE REPITE EL MENU HASTA QUE SE SELECCIONE LA OPCION 6
	do {
		cout << "// MENU: CLIENTE //" << endl;
		cout << "1. Agregar cliente" << endl;
		cout << "2. Editar datos del cliente" << endl;
		cout << "3. Ordenar clientes alfabeticamente" << endl;
		cout << "4. Mostrar clientes registrados" << endl;
		cout << "5. Eliminar clientes" << endl;
		cout << "6. Volver al menu principal" << endl;
		cin >> opcion;
		
		//SWITCH PARA LAS DISTINTAS FUNCIONES DEL MENU CLIENTE
		switch ( opcion ) {
			case 1:
				agregarCliente(clientes, cantidadActualClientes);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				break;
		}
	} while ( opcion != 6 );
}