#ifndef FECHA_H
#define FECHA_H

enum Mes {
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
};

typedef struct {
	unsigned int anio;
	enum Mes mes;
	int dia;
} Fecha;

// Obtiene la cantidad de dias en un determinado mes.
int obtener_dias_del_mes(enum Mes m);

// Comprueba que una fecha sea logicamente correcta.
int validar_fecha(Fecha f);

// Muestra la cantidad de dias transcurridos desde el inicio hasta el fin.
int transcurrido_fechas(Fecha inicio, Fecha fin);

// Si f1 es mayor a f2, retorna 1.
// Si f1 es menor a f2, retorna -1. 
// Si ambas fechas son iguales, retorna 0.
int comparar_fechas(Fecha f1, Fecha f2);

Fecha ingresar_fecha();

void mostrar_fecha(Fecha f);

#endif
