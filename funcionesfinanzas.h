#ifndef FUNCIONESFINANZAS_H
#define FUNCIONESFINANZAS_H
#include "funcionescarta.h"
#include <string>
using namespace std;

const int MAX_FACTURA = 100;

struct FacturaItem {
    string nombre;
    float precio;
    int cantidad;
};

void registrarVenta();
void mostrarOrdenes();
void gastosGanancias();
void ordenarVentas();
void estadisticasGenerales();

#endif

