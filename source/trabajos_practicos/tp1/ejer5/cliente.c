#include "cliente.h"
#include "cadena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned int cliente_pedir_dni() {
	cadena aux;
	do {
		printf("\n- Ingrese un DNI > ");
		cadena_ingresar(aux);
		if (!cadena_es_num_entero(aux)) {
			printf("\n! El DNI ingresado no es un numero valido.");
		} 
	} while(!cadena_es_num_entero(aux));
	return (unsigned int)(strtoul(aux, (char**)(NULL), 10));
}

void cliente_pedir_apellido(cadena s) {
	printf("\n- Ingrese un Apellido > ");
	cadena_ingresar(s);
}

void cliente_pedir_nombre(cadena s) {
	printf("\n- Ingrese un Nombre > ");
	cadena_ingresar(s);
}

float cliente_pedir_saldo_inicial() {
	cadena aux;
	do {
		printf("\n- Ingrese un Saldo > ");
		cadena_ingresar(aux);
		if (!cadena_es_num_real(aux)) {
			printf("\n! El saldo ingresado no es un numero valido.");
		}
	} while(!cadena_es_num_real(aux));
	return (float)(atof(aux));
}

Fecha cliente_pedir_operacion() {
	printf("\n- Carga de la fecha de operacion -");
	return fecha_ingresar();
}

Cliente cliente_ingresar() {
	Cliente c;
	c.dni = cliente_pedir_dni();
	cliente_pedir_apellido(c.apellido);
	cliente_pedir_apellido(c.nombre);
	c.saldo = cliente_pedir_saldo_inicial();
	c.operacion = cliente_pedir_operacion();
	return c;
}

void cliente_nombre_completo(Cliente c, cadena s) {
	int i = 0, j = 0;
	while(c.apellido[i] != '\0' && j < (CAP_CADENA - 1)) {
		s[j] = c.apellido[i];
		i++;
		j++;
	}
	s[j] = ',';
	s[++j] = ' ';
	++j;
	i =0 ;
	while(c.nombre[i] != '\0' && j < (CAP_CADENA - 1)) {
		s[j] = c.nombre[i];
		i++;
		j++;
	}
	s[j] = '\0';
}

Cliente cliente_acreditar(Cliente c, float cantidad) {
	c.saldo += fabs(cantidad);
	return c;
}

Cliente cliente_transferencia(Cliente c, float cantidad) {
	c.saldo -= fabs(cantidad);
	return c;
}

void cliente_mostrar(Cliente c) {
	cadena aux;
	cliente_nombre_completo(c, aux);
	printf("\nDNI: %u", c.dni);
	printf("\nNombre completo: %s", aux);
	printf("\nSaldo actual: %.2f", c.saldo);
	printf("\nOperacion: ");
	fecha_mostrar(c.operacion);
}
