#include "funcionesfinanzas.h"
#include "funcionescarta.h"
#include "funcionesdespensa.h"
#include <iostream>
#include <string>
#include <windows.h>
#define color SetConsoleTextAttribute
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

float montoFinalGanancias = 0;
float montoFinalGastos = 0;
int ordenesTotales=0; //para dar el orden a cada Orden

const float costeHamburguesas = alimento[0].precio*CTH + alimento[1].precio*CLH + alimento[2].precio*CBH + alimento[3].precio*CCH + alimento[6].precio*CQH;
const float costePizzas = alimento[0].precio*CTP + alimento[2].precio*CBP + alimento[3].precio*CCP + alimento[6].precio*CQP;
const float costeConos = alimento[0].precio*CTC + alimento[1].precio*CLC + alimento[2].precio*CBC + alimento[3].precio*CCC + alimento[6].precio*CQC;
const float costeGaseosas = alimento[4].precio*CG;
const float costeAguas = alimento[5].precio*CA;

const int totalComidas = numHamburguesas + numPizzas + numConos + numGaseosas + numAguas;

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
int ordenesPorFactura[MAX_FACTURAS] = {0}; // iniciamos arreglo con 0
paraOrdenarVentas ordenarVentas[MAX_ITEMS];
ventasDeComidas ventasComidas[MAX_FACTURAS];
Ordenes orden[MAX_FACTURAS][MAX_FACTURAS];//definimos matriz de orden "MAX_FACTURAS" 
//filas: N* factura
//columna: N* orden
float montoDeFactura[MAX_FACTURAS] = {0};// arreglo que contiene todas los montos de cada factura iniciamos arreglo con 0
 //Funcion para que cada orden adquiere nombre y producto, ademas se suma por cada orden el precio de la orden + monto.
void ordenRegistro(Ordenes orden[], Producto producto[],  int item, int c, int cantidad){
// FACTURA = conjutno de ordeenes	
	orden[c].nombre = producto[item - 1].nombre;
    orden[c].cantidad = cantidad;
    orden[c].monto = producto[item - 1].precio * cantidad;
}

//el & es para que la funcion modifique el valor de una variable
void montoPorFactura(Ordenes orden[], int n, float& montoDeFactura) {
    for (int i = 0; i < n; i++) {
        montoDeFactura += orden[i].monto;
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

void ordenarPorMasVendidos(paraOrdenarVentas arr[], int n) {
	paraOrdenarVentas aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].total < arr[j].total) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void ordenarPorMenosVendidos(paraOrdenarVentas arr[], int n) {
	paraOrdenarVentas aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].total > arr[j].total) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}


void gananciasTotales(Ordenes orden[][MAX_FACTURAS], float& montoFinalGanancias) {
    for (int i = 0; i <MAX_FACTURAS; i++) {
        for (int j = 0; j <MAX_FACTURAS; j++) {
            montoFinalGanancias += orden[i][j].monto;
        }
    }
}
void gastosTotales(){
	for(int i=0; i<MAX_ALIMENTOS; i++){
		montoFinalGastos += gastos[i].cantidadUsada*alimento[i].precio;
	}
}

void agregarMontoArreglo(){
	
	for(int i=0; i<numHamburguesas; i++){
		ordenarVentas[i].nombre = hamburguesas[i].nombre;
		ordenarVentas[i].total = hamburguesas[i].cantidadVendida*hamburguesas[i].precio;
		ordenarVentas[i].coste = costeHamburguesas;
	}
	for(int i=0; i<numPizzas; i++){
		ordenarVentas[numHamburguesas+i].nombre = pizzas[i].nombre;
		ordenarVentas[numHamburguesas+i].total = pizzas[i].cantidadVendida*pizzas[i].precio;
		ordenarVentas[numHamburguesas+i].coste = costePizzas;
	}
	for(int i=0; i<numConos; i++){
		ordenarVentas[numHamburguesas+numPizzas+i].nombre = conos[i].nombre;
		ordenarVentas[numHamburguesas+numPizzas+i].total = conos[i].cantidadVendida*conos[i].precio;
		ordenarVentas[numHamburguesas+numPizzas+i].coste = costeConos;
	}
	for(int i=0; i<numGaseosas; i++){
		ordenarVentas[numHamburguesas+numPizzas+numConos+i].nombre = gaseosas[i].nombre;
		ordenarVentas[numHamburguesas+numPizzas+numConos+i].total = gaseosas[i].cantidadVendida*gaseosas[i].precio;
		ordenarVentas[numHamburguesas+numPizzas+numConos+i].coste = costeGaseosas;
	}
	for(int i=0; i<numAguas; i++){
		ordenarVentas[numHamburguesas+numPizzas+numConos+numGaseosas+i].nombre = aguas[i].nombre;
		ordenarVentas[numHamburguesas+numPizzas+numConos+numGaseosas+i].total = aguas[i].cantidadVendida*aguas[i].precio;
	}
}

void generarRIG(paraOrdenarVentas arr[], int n){
	for(int i=0; i<n; i++){
		arr[i].RIG = arr[i].total / arr[i].coste;
	}
}
void ordenarPorRIG(paraOrdenarVentas arr[], int n){
	paraOrdenarVentas aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].RIG < arr[j].RIG) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void registrarVenta(){
	int categoria;
	int item;
	string nombre;
	int cantidad;
	string respuesta;
	
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
	            	ordenRegistro(orden[numFactura], hamburguesas, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					ordenesTotales++;
					ordenesPorFactura[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					gastos[0].cantidadUsada += CTH*cantidad;
					gastos[1].cantidadUsada += CLH*cantidad;
					gastos[2].cantidadUsada += CBH*cantidad;
					gastos[3].cantidadUsada += CCH*cantidad;
					gastos[6].cantidadUsada += CQH*cantidad;
					
					alimento[0].cantidad -= CTH*cantidad; // tomate
					alimento[1].cantidad -= CLH*cantidad; // lechuga
					alimento[2].cantidad -= CBH*cantidad; //harina
					alimento[3].cantidad -= CCH*cantidad; //carnes
					alimento[6].cantidad -= CQH*cantidad; // queso
					
					hamburguesas[item-1].cantidadVendida += cantidad;
					
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
	            	ordenRegistro(orden[numFactura], pizzas, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					ordenesTotales++;
					ordenesPorFactura[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					gastos[0].cantidadUsada += CTP*cantidad;
					gastos[2].cantidadUsada += CBP*cantidad;
					gastos[3].cantidadUsada += CCP*cantidad;
					gastos[6].cantidadUsada += CQP*cantidad;
					 
					alimento[0].cantidad -= CTP*cantidad;
					alimento[2].cantidad -= CBP*cantidad;
					alimento[3].cantidad -= CCP*cantidad;
					alimento[6].cantidad -= CQP*cantidad;
					
					pizzas[item-1].cantidadVendida += cantidad;
					
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
	            	ordenRegistro(orden[numFactura], conos, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					ordenesTotales++;
					ordenesPorFactura[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					gastos[0].cantidadUsada += CTC*cantidad;
					gastos[1].cantidadUsada += CLC*cantidad;
					gastos[2].cantidadUsada += CBC*cantidad;
					gastos[3].cantidadUsada += CCC*cantidad;
					gastos[6].cantidadUsada += CQC*cantidad;
					
					alimento[0].cantidad -= CTC*cantidad; // tomate
					alimento[1].cantidad -= CLC*cantidad; // lechuga
					alimento[2].cantidad -= CBC*cantidad; //harina
					alimento[3].cantidad -= CCC*cantidad; //carnes
					alimento[6].cantidad -= CQC*cantidad; // queso
					
					conos[item-1].cantidadVendida += cantidad;
					
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
	            	ordenRegistro(orden[numFactura], gaseosas, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					ordenesTotales++;
					ordenesPorFactura[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					gastos[4].cantidadUsada += CG*cantidad;
					
					alimento[4].cantidad -= CG*cantidad;
					
					gaseosas[item-1].cantidadVendida += cantidad;
					
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
	            	ordenRegistro(orden[numFactura], aguas, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
					ordenesTotales++;
					ordenesPorFactura[numFactura]++;
					continuar = true;
					//restando ingredientes usados
					gastos[5].cantidadUsada += CA*cantidad;
					
					alimento[5].cantidad -= CA*cantidad;
					
					aguas[item-1].cantidadVendida += cantidad;
					
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
	    	cout << "?Va a agregar algo mas a la orden?(si/no)= ";
	    	cin >> respuesta;
		}
	} while(respuesta!= "no" &&categoria!=6);
	
   cout << endl;
   cout << "FACTURA" << endl << endl;
   cout << "Productos en la orden: " << endl << endl;
   int j=0;
   for(int i=0; i<ordenesPorFactura[numFactura]; i++){
   		cout << j+1 << ". " << "(" << orden[numFactura][i].cantidad << ") " << orden[numFactura][i].nombre << " S/. " << orden[numFactura][i].monto << endl;
   		j++;
   }
   montoPorFactura(orden[numFactura], ordenesPorFactura[numFactura], montoDeFactura[numFactura]);
   cout << endl;
   cout << "Total a pagar: S/. " << montoDeFactura[numFactura] << endl;
   numFactura++;
}

void mostrarOrdenes(){
	cout << endl;
	cout << "MOSTRANDO FACTURAS REGISTRADAS" << endl << endl;
	for(int i=0; i<numFactura; i++){
		cout << i+1 << ". FACTURA" << endl << endl;
		cout << "Productos:" << endl << endl;
		for(int j=0; j<ordenesPorFactura[i]; j++){
			cout << "(" << orden[i][j].cantidad << ") " << orden[i][j].nombre << " S/. " << orden[i][j].monto << endl;
		}
		cout << endl;
		cout << "Monto final: S/. " << montoDeFactura[i] << endl << endl;
	}
	cout << endl;
}

void gastosGanancias(){
	cout << endl;
	char respuesta;
	bool valido = true;
	cout << "?Que quieres ver?" << endl << endl;
	cout << "-) Gastos." << endl;
	cout << "+) Ganancias." << endl << endl;
	do{
		cout << "= ";
		cin >> respuesta;
		cout << endl;
		switch(respuesta){
			case '-':
				cout << "Gastos consumidos hasta el momento (mayor a menor)" << endl << endl;
                ordenarGastos(gastos, MAX_ALIMENTOS);
                for(int i=0; i<MAX_ALIMENTOS; i++){
                	cout << gastos[i].nombre << " (" << gastos[i].cantidadUsada << "): S/." << -gastos[i].cantidadUsada*alimento[i].precio << endl;
				}
 				break;
			case '+':
				cout << "Ganancias por categoria" << endl << endl;
                cout << "HAMBURGUESAS" << endl << endl;
                for(int i=0; i<numHamburguesas; i++){
                	cout  << hamburguesas[i].nombre << ": S/. " << hamburguesas[i].cantidadVendida*hamburguesas[i].precio << endl;
				}
				cout << endl;
                cout << "PIZZAS" << endl << endl;
				for(int i=0; i<numPizzas; i++){
                	cout << pizzas[i].nombre << ": S/. " << pizzas[i].cantidadVendida*pizzas[i].precio << endl;
				}
				cout << endl;
                cout << "CONOS" << endl << endl;
				for(int i=0; i<numConos; i++){
                	cout << conos[i].nombre << ": S/. " << conos[i].cantidadVendida*conos[i].precio << endl;
				}
				cout << endl;
                cout << "GASEOSAS" << endl << endl;
				for(int i=0; i<numGaseosas; i++){
                	cout << gaseosas[i].nombre << ": S/. " << gaseosas[i].cantidadVendida*gaseosas[i].precio << endl;
				}
				cout << endl;
                cout << "AGUAS" << endl << endl;
				for(int i=0; i<numAguas; i++){
                	cout << aguas[i].nombre << ": S/. " << aguas[i].cantidadVendida*aguas[i].precio << endl;
				}
				cout << endl;
				gananciasTotales(orden, montoFinalGanancias);
				cout << "Ganancias totales: S/." << montoFinalGanancias << endl;
				break;
			default:
				cout << "Opcion no valida." << endl;
				valido = false;
				break;
		}
		cout << endl;
	} while(!valido);
}

void ordenarMasVendido(){
	cout << endl;
	char opcion;
	agregarMontoArreglo();
	cout << "ORDENAR POR GANANCIAS" << endl << endl;
	cout << "a) De mayor a menor." << endl;
	cout << "b) De menor a mayor." << endl << endl;
	cout << "= ";
	cin >> opcion;
	
	switch(opcion){
		case 'a':
			cout << "Ordenado de mayor a menor ganancias." << endl << endl;
			ordenarPorMasVendidos(ordenarVentas, totalComidas);
			break;
		case 'b':
			cout << "Ordenado de mayor a menor ganancias." << endl << endl;
			ordenarPorMenosVendidos(ordenarVentas, totalComidas);
			break;
		default:
			break;
	}
	
	for(int i=0; i<totalComidas; i++){
		cout << i+1 << ". " << ordenarVentas[i].nombre << ": S/. " << ordenarVentas[i].total << endl;
	}
}

void estadisticasGenerales(){
	gastosTotales();
	gananciasTotales(orden, montoFinalGanancias);
	generarRIG(ordenarVentas, totalComidas);
	cout << endl;
	string contrasenaJhonel="2024-119026";
	string contrasenaAlex="2024-119042";
	string contrasenaDante="2024-119039";
	string contrasena;
	char opcion;
	cout << "Indique la contrase?a" << endl << endl;
	cout << "= ";
	cin >> contrasena;
	cout << endl;
	
	float gananciaNeta = montoFinalGanancias - montoFinalGastos;
	float margenGananciaNeta = (gananciaNeta/montoFinalGanancias)*100;
	float ROI = (gananciaNeta/montoFinalGastos)*100;
	float RIG = (montoFinalGanancias/montoFinalGastos);
	float RIGcomidas;
	
	if(contrasena==contrasenaJhonel || contrasena==contrasenaAlex || contrasena==contrasenaDante ){
		if(contrasena==contrasenaJhonel){
			cout << "?Bienvenido Ingeniero Jhonel, revise como va su negocio!" << endl;
		} else if(contrasena==contrasenaAlex){
			cout << "?Bienvenido Ingeniero Alex, revise como va su negocio!" << endl;
		} else {
			cout << "?Bienvenido Ingeniero Dante, revise como va su negocio!" << endl;
		}
		do{
			cout << endl;
			for(int i=0; i<20; i++){
				cout << ordenarVentas[i].coste << endl;
			}
			cout << "ESTADISTICAS GENERALES DEL NEGOCIO" << endl << endl;
			cout << "a) Ingresos brutos." << endl;
			cout << "b) Egresos brutos." << endl;
			cout << "c) Ingresos netos." << endl;
			cout << "d) Ticket promedio de factura." << endl;
			cout << "e) Margen de Ganancia Neta." << endl;
			cout << "f) ROI (Retorno sobre la inversion)." << endl;
			cout << "g) RIG (Ratio de Ingresos sobre Gastos)." << endl;
			cout << "h) Mostrar comidas mas rentables." << endl;
			cout << "i) Ver todas las metricas juntas." << endl;
			cout << "j) Salir." << endl << endl;
			cout << "= ";
			cin >> opcion;
			cout << endl;
			switch(opcion){
				case 'a':
					cout << "Ingresos brutos (totales) del negocio." << endl;
					cout << "--> " << montoFinalGanancias << endl;
					break;
				case 'b':
					cout << "Egresos brutos (totales) del negocio." << endl;
					cout << "--> " << montoFinalGastos << endl;
					break;
				case 'c':
					cout << "Ingresos netos del negocio." << endl << endl;
					cout << "Ingresos totales: " << montoFinalGanancias << endl;
					cout << "Egresos totales: " << montoFinalGastos << endl;
					cout << "Ingresos netos: " << gananciaNeta << endl;
					break;
				case 'd':
					if(numFactura>0){
						cout << "Cuanto se gasta por factura: " << endl;
						cout << "= " << montoFinalGanancias/numFactura << endl;	
					}else{
						cout << "No hay facturas por analizar." << endl;
					}
					break;
				case 'e':
					cout << "El margen de ganancia neta del negocio es: " << endl;
					cout << "= " << margenGananciaNeta << "%" << endl;
					break;
				case 'f':
					cout << "El ROI de su negocio es: " << endl;
					cout << "= " << ROI << "%" << endl << endl;
					cout << "Eso quiere decir que por cada S/.1 gastado, usted esta ganando " << ROI << "% adicional, osea S/. " << 1+ROI/100 << endl;
					break;
				case 'g':
					cout << "El RIG de su negocio es: " << endl;
					cout << "= " << RIG << endl << endl;
					cout << "Eso quiere decir que por cada S/. 1 gastado, usted gana S/. " << RIG << endl;
					break;
				case 'h':
					ordenarPorRIG(ordenarVentas, totalComidas);
					cout << "Comidas mas rentables (basado en RIG)" << endl << endl;
					for(int i=0; i<totalComidas; i++){
						if(ordenarVentas[i].RIG == 1){
							color(hConsole, 6);
							cout << i+1 << ". " << ordenarVentas[i].nombre << "--> " << ordenarVentas[i].RIG << endl;
						} else if(ordenarVentas[i].RIG < 1){
							color(hConsole, 4);
							cout << i+1 << ". " << ordenarVentas[i].nombre << "--> " << ordenarVentas[i].RIG << endl;
						} else {
							color(hConsole, 10);
							cout << i+1 << ". " << ordenarVentas[i].nombre << "--> " << ordenarVentas[i].RIG << endl;
						}
					}
					color(hConsole, 7); 
					break;
				case 'i':
					break;
			}
			cout << endl;
		}while(opcion!='i');
	} else {
		cout << "Usuario invalido. No puede ingresar, lo siento." << endl;
	}
}
