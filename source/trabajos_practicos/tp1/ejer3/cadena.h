#ifndef CADENA_H
#define CADENA_H
#define CAP_CADENA 100

typedef char cadena[CAP_CADENA];

void ingresar_cadena(const char *mensaje, cadena buff);
void limpiar_buffer();
int cmpcadenas(cadena s1, cadena s2);

#endif
