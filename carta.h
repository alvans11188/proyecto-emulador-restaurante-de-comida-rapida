#ifndef CARTA_H
#define CARTA_H
#include <string>
using namespace std;

void menuCarta();
void mostrarCarta();
void editarCarta();
void agregarCarta();
void inicializarproductos();

struct Producto {
    string nombre;
    float precio;
};

#endif
