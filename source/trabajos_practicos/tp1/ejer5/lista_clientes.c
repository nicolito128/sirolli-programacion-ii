#include "lista_clientes.h"
#include "cliente.h"
#include "cadena.h"
#include "fecha.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

TClientes ordenar_por_dni(TClientes lista);
TClientes ordenar_por_apellido_nombre(TClientes lista);
TClientes ordenar_por_saldo(TClientes lista);

TClientes clientes_inicializar() {
	TClientes lista = {0};
	lista.tam = 0;
	
	Cliente aux;
	
	char opcion;
	int existe;
	do {
		printf("\n- ¿Quiere cargar un nuevo cliente? Escriba su elección [ S/n ] > ");
		scanf("%c", &opcion);
		limpiar_buffer();
		opcion = tolower(opcion);
		if (opcion == 's') {
			printf("\n~ Cargando el cliente #%d ~", lista.tam+1);
			aux.dni = cliente_pedir_dni();
			
			existe = clientes_pertenece(lista, aux.dni);
			if (existe == -1) {
				cliente_pedir_apellido(aux.apellido);
				cliente_pedir_nombre(aux.nombre);
				aux.saldo = cliente_pedir_saldo_inicial();
				aux.operacion = cliente_pedir_operacion();
				
				lista.arr[lista.tam] = aux;
				lista.tam += 1;
			} else {
				printf("\n! El cliente que trata de cargar ya existe.");
			}
		} else {
			if (opcion != 'n') {
				printf("\n! Eleccion no valida. Limitece a las opciones \"s\" (si) o \"n\" (no).");
			}
		}
	} while(opcion != 'n');
	lista = ordenar_por_dni(lista);
	return lista;
}

// Como la lista de clientes se encuentra ordenada
// podemos usar busqueda binaria.
int clientes_pertenece(TClientes lista, unsigned int dni) {
	if (lista.tam == 0) {
		return -1;
	}
	int ini = 0;
	int fin = lista.tam - 1;
	int mid = (ini + fin) / 2;
	while (ini <= fin && lista.arr[mid].dni != dni) {
		if (lista.arr[mid].dni < dni) {
			ini = mid + 1;
		} else {
			fin = mid - 1;
		}
		mid = (ini + fin) / 2;
	}
	if (ini > fin) {
		return  -1;
	}
	return mid;
}

void clientes_mostrar(TClientes lista) {
	if (lista.tam == 0) {
		printf("\nNo hay clientes ha mostrar.");
	} else {
		for (int i = 0; i < lista.tam; i++) {
			printf("\n-------------------------");
			cliente_mostrar(lista.arr[i]);
			printf("\n-------------------------");
		}
	}
}

void clientes_mostrar_por_fecha(TClientes lista, Fecha op) {
	TClientes vec;
	vec.tam = 0;
	int b = 0;
	// Filtramos por fecha.
	for (int i = 0; i< lista.tam; i++) {
		if (fecha_comparar(lista.arr[i].operacion, op) == 0) {
			vec.arr[vec.tam] = lista.arr[i];
			vec.tam += 1;
			b = 1;
		}
	}
	// Ordenamos por apellido y nombre.
	vec = ordenar_por_apellido_nombre(vec);
	
	if (b == 1) {
		printf("\n--- Clientes por fecha, apellido, y nombre ---");
		clientes_mostrar(vec);
	} else {
		printf("\nNo hay clientes ha mostrar para esta operacion.");
	}
}

void clientes_mostrar_deudores(TClientes lista) {
	TClientes deudores;
	deudores.tam = 0;
	int b = 0;
	// Filtramos por deudores (saldo < 0).
	for (int i = 0; i< lista.tam; i++) {
		if (lista.arr[i].saldo < 0) {
			deudores.arr[deudores.tam] = lista.arr[i];
			deudores.tam += 1;
			b = 1;
		}
	}
	// Ordenamos por el saldo de menor a mayor.
	deudores = ordenar_por_saldo(deudores);
	
	if (b == 1) {
		printf("\n--- Deudores ---");
		clientes_mostrar(deudores);
	} else {
		printf("\nNo hay deudores ha mostrar.");
	}
}

TClientes ordenar_por_dni(TClientes lista) {
	Cliente aux;
	int i, j;
	for (i = 0; i < (lista.tam - 1); i++) {
		for (j = 0; j < (lista.tam - i - 1); j++) {
			if (lista.arr[j].dni > lista.arr[j + 1].dni) {
				// swap de variables
				// copiamos en `aux` el valor de la posicion que "pisaremos"
				aux = lista.arr[j + 1];
				lista.arr[j + 1] = lista.arr[j];
				lista.arr[j] = aux;
			}
		}
	}
	return lista;
}

TClientes ordenar_por_apellido_nombre(TClientes lista) {
	Cliente aux;
	cadena nom1, nom2;
	int i, j;
	for (i = 0; i < (lista.tam - 1); i++) {
		for (j = 0; j < (lista.tam - i - 1); j++) {
			// Obtenemos los nombres completos de cada uno.
			cliente_nombre_completo(lista.arr[j], nom1);
			cliente_nombre_completo(lista.arr[j + 1], nom2);
			// Comparamos.
			if (strcmp(nom1, nom2) >= 0) {
				aux = lista.arr[j + 1];
				lista.arr[j + 1] = lista.arr[j];
				lista.arr[j] = aux;
			}
		}
	}
	return lista;
}

TClientes ordenar_por_saldo(TClientes lista) {
	Cliente aux;
	int i, j;
	for (i = 0; i < (lista.tam - 1); i++) {
		for (j = 0; j < (lista.tam - i - 1); j++) {
			if (lista.arr[j].saldo > lista.arr[j + 1].saldo) {
				aux = lista.arr[j + 1];
				lista.arr[j + 1] = lista.arr[j];
				lista.arr[j] = aux;
			}
		}
	}
	return lista;
}

