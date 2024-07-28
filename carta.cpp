
#include "menus.h"
#include "funcionescarta.h"
#include <iostream>
using namespace std;

//FUNCION MENU CARTA
void menuCarta() {
	
    char opcion;
    do {
    	cout << "\n // MENU CARTA // " << endl;
        cout << "A) Mostrar carta" << endl;
        cout << "B) Editar carta" << endl;
        cout << "C) Agregar comida a la carta" << endl;
        cout << "D) Ordenar carta segun el precio" << endl;
        cout << "E) Eliminar producto" << endl;
        cout << "F) Salir del area de carta" << endl;
        cin >> opcion;
        // SWITCH PARA SELECIONAR LAS DIFERENTES OPCIONES DEL MENU CARTA
        switch (opcion) {
            case 'A':
            	mostrarCarta();
                break;
            case 'B':
                editarCarta();
                break;
            case 'C':
            	agregarCarta();
                break;
            case 'D':
                ordenarCarta();
                break;
            case 'E':
                eliminarCarta();
                break;
            case 'F':
                cout << "Regresando al menu principal" << endl;
                break;
            default:
                cout << "Opcion no valida, intente de nuevo" << endl;
                break;
        }
        
    } while (opcion != 'F'); //EN CASO SELECCIONAR EL NUMERO 6 REGRESA AL MENU ANTERIOR
}
