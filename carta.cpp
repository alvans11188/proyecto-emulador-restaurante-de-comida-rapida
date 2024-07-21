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
//FUNCION PARA EDITAR CARTA
void editarCarta() {
    int categoria, item;
    cout << "\n// EDITAR CARTA //" << endl;
    cout << "Seleccione la categoría para editar:" << endl;
    cout << "1. Hamburguesas" << endl;
    cout << "2. Pizzas" << endl;
    cout << "3. Conos" << endl;
    cout << "4. Gaseosas" << endl;
    cout << "5. Aguas" << endl;
    cin >> categoria;

    switch (categoria) {
        case 1:
            cout << "Seleccione el producto a editar:" << endl;
            for (int i = 0; i < 2; i++) {
                cout << i + 1 << ". " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < 2) {
                cout << "Nuevo nombre: ";
                cin >> hamburguesas[item].nombre;
                cout << "Nuevo precio: ";
                cin >> hamburguesas[item].precio;
                cout << "Producto editado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 2:
            cout << "Seleccione el producto a editar:" << endl;
            for (int i = 0; i < 3; i++) {
                cout << i + 1 << ". " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < 3) {
                cout << "Nuevo nombre: ";
                cin >> pizzas[item].nombre;
                cout << "Nuevo precio: ";
                cin >> pizzas[item].precio;
                cout << "Producto editado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 3:
            cout << "Seleccione el producto a editar:" << endl;
            for (int i = 0; i < 3; i++) {
                cout << i + 1 << ". " << conos[i].nombre << " S/. " << conos[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < 3) {
                cout << "Nuevo nombre: ";
                cin >> conos[item].nombre;
                cout << "Nuevo precio: ";
                cin >> conos[item].precio;
                cout << "Producto editado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 4:
            cout << "Seleccione el producto a editar:" << endl;
            for (int i = 0; i < 2; i++) {
                cout << i + 1 << ". " << gaseosas[i].nombre << " S/. " << gaseosas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < 2) {
                cout << "Nuevo nombre: ";
                cin >> gaseosas[item].nombre;
                cout << "Nuevo precio: ";
                cin >> gaseosas[item].precio;
                cout << "Producto editado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 5:
            cout << "Seleccione el producto a editar:" << endl;
            for (int i = 0; i < 2; i++) {
                cout << i + 1 << ". " << aguas[i].nombre << " S/. " << aguas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < 2) {
                cout << "Nuevo nombre: ";
                cin >> aguas[item].nombre;
                cout << "Nuevo precio: ";
                cin >> aguas[item].precio;
                cout << "Producto editado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        default:
            cout << "Categoría no encontrada." << endl;
            break;
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
                editarCarta();
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
