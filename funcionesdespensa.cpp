#include "funcionesdespensa.h"
#include "funcionesfinanzas.h"
using namespace std;

Alimentos alimento[MAX_ALIMENTOS] = {
    {"Tomates", 40, 0.2}, // 0
    {"Lechugas", 5, 1}, // 1
    {"Bolsas de harina", 20, 3.5}, // 2
    {"Carnes", 20, 9}, // 3
    {"Litros de gaseosa", 20, 4}, //4
    {"Litros de agua", 20, 2.5}, //5
    {"Queso", 10, 15}
};

void AgregarAlimentos(){
	float c;
	int opcion;
	float minimoAlmacen = 0;
	int n=0;
	int aux=0;
	if (minimoAlmacen != limiteAlmacen){
		cout << "\t\t\t\t\t\t\t\t\t\tAGREGAR ALIMENTOS" << endl << endl;
		cout << "\t\t\t\t\t\t\t\tLista de alimentos para el negocio" << endl << endl;
		
		for(int i=0; i<MAX_ALIMENTOS; i++){
			cout << i+1 << ". " << alimento[i].nombre << "(" << alimento[i].cantidad << ")." << endl;
		}
		cout << endl;
		
        while (true) {
            cout << "\t\t\t\t\t\t\t\t\t\tIndique: ";
            cin >> opcion;
			cout << endl;
            if(opcion<=6 && opcion>0){
	            cout << "\t\t\t\t\t\t\t\tAgregando '" << alimento[opcion-1].nombre << "'..." << endl << endl;
	            while(c<=0){
	            	cout << "\t\t\t\t\t\t\t\tCantidad: ";
		            cin >> c;
		            cout << endl;
		            if(c>0){
		            	alimento[opcion-1].cantidad += c;
		            	cout << "\t\t\t\t\t\tSe agregaron " << c << " '" << alimento[opcion-1].nombre << "' a la despensa." << endl << endl;
		            	break;
		            }else {
		            	cout << "\t\t\t\t\t\t\t\t\t\tIngrese una cantidad valida." << endl << endl;
					}
				}
	            break;
            } else {
                cout << "\t\t\t\t\t\t\t\t\t\tOpcion no valida." << endl << endl;
            }
        }
    } else {
        cout << "\t\t\t\t\t\t\t\t\t\tLimite maximo de alimentos." << endl << endl;
    }
    cout << endl;
}

void actualizarAlimentos(){
	int opcion;

	cout << "\t\t\t\t\t\t\t\t\t\t\tACTUALIZAR ALIMENTOS" << endl << endl;
	for(int i=0; i<MAX_ALIMENTOS; i++){
		cout << i+1 << ". " << alimento[i].nombre << endl << endl;
		cout << "\t\t\t\t\t\t\t\tUnidades disponibles: " << alimento[i].cantidad << endl;
		cout << "\t\t\t\t\t\t\t\tPrecio unitario: " << alimento[i].precio << endl << endl;
	}
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t\tIndique: ";
	cin >> opcion;
	cout << endl;
	
	cout << "\t\t\t\t\t\t\t\t\t\tActualizando datos de '" << alimento[opcion-1].nombre << "'..." << endl << endl;
	cout << "\t\t\t\t\t\t\t\tUnidades disponibles: ";
	cin >> alimento[opcion-1].cantidad;
	cout << "\t\t\t\t\t\t\t\tPrecio unitario: ";
	cin >> alimento[opcion-1].precio;
	cout << "\t\t\t\t\t\t\t\tSe actualizo '" << alimento[opcion-1].nombre << "' con exito." << endl << endl;
}

void mostrarStock(){
	
	cout << "\t\t\t\t\t\t\t\t\t\t\tSTOCK DE LOS ALIMENTOS" << endl << endl;
	Alimentos copia[MAX_ALIMENTOS];
	for(int i=0; i<MAX_ALIMENTOS; i++){
		copia[i] = alimento[i];
	}
	
	Alimentos mayor;
	for(int i=0; i<MAX_ALIMENTOS-1; i++){
		for(int j=0; j<MAX_ALIMENTOS-1-i; j++){
			if (copia[j].cantidad < copia[j + 1].cantidad) { 
				mayor = copia[j];
				copia[j] = copia[j+1];
				copia[j+1] = mayor;
			}
		}
	}
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t(Ordenados de mayor a menor)" << endl << endl;
	for(int i=0; i<MAX_ALIMENTOS; i++){
		cout << "(" << copia[i].cantidad << ") " << copia[i].nombre << "." << endl;
	}
}


void ordenarPorMasUsados(GastoAlimento arr[], int n) {
	GastoAlimento aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].cantidadUsada < arr[j].cantidadUsada) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void ordenarPorMenosUsados(GastoAlimento arr[], int n) {
    GastoAlimento aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].cantidadUsada > arr[j].cantidadUsada) {
                // Intercambiar productos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void mostrarMasMenosUsados(){
	
	/*
	struct GastoAlimento {
    string nombre;
    float gastos;
    float cantidadUsada;
	};	
	*/
	cout << endl;
	char opcion;
	cout << "\t\t\t\t\t\t\t\t\t\tORDENAR ALIMENTOS USADOS" << endl << endl;
	do{
		cout << "\t\t\t\t\t\t\t\ta) De mayor a menor." << endl;
		cout << "\t\t\t\t\t\t\t\tb) De menor a mayor." << endl << endl;
		cout << "= ";
		cin >> opcion;
		cout << endl;
		switch(opcion){
			case 'a':
				cout << "\t\t\t\t\t\t\t\tOrdenado de mayor a menor uso." << endl << endl;
				ordenarPorMasUsados(gastos, MAX_ALIMENTOS);
				break;
			case 'b':
				cout << "\t\t\t\t\t\t\t\tOrdenado de menor a mayor uso." << endl << endl;
				ordenarPorMenosUsados(gastos, MAX_ALIMENTOS);
				break;
			default:
				cout << "\t\t\t\t\t\t\t\tOpcion no valida. Intente de nuevo." << endl << endl;
				break;
		}
	}while(opcion!='a'&& opcion!='b');

		for(int i=0; i<MAX_ALIMENTOS; i++){
			cout << i+1 << ". " << " (" << gastos[i].cantidadUsada << ")" << gastos[i].nombre << endl;
		}
	cout << endl;
}

