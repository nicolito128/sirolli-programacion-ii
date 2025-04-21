#include "fecha.h"
#include "cadena.h"
#include <stdio.h>

// Obtiene la cantidad de días en un determinado mes.
int obtener_dias_del_mes(Mes m);

int obtener_dias_del_mes(Mes m) {
	switch (m) {
	case ENERO:
	case MARZO:
	case MAYO:
	case JULIO:
	case AGOSTO:
	case OCTUBRE:
	case DICIEMBRE:
		return 31;
	
	case FEBRERO:
		return 28;
	
	case ABRIL:
	case JUNIO:
	case SEPTIEMBRE:
	case NOVIEMBRE:
		return 30;
		
	default:
		return -1;
	}
}

int fecha_comparar(Fecha f1, Fecha f2) {
	if (f1.anio > f2.anio) {
		return  1;
	} else {
		if (f1.anio < f2.anio) {
			return -1;
		}
		if (f1.mes > f2.mes) {
			return 1;
		} else {
			if (f1.mes < f2.mes) {
				return -1;
			}
			if (f1.dia > f2.dia) {
				return 1;
			} else {
				if (f1.dia < f2.dia) {
					return -1;
				}
				return 0;
			}
		}
	}
}

Fecha fecha_ingresar() {
	Fecha f;
	unsigned int tmp;
	int cant_dias;
	
	int b = 1;
	do {
		printf("\n- Ingrese una fecha con el formato DD/MM/YYYY > ");
		scanf("%d/%u/%d", &f.dia, &tmp, &f.anio);
		limpiar_buffer();
		
		if (f.anio <= 0) {
			printf("\n-- El año ingresado no es valido, trate con un numero mayor a 0.");
			continue;
		}
		
		f.mes = tmp;
		if (f.mes < 1|| f.mes > 12) {
			printf("\n-- El mes ingresado no es valido, trate de nuevo con un valor mayor a 1 y menor a 12.");
			continue;
		}
		
		cant_dias = obtener_dias_del_mes(f.mes);
		if (f.dia < 1 || f.dia > cant_dias) {
			printf("\n-- El dia ingresado no es valido. Seleccione un dia en el rango [1, %d]", cant_dias);
			continue;
		}
		b = 0;
	} while(b);
	
	return f;
}

void fecha_mostrar(Fecha f) {
	printf("\n%d/%d/%d", f.dia, f.mes, f.anio);
}
