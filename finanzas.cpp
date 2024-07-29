#include <iostream>
#include "menus.h"
#include "funcionesfinanzas.h"
#include "FUNCIONESDISENO.h"
using namespace std;

void menuFinanzas(){
	char opcion;
	char c;
	c='*';
	separador(c);
	cout << "\t\t\t\t\t\t\t\t\t\tINGRESANDO AL AREA DE FINANZAS..." << endl;
	separador(c);
	do{
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t\tElija que accion va a realizar." << endl << endl;
		cout << "\t\t\t\t\t\t\t\tA) Registrar una orden." << endl;
		cout << "\t\t\t\t\t\t\t\tB) Mostrar facturas de ordenes registradas." << endl;
		cout << "\t\t\t\t\t\t\t\tC) Gastos y ganancias." << endl;
		cout << "\t\t\t\t\t\t\t\tD) Ordenar por lo mas o menos vendido." << endl;
		cout << "\t\t\t\t\t\t\t\tE) Estadisticas generales." << endl;
		cout << "\t\t\t\t\t\t\t\tF) Salir del area de finanzas." << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t= ";
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
				cout << "\t\t\t\t\t\t\t\t\t\tOpcion no valida. Intente de nuevo." << endl;
				break;
		}
		cout << endl;
	}while(opcion!='F');
}
