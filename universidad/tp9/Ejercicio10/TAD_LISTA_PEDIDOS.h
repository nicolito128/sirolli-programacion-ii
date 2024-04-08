#ifndef TAD_LISTA_PEDIDOS_H
#define TAD_LISTA_PEDIDOS_H
#include "TAD_PEDIDO.h"
#include "TAD_FECHA.h"

typedef struct Nodo {
	Pedido valor;
	struct Nodo *sig;
} TNodo;

typedef TNodo* TLista;

void mostrarPedidos(TLista);
void mostrarPedidosSegunFecha(TLista, Fecha);
void agregarPedido(TLista*);
void resolverPedido(TLista*, TLista*);

#endif
