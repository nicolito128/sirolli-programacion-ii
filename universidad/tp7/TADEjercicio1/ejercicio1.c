#include "ejercicio1.h"
#include <stdio.h>

Repuesto obtenerRepuesto();

Repuesto obtenerRepuesto() {
	Repuesto ret;
	printf("\nIngrese el codigo del repuesto: ");
	scanf("%d", &ret.codigo);
	
	return ret;
}

void agregarRepuesto(RegistroRepuestos* registro) {
	Repuesto r = obtenerRepuesto();
	
}
