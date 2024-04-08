#ifndef TAD_ARTICULO_H
#define TAD_ARTICULO_H
#include "TAD_CADENAS.h"

typedef struct {
	long int codigo;
	int precio;
	cadena descripcion;
} Articulo;

typedef struct {
	long int codigo;
	int cantidad;
} ArticuloComprado;

Articulo crearArticulo();
void mostrarArticulo(Articulo);

#endif
