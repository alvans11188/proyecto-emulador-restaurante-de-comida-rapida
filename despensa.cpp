#include <iostream>
using namespace std;

void menuDespensa(){
	
	char opcion;
	do{
		cout << endl << endl;
		cout << "INGRESANDO A LA DESPENSA..."; cout << endl << endl;
		cout << "A) Ingresar productos a la despensa" << endl;
		cout << "B) Editar productos de la despensa" << endl;
		cout << "C) Mostrar productos alfabeticamente" << endl;
		cout << "D) Mostrar stock de productos" << endl;
		cout << "E) Mostrar productos mas vendidos" << endl;
		cout << "F) Salir de la despensa" << endl << endl;
		cin >> opcion;
		
		switch(opcion){
			
			case 'A':
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
