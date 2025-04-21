#ifndef CADENA_H
#define CADENA_H
#define CAP_CADENA 128

typedef char cadena[CAP_CADENA];

// Ingresa una cadena por consola.
void cadena_ingresar(cadena s);

// Ejecutar después de un scanf para limpiar la stdin.
void limpiar_buffer();

int cadena_es_num_entero(cadena s);

int cadena_es_num_real(cadena s);
	
#endif
