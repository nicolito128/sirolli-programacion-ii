#ifndef LISTA_ARTICULOS_H
#define LISTA_ARTICULOS_H
#define CAP_ARTICULOS 100
#include "articulo.h"
#include "cadena.h"

typedef struct {
	Articulo elementos[CAP_ARTICULOS];
	int tam;
} ListaArticulos;

// Inicializa la lista de articulos con "n" elementos cargados por el usuario.
ListaArticulos lista_articulos_inicializar(int n);

// Agrega un nuevo artículo a la lista.
ListaArticulos lista_articulos_agregar(ListaArticulos lista, Articulo item);

// Elimina un articulo de la lista sabiendo su posicion.
ListaArticulos lista_articulos_eliminar(ListaArticulos lista, int pos);

// Si el articulo existe, devuelve su posición en la lista.
// Caso contrario, devuelve -1.
int lista_articulos_pertenece(ListaArticulos lista, unsigned int codigo);

void lista_articulos_mostrar(ListaArticulos lista);

void lista_articulos_mostrar_por_proveedor(ListaArticulos lista, cadena proveedor);

void lista_articulos_mostrar_por_stock(ListaArticulos lista, unsigned int stock);

#endif
