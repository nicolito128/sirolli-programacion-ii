#ifndef TAD_LISTA_ARTICULOS_H
#define TAD_LISTA_ARTICULOS_H
#include "TAD_ARTICULO.h"
#define tamLista 100

typedef Articulo ListaArticulos[tamLista];
typedef ArticuloComprado ListaArticulosComprados[tamLista];

typedef struct {
	int tam;
	ListaArticulos vec;
} TLista;

typedef struct {
	int tam;
	ListaArticulosComprados vec;
} TListaComprados;

void cargarArticulos(TLista*, int);
void mostrarLista(TLista);
void mergesort(ListaArticulos, int, int);

#endif
