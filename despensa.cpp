#include <iostream>
#include "menus.h"
#include "funcionesdespensa.h"
#include "FUNCIONESDISENO.H"
using namespace std;

void menuDespensa(){
	
	char opcion;
	char c;
	separador(c);
	cout << "\t\t\t\t\t\t\t\t\t\tINGRESANDO A LA DESPENSA..." << endl;
	separador(c); cout << endl << endl << endl;
	do{
		cout << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\tA) Agregar alimentos a la despensa" << endl;
		cout << "\t\t\t\t\t\t\t\tB) Actualizar alimentos de la despensa" << endl;
		cout << "\t\t\t\t\t\t\t\tC) Mostrar stock de alimentos" << endl;
		cout << "\t\t\t\t\t\t\t\tD) Mostrar alimentos mas y menos usados" << endl;
		cout << "\t\t\t\t\t\t\t\tE) Salir de la despensa" << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t" << endl << endl;
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
				mostrarMasMenosUsados();
				break;
			case 'E':
				cout << "\t\t\t\t\t\t\t\t\t\t\tSaliendo de la despensa..." << endl;
				break;
			default:
				cout << "\t\t\t\t\t\t\t\t\t\tValor ingresado incorrecto, vuelva a ingresar otro valor" << endl;
				break;
		}
	} while(opcion!='E');
} 
