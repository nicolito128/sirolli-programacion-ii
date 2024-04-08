#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTA_PEDIDOS.h"
#include "TAD_PEDIDO.h"

void menu(TLista*, TLista*);

int main() {
	TLista reparar, resueltos;
	reparar = NULL;
	resueltos = NULL;
	
	menu(&reparar, &resueltos);
	return 0;
}

void menu(TLista* reparar, TLista* resueltos) {
	int option;
	// Meter en una funcion "opciones"
	Fecha fecha_aux;
	printf("Menu de Opciones");
	printf("\nIngrese alguna de las siguientes opciones: ");
	printf("\n0. Salir\n1. Agregar nuevo pedido de reparacion");
	printf("\n2. Mostrar los pedidos en reparacion\n3. Mostrar pedidos resueltos por una fecha dada");
	printf("\n4. Eliminar un pedido de reparacion y resuelvelo");
	printf("\n> ");
	scanf("%d", &option);
	
	switch(option) {
	case 1:
		agregarPedido(reparar);
		break;
	case 2:
		mostrarPedidos(*reparar);
		break;
	case 3:
		fecha_aux = crearFecha();
		mostrarPedidosSegunFecha(*resueltos, fecha_aux);
		break;
	case 4:
		resolverPedido(reparar, resueltos);
		break;
	case 0:
		return;
		break;
	}
	
	printf("\n");
	system("pause");
	system("cls");
	menu(reparar, resueltos);
}
