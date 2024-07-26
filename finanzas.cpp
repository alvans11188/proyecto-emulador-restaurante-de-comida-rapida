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
		cout << "B) Mostrar ordenes registradas." << endl;
		cout << "C) Gastos y ganancias." << endl;
		cout << "D) Ordenar por lo mas o menos vendido." << endl;
		cout << "E) Estadisticas generales." << endl;
		cout << "F) Salir del area de finanzas." << endl << endl;
		cout << "= ";
		cin >> opcion;
		
		switch(opcion){
			case 'A':
				registrarVenta();
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			case 'E':
				break;
			default:
				break;
		}
		cout << endl;
	}while(opcion!='F');
}
