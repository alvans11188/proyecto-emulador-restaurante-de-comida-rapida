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

const int MAX_ITEMS=10;

Alimentos alimento[MAX_ITEMS] = {
    {"Tomate", 4, 0.2},
    {"Lechuga", 0.5, 0.3},
    {"Bolsa de harina", 2, 1.5},
    {"Carnes", 2, 2},
    {"Litro de gaseosa", 2, 3},
    {"Litro de agua", 2, 2.5}
};


const int limiteAlmacen = 100;

int ingresarAlimentos(){
	string opcion;
	float c;
	float minimoAlmacen = 0;
	int n=0;
	if (minimoAlmacen != limiteAlmacen){
		cout << endl << endl;
		cout << "//IngresarAlimento" << endl;
		cout << "(Tomate, Lechuga, Bolsa de harina, Carnes, Litro de gaseosa, Litro de agua)";
		cout << endl << endl;
		
		bool encontrado = false;
		do{
			cout << "Indique: ";
			if(n>=0) cin.ignore();
			getline(cin, opcion);
			cout << endl;
			for(int i=0; i<MAX_ITEMS; i++){
				if(alimento[i].nombre==opcion){
					cout << "Cantidad: ";
					cin >> c;
					minimoAlmacen += c;
					cout << endl;
			        cout << "Cantidad de " << alimento[i].nombre << " actualizada a " << alimento[i].cantidad << endl;
			        bool encontrado = true;
			        break;
				} 
			}
			if(!encontrado){
				cout << "¡Gasta en lo necesario!" << endl << endl;
			}
			
		} while (!encontrado);
	} else {
		cout << "Limite maximo de alimentos." << endl;
	}
}
#endif
