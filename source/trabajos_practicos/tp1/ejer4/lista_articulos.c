#include "lista_articulos.h"
#include "articulo.h"
#include <stdio.h>
#include <string.h>

ListaArticulos lista_articulos_inicializar(int n) {
	ListaArticulos lista = {};
	lista.tam = 0;
	Articulo aux;
	int i, b;
	
	i = 0;
	while (i < n && i < CAP_ARTICULOS) {
		printf("\n--- Cargando articulo #%d ---", i+1);
		
		aux.codigo = articulo_pedir_codigo();
		b = lista_articulos_pertenece(lista, aux.codigo);\
		if (b != -1) {
			printf("\n! Un articulo con ese codigo ya se encuentra cargado en la lista. Intente de nuevo.");
		} else {
			// Ingresando el resto de datos
			articulo_pedir_nombre(aux.nombre);
			articulo_pedir_proveedor(aux.proveedor);
			aux.stock = articulo_pedir_stock();
			aux.precio = articulo_pedir_precio();
			// Lo añadimos a la lista
			lista = lista_articulos_agregar(lista, aux);
			i++;
		}
	}
	return lista;
}

ListaArticulos lista_articulos_agregar(ListaArticulos lista, Articulo item) {
	int i = lista.tam - 1;
	while (i >= 0 && lista.elementos[i].codigo > item.codigo) {
		lista.elementos[i+1] = lista.elementos[i];
		i--;
	}
	lista.elementos[i+1] = item;
	lista.tam += 1;
	return lista;
}

ListaArticulos lista_articulos_eliminar(ListaArticulos lista, int pos) {
	if (pos >= 0 && pos < lista.tam) {
		for (int i = pos; i < (lista.tam - 1); i++) {
			lista.elementos[i] = lista.elementos[i+1];
		}
		lista.tam--;
	}
	return lista;
}

// Usamos la busqueda binaria para la lista ordenada.
int lista_articulos_pertenece(ListaArticulos lista, unsigned int codigo_buscado) {
	if (lista.tam == 0) {
		return -1;
	}
	int ini = 0;
	int fin = lista.tam;
	int mid = (ini + fin) / 2;
	
	while (ini <= fin && lista.elementos[mid].codigo != codigo_buscado) {
		if (codigo_buscado > lista.elementos[mid].codigo) {
			ini = mid + 1;
		} else {
			fin = mid - 1;
		}
		mid = (ini + fin) / 2;
	}
	
	if (ini > fin) {
		return -1;
	}
	return mid;
}

void lista_articulos_mostrar(ListaArticulos lista) {
	if (lista.tam == 0) {
		printf("\n~ No hay articulos para mostrar.");
	}
	for (int i = 0; i < lista.tam; i++) {
		printf("\n-------------------------");
		articulo_mostrar(lista.elementos[i]);
		printf("\n-------------------------");
	}
}

void lista_articulos_mostrar_por_proveedor(ListaArticulos lista, cadena proveedor) {
	Articulo aux;
	cadena proveedor_aux, articulo_prov;
	int b = 0;
	
	// Copiamos por las dudas, para no modificar el proveedor pasado como argumento.
	strcpy(proveedor_aux, proveedor);
	
	for (int i = 0; i < lista.tam; i++) {
		aux = lista.elementos[i];
		// Pasamos todo a minusculas para comparar.
		strcpy(articulo_prov, aux.proveedor);
		cadena_lower(articulo_prov);
		cadena_lower(proveedor_aux);
		
		if (strcmp(articulo_prov, proveedor_aux) == 0) {
			printf("\n-------------------------");
			articulo_mostrar(aux);
			printf("\n-------------------------");
			b = 1;
		}
	}
	
	if (b == 0) {
		printf("\n~ No hay articulos asociados al proveedor que especifo.");
	}
}

void lista_articulos_mostrar_por_stock(ListaArticulos lista, unsigned int stock) {
	Articulo aux;
	int b = 0;
	for (int i = 0; i < lista.tam; i++) {
		aux = lista.elementos[i];
		if (aux.stock < stock) {
			printf("\n-------------------------");
			articulo_mostrar(aux);
			printf("\n-------------------------");
			b = 1;
		}
	}
	if (b == 0) {
		printf("\n~ No hay articulos que tengan el nivel de stock especificado.");
	}
}
