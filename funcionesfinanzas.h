#ifndef FUNCIONESFINANZAS_H
#define FUNCIONESFINANZAS_H
#include "funcionescarta.h"
#include <string>
using namespace std;

const int MAX_FACTURAS = 100;

struct Ordenes{
	string nombre;
	int cantidad;
	float monto;
};


void registrarVenta();
void mostrarOrdenes();
void gastosGanancias();
void ordenarVentas();
void estadisticasGenerales();

#endif

