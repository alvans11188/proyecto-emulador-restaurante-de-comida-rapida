#include <iostream>
#include "funcionescliente.h"
using namespace std;

//FUNCION PARA AGREGAR CLIENTES
void agregarCliente(Cliente clientes[50], int &cantidadActualClientes) {
	cantidadActualClientes++;
	cout << "// AGREGAR CLIENTE //" << endl;
	cout << "Nombre del cliente: ";
	cin.ignore(); //LIMPIAR EL BUFFER POR EL SALTO DE LINEA
	getline(cin, clientes[cantidadActualClientes].nombre);
	cout << "Numero del cliente: ";
	cin >> clientes[cantidadActualClientes].telefono;
	
	cout << "// Direccion del cliente // " << endl;
	cout << "Distrito: ";
	cin.ignore(); //LIMPIAR EL BUFFER POR EL SALTO DE LINEA
	getline(cin, clientes[cantidadActualClientes].direccionCliente.distrito);
	cout << "Calle: ";
	getline(cin, clientes[cantidadActualClientes].direccionCliente.calle);
	cout << "Manzana: ";
	getline(cin, clientes[cantidadActualClientes].direccionCliente.manzana);
	cout << "Lote: ";
	getline(cin, clientes[cantidadActualClientes].direccionCliente.lote);
	cout << "// USUARIO AGREGADO CORRECTAMENTE //" << endl;
}

//FUNCION PARA EDITAR DATOS DEL CLIENTES
void editarDatosCliente(Cliente clientes[50], int &cantidadActualClientes) {
	int clienteEditar; //POSICION DE MEMORIA QUE LUEGO SERA EL CLIENTE QUE SE VA A EDITAR
	cout << "// EDITAR CLIENTE //" << endl;
	
	do { //DO WHILE PARA REPETIR EN TAL CASO EL USUARIO INGRESE NUMEROS QUE NO ESTEN ENTRE 1 Y 20
		cout << "Ingrese la posicion del usuario que desea editar (1 - " << cantidadActualClientes + 1 << "): ";
		cin >> clienteEditar;
		if ( clienteEditar >= 1 && clienteEditar <= cantidadActualClientes + 1 ) {
			cout << "// POSICION VALIDA //" << endl;
		} else {
			cout << "// ERROR: VALOR INCORRECTO //" << endl;
		}
	} while ( clienteEditar < 1 || clienteEditar > cantidadActualClientes + 1);
	
	clienteEditar--; //SE REDUCE EN 1 PARA QUE SEA LA POSICION CORRECTA, YA QUE SE CUENTA LA POSICION 0
	
	cout << "// DATOS DEL CLIENTE A EDITAR //" << endl;
	cout << "Nombre del cliente: ";
	cin.ignore(); //LIMPIAR EL BUFFER POR EL SALTO DE LINEA
	getline(cin, clientes[clienteEditar].nombre);
	cout << "Numero del cliente: ";
	cin >> clientes[clienteEditar].telefono;
	
	cout << "// Direccion del cliente // " << endl;
	cout << "Distrito: ";
	cin.ignore(); //LIMPIAR EL BUFFER POR EL SALTO DE LINEA
	getline(cin, clientes[clienteEditar].direccionCliente.distrito);
	cout << "Calle: ";
	getline(cin, clientes[clienteEditar].direccionCliente.calle);
	cout << "Manzana: ";
	getline(cin, clientes[clienteEditar].direccionCliente.manzana);
	cout << "Lote: ";
	getline(cin, clientes[clienteEditar].direccionCliente.lote);
	cout << "// USUARIO AGREGADO CORRECTAMENTE //" << endl;
}

//FUNCION PARA ORDENAR LOS CLIENTES ALFABETICAMENTE
void ordenarClientesAlfabeticamente(Cliente clientes[50], int &cantidadActualClientes) {
	//AUXILIARES PARA CADA DATO DEL CLIENTE QUE SE VA A ORDENAR
	string auxiliar1, auxiliar2, auxiliar3, auxiliar4, auxiliar5, auxiliar6;
	//BUCLE FOR PARA ORDENAR DE LA A-Z
	for ( int i = 0; i <= cantidadActualClientes; i++ ) {
		for ( int j = i + 1; j <= cantidadActualClientes; j++ ) {
			if ( clientes[i].nombre > clientes[j].nombre ) {
				//GUARDANDO TODOS LOS DATOS DEL CLIENTE EN LOS AUXILIARES
				auxiliar1 = clientes[i].nombre;
				auxiliar2 = clientes[i].telefono;
				auxiliar3 = clientes[i].direccionCliente.distrito;
				auxiliar4 = clientes[i].direccionCliente.calle;
				auxiliar5 = clientes[i].direccionCliente.manzana;
				auxiliar6 = clientes[i].direccionCliente.lote;
				
				//REEMPLAZAMOS LOS DATOS DEL CLIENTE "i" POR LOS DATOS DEL CLIENTE "j"
				clientes[i].nombre = clientes[j].nombre;
				clientes[i].telefono = clientes[j].telefono;
				clientes[i].direccionCliente.distrito = clientes[j].direccionCliente.distrito;
				clientes[i].direccionCliente.calle = clientes[j].direccionCliente.calle;
				clientes[i].direccionCliente.manzana = clientes[j].direccionCliente.manzana;
				clientes[i].direccionCliente.lote = clientes[j].direccionCliente.lote;
				
				//REEMPLAZAMOS LOS DATOS DEL CLIENTE "j" POR LOS QUE ALMACENAMOS EN LOS AUXILIARES
				clientes[j].nombre = auxiliar1; 
				clientes[j].telefono = auxiliar2;
				clientes[j].direccionCliente.distrito = auxiliar3;
				clientes[j].direccionCliente.calle = auxiliar4;
				clientes[j].direccionCliente.manzana = auxiliar5;
				clientes[j].direccionCliente.lote = auxiliar6;
			}
		}
	}
	
	//BUCLE PARA MOSTRAR LOS CLIENTES ORDENADOS Y SUS DATOS
	cout << "// CLIENTES ORDENADOS ALFABETICAMENTE //" << endl;
	
	for ( int i = 0; i <= cantidadActualClientes; i++ ) {
		cout << "Cliente Nro " << i + 1 << ":" << endl;
		cout << "Nombre: " << clientes[i].nombre << endl;
		cout << "Telefono: " << clientes[i].telefono << endl;
		
		cout << "// DIRECCION DEL CLIENTE // " << endl;
		cout << "Distrito: " << clientes[i].direccionCliente.distrito << endl;
		cout << "Calle: " << clientes[i].direccionCliente.calle << endl;
		cout << "Manzana: " << clientes[i].direccionCliente.manzana << endl;
		cout << "Lote: " << clientes[i].direccionCliente.lote << endl << endl;
	}
}

//FUNCION PARA ELIMINAR CLIENTES
void eliminarClientes(Cliente clientes[50], int &cantidadActualClientes) {
	//POSICION QUE EL USUARIO VA A ELIMINAR
	int posicionEliminar;
	cout << "// ELIMINAR CLIENTE //" << endl;
	cout << "Eliga que cliente desea eliminar (1 - " << cantidadActualClientes + 1 << "): "; //SE SUMA MÁS UNO PORQUE EL 0 CUENTA COMO UNA POSICIÓN DE UN CLIENTE
	cin >> posicionEliminar;
	
	//VERIFICAR QUE LA POSICIÓN ESTÁ DENTRO DEL RANGO
	if ( posicionEliminar >= 1 && posicionEliminar <= cantidadActualClientes + 1 ) {
		//BUCLE FOR PARA SUSTITUIR LA POSICION ELIMINADA
		for ( int i = posicionEliminar - 1; i < cantidadActualClientes - 1; i++ ) { //SE LE RESTA 1 A "POSICIONELIMINAR" PARA QUE ENCAJE CON LA POSICIÓN ESCOGIDA, PORQUE COMO EL 0 CUENTA COMO POSICIÓN DE MEMORIA, EL 0 CUENTA Y SI EL USUARIO ESCOGE 1, SE REFIERE A LA POSICIÓN 0
			clientes[i].nombre = clientes[i + 1].nombre;
			clientes[i].telefono = clientes[i + 1].telefono;
			clientes[i].direccionCliente.distrito = clientes[i + 1].direccionCliente.distrito;
			clientes[i].direccionCliente.calle = clientes[i + 1].direccionCliente.calle;
			clientes[i].direccionCliente.manzana = clientes[i + 1].direccionCliente.manzana;
			clientes[i].direccionCliente.lote = clientes[i + 1].direccionCliente.lote;
		}
		cantidadActualClientes--; //SE LE RESTA UNO PORQUE SE ELIMINO UN CLIENTE Y LA CANTIDAD ACTUAL SE REDUCE
		cout << "// CLIENTE ELIMINADO CORRECTAMENTE // " << endl << endl;
	} else {
		cout << "Ingreso un número inválido" << endl << endl;
	}
}
