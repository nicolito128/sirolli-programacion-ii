#include "TAD_FECHA.h"
#include <stdio.h>

int obtenerDiasDelMes(int);

// Implementaciones publicas
Fecha crearFecha() {
	Fecha aux;
	
	printf("Cargando una fecha\n");

	do {
		printf("Ingrese el anio: ");
		scanf("%d", &aux.anio);
	} while(aux.anio <= 0);
	
	do {
		printf("Ingrese el mes: ");
		scanf("%d", &aux.mes);
	} while(aux.mes <= 0 || obtenerDiasDelMes(aux.mes) == 0);
	
	do {
		printf("Ingrese el dia: ");
		scanf("%d", &aux.dia);
	} while(aux.dia < 1 || aux.dia > obtenerDiasDelMes(aux.mes));
	
	return aux;
}

int compararFechas(Fecha f1, Fecha f2) {
	if (f1.anio == f2.anio && f1.mes == f2.mes && f1.dia == f1.dia) return 1;
	return 0;
}

// Implementaciones privadas
int obtenerDiasDelMes(int mes) {
	if (mes < 1 ||  mes > 12) return 0;
	
	switch(mes){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
		
	case 2:
		return 28;
		break;
		
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	}
	
	return 0;
}
