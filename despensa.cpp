#include <iostream>
#include "menus.h"
#include "funcionesdespensa.h"
using namespace std;

void menuDespensa(){
	
	char opcion;
	cout << "INGRESANDO A LA DESPENSA..." << endl;
	do{
		cout << endl;
		cout << "A) Agregar alimentos a la despensa" << endl;
		cout << "B) Actualizar alimentos de la despensa" << endl;
		cout << "C) Mostrar stock de alimentos" << endl;
		cout << "D) Mostrar alimentos mas usados" << endl;
		cout << "E) Salir de la despensa" << endl << endl;
		cin >> opcion;
		cout << endl << endl;
		switch(opcion){
			
			case 'A':
				AgregarAlimentos();
				break;
			case 'B':
				actualizarAlimentos();
				break;
			case 'C':
				mostrarStock();
				break;
			case 'D':
				break;
			case 'E':
				cout << "Saliendo de la despensa..." << endl;
				break;
			default:
				cout << "Valor ingresado incorrecto, vuelva a ingresar otro valor" << endl;
				break;
		}
	} while(opcion!='E');
} 
