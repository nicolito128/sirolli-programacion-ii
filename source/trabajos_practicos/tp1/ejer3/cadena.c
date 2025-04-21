#include "cadena.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ingresar_cadena(const char *mensaje, cadena buff) {
	printf(mensaje);
	unsigned char c;
	int i = 0;
	while (i < (CAP_CADENA - 1) && (c = getchar()) != '\n' && c != EOF) {
		buff[i] = c;
		i++;
	}
	buff[i] = '\0';
	if (c != EOF && c != '\n') limpiar_buffer();
}

void limpiar_buffer() {
	unsigned char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int cmpcadenas(cadena s1, cadena s2) {
    return strcmp(s1, s2);
}
