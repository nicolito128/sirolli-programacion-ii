#ifndef ALUMNO_H
#define ALUMNO_H
#include "cadena.h"
#include "fecha.h"

enum EstadoAlumno {
    Cursando,
    Finalizado,
    Pendiente,
    Baja
};

typedef struct {
    unsigned int dni;
    cadena curso_posgrado;
    cadena nombre_completo;
    Fecha inicio_posgrado;
    Fecha fin_posgrado;
    EstadoAlumno estado;
} Alumno;

#endif