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
    cout << "\n // CARTA DE HOY //" << endl;

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
    int  item;
	char categoria;
    do {
    	
    cout << "\n// EDITAR CARTA //" << endl;
    cout << "Seleccione la categoria para editar:" << endl;
    cout << "A. Hamburguesas" << endl;
    cout << "B. Pizzas" << endl;
    cout << "C. Conos" << endl;
    cout << "D. Gaseosas" << endl;
    cout << "E. Aguas" << endl;
    cout << "F. Volver al menu anterior" << endl;
    cin >> categoria;
    
    switch (categoria) {
        case 'A':
            cout << "Seleccione el producto a editar:" << endl;
            for (int i = 0; i < numHamburguesas; i++) {
                cout << i + 1 << ". " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
            }
            cin >> item;
            item -= 1;
            if (item >= 0 && item < numHamburguesas) {
                cin.ignore(); // Ignorar el primer valor
                cout << "Nuevo nombre: ";
                getline(cin, hamburguesas[item].nombre);
                cout << "Nuevo precio: ";
                cin >> hamburguesas[item].precio;
                cout << "Producto editado satisfactoriamente" << endl;
            } else {
                cout << "Producto no valido." << endl;
            }
            break;
        case 'B':
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
        case 'C':
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
        case 'D':
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
        case 'E':
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
        case 'F':
        	cout << "Regresando al menu anterior" << endl;
        	break;
        default:
            cout << "Categoria no encontrada." << endl;
            break;
    } 

	
    }while (categoria != 'F');
}
//FUNCION PARA AGREGAR A LA CARTA
void agregarCarta() {
    char categoria;
    Producto nuevoProducto;
    do{
    cout << "\n// AGREGAR PRODUCTO A LA CARTA //" << endl;
    cout << "Seleccione la categoria para agregar un nuevo producto:" << endl;
    cout << "A. Hamburguesas" << endl;
    cout << "B. Pizzas" << endl;
    cout << "C. Conos" << endl;
    cout << "D. Gaseosas" << endl;
    cout << "E. Aguas" << endl;
    cout << "F. Volver al menu anterior" << endl;
    cin >> categoria;

   
     switch (categoria) {
     	
        case 'A':
        	cout << "Ingrese el nombre del nuevo producto: ";
		    cin.ignore();
		    getline(cin, nuevoProducto.nombre);
		    cout << "Ingrese el precio del nuevo producto: ";
		    cin >> nuevoProducto.precio;
            if (numHamburguesas < MAX_ITEMS) {
                hamburguesas[numHamburguesas] = nuevoProducto;
                numHamburguesas++;
            cout << "Producto agregado exitosamente" << endl;
            } else {
                cout << "No se puede agregar más hamburguesas." << endl;
            }
            break;
        case 'B':
        	cout << "Ingrese el nombre del nuevo producto: ";
		    cin.ignore();
		    getline(cin, nuevoProducto.nombre);
		    cout << "Ingrese el precio del nuevo producto: ";
		    cin >> nuevoProducto.precio;
            if (numPizzas < MAX_ITEMS) {
                pizzas[numPizzas] = nuevoProducto;
                numPizzas++;
            cout << "Producto agregado exitosamente" << endl;
            } else {
                cout << "No se puede agregar más pizzas." << endl;
            }
            break;
        case 'C':
        	cout << "Ingrese el nombre del nuevo producto: ";
		    cin.ignore();
		    getline(cin, nuevoProducto.nombre);
		    cout << "Ingrese el precio del nuevo producto: ";
		    cin >> nuevoProducto.precio;
            if (numConos < MAX_ITEMS) {
                conos[numConos] = nuevoProducto;
                numConos++;
            cout << "Producto agregado exitosamente" << endl;
            } else {
                cout << "No se puede agregar más conos." << endl;
            }
            break;
        case 'D':
        	cout << "Ingrese el nombre del nuevo producto: ";
		    cin.ignore();
		    getline(cin, nuevoProducto.nombre);
		    cout << "Ingrese el precio del nuevo producto: ";
		    cin >> nuevoProducto.precio;
            if (numGaseosas < MAX_ITEMS) {
                gaseosas[numGaseosas] = nuevoProducto;
                numGaseosas++;
            cout << "Producto agregado exitosamente" << endl;
            } else {
                cout << "No se puede agregar más gaseosas." << endl;
            }
            break;
        case 'E':
        	cout << "Ingrese el nombre del nuevo producto: ";
		    cin.ignore();
		    getline(cin, nuevoProducto.nombre);
		    cout << "Ingrese el precio del nuevo producto: ";
		    cin >> nuevoProducto.precio;
            if (numAguas < MAX_ITEMS) {
                aguas[numAguas] = nuevoProducto;
                numAguas++;
            cout << "Producto agregado exitosamente" << endl;
            } else {
                cout << "No se puede agregar más aguas." << endl;
            }
            break;
    	case 'F':
    		categoria = 'F';
    		break;
        default:
            cout << "Valor no valido, asegurese de ingresar una letra de la A hasta la F" << endl;
            break;
    }
    
	}while (categoria !='F');
	cout << "Volviendo al menu anterior.." << endl;
}
//FUNCION ORDENAR CARTA
void ordenarCarta() {
   char categoria;
   do {
   	
  
    cout << "\n// ORDENAR CARTA //" << endl;
    cout << "Seleccione la categoría para ordenar por precio decendente:" << endl;
    cout << "A. Hamburguesas" << endl;
    cout << "B. Pizzas" << endl;
    cout << "C. Conos" << endl;
    cout << "D. Gaseosas" << endl;
    cout << "E. Aguas" << endl;
    cout << "F. Volver al menu anterior" << endl;
    cin >> categoria;

    switch (categoria) {
        case 'A':
            for (int i = 0; i < numHamburguesas - 1; i++) {
                for (int j = 0; j < numHamburguesas - i - 1; j++) {
                    if (hamburguesas[j].precio > hamburguesas[j + 1].precio) {
                        swap(hamburguesas[j], hamburguesas[j + 1]);
                    }
                }
            }
            cout << "Hamburguesas ordenadas satisfactoriamente" << endl;
            break;
        case 'B':
            for (int i = 0; i < numPizzas - 1; i++) {
                for (int j = 0; j < numPizzas - i - 1; j++) {
                    if (pizzas[j].precio > pizzas[j + 1].precio) {
                        swap(pizzas[j], pizzas[j + 1]);
                    }
                }
            }
            cout << "Pizzas ordenadas satisfactoriamente" << endl;
            break;
        case 'C':
            for (int i = 0; i < numConos - 1; i++) {
                for (int j = 0; j < numConos - i - 1; j++) {
                    if (conos[j].precio > conos[j + 1].precio) {
                        swap(conos[j], conos[j + 1]);
                    }
                }
            }
            cout << "Conos ordenados satisfactoriamente" << endl;
            break;
        case 'D':
            for (int i = 0; i < numGaseosas - 1; i++) {
                for (int j = 0; j < numGaseosas - i - 1; j++) {
                    if (gaseosas[j].precio > gaseosas[j + 1].precio) {
                        swap(gaseosas[j], gaseosas[j + 1]);
                    }
                }
            }
            cout << "Gaseosas ordenadas satisfactoriamente" << endl;
            break;
        case 'E':
            for (int i = 0; i < numAguas - 1; i++) {
                for (int j = 0; j < numAguas - i - 1; j++) {
                    if (aguas[j].precio > aguas[j + 1].precio) {
                        swap(aguas[j], aguas[j + 1]);
                    }
                }
            }
            cout << "Aguas ordenadas satisfactoriamente" << endl;
            break;
        case 'F':
        	cout << "Volviendo al menu anterior" << endl;
        	break;
        default:
            cout << "Categoría no encontrada o ingreso un valor en minuscula, asegurese que su valor ingresado sea en mayuscula" << endl;
            break;
    }
    } while (categoria =! 'F');
}
//FUNCION PARA ELIMINAR PRODUCTOS DE LA CARTA
void eliminarCarta() {
    int item;
    char categoria;
    do {
    cout << "\n// ELIMINAR PRODUCTO //" << endl;
    cout << "Seleccione la categoría del producto a eliminar:" << endl;
    cout << "A. Hamburguesas" << endl;
    cout << "B. Pizzas" << endl;
    cout << "C. Conos" << endl;
    cout << "D. Gaseosas" << endl;
    cout << "E. Aguas" << endl;
    cout << "F. Volver al menu anterior" << endl;
    cin >> categoria;

    switch (categoria) {
        case 'A':
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
        case 'B':
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
        case 'C':
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
        case 'D':
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
        case 'E':
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
        case 'F':
        	cout << "Regresando al menu anterior" << endl;
        	break;
        default:
            cout << "Categoría no encontrada, Ingrese una categoria del 1 al 6" << endl;
            break;
    }
    } while (categoria!=6);
}
//USAR EN FUNCIONESFINANZAS.CPP

