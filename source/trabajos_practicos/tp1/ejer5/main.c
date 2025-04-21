#include <stdio.h>
#include "lista_clientes.h"
#include "cliente.h"
#include "cadena.h"
#include "fecha.h"
#include <stdlib.h>

void menu();
TClientes opcion_acreditar(TClientes lista);
TClientes opcion_transferir(TClientes lista);
void opcion_mostrar_operaciones(TClientes lista);

int main(void) {
	menu();
	return 0;
}

void menu() {
	int opcion;
	float aux;
	TClientes lista = clientes_inicializar();
	do {
		printf("\n----- Menu del Ejercicio 5: Clientes de un banco -----");
		printf("\n[ 0 ] Salir.");
		printf("\n[ 1 ] Actualizar saldo por Acreditación.");
		printf("\n[ 2 ] Actualizar saldo por Transferencia.");
		printf("\n[ 3 ] Mostrar lista de Operaciones.");
		printf("\n[ 4 ] Mostrar lista de Deudores.");
		printf("\nSeleccione una opcion > ");
		scanf("%f", &aux);
		limpiar_buffer();
		opcion = (int)(aux);
		
		switch (opcion) {
		case 1:
			lista = opcion_acreditar(lista);
			break;
		case 2:
			lista = opcion_transferir(lista);
			break;
		case 3:
			opcion_mostrar_operaciones(lista);
			break;
		case 4:
			clientes_mostrar_deudores(lista);
			break;
		}
	} while(opcion != 0);
	printf("\nSaliendo del programa. Ciao!");
}

TClientes opcion_acreditar(TClientes lista) {
	Cliente c;
	cadena aux;
	float cantidad;
	int pos_cliente;
	
	do {
		c.dni = cliente_pedir_dni();
		pos_cliente = clientes_pertenece(lista, c.dni);
		if (pos_cliente == -1) {
			printf("\n! El DNI ingresado no pertenece a ningun cliente. Intente de nuevo.");
		}
	} while(clientes_pertenece(lista, c.dni) == -1);
	c = lista.arr[pos_cliente];
	
	do {
		printf("\n- Ingrese una cantidad para acreditar > ");
		cadena_ingresar(aux);
		if (!cadena_es_num_real(aux)) {
			printf("\n! La cantidad ingresada no es un numero valido.");
		}
	} while(!cadena_es_num_real(aux));
	cantidad = (float)(atof(aux));
	
	lista.arr[pos_cliente] = cliente_acreditar(c, cantidad);
	return lista;
}

TClientes opcion_transferir(TClientes lista) {
	Cliente c;
	cadena aux;
	float cantidad;
	int pos_cliente;
	
	do {
		c.dni = cliente_pedir_dni();
		pos_cliente = clientes_pertenece(lista, c.dni);
		if (pos_cliente == -1) {
			printf("\n! El DNI ingresado no pertenece a ningun cliente. Intente de nuevo.");
		}
	} while(clientes_pertenece(lista, c.dni) == -1);
	c = lista.arr[pos_cliente];
	
	do {
		printf("\n- Ingrese una cantidad para transferir > ");
		cadena_ingresar(aux);
		if (!cadena_es_num_real(aux)) {
			printf("\n! La cantidad ingresada no es un numero valido.");
		}
	} while(!cadena_es_num_real(aux));
	cantidad = (float)(atof(aux));
	
	lista.arr[pos_cliente] = cliente_transferencia(c, cantidad);
	return lista;
}

void opcion_mostrar_operaciones(TClientes lista) {
	Fecha f = cliente_pedir_operacion();
	clientes_mostrar_por_fecha(lista, f);
}
