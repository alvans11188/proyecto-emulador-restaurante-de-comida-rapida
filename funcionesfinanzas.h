#ifndef FUNCIONESFINANZAS_H
#define FUNCIONESFINANZAS_H
#include "funcionescarta.h"
#include "funcionesdespensa.h"
#include <string>
using namespace std;

const int MAX_FACTURAS = 100; //tambien se usa para el maximo de ordenes en una factura
extern int numFactura;

struct Ordenes{
	string nombre;
	int cantidad;
	float monto;
};


struct GastoAlimento {
    string nombre;
    float gastos;
};

extern Ordenes orden[MAX_FACTURAS][MAX_FACTURAS];

extern float montofinal[MAX_FACTURAS];
extern int ordenesTotales[MAX_FACTURAS];

void registrarVenta();
void mostrarOrdenes();
void gastosGanancias();
void ordenarVentas();
void estadisticasGenerales();

#endif

