#ifndef FUNCIONESCARTA_H
#define FUNCIONESCARTA_H
#include <string>
#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

void mostrarProductos();
//NUMERO MAXIMO DE PRODUCTOS
const int MAX_ITEMS = 100;
// PRODUNTOS PREDEFINIDOS
void inicializarproductos();
// FUNCION MOSTRAR CARTA
void mostrarCarta();
//FUNCION PARA EDITAR CARTA
void editarCarta();
//FUNCION PARA AGREGAR A LA CARTA
void agregarCarta();
#endif
