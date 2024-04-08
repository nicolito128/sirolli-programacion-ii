#ifndef TAD_FECHA_H
#define TAD_FECHA_H

typedef struct {
	int dia, mes, anio;
} Fecha;

Fecha crearFecha();
int compararFechas(Fecha, Fecha);

#endif
