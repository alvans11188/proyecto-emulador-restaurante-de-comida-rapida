#ifndef CARTA_H
#define CARTA_H
#include <string>
#include <iostream>
using namespace std;

void menuCarta();
void mostrarCarta();
void editarCarta();
void agregarCarta();
void inicializarproductos();

struct Alimentos{
	string nombre;
	int cantidad;
	float precio;
};

struct Producto {
    string nombre;
    float precio;
};

#endif
