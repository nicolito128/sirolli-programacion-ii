#include "cadena.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void cadena_ingresar(cadena s) {
	unsigned char ch;
	int i = 0;
	while (i < (CAP_CADENA - 1) && (ch = getchar()) != '\n' && ch != EOF) {
		s[i] = ch;
		i += 1;
	}
	s[i] = '\0';
	if (ch != '\n' && ch != EOF) limpiar_buffer();
}

// Limpiando el buffer de entrada/salida.
// Si, es absolutamente necesario.
void limpiar_buffer() {
	unsigned char c;
	while ((c= getchar()) != '\n' && c != EOF) {}
}

void cadena_lower(cadena s) {
	unsigned char ch;
	int i = 0;
	ch = s[i];
	while (ch != '\0' && i < CAP_CADENA) {
		s[i] = tolower(ch);
		i += 1;
		ch = s[i];
	}
}

int cadena_es_numero(cadena s) {
	unsigned char ch;
	int i = 0, b = 1;
	ch = s[i];
	while(ch != '\0' && i < CAP_CADENA) {
		if (isdigit(ch) == 0) {
			b = 0;
			break;
		}
		i += 1;
		ch = s[i];
	}
	return b;
}
