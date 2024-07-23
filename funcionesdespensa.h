#ifndef FUNCIONESDESPENSA_H
#define FUNCIONESDESPENSA_H
#include "carta.h"
#include <string>
#include <iostream>
using namespace std;

//Hamburguesa = 1 tomate, 0.25 lechuga, 0.5 bolsaharina, 0.5 carnes
//Pizzas = 4 tomate, 2 bolsaharina, 2 carnes
//Conos = 2 tomate, 0.5 lechuca, 1 bolsaharina 1 carnes
//Gaseosas = 0.5 litrogaseosa
//Agua = 0.5 litroagua

const int MAX_ITEMS=6;

Alimentos alimento[MAX_ITEMS] = {
    {"Tomates", 4, 0.2},
    {"Lechugas", 0.5, 0.3},
    {"Bolsas de harina", 2, 1.5},
    {"Carnes", 2, 2},
    {"Litros de gaseosa", 2, 3},
    {"Litros de agua", 2, 2.5}
};

void clearInputBuffer() {
    cin.clear();
    while (cin.get() != '\n');
}

const int limiteAlmacen = 100;

int AgregarAlimentos(){
	float c;
	int opcion;
	float minimoAlmacen = 0;
	int n=0;
	int aux=0;
	if (minimoAlmacen != limiteAlmacen){
		cout << endl << endl;
		cout << "//AgregarAlimento" << endl;
		cout << "Lista de alimentos para el negocio" << endl << endl;
		
		for(int i=0; i<MAX_ITEMS; i++){
			cout << i+1 << ". " << alimento[i].nombre << "(" << alimento[i].cantidad << ")." << endl;
		}
		cout << endl;
		
        while (true) {
            cout << "Indique: ";
            cin >> opcion;
			cout << endl;
            if(opcion<=6 && opcion>0){
	            cout << "Agregando '" << alimento[opcion-1].nombre << "'..." << endl << endl;
	            while(c<=0){
	            	cout << "Cantidad: ";
		            cin >> c;
		            cout << endl;
		            if(c>0){
		            	alimento[opcion-1].cantidad += c;
		            	cout << "Se agregaron " << c << " '" << alimento[opcion-1].nombre << "' a la despensa." << endl << endl;
		            	break;
		            }else {
		            	cout << "Ingrese una cantidad valida." << endl << endl;
					}
				}
	            break;
            } else {
                cout << "Opcion no valida." << endl << endl;
            }
        }
    } else {
        cout << "Limite maximo de alimentos.\n" << endl;
    }
    cout << endl;
}

int actualizarAlimentos(){
	int opcion;
	cout << endl;
	cout << "//ActualizarAlimentos//" << endl << endl;
	for(int i=0; i<MAX_ITEMS; i++){
		cout << i << alimento[i].nombre << endl << endl;
		cout << "Unidades disponibles: " << alimento[i].cantidad << endl;
		cout << "Precio unitario: " << alimento[i].precio << endl;
	}
	cout << endl;
	cout << "Indique: ";
	cin >> opcion;
	
	cout << "Actualizando datos de '" << alimento[opcion].nombre << "'..." << endl << endl;
	cout << "Unidades disponibles: ";
	cin >> alimento[opcion].cantidad;
	cout << "Precio unitario: ";
	cin >> alimento[opcion].precio;
	cout << endl << endl;
}
#endif
