#ifndef FUNCIONESDESPENSA_H
#define FUNCIONESDESPENSA_H
#include <string>
#include <iostream>
using namespace std;

const int MAX_ALIMENTOS=6;


struct Alimentos{
	string nombre;
	float cantidad;
	float precio;
};
extern Alimentos alimento[MAX_ALIMENTOS];

const int limiteAlmacen = 100;

void AgregarAlimentos();
void actualizarAlimentos();
void mostrarStock();

#endif
