#ifndef CLIENTE_H
#define CLIENTE_H
#include "cadena.h"
#include "fecha.h"

typedef struct {
	cadena apellido;
	cadena nombre;
	unsigned int dni;
	float saldo;
	Fecha operacion;
} Cliente;

// Cabeceras para ingresar datos

unsigned int cliente_pedir_dni();
void cliente_pedir_apellido(cadena s);
void cliente_pedir_nombre(cadena s);
float cliente_pedir_saldo_inicial();
Fecha cliente_pedir_operacion();

// Ingresar un cliente completo desde consola.
Cliente cliente_ingresar();

// Obtener el nombre completo con el formato `%s(apellido), %s(nombre)` 
void cliente_nombre_completo(Cliente c, cadena s);

// Acredita (suma) saldo a la cuenta del cliente.
Cliente cliente_acreditar(Cliente c, float cantidad);

// Transfiere (resta) saldo a la cuenta del cliente.
Cliente cliente_transferencia(Cliente c, float cantidad);

void cliente_mostrar(Cliente c);

#endif
