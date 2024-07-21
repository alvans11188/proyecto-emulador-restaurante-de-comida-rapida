#include <iostream>
#include "cliente.h"
using namespace std;

void menuCliente() {
	int opcion;
	do {
		cout << "1. Agregar cliente" << endl;
		cout << "2. Editar datos del cliente" << endl;
		cout << "3. Ordenar clientes alfabeticamente" << endl;
		cout << "4. Mostrar clientes registrados" << endl;
		cout << "5. Eliminar clientes" << endl;
		cout << "6. Volver al menu principal" << endl;
		cin >> opcion;
		
		switch ( opcion ) {
			case 1:
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
