#include <iostream>
#include "cliente.h"
#include "carta.h"
using namespace std;


int main() {
	int opcion;
	
	do {
		cout << "1. Cliente" << endl;
		cout << "2. Carta" << endl;
		cout << "3. Despuensa" << endl;
		cout << "4. Ventas" << endl;
		cout << "5. Salir del programa" << endl;
		cin >> opcion;
		
		switch (opcion){
			case 1:
				menuCliente();
				break;
			case 2:
				menuCarta();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				cout << "Valor ingresado incorrecto, vuelva a ingresar otro valor" << endl;	
		}

	} while (opcion !=5 );
		cout << "Programa finalizado" << endl;

	return 0;
}
