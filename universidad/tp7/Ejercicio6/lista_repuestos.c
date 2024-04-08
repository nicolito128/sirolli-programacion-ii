#include "tad_repuesto.h"
#include "lista_repuestos.h"
#include <stdio.h>

// Prototipos privados
void agregarRepuesto(ListaRepuestos*, Repuesto);
void mostrarCodigos(ListaRepuestos);
int buscarRepuesto(ListaRepuestos, long int);

// Implementaciones privadas
void agregarRepuesto(ListaRepuestos* lista, Repuesto r) {
	int j;
	
	lista->vec[0] = r;
	j = lista->tam;
	while(lista->vec[j].codigo > r.codigo) {
		lista->vec[j+1] = lista->vec[j];
		j--;
	}
	
	lista->vec[j+1] = r;
	lista->tam += 1;
}

int buscarRepuesto(ListaRepuestos lista, long int codigo) {
	int ini, fin, mid;
	ini = 1;
	fin = lista.tam;
	mid = (ini + fin) / 2;
	
	while(ini <= fin && lista.vec[mid].codigo != codigo) {
		if (codigo > lista.vec[mid].codigo) {
			ini = mid + 1;
		} else {
			fin = mid - 1;
		}
		
		mid = (ini + fin) / 2;
	}
	
	if (ini > fin) {
		return 0;
	}
	
	return mid;
}

void mostrarCodigos(ListaRepuestos lista) {
	int i;
	for (i = 1; i <= lista.tam; i++) {
		printf("\n%d) %ld", i, lista.vec[i].codigo);
	}
}

// Implementaciones publicas
void cargarLista(ListaRepuestos* lista, int iter) {
	int i, pos;
	Repuesto r;
	
	for(i = 1; i <= iter; i++) {
		r = obtenerRepuesto();
		pos = buscarRepuesto(*lista, r.codigo);
		
		if (pos == 0) {
			agregarRepuesto(lista, r);
		} else {
			printf("\nEl repuesto ya existia en la base de datos.");
		}
	}
}

void mostrarListaRepuestos(ListaRepuestos lista) {
	int i;
	
	for (i = 1; i <= lista.tam; i++) {
		printf("\n(%d)", i);
		mostrarRepuesto(lista.vec[i]);
	}
}

void mostrarRepuestoPorCodigo(ListaRepuestos lista) {
	long int ldaux;
	int pos;
	
	printf("Ingrese el codigo de algun repuesto a mostrar: ");
	mostrarCodigos(lista);
	printf("\n>");
	scanf("%ld", &ldaux);
	
	pos = buscarRepuesto(lista, ldaux);
	if (pos != 0) {
		mostrarRepuesto(lista.vec[pos]);
	} else {
		printf("No se encontro ningun repuesto con ese codigo.");
	}
}

void modificarPrecioListaRepuesto(ListaRepuestos* lista) {
	long int ldaux;
	int pos;
	
	printf("Ingrese el codigo de algun repuesto a modificar: ");
	mostrarCodigos(*lista);
	printf("\n>");
	scanf("%ld", &ldaux);
	
	pos = buscarRepuesto(*lista, ldaux);
	if (pos != 0) {
		modificarPrecio(&(lista->vec[pos]));
	} else {
		printf("\nNo se encontro ningun repuesto con ese codigo.");
	}
}

void mostrarRepuestosSinStock(ListaRepuestos lista) {
	int i, b;
	b = 0;
	
	for (i = 1; i <= lista.tam; i++) {
		if (lista.vec[i].stock == 0) {
			mostrarRepuesto(lista.vec[i]);
			b = 1;
		}
	}
	
	if (b == 0) {
		printf("\nNo se encontraron repuestos sin stock.");
	}
}
