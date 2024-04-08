#include "tad_repuesto.h"
#include "cadenas.h"
#include <stdio.h>
#include <string.h>

Repuesto obtenerRepuesto() {
	Repuesto ret;
	long int ldaux;
	float faux;
	cadena caux;
	
	printf("\nObteniendo datos de un repuesto...\n");
	
	do {
		printf("Ingrese el codigo: ");
		scanf("%ld", &ldaux);
	} while(ldaux < 0);
	ret.codigo = ldaux;
	
	do {
		printf("Ingrese el precio: ");
		scanf("%f", &faux);
	} while(faux < 0);
	ret.precio = faux;
	
	do {
		printf("Ingrese las unidades disponibles: ");
		scanf("%f", &faux);
	} while(faux < 0 || faux != (int)faux);
	ret.stock = (int)faux;
	
	do {
		printf("Ingrese el nombre del repuesto: ");
		leeCad(caux, 100);
	} while(strlen(caux) < 1);
	strcpy(ret.nombre, caux);
	
	return ret;
}

void mostrarRepuesto(Repuesto r) {
	printf("\nCodigo: %ld", r.codigo);
	printf("\nPrecio: $%.2f", r.precio);
	printf("\nUnidades: %d", r.stock);
	printf("\nNombre: %s", r.nombre);
}

void modificarPrecio(Repuesto* r) {
	float nuevoPrecio;
	printf("\nPrecio antiguo: $%.2f", r->precio);
	printf("\nIngrese un nuevo precio para el repuesto: ");
	scanf("%f", &nuevoPrecio);
	
	r->precio = nuevoPrecio;
	printf("\nPrecio actualizado satisfactoriamente.");
}

int stockDisponible(Repuesto r) {
	return r.stock;
}
