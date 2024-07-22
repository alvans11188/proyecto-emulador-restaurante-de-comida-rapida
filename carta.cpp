#include <iostream>
#include "carta.h"
using namespace std;
//NUMERO MAXIMO DE PRODUCTOS
const int MAX_ITEMS = 100;
// Estructura de Producto
struct Producto {
    string nombre;
    float precio;
};

// CADENAS CONCETENEDORAS DE PRODUCTOS

Producto hamburguesas[MAX_ITEMS];
int numHamburguesas = 2;

Producto pizzas[MAX_ITEMS];
int numPizzas = 3;

Producto conos[MAX_ITEMS];
int numConos = 3;

Producto gaseosas[MAX_ITEMS];
int numGaseosas = 2;

Producto aguas[MAX_ITEMS];
int numAguas = 2;

// PRODUNTOS PREDEFINIDOS
void inicializarproductos() {
    hamburguesas[0] = {"Pollo", 5.0};
    hamburguesas[1] = {"Carne", 6.0};
    
    pizzas[0] = {"Personal", 10.0};
    pizzas[1] = {"Mediana", 15.0};
    pizzas[2] = {"Familiar", 25.0};
    
    conos[0] = {"Pollo", 5.0};
    conos[1] = {"Salchicha", 6.0};
    conos[2] = {"Mixto", 7.0};
    
    gaseosas[0] = {"Coca-Cola", 3.0};
    gaseosas[1] = {"Inca-Kola", 3.0};
    
    aguas[0] = {"Agua sin gas", 1.0};
    aguas[1] = {"Agua con gas", 1.5};
}


// FUNCION MOSTRAR CARTA
void mostrarCarta() {
    cout << "\nCARTA DE HOY" << endl;

    cout << "Hamburguesas:" << endl;
    for (int i = 0; i < numHamburguesas; i++) {
        cout << "   " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
    }
    cout << "\nPizzas:" << endl;
    for (int i = 0; i < numPizzas; i++) {
        cout << "   " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
    }
    cout << "\nConos:" << endl;
    for (int i = 0; i < numConos; i++) {
        cout << "   " << conos[i].nombre << " S/. " << conos[i].precio << endl;
    }
    cout << "\nBebidas:" << endl;
    cout << "   Gaseosas" << endl;
    for (int i = 0; i < numGaseosas; i++) {
        cout << "      " << gaseosas[i].nombre << " S/. " << gaseosas[i].precio << endl;
    }
    cout << "   Aguas" << endl;
    for (int i = 0; i < numAguas; i++) {
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
            for (int i = 0; i < numHamburguesas; i++) {
                cout << i + 1 << ". " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numHamburguesas) {
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
            for (int i = 0; i < numPizzas; i++) {
                cout << i + 1 << ". " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numPizzas) {
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
            for (int i = 0; i < numConos; i++) {
                cout << i + 1 << ". " << conos[i].nombre << " S/. " << conos[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numConos) {
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
            for (int i = 0; i < numGaseosas; i++) {
                cout << i + 1 << ". " << gaseosas[i].nombre << " S/. " << gaseosas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numGaseosas) {
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
            for (int i = 0; i < numAguas; i++) {
                cout << i + 1 << ". " << aguas[i].nombre << " S/. " << aguas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numAguas) {
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
void agregarCarta() {
    int categoria;
    Producto nuevoProducto;
    cout << "\n// AGREGAR PRODUCTO A LA CARTA //" << endl;
    cout << "Seleccione la categoría para agregar un nuevo producto:" << endl;
    cout << "1. Hamburguesas" << endl;
    cout << "2. Pizzas" << endl;
    cout << "3. Conos" << endl;
    cout << "4. Gaseosas" << endl;
    cout << "5. Aguas" << endl;
    cin >> categoria;

    cout << "Ingrese el nombre del nuevo producto: ";
    cin.ignore();
    getline(cin, nuevoProducto.nombre);
    cout << "Ingrese el precio del nuevo producto: ";
    cin >> nuevoProducto.precio;

     switch (categoria) {
        case 1:
            if (numHamburguesas < MAX_ITEMS) {
                hamburguesas[numHamburguesas] = nuevoProducto;
                numHamburguesas++;
            } else {
                cout << "No se puede agregar más hamburguesas." << endl;
            }
            break;
        case 2:
            if (numPizzas < MAX_ITEMS) {
                pizzas[numPizzas] = nuevoProducto;
                numPizzas++;
            } else {
                cout << "No se puede agregar más pizzas." << endl;
            }
            break;
        case 3:
            if (numConos < MAX_ITEMS) {
                conos[numConos] = nuevoProducto;
                numConos++;
            } else {
                cout << "No se puede agregar más conos." << endl;
            }
            break;
        case 4:
            if (numGaseosas < MAX_ITEMS) {
                gaseosas[numGaseosas] = nuevoProducto;
                numGaseosas++;
            } else {
                cout << "No se puede agregar más gaseosas." << endl;
            }
            break;
        case 5:
            if (numAguas < MAX_ITEMS) {
                aguas[numAguas] = nuevoProducto;
                numAguas++;
            } else {
                cout << "No se puede agregar más aguas." << endl;
            }
            break;
        default:
            cout << "Categoría no encontrada." << endl;
            break;
    }
}
//FUNCION MENU CARTA
void menuCarta() {
	inicializarproductos();
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
            	agregarCarta();
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
