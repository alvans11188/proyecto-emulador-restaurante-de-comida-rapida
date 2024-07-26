#include "funcionesfinanzas.h"
#include "funcionescarta.h"
#include "funcionesdespensa.h"
#include <iostream>
#include <string>
using namespace std;

struct Ordenes{
	string nombre;
	float monto;
};

void ordenRegistro(Ordenes orden[], Producto producto[],  int item, int c, int cantidad){
	orden[c].nombre = producto[item-1].nombre;
	orden[c].monto = producto[item-1].precio*cantidad;
}
Ordenes orden[MAX_FACTURA];
void registrarVenta(){
	int categoria;
	int item;
	float montofinal=0;
	string nombre;
	int cantidad;
	int c=0;
	string respuesta;
	cout << endl << endl;
	cout << "Registrando una venta..." << endl << endl;
	do{
		cout << endl;
		cout << "Elija la categoria a vender." << endl << endl;
		cout << "1. Hamburguesas" << endl;
	    cout << "2. Pizzas" << endl;
	    cout << "3. Conos" << endl;
	    cout << "4. Gaseosas" << endl;
	    cout << "5. Aguas" << endl << endl;
	    cout << "= ";
	    cin >> categoria;
		
		bool continuar = true;
		cout << endl;
	    switch (categoria) {
	        case 1:
	            cout << "Seleccione la hamburguesa:" << endl;
	            for (int i = 0; i < numHamburguesas; i++) {
	                cout << i + 1 << ". " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
	            }
	            cout << endl;
	            cout << "= ";
	            cin >> item;
	            cout << "Cantidad: ";
				cin >> cantidad;
	            ordenRegistro(orden, hamburguesas, item, c, cantidad);
				c++;
				break;
	        case 2:
	            cout << "Seleccione la pizza:" << endl;
	            for (int i = 0; i < numPizzas; i++) {
	                cout << i + 1 << ". " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
	            }
	            cout << endl;
	            cout << "= ";
	            cin >> item;
	            cout << "Cantidad: ";
				cin >> cantidad;
	            ordenRegistro(orden, pizzas, item, c, cantidad);
	            c++;
	            break;
	            
	        case 3:
	            cout << "Seleccione el cono:" << endl;
	            for (int i = 0; i < numConos; i++) {
	                cout << i + 1 << ". " << conos[i].nombre << " S/. " << conos[i].precio << endl;
	            }
	            cout << endl;
	            cout << "= ";
	            cin >> item;
	            cout << "Cantidad: ";
				cin >> cantidad;
	            ordenRegistro(orden, conos, item, c, cantidad);
	            c++;
	            break;
	        case 4:
	            cout << "Seleccione la gaseosa:" << endl;
	            for (int i = 0; i < numGaseosas; i++) {
	                cout << i + 1 << ". " << gaseosas[i].nombre << " S/. " << gaseosas[i].precio << endl;
	            }
	            cout << endl;
	            cout << "= ";
	            cin >> item;
	            cout << "Cantidad: ";
				cin >> cantidad;
	            ordenRegistro(orden, gaseosas, item, c, cantidad);
	            c++;
	            break;
	        case 5:
	            cout << "Seleccione el agua:" << endl;
	            for (int i = 0; i < numAguas; i++) {
	                cout << i + 1 << ". " << aguas[i].nombre << " S/. " << aguas[i].precio << endl;
	            }
	            cout << endl;
	            cout << "= ";
	            cin >> item;
	            cout << "Cantidad: ";
				cin >> cantidad;
	            ordenRegistro(orden, aguas, item, c, cantidad);
	            c++;
	            break;
	        default:
	            cout << "Categoría no válida." << endl;
	            continuar = false;
	            break;
	    }
	    if(continuar){
	    	cout << "¿Va a agregar algo mas a la orden?(si/no)= ";
	    	cin >> respuesta;
		}
	} while(respuesta!= "no");
   cout << endl;
   cout << "FACTURA" << endl << endl;
   cout << "Productos en la orden: " << endl;
   int j=0;
   for(int i=0; i<c; i++){
   		cout << j+1 << ". " << orden[i].nombre << "(" << orden[i].monto << ")" << endl;
   		j++;
   }
   for(int i=0; i<c; i++){
   		montofinal += orden[i].monto;
   }
   cout << "Total a pagar: " << montofinal << endl;
}

void mostrarOrdenes(){
	
}

void gastosGanancias(){
	
}

void ordenarVentas(){
	
}

void estadisticasGenerales(){
	
}
