#ifndef FUNCIONESDESPENSA_H
#define FUNCIONESDESPENSA_H
#include <string>
#include <iostream>
using namespace std;

const int MAX_ITEMS=6;

//Hamburguesa = 1 tomate, 0.25 lechuga, 0.5 bolsaharina, 0.5 carnes
//Pizzas = 4 tomate, 2 bolsaharina, 2 carnes
//Conos = 2 tomate, 0.5 lechuca, 1 bolsaharina 1 carnes
//Gaseosas = 0.5 litrogaseosa
//Agua = 0.5 litroagua

struct Alimentos{
	string nombre;
	float cantidad;
	float precio;
};

Alimentos alimento[MAX_ITEMS] = {
    {"Tomates", 4, 0.2},
    {"Lechugas", 0.5, 0.3},
    {"Bolsas de harina", 2, 1.5},
    {"Carnes", 2, 2},
    {"Litros de gaseosa", 2, 3},
    {"Litros de agua", 2, 2.5}
};

const int limiteAlmacen = 100;

int AgregarAlimentos(){
	float c;
	int opcion;
	float minimoAlmacen = 0;
	int n=0;
	int aux=0;
	if (minimoAlmacen != limiteAlmacen){
		cout << "AGREGAR ALIMENTOS" << endl << endl;
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

	cout << "ACTUALIZAR ALIMENTOS" << endl << endl;
	for(int i=0; i<MAX_ITEMS; i++){
		cout << i+1 << ". " << alimento[i].nombre << endl << endl;
		cout << "Unidades disponibles: " << alimento[i].cantidad << endl;
		cout << "Precio unitario: " << alimento[i].precio << endl << endl;
	}
	cout << endl;
	cout << "Indique: ";
	cin >> opcion;
	cout << endl;
	
	cout << "Actualizando datos de '" << alimento[opcion-1].nombre << "'..." << endl << endl;
	cout << "Unidades disponibles: ";
	cin >> alimento[opcion-1].cantidad;
	cout << "Precio unitario: ";
	cin >> alimento[opcion-1].precio;
	cout << "Se actualizo '" << alimento[opcion-1].nombre << "' con exito." << endl << endl;
}

int mostrarStock(){
	
	cout << "STOCK DE LOS ALIMENTOS" << endl << endl;
	Alimentos copia[MAX_ITEMS];
	for(int i=0; i<MAX_ITEMS; i++){
		copia[i] = alimento[i];
	}
	
	Alimentos mayor;
	for(int i=0; i<MAX_ITEMS-1; i++){
		for(int j=0; j<MAX_ITEMS-1-i; j++){
			if (copia[j].cantidad < copia[j + 1].cantidad) { 
				mayor = copia[j];
				copia[j] = copia[j+1];
				copia[j+1] = mayor;
			}
		}
	}
	
	cout << "(Ordenados de mayor a menor)" << endl << endl;
	for(int i=0; i<MAX_ITEMS; i++){
		cout << "(" << copia[i].cantidad << ") " << copia[i].nombre << "." << endl;
	}
}
#endif
