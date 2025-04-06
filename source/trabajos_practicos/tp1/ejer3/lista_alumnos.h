#ifndef LISTA_ALUMNOS_H
#define LISTA_ALUMNOS_H
#define TAM_LISTA_ALUMNOS 60
#include "alumno.h"

typedef struct {
    Alumno elems[TAM_LISTA_ALUMNOS];
    int cant;
} TAlumnos;

#endif