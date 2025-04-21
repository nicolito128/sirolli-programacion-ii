#ifndef ARTICULO_H
#define ARTICULO_H
#include "cadena.h"

typedef struct {
	cadena nombre;
	cadena proveedor;
	unsigned int codigo;
	unsigned int stock;
	float precio;
} Articulo;

// Cabeceras para obtener datos individuales de un articulo cualquiera.
void articulo_pedir_nombre(cadena s);
void articulo_pedir_proveedor(cadena s);
unsigned int articulo_pedir_codigo();
unsigned int articulo_pedir_stock();
float articulo_pedir_precio();

// Ingresar un nuevo Articulo completo desde consola.
Articulo articulo_ingresar();

// Muestra los datos del articulo por consola.
void articulo_mostrar(Articulo item);

#endif
