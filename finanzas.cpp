#include <iostream>
#include "menus.h"
#include "funcionesfinanzas.h"
using namespace std;

void menuFinanzas(){
	char opcion;
	cout << "INGRESANDO AL AREA DE FINANZAS..." << endl;
	do{
		cout << endl;
		cout << "Elija que accion va a realizar." << endl << endl;
		cout << "A) Registrar una orden." << endl;
		cout << "B) Mostrar facturas de ordenes registradas." << endl;
		cout << "C) Gastos y ganancias." << endl;
		cout << "D) Ordenar por lo mas o menos vendido." << endl;
		cout << "E) Estadisticas generales." << endl;
		cout << "F) Salir del area de finanzas." << endl << endl;
		cout << "= ";
		cin >> opcion;
		cout << endl;
		switch(opcion){
			case 'A':
				registrarVenta();
				break;
			case 'B':
				mostrarOrdenes();
				break;
			case 'C':
				gastosGanancias();
				break;
			case 'D':
				ordenarMasVendido();
				break;
			case 'E':
				estadisticasGenerales();
				break;
			default:
				cout << "Opcion no valida. Intente de nuevo." << endl;
				break;
		}
		cout << endl;
	}while(opcion!='F');
}
