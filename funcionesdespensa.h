#ifndef FUNCIONESDESPENSA_H
#define FUNCIONESDESPENSA_H
#include <string>
#include <iostream>
using namespace std;

const int MAX_ALIMENTOS=6;

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
extern Alimentos alimento[MAX_ALIMENTOS];

const int limiteAlmacen = 100;

int AgregarAlimentos();
int actualizarAlimentos();
int mostrarStock();

#endif
