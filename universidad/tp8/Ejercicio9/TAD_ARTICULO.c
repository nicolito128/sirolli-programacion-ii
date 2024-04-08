#include "TAD_ARTICULO.h"
#include "TAD_CADENAS.h"
#include <stdio.h>

Articulo crearArticulo() {
	Articulo aux;
	
	printf("\nCargando un Articulo\n");
	printf("Ingrese el codigo del articulo: ");
	scanf("%ld", &aux.codigo);
	
	printf("Ingrese la descripcion del articulo: ");
	leeCad(aux.descripcion, 100);
	
	printf("Ingrese el precio del articulo: ");
	scanf("%d", &aux.precio);
	
	return aux;
}

void mostrarArticulo(Articulo art) {
	printf("\nCodigo: %ld", art.codigo);
	printf("\nDescripcion: %s", art.descripcion);
	printf("\nPrecio: $%d", art.precio);
}
