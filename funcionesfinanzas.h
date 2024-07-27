#ifndef FUNCIONESFINANZAS_H
#define FUNCIONESFINANZAS_H
#include "funcionescarta.h"
#include <string>
using namespace std;

const int MAX_FACTURAS = 100;
extern int numFactura;

struct Ordenes{
	string nombre;
	int cantidad;
	float monto;
};

extern int ordenesTotales[MAX_FACTURAS];
extern Ordenes orden[MAX_FACTURAS][MAX_FACTURAS];
extern float montofinal[MAX_FACTURAS];

void registrarVenta();
void mostrarOrdenes();
void gastosGanancias();
void ordenarVentas();
void estadisticasGenerales();

#endif

