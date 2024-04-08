#include "TAD_PEDIDO.h"
#include "TAD_CADENA.h"
#include "TAD_FECHA.h"

Fecha obtenerFecha(Pedido p) {
	return p.fecha;
}

Pedido crearPedido() {
	Pedido aux;
	
	printf("\nCargando pedido\n");
	printf("Ingrese el identificador del pedido: ");
	scanf("%ld", &aux.id);
	
	printf("Ingrese el identificador del abonado para este pedido: ");
	scanf("%ld", &aux.abonado);
	
	printf("Ingrese la descripcion del problema a resolver del pedido: ");
	leeCad(aux.descripcion, 100);
	
	aux.fecha = crearFecha();
	
	return aux;
}


void mostrarPedido(Pedido p) {
	printf("\nN* de Pedido: %ld", p.id);
	printf("\nN* de abonado: %ld", p.abonado);
	printf("\nDescripcion: %s", p.descripcion);
	printf("\nFecha: %d/%d/%d", p.fecha.dia, p.fecha.mes, p.fecha.anio);
	
}
