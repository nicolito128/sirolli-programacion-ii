#ifndef FECHA_H
#define FECHA_H

typedef enum {
	ENERO = 1,
	FEBRERO, // 2
	MARZO, // 3
	ABRIL, // 4
	MAYO, // 5...
	JUNIO,
	JULIO, 
	AGOSTO, 
	SEPTIEMBRE, 
	OCTUBRE, 
	NOVIEMBRE,
	DICIEMBRE
} Mes;

typedef struct {
	int anio;
	Mes mes;
	int dia;
} Fecha;

// Si f1 es mayor a f2, retorna 1.
// Si f1 es menor a f2, retorna -1. 
// Si ambas fechas son iguales, retorna 0.
int fecha_comparar(Fecha f1, Fecha f2);

// Carga una nueva fecha por consola.
Fecha fecha_ingresar();

// Muestra la fecha por consola
void fecha_mostrar(Fecha f);

#endif
