#include <iostream>
#include "carta.h"
using namespace std;
// Estructura de Producto
struct Producto {
    string nombre;
    float precio;
};
// PRODUNTOS PREDEFINIDOS
Producto hamburguesas[2] = {
    {"Pollo", 5.0},
    {"Carne", 6.0}
};
Producto pizzas[3] = {
    {"Personal", 10.0},
    {"Mediana", 15.0},
    {"Familiar", 25.0}
};
Producto conos[3] = {
    {"Pollo", 5.0},
    {"Alchicha", 6.0},
    {"Mixto", 7.0}
};
Producto gaseosas[2] = {
    {"Cocacola", 3.0},
    {"Incacola", 3.0}
};
Producto aguas[2] = {
    {"Agua sin gas", 1.0},
    {"Agua con gas", 1.50}
};
// FUNCION MOSTRAR CARTA
void mostrarCarta() {
    cout << "\n CARTA DE HOY" << endl;

    cout << "Hamburguesas:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "   " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
    }
    cout << "\nPizzas:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "   " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
    }
    cout << "\nConos:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "   " << conos[i].nombre << " S/. " << conos[i].precio << endl;
    }
    cout << "\nBebidas:" << endl;
    cout << "   Gaseosas" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "      " << gaseosas[i].nombre << " S/. " << gaseosas[i].precio << endl;
    }
    cout << "   Aguas" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "      " << aguas[i].nombre << " S/. " << aguas[i].precio << endl;
    }
}
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
            	mostrarCarta();
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
