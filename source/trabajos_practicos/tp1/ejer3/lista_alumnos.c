#include "lista_alumnos.h"
#include "alumno.h"
#include "fecha.h"
#include "cadena.h"
#include <stdio.h>

int buscar_alumno_por_dni(TAlumnos lista, unsigned int dni);

TAlumnos cargar_lista_alumnos(int n) {
	Alumno aux;
	TAlumnos lista = {};
	for (int i = 0; i < n; i++) {
		aux = ingresar_alumno();
		lista = agregar_alumno(lista, aux);
	}
	return lista;
}

TAlumnos agregar_alumno(TAlumnos lista, Alumno alumno) {
	int i = lista.tam - 1;
	while (i >= 0 && cmpalumnos(lista.elems[i], alumno) > 0) {
		lista.elems[i+1] = lista.elems[i];
		i--;
	}
	lista.elems[i+1] = alumno;
	lista.tam += 1;
	return lista;
}

// Cuando el alumno existe, devuelve su posicion en la lista.
// Cuando no existe, retorna -1.
int buscar_alumno_por_dni(TAlumnos lista, unsigned int dni) {
	int posicion = -1;
	int i = 0;
	while (i < lista.tam) {
		if (lista.elems[i].dni == dni) {
			posicion = i;
			break;
		}
		i++;
	}
	return posicion;
}

TAlumnos modificar_alumno(TAlumnos lista, unsigned int dni) {
	int opcion, pos = buscar_alumno_por_dni(lista, dni);
	if (pos != -1) {
		do {
			printf("\n--- Modificando los datos del alumon con DNI %d (%s, %s) ---", lista.elems[pos].dni, lista.elems[pos].apellido, lista.elems[pos].nombre);
			printf("\n[ 0 ] Salir.");
			printf("\n[ 1 ] Cambiar nombre.");
			printf("\n[ 2 ] Cambiar apellido.");
			printf("\n[ 3 ] Cambiar curso de posgrado.");
			printf("\n[ 4 ] Cambiar estado de posgrado.");
			printf("\n[ 5 ] Cambiar fecha de inicio de posgrado.");
			printf("\n[ 5 ] Cambiar fecha de fin de posgrado.");
			printf("\nSeleccione una opcion de modificacoón > ");
			scanf("%d", &opcion);
			limpiar_buffer();
			
			switch(opcion) {
			case 1:
				pedir_nombre(lista.elems[pos].nombre);
				break;
			case 2:
				pedir_apellido(lista.elems[pos].apellido);
				break;
			case 3:
				pedir_curso_posgrado(lista.elems[pos].curso_posgrado);
				break;
			case 4:
				lista.elems[pos].estado = pedir_estado();
				break;
			case 5:
				lista.elems[pos].inicio_posgrado = pedir_fecha_inicio();
				break;
			case 6:
				lista.elems[pos].fin_posgrado = pedir_fecha_fin(lista.elems[pos].inicio_posgrado);
				break;
			}
		} while(opcion != 0);
	} else {
		printf("\n-- No fue posible encontrar al alumno.\n");
	}
	return lista;
}

TAlumnos dar_bajas(TAlumnos lista, Fecha fecha_finalizacion) {
	int dias;
	for (int i = 0; i < lista.tam; i++) {
		dias = transcurrido_fechas(lista.elems[i].inicio_posgrado, fecha_finalizacion);
		if (dias > 365) {
			lista.elems[i].estado = BAJA;
			printf("\n-> DNI N. %d (%s, %s) fue dado de baja.", lista.elems[i].dni, lista.elems[i].apellido, lista.elems[i].nombre);
		}
	}
	return lista;
}

void mostrar_alumnos(TAlumnos lista) {
	Alumno aux;
	if (lista.tam == 0) {
		printf("\nNo hay datos para mostrar.");
	} else {
		for (int i = 0; i < lista.tam; i += 1) {
			aux = lista.elems[i];
			mostrar_alumno(aux);
		}		
	}
}

void mostrar_alumnos_posgrado(TAlumnos lista, cadena posgrado) {
	Alumno aux;
	int b = 0;
	if (lista.tam == 0) {
		printf("\nNo hay datos para mostrar.");
	} else {
		for (int i = 0; i < lista.tam; i += 1) {
			aux = lista.elems[i];
			if (cmpcadenas(posgrado, aux.curso_posgrado) == 0) {
				mostrar_alumno(aux);
				b = 1;
			}
		}
		if (b == 0) {
			printf("\nNo se encontraron alumnos del posgrado.");
		}
	}
}
