#ifndef EJERCICIO1_H
#define EJERCICIO1_H
#define tamCadena 100
#define tamVRepuestos 1000

typedef char cadena[tamCadena];

typedef struct {
	int codigo;
	int precio;
	int unidades;
	cadena nombre;
} Repuesto;

typedef Repuesto VRepuestos[tamVRepuestos];

typedef struct {
	VRepuestos vec;
	int tam;
} TRepuesto;

void agregarRepuesto(RegistroRepuestos*);
void mostrarDatosRepuesto(RegistroRepuestos);
void modificarPrecioRepuesto(RegistroRepuestos);
int unidadesDisponibles(RegistroRepuestos, int);


#endif
