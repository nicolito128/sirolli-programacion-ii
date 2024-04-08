#ifndef LISTA_REPUESTOS_H
#define LISTA_REPUESTOS_H
#include "tad_repuesto.h"
#define tamRepuestos 100

// Tipos y estructuras
typedef Repuesto VRepuestos[tamRepuestos];

typedef struct {
	VRepuestos vec;
	int tam;
} ListaRepuestos;

// Prototipos
void cargarLista(ListaRepuestos*, int);
void mostrarListaRepuestos(ListaRepuestos);
void mostrarRepuestoPorCodigo(ListaRepuestos);
void modificarPrecioListaRepuesto(ListaRepuestos*);
void mostrarRepuestosSinStock(ListaRepuestos);

#endif
