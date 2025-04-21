#include "cadena.h"
#include <stdio.h>
#include <ctype.h>

void cadena_ingresar(cadena s) {
	unsigned char c;
	int i = 0;
	while (i < (CAP_CADENA - 1) && (c = getchar()) != '\n' && c != EOF) {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	if (c != EOF && c != '\n') limpiar_buffer();
}

void limpiar_buffer() {
	unsigned char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int cadena_es_num_entero(cadena s) {
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

int cadena_es_num_real(cadena s) {
	unsigned char ch;
	int i = 0, b = 1, coma = 0;
	ch = s[i];
	while(ch != '\0' && i < CAP_CADENA) {
		if (isdigit(ch) == 0) {
			if (ch == '-' && i == 0) {
				i += 1;
				ch = s[i];
				continue;
			}
			if (ch == '.') {
				if (coma == 0) {
					coma = 1;
				} else {
					b = 0;
					break;
				}
			} else {
				b = 0;
				break;
			}
		}
		i += 1;
		ch = s[i];
	}
	return b;
}
