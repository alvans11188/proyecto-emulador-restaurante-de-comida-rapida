#ifndef FUNCIONESCLIENTE_H
#define FUNCIONESCLIENTE_H
#include <iostream>
using namespace std;

//REGISTRO DE DIRECCION
struct Direccion {
	string distrito;
	string calle;
	string manzana;
	string lote;
};

//REGISTRO DE CLIENTE
struct Cliente {
	string nombre;
	string telefono;
	Direccion direccionCliente;
};

void agregarCliente(Cliente clientes[20], int &cantidadActualClientes);
void editarDatosCliente(Cliente clientes[20], int &cantidadActualClientes);

#endif
