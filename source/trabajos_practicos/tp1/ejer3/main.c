#include <stdio.h>
#include "lista_alumnos.h"
#include "alumno.h"
#include "fecha.h"
#include "cadena.h"

void menu();
TAlumnos inicializar_lista();
TAlumnos opcion_agregar(TAlumnos lista);
TAlumnos opcion_modificar_datos(TAlumnos lista);
TAlumnos opcion_dar_de_baja(TAlumnos lista);
void opcion_mostrar_posgrado(TAlumnos lista);
void opcion_mostrar_alumnos(TAlumnos lista);

int main() {
	menu();
    return 0;
}

void menu() {
	TAlumnos lista = inicializar_lista();
	double opcion;
	
	do {
		printf("\n--- Menu del Ejercicio 3: Gestor de alumnos de posgrado ---");
		printf("\n[ 0 ] Salir.");
		printf("\n[ 1 ] Agregar un nuevo alumno de posgrado.");
		printf("\n[ 2 ] Modificar los datos de un alumno.");
		printf("\n[ 3 ] Dar bajas segun fecha.");
		printf("\n[ 4 ] Mostrar lista de alumnos de posgrado.");
		printf("\n[ 5 ] Mostrar lista de alumnos completa.");
		printf("\nSeleccione una de las opciones > ");
		scanf("%lf", &opcion);
		limpiar_buffer();
		
		switch ((int)(opcion)) {
		case 1:
			lista = opcion_agregar(lista);
			break;
		case 2:
			lista = opcion_modificar_datos(lista);
			break;
		case 3:
			lista = opcion_dar_de_baja(lista);
			break;
		case 4:
			opcion_mostrar_posgrado(lista);
			break;
		case 5:
			opcion_mostrar_alumnos(lista);
			break;
		}
	} while((int)(opcion) != 0);
	printf("\nFinalizando el programa. Ciao!");
}

TAlumnos inicializar_lista() {
	int n;
	TAlumnos lista = {};
	lista.tam = 0;
	
	printf("\nIngrese la N cantidad de alumnos a cargar o 0 para una lista vacia > ");
	scanf("%d", &n);
	limpiar_buffer();
	
	if (n > 0) {
		lista = cargar_lista_alumnos(n);
	}
	
	return lista;
}

TAlumnos opcion_agregar(TAlumnos lista) {
	Alumno aux = ingresar_alumno();
	lista = agregar_alumno(lista, aux);
	return lista;
}

TAlumnos opcion_modificar_datos(TAlumnos lista) {
	unsigned int dni;
	printf("\n- Ingrese el DNI del alumno a modificar > ");
	scanf("%u", &dni);
	limpiar_buffer();
	lista = modificar_alumno(lista, dni);
	return lista;
}

TAlumnos opcion_dar_de_baja(TAlumnos lista) {
	printf("\n-- Fecha de finalizacion para dar de baja --");
	Fecha fin = ingresar_fecha();
	lista = dar_bajas(lista, fin);
	return lista;
}

void opcion_mostrar_posgrado(TAlumnos lista) {
	cadena posgrado;
	ingresar_cadena("\nIngrese el curso de posgrado > ", posgrado);
	mostrar_alumnos_posgrado(lista, posgrado);
}

void opcion_mostrar_alumnos(TAlumnos lista) {
	mostrar_alumnos(lista);
}
