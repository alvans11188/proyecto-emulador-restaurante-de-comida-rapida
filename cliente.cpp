#include <iostream>
#include "menus.h"
#include "funcionescliente.h"
using namespace std;

//FUNCION DEL MENU CLIENTE
void menuCliente() {
	int opcion;
	const int cantidadClientes = 20;
	int cantidadActualClientes = 9; //SON 10 PERO AL SER UN ARREGLO EMPIEZA POR "0"
	
	
	
	//DO WHILE QUE REPITE EL MENU HASTA QUE SE SELECCIONE LA OPCION 6
	do {
		cout << "// MENÚ: CLIENTE //" << endl;
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
				editarDatosCliente(clientes, cantidadActualClientes);
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
