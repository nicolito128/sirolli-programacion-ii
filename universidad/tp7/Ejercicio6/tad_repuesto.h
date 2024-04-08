#ifndef TAD_REPUESTO_H
#define TAD_REPUESTO_H
#include "cadenas.h"

typedef struct {
	long int codigo;
	float precio;
	int stock;
	cadena nombre;
} Repuesto;

// Prototipos
Repuesto obtenerRepuesto();
void mostrarRepuesto(Repuesto);
void modificarPrecio(Repuesto*);
int stockDisponible(Repuesto);

#endif
