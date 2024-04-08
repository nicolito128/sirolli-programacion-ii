#include <stdio.h>
#include <stdlib.h>
#include "TAD_MIEMBRO.h"
#include "TAD_CADENA.h"

Miembro crear_miembro() {
	Miembro res;
	
	printf("Obteniendo Miembro\n");
	
	printf("Ingrese un DNI > ");
	scanf("%ld", &res.dni);
		
	printf("Ingrese un telefono celular > ");
	leeCad(res.celular, 9);
	
	printf("Ingrese un estado civil (C: casado, S: soltero, V: viudo, W: separado) > ");
	scanf("%s", &res.celular);
	
	printf("Ingrese una edad > ");
	scanf("%d", &res.edad);
	printf("\n");
	
	return res;
}

int comparar_dni(Miembro m, long int dni) {
	int resultado;
	if (m.dni == dni) {
		resultado = 1;
	} else {
		resultado = 0;
	}
	
	return resultado;
}

void mostrar_miembro(Miembro m) {
	printf("DNI: %ld\n", m.dni);
	printf("Celular: %s\n", m.celular);
	printf("Estado: %c\n", m.estado);
	printf("Edad: %d\n", m.edad);
}
