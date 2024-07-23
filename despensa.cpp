#include <iostream>
#include "funcionesdespensa.h"
#include "despensa.h"
using namespace std;

void menuDespensa(){
	
	char opcion;
	cout << "INGRESANDO A LA DESPENSA..." << endl << endl;
	do{
		cout << "A) Agregar alimentos a la despensa" << endl;
		cout << "B) Actualizar alimentos de la despensa" << endl;
		cout << "C) Mostrar alimentos alfabeticamente" << endl;
		cout << "D) Mostrar stock de alimentos" << endl;
		cout << "E) Mostrar alimentos mas usados" << endl;
		cout << "F) Salir de la despensa" << endl << endl;
		cin >> opcion;
		
		switch(opcion){
			
			case 'A':
				AgregarAlimentos();
				break;
			case 'B':
				actualizarAlimentos();
				break;
			case 'C':
				break;
			case 'D':
				break;
			case 'E':
				break;
			case 'F':
				break;
			default:
				break;
		}
	} while(opcion!='F');
} 
