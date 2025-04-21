#ifndef CADENA_H
#define CADENA_H
#define CAP_CADENA 128

typedef char cadena[CAP_CADENA];

// Ingresa una nueva cadena por consola.
void cadena_ingresar(cadena s);

// Usar SIEMPRE despues de un scanf.
void limpiar_buffer();

// Modifica la cadena `s` para que todas las letras pasen a ser minúsculas.
void cadena_lower(cadena s);

// Devuelve 1 cuando la cadena `s` puede considerarse un numero entero valido.
// Caso contrario, devuelve 0.
int cadena_es_numero(cadena s);

#endif
