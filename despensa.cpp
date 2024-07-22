#include <iostream>
#include "funcionesdespensa.h"
#include "despensa.h"
using namespace std;

void menuDespensa(){
	
	char opcion;
	do{
		cout << endl << endl;
		cout << "INGRESANDO A LA DESPENSA..."; cout << endl << endl;
		cout << "A) Ingresar alimentos a la despensa" << endl;
		cout << "B) Actualizar alimentos de la despensa" << endl;
		cout << "C) Mostrar alimentos alfabeticamente" << endl;
		cout << "D) Mostrar stock de alimentos" << endl;
		cout << "E) Mostrar alimentos mas usados" << endl;
		cout << "F) Salir de la despensa" << endl << endl;
		cin >> opcion;
		
		switch(opcion){
			
			case 'A':
				ingresarAlimentos();
				break;
			case 'B':
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
