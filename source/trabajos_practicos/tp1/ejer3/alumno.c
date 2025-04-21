#include "alumno.h"
#include "cadena.h"
#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Interfaz privada
const char *estadostr(enum EstadoPosgrado);

const char *estadostr(enum EstadoPosgrado ep) {
	char *res = "";
	switch(ep) {
	case 0:
		res = "Cursando";
		break;
	case 1:
		res = "Finalizado";
		break;
	case 2:
		res = "Pendiente";
		break;
	case 3:
		res = "Baja";
		break;
	default:
		res = "NADA";
	}
	return (const char*)(res);
}

unsigned int pedir_dni() {
	cadena aux;
	unsigned char c;
	int b = 0;
	
	do {
		ingresar_cadena("\n- Ingrese el DNI > ", aux);
		
		int i = 0;
		c = aux[i];
		while (isdigit(c) != 0 && c != '\0' && c != '\n' && c != EOF) {
			i++;
			c = aux[i];
		}
		
		if (isdigit(c) == 0 && c != '\0' && c != '\n' && c != EOF) {
			printf("\n-- No ingreso un DNI valido. Trate de nuevo.");
		} else {
			b = 1;
		}
	} while(b != 1);
	char *end = NULL;
	return strtoul(aux, &end, 10);
}

void pedir_nombre(cadena s) {
	ingresar_cadena("\n- Ingrese un Nombre > ", s);
}

void pedir_apellido(cadena s) {
	ingresar_cadena("\n- Ingrese un Apellido > ", s);
}

void pedir_curso_posgrado(cadena s) {
	ingresar_cadena("\n- Ingrese un Curso de Posgrado > ", s);
}

enum EstadoPosgrado pedir_estado() {
	unsigned int tmp;
	int b = 0;
	do {
		printf("\n- Ingrese un Estado de Posgrado (0: Cursando, 1: Finalizado, 2: Pendiente, 3: Baja) > ");
		scanf("%u", &tmp);
		if (tmp < 0 || tmp > 3) {
			printf("\n-- Estado de posgrado INVALIDO. Intente de nuevo.");
		} else {
			b = 1;
		}
	} while(b != 1);
	return (enum EstadoPosgrado)(tmp);
}

Fecha pedir_fecha_inicio() {
	printf("\n- Inicio de posgrado");
	return ingresar_fecha();
}

Fecha pedir_fecha_fin(Fecha inicio) {
	Fecha fin;
	int dias_transcurridos;
	printf("\n- Fin de posgrado");
	do {
		fin = ingresar_fecha();
		dias_transcurridos = transcurrido_fechas(inicio, fin);
		if (dias_transcurridos == -1) {
			printf("\n--La fecha de finalizacoón no puede ser anterior a la de inicio. Intente de nuevo.");
		}
	} while(dias_transcurridos == -1);
	return fin;
}

Alumno ingresar_alumno() {
	Alumno in;
	in.dni = pedir_dni();
	
	pedir_apellido(in.apellido);
	pedir_nombre(in.nombre);
	pedir_curso_posgrado(in.curso_posgrado);
	
	in.estado = pedir_estado();
	
	// Inicio del posgrado
	in.inicio_posgrado = pedir_fecha_inicio();
	
	// Fin de posgrado
	in.fin_posgrado.anio = 0;
	in.fin_posgrado.mes = 0;
	in.fin_posgrado.dia = 0;
	if (in.estado == FINALIZADO)  {
		in.fin_posgrado = pedir_fecha_fin(in.inicio_posgrado);
	}
	return in;
}

int cmpalumnos(Alumno a1, Alumno a2) {
	if (a1.dni > a2.dni) {
		return 1;
	} else {
		if (a1.dni < a2.dni) {
			int cmp = cmpcadenas(a1.apellido, a2.apellido);
			if (cmp == 1) {
				return 1;
			} else {
				if (cmp < 0) {
					return -1;
				} else {
					return 0;
				}
			}
		}
	}
	return 0;
}

void mostrar_alumno(Alumno a) {
	printf("\n----------------------------------");
	printf("\nDNI: %d", a.dni);
	printf("\nNombre completo: %s, %s", a.apellido, a.nombre);
	printf("\nCurso de posgrado: %s", a.curso_posgrado);
	printf("\nEstado: %s", estadostr(a.estado));
	printf("\nFecha de inicio: ");
	mostrar_fecha(a.inicio_posgrado);
	printf("\nFecha de finalización: ");
	mostrar_fecha(a.fin_posgrado);
	printf("\n----------------------------------");
}
