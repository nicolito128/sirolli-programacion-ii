#include <stdio.h>
#include "lista_articulos.h"
#include "articulo.h"
#include "cadena.h"

void menu();
void opcion_mostrar_lista_por_proveedor(ListaArticulos lista);
void opcion_mostrar_por_stock(ListaArticulos lista);
ListaArticulos inicializar_lista();
ListaArticulos opcion_agregar_elemento(ListaArticulos lista);
ListaArticulos opcion_eliminar_elemento(ListaArticulos lista);

int main(void) {
	menu();
	return 0;
}

void menu() {
	int opcion;
	float aux;
	ListaArticulos lista = inicializar_lista();
	do {
		printf("\n----- Menu del Ejercicio 4: Tienda de articulos de libreria -----");
		printf("\n[ 0 ] Salir.");
		printf("\n[ 1 ] Agregar un nuevo articulo.");
		printf("\n[ 2 ] Eliminar un artículo segun su codigo.");
		printf("\n[ 3 ] Mostrar todos los articulos.");
		printf("\n[ 4 ] Mostrar los articulos segun Proveedor.");
		printf("\n[ 5 ] Mostrar articulos según el Stock disponible..");
		printf("\nSeleccione una opcion > ");
		scanf("%f", &aux);
		limpiar_buffer();
		opcion = (int)(aux);
		
		switch (opcion) {
		case 1:
			lista = opcion_agregar_elemento(lista);
			break;
		case 2:
			lista = opcion_eliminar_elemento(lista);
			break;
		case 3:
			lista_articulos_mostrar(lista);
			break;
		case 4:
			opcion_mostrar_lista_por_proveedor(lista);
			break;
		case 5:
			opcion_mostrar_por_stock(lista);
			break;
		}
	} while(opcion != 0);
	printf("\nSaliendo del programa. Ciao!");
}

ListaArticulos inicializar_lista() {
	float aux;
	int n, b = 0;
	do {
		printf("\n- Seleccione un numero entero N para inicializar la lista o 0 para dejarla vacia > ");
		scanf("%f", &aux);
		limpiar_buffer();
		n = (int)(aux);
		if (n < 0 || n != aux) {
			printf("\n! El numero ingresado no es valido. Intente de nuevo.");
		} else {
			b = 1;
		}
	} while(b != 1);
	return lista_articulos_inicializar(n);
}

ListaArticulos opcion_agregar_elemento(ListaArticulos lista) {
	Articulo aux = articulo_ingresar();
	lista = lista_articulos_agregar(lista, aux);
	return lista;
}

ListaArticulos opcion_eliminar_elemento(ListaArticulos lista) {
	unsigned int codigo = articulo_pedir_codigo();
	int pos = lista_articulos_pertenece(lista, codigo);
	if (pos != -1) {
		lista = lista_articulos_eliminar(lista, pos);
		printf("\n~ Articulo con codigo #%u elimnado.", codigo);
	} else {
		printf("\n! No existe el codigo del articulo ha ser eliminado.");
	}
	return lista;
}

void opcion_mostrar_lista_por_proveedor(ListaArticulos lista) {
	cadena proveedor;
	articulo_pedir_proveedor(proveedor);
	lista_articulos_mostrar_por_proveedor(lista, proveedor);
}

void opcion_mostrar_por_stock(ListaArticulos lista) {
	unsigned int stock = articulo_pedir_stock();
	lista_articulos_mostrar_por_stock(lista, stock);
}
