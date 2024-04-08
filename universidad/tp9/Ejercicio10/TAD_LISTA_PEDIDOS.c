#include "TAD_LISTA_PEDIDOS.h"
#include "TAD_PEDIDO.h"
#include "TAD_FECHA.h"
#include <stdlib.h>
#include <stdio.h>

TLista crearNodo(Pedido);
Pedido obtenerValorNodo(TLista, long int);
void insertarNodo(TLista*, Pedido);
void eliminarNodo(TLista*, long int);
void mostrarIds(TLista);
int buscarNodo(TLista lista, long int);

TLista crearNodo(Pedido p) {
	TLista nodo;
	nodo = (TLista)malloc(sizeof(TNodo));
	nodo->valor = p;
	nodo->sig = NULL;
	
	return nodo;
}

void insertarNodo(TLista* lista, Pedido p) {
	if (*lista == NULL) {
		*lista = crearNodo(p);
	} else {
		TLista aux = *lista;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
	
		aux->sig = crearNodo(p);
	}
}

int buscarNodo(TLista lista, long int id) {
	if (lista == NULL) {
		return 0;
	}
	
	TLista aux = lista;
	while (aux != NULL && aux->valor.id != id) {
		aux = aux->sig;
	}
	if (aux != NULL) return 1;
	//if (aux->valor.id == id) return 1;
	return 0;
}

void eliminarNodo(TLista* lista, long int id) {
	if (*lista == NULL) {
		return;
	}
	
	TLista aux, ant;
	ant = NULL;
	aux = *lista;
	while(aux!=NULL && aux->valor.id != id) {
		ant = aux;
		aux = aux->sig;
	}
	
	if(ant==NULL) {
		*lista = aux->sig;
		aux= NULL; 
	} else { 
		if(aux != NULL){
			ant->sig = aux->sig;
			aux->sig = NULL; 
		}
	}
}

Pedido obtenerValorNodo(TLista lista, long int id) {
	TLista aux = lista;
	while (aux->sig != NULL && aux->valor.id != id) {
		aux = aux->sig;
	}
	
	return aux->valor;
}

void mostrarPedidos(TLista lista) {
	if (lista == NULL) {
		printf("\nNo habia elementos a mostrar.");
		return;
	}
	
	TLista aux = lista;
	while(aux != NULL) {
		mostrarPedido(aux->valor);
		printf("\n");
		aux = aux->sig;
	}
}

void mostrarPedidosSegunFecha(TLista lista, Fecha fecha) {
	if (lista == NULL) {
		printf("\nNo habia elementos a mostrar.");
		return;
	}
	
	int b = 0;
	TLista aux = lista;
	while(aux != NULL) {
		if (compararFechas(fecha, aux->valor.fecha) == 1) {
			mostrarPedido(aux->valor);
			printf("\n");
			b = 1;
		}
		
		aux = aux->sig;
	}
	
	if (b == 0) {
		printf("\nNo habia ningun elemento coincidente a mostrar.");
	}
}

void mostrarIds(TLista lista) {
	if (lista == NULL) {
		printf("\nNo habia elementos a mostrar.");
		return;
	}
	
	TLista aux = lista;
	while(aux != NULL) {
		printf("\n-> %ld", aux->valor.id);
		aux = aux->sig;
	}
}

void agregarPedido(TLista* lista) {
	Pedido p = crearPedido();
	int existe = buscarNodo(*lista, p.id);
	
	if (existe == 0) {
		insertarNodo(lista, p);
		printf("\nNuevo pedido agregado con exito.");
	} else {
		printf("\nNo se pudo agregar el pedido (ya existe).");
	}
}

void resolverPedido(TLista* reparar, TLista* resueltos) {
	if (*reparar == NULL) {
		printf("\nNo hay pedidos a resolver.");
		return;
	}
	Pedido aux;
	long int buscar;
	int existe;
	
	printf("\nDigite un id para resolver: ");
	mostrarIds(*reparar);
	printf("\n> ");
	scanf("%ld", &buscar);
	existe = buscarNodo(*reparar, buscar);
	
	if (existe == 1) {
		aux = obtenerValorNodo(*reparar, buscar);
		eliminarNodo(reparar, buscar);
		insertarNodo(resueltos, aux);
	} else {
		printf("\nNo se encontro el pedido a resolver.");
	}
	
}
