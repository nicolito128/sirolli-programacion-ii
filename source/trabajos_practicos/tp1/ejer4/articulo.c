#include "articulo.h"
#include "cadena.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned int convertir_cadena_a_uint(cadena s);

void articulo_pedir_nombre(cadena s) {
	printf("\n- Ingrese un Nombre de Artículo > ");
	cadena_ingresar(s);
}

void articulo_pedir_proveedor(cadena s) {
	printf("\n- Ingrese un Proveedor > ");
	cadena_ingresar(s);
}

unsigned int articulo_pedir_codigo() {
	cadena aux = {0};
	int b = 0;
	do {
		printf("\n- Ingrese un entero como Codigo > ");
		cadena_ingresar(aux);
		
		if (cadena_es_numero(aux) == 1) {
			b = 1;
		} else {
			printf("\n! El codigo ingresado NO es nemero entero valido.");
		}
	} while(b != 1);
	return convertir_cadena_a_uint(aux);
}

unsigned int articulo_pedir_stock() {
	cadena aux = {0};
	int b = 0;
	do {
		printf("\n- Ingrese un entero para el Stock > ");
		cadena_ingresar(aux);
		
		if (cadena_es_numero(aux) == 1) {
			b = 1;
		} else {
			printf("\n! El stock ingresado NO es numero entero valido.");
		}
	} while(b != 1);
	return convertir_cadena_a_uint(aux);
}

float articulo_pedir_precio() {
	float precio;
	int b = 0;
	do {
		printf("\n- Ingrese un Precio $");
		scanf("%f", &precio);
		limpiar_buffer();
		
		if (precio < 0) {
			printf("\n! El precio ingresado no puede ser negativo.");
		} else {
			b = 1;
		}
	} while(b != 1);
	return precio;
}

Articulo articulo_ingresar() {
	Articulo item;
	item.codigo = articulo_pedir_codigo();
	articulo_pedir_nombre(item.nombre);
	articulo_pedir_proveedor(item.proveedor);
	item.stock = articulo_pedir_stock();
	item.precio = articulo_pedir_precio();
	return item;
}

void articulo_mostrar(Articulo item) {
	printf("\nCodigo: %u", item.codigo);
	printf("\nNombre: %s", item.nombre);
	printf("\nProveedor: %s", item.proveedor);
	printf("\nStock: %u", item.stock);
	printf("\nPrecio: %.2f", item.precio);
}

unsigned int convertir_cadena_a_uint(cadena s) {
	unsigned char ch;
	unsigned int res = 0;
	int i = 0;
	ch = s[i];
	while (ch != '\0' && i < CAP_CADENA) {
		res = res*10 + (int)(ch - '0');
		i += 1;
		ch = s[i];
	}
	return res;
}
