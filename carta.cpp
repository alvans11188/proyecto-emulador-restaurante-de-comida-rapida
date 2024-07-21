#include <iostream>
#include "carta.h"
using namespace std;

//FUNCION MENU CARTA
void menuCarta() {
    int opcion;
    do {
    	cout << "\n" << endl;
        cout << "1. Mostrar carta" << endl;
        cout << "2. Editar carta" << endl;
        cout << "3. Agregar comida a la carta" << endl;
        cout << "4. Ordenar carta según el precio" << endl;
        cout << "5. Eliminar producto" << endl;
        cout << "6. Volver al menú principal" << endl;
        cin >> opcion;
        // SWITCH PARA SELECIONAR LAS DIFERENTES OPCIONES DEL MENU CARTA
        switch (opcion) {
            case 1:
                break;
            case 2:
                
                break;
            case 3:
               
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                cout << "Regresando al menu inicial" << endl;
                break;
            default:
                cout << "Valor ingresado incorrecto, vuelva a ingresar otro valor" << endl;
                break;
        }
        
    } while (opcion != 6); //EN CASO SELECCIONAR EL NUMERO 6 REGRESA AL MENU ANTERIOR
}
