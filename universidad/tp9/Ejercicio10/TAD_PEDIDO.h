#ifndef TAD_PEDIDO_H
#define TAD_PEDIDO_H
#include "TAD_CADENA.h"
#include "TAD_FECHA.h"

typedef struct {
	long int id;
	long int abonado;
	cadena descripcion;
	Fecha fecha;
} Pedido;

Pedido crearPedido();
Fecha obtenerFecha(Pedido);
void mostrarPedido(Pedido);

#endif
