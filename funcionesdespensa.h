#ifndef FUNCIONESDESPENSA_H
#define FUNCIONESDESPENSA_H
#include <iostream>
using namespace std;

const int MAX_ITEMS=6;

struct Alimentos{
	string nombre;
	float cantidad;
	float precio;
};

const int limiteAlmacen = 100;
void AgregarAlimentos();
void actualizarAlimentos();
void mostrarStock();

#endif
