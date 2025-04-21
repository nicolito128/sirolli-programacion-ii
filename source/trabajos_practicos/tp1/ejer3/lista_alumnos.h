#ifndef LISTA_ALUMNOS_H
#define LISTA_ALUMNOS_H
#define CAP_LISTA_ALUMNOS 80
#include "alumno.h"
#include "cadena.h"

typedef struct {
    Alumno elems[CAP_LISTA_ALUMNOS];
    int tam;
} TAlumnos;

// Carga una nueva lista de N alumnos.
TAlumnos cargar_lista_alumnos(int n);

// Agrega un alumno a lista y devuelve su nuevo valor.
TAlumnos agregar_alumno(TAlumnos lista, Alumno alumno);

// Dado un DNI y Curso de Posgrado, cambia los datos del alumno.
TAlumnos modificar_alumno(TAlumnos lista, unsigned int dni);

TAlumnos dar_bajas(TAlumnos lista, Fecha fecha_finalizacion);

void mostrar_alumnos(TAlumnos lista);

void mostrar_alumnos_posgrado(TAlumnos lista, cadena posgrado);

#endif
