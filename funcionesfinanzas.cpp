#include "funcionesfinanzas.h"
#include "funcionescarta.h"
#include "funcionesdespensa.h"
#include <iostream>
#include <string>
using namespace std;

float aguasTotalUsadas = 0;
float gaseosasTotalUsadas = 0;
float quesosTotalUsados = 0;
float carnesTotalUsadas = 0;
float bolsasharinaTotalUsadas = 0;
float lechugasTotalUsadas = 0;
float tomatesTotalUsados = 0;

GastoAlimento gastos[MAX_ALIMENTOS] = {
                    {"Tomate", tomatesTotalUsados * alimento[0].precio},
                    {"Lechugas", lechugasTotalUsadas * alimento[1].precio},
                    {"Bolsas de harina", bolsasharinaTotalUsadas * alimento[2].precio},
                    {"Carnes", carnesTotalUsadas * alimento[3].precio},
                    {"Litros de gaseosa", gaseosasTotalUsadas * alimento[4].precio},
                    {"Litros de agua", aguasTotalUsadas * alimento[5].precio},
                    {"Queso", quesosTotalUsados * alimento[6].precio}
                };
// Tomate: 0.2   lechuga: 0.3  bolsaharina: 1.5   carnes: 2   				//Costo
// litrosgaseosa: 3   litrosagua: 2.5														
//Hamburguesa = 1 tomate, 0.25 lechuga, 0.5 bolsaharina, 0.15 carnes; 		// 1*0.2 + 0.25*0.3 + 0.5
//Pizzas = 4 tomate, 2 bolsaharina, 2 carnes
//Conos = 2 tomate, 0.5 lechuca, 1 bolsaharina 1 carnes
//Gaseosas = 0.5 litrogaseosa
//Agua = 0.5 litroagua

	//{"Tomates" // 0  				= 40u en despensa
   // {"Lechugas" // 1|				= 5u en despoensa
   // {"Bolsas de harina", // 2		= 20u en despensa
   // {"Carnes" // 3				= 20u en despensa
   // {"Litros de gaseosa" //4		= 20u en despensa
    //{"Litros de agua" //5			= 20u en despensa
int numFactura = 0;// iniciamos variable con 0
int ordenesTotales[MAX_FACTURAS] = {0}; // iniciamos arreglo con 0
Ordenes orden[MAX_FACTURAS][MAX_FACTURAS];//definimos matriz de orden "MAX_FACTURAS" 
//filas: N* factura
//columna: N* orden
float montofinal[MAX_FACTURAS] = {0};// iniciamos arreglo con 0

 //Funcion para que cada orden adquiere nombre y producto, ademas se suma por cada orden el precio de la orden + monto.
void ordenRegistro(Ordenes orden[], Producto producto[],  int item, int c, int cantidad){
// FACTURA = conjutno de ordeenes	
	orden[c].nombre = producto[item - 1].nombre;
    orden[c].cantidad = cantidad;
    orden[c].monto = producto[item - 1].precio * cantidad;
}

//el & es para que la funcion modifique el valor de una variable
void montoFinal(Ordenes orden[], int totalOrdenes, float& montofinal) {
    for (int i = 0; i < totalOrdenes; i++) {
        montofinal += orden[i].monto;
    }
}

void ordenarGastos(GastoAlimento arr[], int n) {
	GastoAlimento aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].gastos < arr[j].gastos) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void ordenarGanancias(Producto arr[], int n) {
	
}

void registrarVenta(){
	int categoria;
	int item;
	string nombre;
	int cantidad;
	string respuesta;
	int c=0; //para dar el orden a cada Orden
	cout << endl << endl;
	cout << "Registrando una orden..." << endl << endl;
	do{ // MENU INTERFAZ
		cout << endl;
		cout << "Elija la categoria." << endl << endl;
		cout << "1. Hamburguesas" << endl;
	    cout << "2. Pizzas" << endl;
	    cout << "3. Conos" << endl;
	    cout << "4. Gaseosas" << endl;
	    cout << "5. Aguas" << endl;
	    cout << "6. Terminar orden." << endl << endl;
	    cout << "= ";
	    cin >> categoria;
		
		bool continuar = false; //si es que no cumple una condicion, no podra continuar agregando en la orden
		bool suficiente = true;
		cout << endl;
	    switch (categoria) {
	        case 1:
	            cout << "Seleccione la hamburguesa:" << endl; // interfaz de menu de hamburguesas
	            for (int i = 0; i < numHamburguesas; i++) {
	                cout << i + 1 << ". " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
	            }
	            cout << endl;
	            cout << "= ";
	            cin >> item;
	            cout << "Cantidad: ";
				cin >> cantidad;
				if(alimento[0].cantidad>=CTH*cantidad && alimento[1].cantidad>=CLH*cantidad && alimento[2].cantidad>=CBH*cantidad && alimento[3].cantidad>=CCH*cantidad && alimento[6].cantidad >= CQH*cantidad){ // ingredientes para cocinar una hamburguesa
	            	ordenRegistro(orden[numFactura], hamburguesas, item, c, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					c++;
					ordenesTotales[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					tomatesTotalUsados += CTH*cantidad;
					lechugasTotalUsadas += CLH*cantidad;
					bolsasharinaTotalUsadas += CBH*cantidad;
					carnesTotalUsadas += CCH*cantidad;
					quesosTotalUsados += CQH*cantidad;
					
					alimento[0].cantidad -= CTH*cantidad; // tomate
					alimento[1].cantidad -= CLH*cantidad; // lechuga
					alimento[2].cantidad -= CBH*cantidad; //harina
					alimento[3].cantidad -= CCH*cantidad; //carnes
					alimento[6].cantidad -= CQH*cantidad; // queso
					
				} else {
					suficiente = false;
					continuar = false;
				}
				break;
	        case 2:
	            cout << "Seleccione la pizza:" << endl;// interfaz de menu de pizzas
	            for (int i = 0; i < numPizzas; i++) {
	                cout << i + 1 << ". " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
	            }
	            cout << endl;
	            cout << "= ";
	            cin >> item;
	            cout << "Cantidad: ";
	            cin >> cantidad;
				if(alimento[0].cantidad>=CTP*cantidad &&  alimento[2].cantidad>=CBP*cantidad && alimento[3].cantidad>=CCP*cantidad && alimento[6].cantidad >= CQP*cantidad){ // ingredientes para cocinar una hamburguesa
	            	ordenRegistro(orden[numFactura], pizzas, item, c, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					c++;
					ordenesTotales[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					tomatesTotalUsados += CTP*cantidad;
					bolsasharinaTotalUsadas += CBP*cantidad;
					carnesTotalUsadas += CCP*cantidad;
					quesosTotalUsados += CQP*cantidad;
					 
					alimento[0].cantidad -= CTP*cantidad;
					alimento[2].cantidad -= CBP*cantidad;
					alimento[3].cantidad -= CCP*cantidad;
					alimento[6].cantidad -= CQP*cantidad;
				} else {
					suficiente = false;
					continuar = false;
				}
	            break;
	            
	        case 3:
	            cout << "Seleccione el cono:" << endl; // interfaz de menu de conos
	            for (int i = 0; i < numConos; i++) {
	                cout << i + 1 << ". " << conos[i].nombre << " S/. " << conos[i].precio << endl;
	            }
	            cout << endl;
	            cout << "= ";
	            cin >> item;
	            cout << "Cantidad: ";
				cin >> cantidad;
				if(alimento[0].cantidad>=CTC*cantidad && alimento[1].cantidad>=CLC*cantidad && alimento[2].cantidad>=CBC*cantidad && alimento[3].cantidad>=CCC*cantidad && alimento[6].cantidad >= CQC*cantidad){ // ingredientes para cocinar una hamburguesa
	            	ordenRegistro(orden[numFactura], conos, item, c, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					c++;
					ordenesTotales[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					tomatesTotalUsados += CTC*cantidad;
					lechugasTotalUsadas += CLC*cantidad;
					bolsasharinaTotalUsadas += CBC*cantidad;
					carnesTotalUsadas += CCC*cantidad;
					quesosTotalUsados += CQC*cantidad;
					
					alimento[0].cantidad -= CTC*cantidad; // tomate
					alimento[1].cantidad -= CLC*cantidad; // lechuga
					alimento[2].cantidad -= CBC*cantidad; //harina
					alimento[3].cantidad -= CCC*cantidad; //carnes
					alimento[6].cantidad -= CQC*cantidad; // queso
					
				} else {
					suficiente = false;
					continuar = false;
				}
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
				if(alimento[4].cantidad>=CG*cantidad){ // ingredientes para cocinar una hamburguesa
	            	ordenRegistro(orden[numFactura], gaseosas, item, c, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					c++;
					ordenesTotales[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					gaseosasTotalUsadas += CG*cantidad;
					alimento[4].cantidad -= CG*cantidad;
					
				} else {
					suficiente = false;
					continuar = false;
				}
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
				if(alimento[5].cantidad>=CA*cantidad){ // ingredientes para cocinar una hamburguesa
	            	ordenRegistro(orden[numFactura], aguas, item, c, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					c++;
					ordenesTotales[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					aguasTotalUsadas += CA*cantidad;
					alimento[5].cantidad -= CA*cantidad;
				} else {
					suficiente = false;
					continuar = false;
				}
	            break;
	        default:
	            cout << "Categoria no valida." << endl;
	            break;
	    }
	    cout << endl;
	    if(!suficiente){
	    	cout << "No hay suficientes ingredientes." << endl;
		}
	    if(continuar){
	    	cout << "¿Va a agregar algo mas a la orden?(si/no)= ";
	    	cin >> respuesta;
		}
	} while(respuesta!= "no" &&categoria!=6);
	
   cout << endl;
   cout << "FACTURA" << endl << endl;
   cout << "Productos en la orden: " << endl << endl;
   int j=0;
   for(int i=0; i<ordenesTotales[numFactura]; i++){
   		cout << j+1 << ". " << "(" << orden[numFactura][i].cantidad << ") " << orden[numFactura][i].nombre << " S/. " << orden[numFactura][i].monto << endl;
   		j++;
   }
   montoFinal(orden[numFactura], ordenesTotales[numFactura], montofinal[numFactura]);
   cout << endl;
   cout << "Total a pagar: S/. " << montofinal[numFactura] << endl;
   numFactura++;
}

void mostrarOrdenes(){
	cout << endl;
	cout << "MOSTRANDO FACTURAS REGISTRADAS" << endl << endl;
	for(int i=0; i<numFactura; i++){
		cout << i+1 << ". FACTURA" << endl << endl;
		cout << "Productos:" << endl << endl;
		for(int j=0; j<ordenesTotales[i]; j++){
			cout << "(" << orden[i][j].cantidad << ") " << orden[i][j].nombre << " S/. " << orden[i][j].monto << endl;
		}
		cout << "Monto final: S/. " << montofinal[i] << endl << endl;
	}
	cout << endl;
}

void gastosGanancias(){
	cout << endl;
	char respuesta;
	bool valido = true;
	do{
		cout << "¿Que quieres ver?" << endl << endl;
		cout << "- ) Gastos." << endl;
		cout << "+ ) Ganancias." << endl;
		cin >> respuesta;
		cout << endl;
		switch(respuesta){
			case '-':
				cout << "Gastos consumidos hasta el momento (mayor a menor)" << endl << endl;
                ordenarGastos(gastos, MAX_ALIMENTOS);
                for(int i=0; i<MAX_ALIMENTOS; i++){
                	cout << gastos[i].nombre << "(" << alimento[i].cantidad << "): S/." << -gastos[i].gastos << endl;
				}
 				break;
			case '+':
				cout << "Ganancias hasta el momento (mayor a menor)" << endl << endl;
				break;
			default:
				cout << "Opcion no valida." << endl;
				valido = false;
				break;
		}
		cout << endl;
	} while(!valido);
}

void ordenarVentas(){
	
}

void estadisticasGenerales(){
	
}
