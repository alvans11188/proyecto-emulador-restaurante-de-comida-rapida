#include <iostream>
#ifndef FUNCIONESCLIENTE_H
#define FUNCIONESCLIENTE_H
using namespace std;

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

//SE AGREGAN 10 CLIENTES PREDEFINIDOS
Cliente clientes[20] = {
		{"Carlos Flores", "827364958", {"Miraflores", "Av. Pardo", "Mz. B", "Lt. 12"}}, //POSICION 0
		{"Juan Perez", "817361123", {"San Isidro", "Calle Las Flores", "Mz. F", "Lt. 8"}}, //POSICION 1
		{"Maria Lopez", "917345991", {"Barranco", "Av. Grau", "Mz. C", "Lt. 5"}}, //POSICION 2
		{"Carlos Gomez", "611230194", {"Surco", "Calle Los Alamos", "Mz. D", "Lt. 3"}}, //POSICION 3
		{"Laura Fernandez", "471623090", {"La Molina", "Av. La Universidad", "Mz. A", "Lt. 1"}}, //POSICION 4
		{"Luis Martinez", "918453124", {"San Borja", "Calle Los Laureles", "Mz. J", "Lt. 9"}}, //POSICION 5
		{"Sofia Torres", "019434198", {"Vitacura", "Av. Bolivar", "Mz. E", "Lt. 6"}}, //POSICION 6
		{"Pedro Meza", "981450001", {"Magdalena", "Calle San Martin", "Mz. H", "Lt. 2"}}, //POSICION 7
		{"Elena Mamani", "934217501", {"Polanco", "Av. Arequipa", "Mz. G", "Lt. 7"}}, //POSICION 8
		{"Jorge Morales", "091245762", {"Palermo", "Calle Salaverry", "Mz. L", "Lt. 3"}} //POSICION 9
	};

//REGISTRO DE DIRECCION


void agregarCliente(Cliente clientes[20], int &cantidadActualClientes);
void editarDatosCliente(Cliente clientes[20], int &cantidadActualClientes);

#endif
