#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H
#define CAP_CLIENTES 100
#include "cliente.h"

typedef struct {
	Cliente arr[CAP_CLIENTES];
	int tam;
} TClientes;

// Carga una cantidad no conocida de clientes por consola.
TClientes clientes_inicializar();

// Determina si un cliente pertenece o no a la lista.
// Si el dni pertenece a la lista, devuelve la posición, caso contrario retorna -1.
int clientes_pertenece(TClientes lista, unsigned int dni);

void clientes_mostrar(TClientes lista);

void clientes_mostrar_por_fecha(TClientes lista, Fecha op);

void clientes_mostrar_deudores(TClientes lista);

#endif
