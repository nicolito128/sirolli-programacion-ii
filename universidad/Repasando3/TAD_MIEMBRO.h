#ifndef MIEMBRO_H
#define MIEMBRO_H
#include "TAD_CADENA.h"

typedef struct {
	long int dni;
	cadena celular;
	char estado;
	int edad;
} Miembro;

Miembro crear_miembro();
int comparar_dni(Miembro, long int);
void mostrar_miembro(Miembro);

#endif
