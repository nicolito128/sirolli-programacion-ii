#ifndef ALUMNO_H
#define ALUMNO_H
#include "cadena.h"
#include "fecha.h"

enum EstadoPosgrado {
    CURSANDO, FINALIZADO, PENDIENTE, BAJA
};

typedef struct {
    unsigned int dni;
    cadena curso_posgrado;
    cadena nombre;
	cadena apellido;

	enum EstadoPosgrado estado;
    Fecha inicio_posgrado;
    Fecha fin_posgrado;
} Alumno;

unsigned int pedir_dni();
void pedir_nombre(cadena s);
void pedir_apellido(cadena s);
void pedir_curso_posgrado(cadena s);
enum EstadoPosgrado pedir_estado();
Fecha pedir_fecha_inicio();
Fecha pedir_fecha_fin(Fecha inicio);

// Carga un nuevo alumno desde consola.
Alumno ingresar_alumno();

// Compara dos alumnos en funcion de su DNI y Nombre.
int cmpalumnos(Alumno a1, Alumno a2);

void mostrar_alumno(Alumno a);

#endif
