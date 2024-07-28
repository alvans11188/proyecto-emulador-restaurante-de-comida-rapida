#include "funcionescarta.h"
#include <iostream>
using namespace std;

Producto hamburguesas[MAX_ITEMS] = {
    {"Hamburguesa de pollo", 5.0},
    {"Hamburguesa de carne", 6.0}
};

Producto pizzas[MAX_ITEMS] = {
    {"Pizza personal", 10.0},
    {"Pizza mediana", 15.0},
    {"Pizza familiar", 25.0}
};

Producto conos[MAX_ITEMS] = {
    {"Cono de pollo", 5.0},
    {"Cono de salchicha", 6.0},
    {"Cono mixto", 7.0}
};

Producto gaseosas[MAX_ITEMS] = {
    {"Coca-Cola", 3.0},
    {"Inca-Kola", 3.0}
};

Producto aguas[MAX_ITEMS] = {
    {"Agua sin gas", 1.0},
    {"Agua con gas", 1.5}
};

int numHamburguesas = 2;
int numPizzas = 3;
int numConos = 3;
int numGaseosas = 2;
int numAguas = 2;

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
    cout << "Seleccione la categor�a para editar:" << endl;
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
                cin.ignore(); // Ignorar el car�cter de nueva l�nea residual
                cout << "Nuevo nombre: ";
                getline(cin, hamburguesas[item].nombre);
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
                cin.ignore();
                cout << "Nuevo nombre: ";
                getline(cin, pizzas[item].nombre);
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
                cin.ignore();
                cout << "Nuevo nombre: ";
                getline(cin, conos[item].nombre);
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
                cin.ignore();
                cout << "Nuevo nombre: ";
                getline(cin, gaseosas[item].nombre);
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
                cin.ignore();
                cout << "Nuevo nombre: ";
                getline(cin, aguas[item].nombre);
                cout << "Nuevo precio: ";
                cin >> aguas[item].precio;
                cout << "Producto editado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        default:
            cout << "Categor�a no encontrada." << endl;
            break;
    }
}
//FUNCION PARA AGREGAR A LA CARTA
void agregarCarta() {
    int categoria;
    Producto nuevoProducto;
    cout << "\n// AGREGAR PRODUCTO A LA CARTA //" << endl;
    cout << "Seleccione la categor�a para agregar un nuevo producto:" << endl;
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
                cout << "No se puede agregar m�s hamburguesas." << endl;
            }
            break;
        case 2:
            if (numPizzas < MAX_ITEMS) {
                pizzas[numPizzas] = nuevoProducto;
                numPizzas++;
            } else {
                cout << "No se puede agregar m�s pizzas." << endl;
            }
            break;
        case 3:
            if (numConos < MAX_ITEMS) {
                conos[numConos] = nuevoProducto;
                numConos++;
            } else {
                cout << "No se puede agregar m�s conos." << endl;
            }
            break;
        case 4:
            if (numGaseosas < MAX_ITEMS) {
                gaseosas[numGaseosas] = nuevoProducto;
                numGaseosas++;
            } else {
                cout << "No se puede agregar m�s gaseosas." << endl;
            }
            break;
        case 5:
            if (numAguas < MAX_ITEMS) {
                aguas[numAguas] = nuevoProducto;
                numAguas++;
            } else {
                cout << "No se puede agregar m�s aguas." << endl;
            }
            break;
        default:
            cout << "Categor�a no encontrada." << endl;
            break;
    }
}
//FUNCION ORDENAR CARTA
void ordenarCarta() {
   int categoria;
    cout << "\n// ORDENAR CARTA //" << endl;
    cout << "Seleccione la categor�a para ordenar por precio decendente:" << endl;
    cout << "1. Hamburguesas" << endl;
    cout << "2. Pizzas" << endl;
    cout << "3. Conos" << endl;
    cout << "4. Gaseosas" << endl;
    cout << "5. Aguas" << endl;
    cin >> categoria;

    switch (categoria) {
        case 1:
            for (int i = 0; i < numHamburguesas - 1; i++) {
                for (int j = 0; j < numHamburguesas - i - 1; j++) {
                    if (hamburguesas[j].precio > hamburguesas[j + 1].precio) {
                        swap(hamburguesas[j], hamburguesas[j + 1]);
                    }
                }
            }
            cout << "Hamburguesas ordenadas satisfactoriamente" << endl;
            break;
        case 2:
            for (int i = 0; i < numPizzas - 1; i++) {
                for (int j = 0; j < numPizzas - i - 1; j++) {
                    if (pizzas[j].precio > pizzas[j + 1].precio) {
                        swap(pizzas[j], pizzas[j + 1]);
                    }
                }
            }
            cout << "Pizzas ordenadas satisfactoriamente" << endl;
            break;
        case 3:
            for (int i = 0; i < numConos - 1; i++) {
                for (int j = 0; j < numConos - i - 1; j++) {
                    if (conos[j].precio > conos[j + 1].precio) {
                        swap(conos[j], conos[j + 1]);
                    }
                }
            }
            cout << "Conos ordenados satisfactoriamente" << endl;
            break;
        case 4:
            for (int i = 0; i < numGaseosas - 1; i++) {
                for (int j = 0; j < numGaseosas - i - 1; j++) {
                    if (gaseosas[j].precio > gaseosas[j + 1].precio) {
                        swap(gaseosas[j], gaseosas[j + 1]);
                    }
                }
            }
            cout << "Gaseosas ordenadas satisfactoriamente" << endl;
            break;
        case 5:
            for (int i = 0; i < numAguas - 1; i++) {
                for (int j = 0; j < numAguas - i - 1; j++) {
                    if (aguas[j].precio > aguas[j + 1].precio) {
                        swap(aguas[j], aguas[j + 1]);
                    }
                }
            }
            cout << "Aguas ordenadas satisfactoriamente" << endl;
            break;
        default:
            cout << "Categor�a no encontrada." << endl;
            break;
    }
}
//FUNCION PARA ELIMINAR PRODUCTOS DE LA CARTA
void eliminarCarta() {
    int categoria, item;
    cout << "\n// ELIMINAR PRODUCTO //" << endl;
    cout << "Seleccione la categor�a del producto a eliminar:" << endl;
    cout << "1. Hamburguesas" << endl;
    cout << "2. Pizzas" << endl;
    cout << "3. Conos" << endl;
    cout << "4. Gaseosas" << endl;
    cout << "5. Aguas" << endl;
    cin >> categoria;

    switch (categoria) {
        case 1:
            cout << "Seleccione el producto a eliminar:" << endl;
            for (int i = 0; i < numHamburguesas; i++) {
                cout << i + 1 << ". " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numHamburguesas) {
                for (int i = item; i < numHamburguesas - 1; i++) {
                    hamburguesas[i] = hamburguesas[i + 1];
                }
                numHamburguesas--;
                cout << "Producto eliminado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 2:
            cout << "Seleccione el producto a eliminar:" << endl;
            for (int i = 0; i < numPizzas; i++) {
                cout << i + 1 << ". " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numPizzas) {
                for (int i = item; i < numPizzas - 1; i++) {
                    pizzas[i] = pizzas[i + 1];
                }
                numPizzas--;
                cout << "Producto eliminado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 3:
            cout << "Seleccione el producto a eliminar:" << endl;
            for (int i = 0; i < numConos; i++) {
                cout << i + 1 << ". " << conos[i].nombre << " S/. " << conos[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numConos) {
                for (int i = item; i < numConos - 1; i++) {
                    conos[i] = conos[i + 1];
                }
                numConos--;
                cout << "Producto eliminado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 4:
            cout << "Seleccione el producto a eliminar:" << endl;
            for (int i = 0; i < numGaseosas; i++) {
                cout << i + 1 << ". " << gaseosas[i].nombre << " S/. " << gaseosas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numGaseosas) {
                for (int i = item; i < numGaseosas - 1; i++) {
                    gaseosas[i] = gaseosas[i + 1];
                }
                numGaseosas--;
                cout << "Producto eliminado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 5:
            cout << "Seleccione el producto a eliminar:" << endl;
            for (int i = 0; i < numAguas; i++) {
                cout << i + 1 << ". " << aguas[i].nombre << " S/. " << aguas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numAguas) {
                for (int i = item; i < numAguas - 1; i++) {
                    aguas[i] = aguas[i + 1];
                }
                numAguas--;
                cout << "Producto eliminado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        default:
            cout << "Categor�a no encontrada." << endl;
            break;
    }
}
//USAR EN FUNCIONESFINANZAS.CPP

