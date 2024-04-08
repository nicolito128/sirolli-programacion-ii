#include "TAD_LISTA_ARTICULOS.h"
#include <stdio.h>

void merge(ListaArticulos, int, int, int);
void insertarArticulo(TLista*, Articulo);
int buscarArticulo(TLista, long int);

// Implementaciones publicas
void cargarArticulos(TLista* lista, int N) {
	Articulo aux;
	if (N <= 0) return;
	
	aux = crearArticulo();
	insertarArticulo(lista, aux);
	cargarArticulos(lista, N - 1);
}

void mostrarLista(TLista lista) {
	TLista aux = lista;
	if (lista.tam <= 0) return;
	aux.tam -= 1;
	mostrarLista(aux);
	printf("\n");
	mostrarArticulo(lista.vec[lista.tam]);
}

void mergesort(ListaArticulos lista, int ini, int fin) {
	int mid;
	if (ini < fin) {
		mid = (ini + fin) / 2;
		mergesort(lista, ini, mid);
		mergesort(lista, mid+1, fin);
		merge(lista, ini, mid, fin);
	}
}

// Implementaciones privadas
void merge(ListaArticulos lista, int ini, int mid, int fin) {
	int i, j, k, t;
	ListaArticulos aux;
	k = 0;
	i = ini;
	j = mid + 1;
	
	while(i <= mid && j <= fin) {
		k++;
		
		if(lista[i].codigo < lista[j].codigo) {
			aux[k] = lista[i];
			i++;
		} else {
			aux[k] = lista[j];
			j++;
		}
	}
	
	for(t = i; t <= mid; t++) {
		k++;
		aux[k] = lista[t];
	}
	
	for(t = j; t <= fin; t++) {
		k++;
		aux[k] = lista[t];
	}
	
	for(t = 1; t <= k; t++) {
		lista[ini+t-1] = aux[t];
	}
}

void insertarArticulo(TLista* lista, Articulo art) {
	lista->tam += 1;
	lista->vec[lista->tam] = art;
}

int buscarArticulo(TLista lista, long int codigo) {
	int ini = 1, fin = lista.tam;
	int mid = (ini + fin) / 2;
	
	while(ini <= fin && lista.vec[mid].codigo != codigo) {
		if (lista.vec[mid].codigo < codigo) {
			ini = mid + 1;
		} else {
			fin = mid - 1;
		}
		
		mid = (ini + fin) / 2;
	}
	
	if (ini <= fin) {
		return mid;
	}
	
	return 0;
}
